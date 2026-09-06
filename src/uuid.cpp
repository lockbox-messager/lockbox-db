#include <string>
#include "external/httplib.h"

std::string grabUUID() {
    httplib::Client client("localhost", 3633);

    auto response = client.Get("/uuid");

    if (response && response->status == 200) {
        std::string uuid = response->body;
        return uuid;
    } else {
        std::cerr << "Request failed\n";
    }
}