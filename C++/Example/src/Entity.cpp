#include "../include/Entity.h"
#include <iostream> 

// Define the static member
int Entity::nextId = 0;

Entity::Entity(const std::string& name)
     : id(nextId++), name(name) {}

// Getter functions (optional if defined in header)
int Entity::getId() const {
    return id;
}

std::string Entity::getName() const {
    return name;
}

// Show entity info
void Entity::showEntity() const {
    std::cout << "Entity ID: " << id
              << ", Name: " << name << std::endl;
}
