/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.8.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: 2020-02-21
 ***********************************************************************************************/

#ifndef COUNTER_INTERFACE_H
#define COUNTER_INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "digitaltwin_interface_client.h"
#include "azure_c_shared_utility/xlogging.h"
#include "azure_c_shared_utility/threadapi.h"

#include "digitaltwin_client_helper.h"
#include "digitaltwin_serializer.h"
#include "parson.h"
#include "../IoTHandTallyCounterModel_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum COUNTER_TELEMETRY_TAG
{
    Counter_HITCOUNT_TELEMETRY
} COUNTER_TELEMETRY;

typedef enum COUNTER_READONLY_PROPERTY_TAG
{
    Counter_TYPE_PROPERTY,
    Counter_RESETTIME_PROPERTY,
    Counter_TOTALCOUNT_PROPERTY,
    Counter_INTERVAL_PROPERTY
} COUNTER_PROPERTY;

// DigitalTwin interface name from service perspective.
static const char CounterInterfaceId[] = "urn:ilseokoh:Counter:1";
static const char CounterInterfaceInstanceName[] = "counter";

// Telemetry names for this interface.

static const char CounterInterface_HitCountTelemetry[] = "hitCount";

// Property names for this interface.

#define CounterInterface_TypeProperty "Type"

#define CounterInterface_ResetTimeProperty "ResetTime"

#define CounterInterface_TotalCountProperty "TotalCount"

#define CounterInterface_IntervalProperty "Interval"

// Command names for this interface

#define CounterInterface_ResetCountCommand "ResetCount"

// Methods
DIGITALTWIN_INTERFACE_CLIENT_HANDLE CounterInterface_Create();

void CounterInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle);

DIGITALTWIN_CLIENT_RESULT CounterInterface_Telemetry_SendAll();

DIGITALTWIN_CLIENT_RESULT CounterInterface_Property_ReportAll();

DIGITALTWIN_CLIENT_RESULT CounterInterface_Property_ReportType();

DIGITALTWIN_CLIENT_RESULT CounterInterface_Property_ReportResetTime();

DIGITALTWIN_CLIENT_RESULT CounterInterface_Property_ReportTotalCount();

#ifdef __cplusplus
}
#endif

#endif  // COUNTER_INTERFACE_H