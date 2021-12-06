#pragma once

#include <string>
#include "json.h"

struct CameraDevice {
    std::string ip;
    std::string channel;
    int angle;
};


const std::string generateHelloString(const std::string & personName);

const nlohmann::json parseSystemJson(const std::string & filename);

const nlohmann::json convertCameraDeviceToJson(struct CameraDevice cameraDevice);

const nlohmann::json addCameraDeviceToJson(struct CameraDevice cameraDevice);

const nlohmann::json deleteCameraDeviceToJson(struct CameraDevice cameraDevice);

const nlohmann::json updateCameraDeviceToJson(struct CameraDevice cameraDevice);

 