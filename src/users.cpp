#include <string>
#include <vector>
#include "users.hpp"

std::vector<User> Users;

std::string newUser(std::string name) {
    std::string uid;
    Users.emplace_back(name, uid);
    return uid;
}