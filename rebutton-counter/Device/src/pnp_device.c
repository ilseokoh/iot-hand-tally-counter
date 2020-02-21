/*********************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 *
 * Generated Date: 2020-02-21
 *********************************************************************************************/

#include "pnp_device.h"

// Number of Digital Twins interfaces that this device supports.
#define DIGITALTWIN_INTERFACE_NUM 2

#define COUNTER_INDEX 0

#define DEVICEINFO_INDEX 1

#define DEFAULT_SEND_TELEMETRY_INTERVAL_MS 10000

#define DEVICE_CAPABILITY_MODEL_URI "urn:ilseokoh:IoTHandTallyCounterModel:1"

static DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceClientHandles[DIGITALTWIN_INTERFACE_NUM];
static TICK_COUNTER_HANDLE tickcounter = NULL;
static tickcounter_ms_t lastTickSend;

int pnp_device_initialize(const char* connectionString, const char* trustedCert)
{
    if ((tickcounter = tickcounter_create()) == NULL)
    {
        LogError("tickcounter_create failed");
        return -1;
    }

    DIGITALTWIN_DEVICE_CLIENT_LL_HANDLE digitalTwinDeviceClientHandle = NULL;
    memset(&interfaceClientHandles, 0, sizeof(interfaceClientHandles));

    // Initialize DigitalTwin device handle
    if ((digitalTwinDeviceClientHandle = DigitalTwinClientHelper_InitializeDeviceHandle(connectionString, false, trustedCert)) == NULL)
    {
        LogError("DigitalTwinClientHelper_InitializeDeviceHandle failed");
        return -1;
    }

    // Invoke to the ***Interface_Create - implemented in a separate library - to create DIGITALTWIN_INTERFACE_CLIENT_HANDLE.
    // NOTE: Other than creation and destruction, NO operations may occur on any DIGITALTWIN_INTERFACE_CLIENT_HANDLE
    // until after we've completed its registration (see DigitalTwinClientHelper_RegisterInterfacesAndWait).

    if ((interfaceClientHandles[COUNTER_INDEX] = CounterInterface_Create(digitalTwinDeviceClientHandle)) == NULL)
    {
        LogError("CounterInterface_Create failed");
        return -1;
    }

    if ((interfaceClientHandles[DEVICEINFO_INDEX] = DeviceinfoInterface_Create(digitalTwinDeviceClientHandle)) == NULL)
    {
        LogError("DeviceinfoInterface_Create failed");
        return -1;
    }

    // Register the interface(s) we've created with Azure IoT.  This call will block until interfaces
    // are successfully registered, we get a failure from server, or we timeout.
    if (DigitalTwinClientHelper_RegisterInterfacesAndWait(digitalTwinDeviceClientHandle, DEVICE_CAPABILITY_MODEL_URI, interfaceClientHandles, DIGITALTWIN_INTERFACE_NUM) != DIGITALTWIN_CLIENT_OK)
    {
        LogError("DigitalTwinClientHelper_RegisterInterfacesAndWait failed");
        return -1;
    }

    DigitalTwinClientHelper_Check();

    // report properties

    CounterInterface_Property_ReportAll();

    DeviceinfoInterface_Property_ReportAll();

    tickcounter_get_current_ms(tickcounter, &lastTickSend);
    return 0;
}

void pnp_device_run()
{
    tickcounter_ms_t nowTick;
    tickcounter_get_current_ms(tickcounter, &nowTick);

    if (nowTick - lastTickSend >= DEFAULT_SEND_TELEMETRY_INTERVAL_MS)
    {
        LogInfo("Send telemetry data to IoT Hub");

        CounterInterface_Telemetry_SendAll();

        tickcounter_get_current_ms(tickcounter, &lastTickSend);
    }
    else
    {
        // Just check data from IoT Hub
        DigitalTwinClientHelper_Check();
    }
}

void pnp_device_close()
{
    if (interfaceClientHandles[COUNTER_INDEX] != NULL)
    {
        CounterInterface_Close(interfaceClientHandles[COUNTER_INDEX]);
    }

    if (interfaceClientHandles[DEVICEINFO_INDEX] != NULL)
    {
        DeviceinfoInterface_Close(interfaceClientHandles[DEVICEINFO_INDEX]);
    }

    DigitalTwinClientHelper_DeInitialize();
}
