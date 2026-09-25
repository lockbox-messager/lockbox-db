#include <string>
#include "external/httplib.h"

std::string grabRoomID() {
    httplib::Client client("localhost", 3633);

    auto response = client.Get("/room-id");

    if (response && response->status == 200) {
        std::string uuid = response->body;
        return uuid;
    } else {
        std::cerr << "Request failed\n";
    }

    return nullptr;
}

std::string grabUserID() {
    httplib::Client client("localhost", 3633);

    auto response = client.Get("/room-id");

    if (response && response->status == 200) {
        std::string uuid = response->body;
        return uuid;
    } else {
        std::cerr << "Request failed\n";
    }

    return nullptr;
}