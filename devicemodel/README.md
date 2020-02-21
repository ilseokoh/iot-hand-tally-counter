# Azure IoT Plug and Play (Preview)

Microsoft announced IoT Plug and Play preview at Microsoft Build in May 2019. 

 The [Azure IoT Device Workbench extension for VS Code](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-iot-workbench) adds IntelliSense for easy authoring of IoT Play and Play device models. It also enables code generation to create C device code that implements the IoT Plug and Play model. The new tooling capabilities also integrates with the model repository service for seamless publishing of device models. In addition to the Azure IoT Device Workbench, device developers can use tools like the [Azure IoT explorer](https://github.com/Azure/azure-iot-explorer/releases) and the Azure IoT extension for Azure Command-line Interface. Device code can be developed with the [Azure IoT SDK for C](https://aka.ms/iotpnpcsdk) and for [Node.js](https://aka.ms/iotpnpnodesdk).

 # Prerequisites

  - Visual Studio Code
  - Azure IoT Tools for VS Code 
  - Azure IoT explorer

# Model IoT Counter

I use the [digital twin definition language](https://aka.ms/DTDL) to create a device capability model. I need to define 2 types files. One is model file, the other is interface file. 