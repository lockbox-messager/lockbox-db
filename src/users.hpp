#pragma once

#include <string>
#include "crypto.hpp"

class Room;

class User {
    public:
        std::string name;
        std::string uuid;
        Room* connection;

        User(std::string _name, std::string& uid) {
            uuid = grabUserID();
            name = _name;
            uid = uuid;
        };
};

std::string newUser(std::string name);