#pragma once

#include <string>
#include <vector>
#include "crypto.hpp"
#include "users.hpp"

class Room {
    public:
        std::vector<User*> connectedUsers;
        
        Room(std::string& id) {
            uuid = grabRoomID();
            id = uuid;
        }

        std::string uuid;

        void addUser(User user) {
            connectedUsers.push_back(&user);
            user.connection = this;
        }
};

extern std::vector<Room> rooms;

std::string newRoom();