#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
private: 
    const int id;               // unique id for each entity
    const std::string name;     // entity name
    static int nextId;          // used to generate unique ids

public:
    // Constructor: must initialize all const members
    Entity(const std::string& name);

    // Getters (const because they don't modify the object)
    int getId() const;
    std::string getName() const;

    // Display entity info
    void showEntity() const;
};

#endif // ENTITY_H
