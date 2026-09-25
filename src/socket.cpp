#include <iostream>
#include "external/httplib.h"
#include "rooms.hpp"
#include "users.hpp"

int socket_main() {
    httplib::Server server;

    // PingPong
    server.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(
            "pong",
            "text/plain"
        );
    });

    // New Room
    server.Get("/newroom", [](const httplib::Request&,
                          httplib::Response& res) {

        auto roomid = newRoom();

        res.set_content(
            roomid,
            "text/plain"
        );
    });

    // New Log-on
    server.Post("/newuser", [](const httplib::Request& req,
                          httplib::Response& res) {

        auto uid = newUser(req.body);

        res.set_content(
            uid,
            "text/plain"
        );
    });

    std::cout << "Database server listening on port 3632...\n";

    // Listen on all local interfaces, port 3632
    if (!server.listen("0.0.0.0", 3632)) {
        std::cerr << "Failed to start server\n";
        return 1;
    }

    return 0;
}
