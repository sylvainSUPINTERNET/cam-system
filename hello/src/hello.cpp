#include "hello.h"
#include "json.h"
#include <iostream>
#include <fstream>

using json = nlohmann::json;


using namespace std;


// TODO => changer tous les chemin en dur par une variable du cmake build !

/**
 * @brief Return conf
 * 
 * @param filename 
 * @return const json 
 */
const json parseSystemJson(const string & filename) {
    std::ifstream i("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    json systemJson;
    i >> systemJson;
    return systemJson;
}




// TODO => struct en fait sera un object de type CameraDevice dans le cas du hac camera
const json convertCameraDeviceToJson(struct CameraDevice cameraDevice) {
    // TODO faire une boucle intelligente ici pour construire l'objet en fonction des valeur optionel ou non
   json o = json({ {"ip",cameraDevice.ip}, {"angle", cameraDevice.angle} });
   return o;
}

const json addCameraDeviceToJson(struct CameraDevice cameraDevice) {   
    // TODO check if IP already exist before adding 
    // AND ALSO FOR CHANNNEL
    json newCameraDeviceJson = convertCameraDeviceToJson(cameraDevice);
    std::ifstream i("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    json systemJson;
    i >> systemJson;
    systemJson["hacCamera"]["cameras"].push_back(newCameraDeviceJson);
    std::ofstream  file("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    file << systemJson;
    return systemJson;
}

const json deleteCameraDeviceToJson(struct CameraDevice cameraDevice) {
    // TODO add check by channel
    std::ifstream currentJson("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    json systemJson;
    currentJson >> systemJson;

    for (size_t i=0; i < systemJson["hacCamera"]["cameras"].size(); i++) {
        if ( systemJson["hacCamera"]["cameras"][i]["channel"] == cameraDevice.channel ) {
            std::cout << "REMOVE cam at channel " +  cameraDevice.channel << std::endl;
            systemJson["hacCamera"]["cameras"].erase(i);
        }
    }


   std::ofstream  file("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
   file << systemJson;

   return systemJson;

}

const json updateCameraDeviceToJson(struct CameraDevice cameraDevice) {
    std::ifstream currentJson("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    json systemJson;
    currentJson >> systemJson;
    

    for (size_t i=0; i < systemJson["hacCamera"]["cameras"].size(); i++) {
        if ( systemJson["hacCamera"]["cameras"][i]["channel"] == cameraDevice.channel ) {
            std::cout << "UPDATE cam at channel " +  cameraDevice.channel << std::endl;
            // TODO loop pour mettre tous les mettre à jour si ils sont definies
            systemJson["hacCamera"]["cameras"][i]["angle"] = 290;
        }
    }

   std::ofstream  file("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
   file << systemJson;
   return systemJson;

}


// // TODO take camera device in param
// const json addCamera(const string & filename, json::object newCamera) {
//     std::ifstream i("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
//     json systemJson;
//     i >> systemJson;
//     return systemJson
// }

// TODO 
// Implements : 
// - function convertir l'object de type CameraDevice en json::object 
// - function pour ecrire une nouvelle camera 
// - function pour supprimer une camera 

const string generateHelloString(const string & personName) 
{
    // json object = { {"currency", "USD"}, {"value", 42.99} };

    // // For cbv, ça sera /captures/system.json je pense 
    // // Ou voir, je crois que ça vient des parmaètres du executable qu'on passe dans la conf CLion ? du cmake
    // // Sinon c'est chiant
    // std::ifstream i("C:\\Workspace\\personnal\\vscode-cmake-hello\\captures\\system.json");
    // json systemJson;
    // i >> systemJson;

    // std::cout << systemJson["hacCamera"]["cameras"][0]["ip"] << std::endl;
    
    // auto test = object["value"];

    // std::cout << test << std::endl;
    

    return "Hello ";
}
