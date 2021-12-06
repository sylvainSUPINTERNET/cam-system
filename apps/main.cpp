#include <iostream>
#include "hello.h"
#include "json.h"

using json = nlohmann::json;


int main(int, char**) {
    std::string helloJim = generateHelloString("Jim");
    std::cout << helloJim << std::endl;

    // struct CAMERA {
    //     std::string ip;
    //     int angle;
    // };

    json systemJson = parseSystemJson("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    // std::vector arr = systemJson["hacCamera"]["cameras"].get<std::vector<CAMERA>>();
    for (size_t i=0; i < systemJson["hacCamera"]["cameras"].size(); i++) {
        // TODO => ici on peut donc initialiser les cameraDevice
        std::cout << systemJson["hacCamera"]["cameras"][i]["angle"] << std::endl;
        std::cout << systemJson["hacCamera"]["cameras"][i]["ip"] << std::endl;
    }

    CameraDevice newCameraDevice = CameraDevice();
    newCameraDevice.ip = "1922929292";
    newCameraDevice.angle = 90;
    newCameraDevice.channel = "3";
    // json newCameraObjectJson = convertCameraDeviceToJson(newCameraDevice);

    // std::cout << newCameraObjectJson["ip"] << std::endl;

    // OK
    //addCameraDeviceToJson(newCameraDevice);

    // OK
    // deleteCameraDeviceToJson(newCameraDevice);

    // OK 
    //updateCameraDeviceToJson(newCameraDevice);




    return 0;
}