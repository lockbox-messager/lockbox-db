#include <vector>
#include <string>
#include "rooms.hpp"

std::vector<Room> Rooms;

std::string newRoom() {
    std::string roomid;
    Rooms.emplace_back(roomid);
    return roomid;
}