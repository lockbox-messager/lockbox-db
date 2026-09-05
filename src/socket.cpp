#include <iostream>
#include "httplib.h"

int socket_main() {
    httplib::Server 
server;

    // Test endpoint
    server.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(
            R"({"success":true,"message":"pong"})",
            "application/json"
        );
    });

    // Example database command
    server.Get("/get", [](const httplib::Request& req,
                          httplib::Response& res) {

        if (!req.has_param("key")) {
            res.status = 400;
            res.set_content(
                R"({"success":false,"error":"Missing key"})",
                "application/json"
            );
            return;
        }

        std::string key = req.get_param_value("key");

        // TODO: Call your database here
        //
        // auto value = database.get(key);

        std::cout << "GET: " << key << '\n';

        res.set_content(
            R"({"success":true})",
            "application/json"
        );
    });

    // Example POST command
    server.Post("/insert", [](const httplib::Request& req,
                              httplib::Response& res) {

        std::cout << "INSERT request received\n";
        std::cout << req.body << '\n';

        // TODO:
        // Parse req.body as JSON
        // Call your database's insert function

        res.set_content(
            R"({"success":true})",
            "application/json"
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
