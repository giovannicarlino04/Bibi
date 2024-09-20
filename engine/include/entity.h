#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>  // <-- Add this line to include std::remove
#include <typeinfo>

// Base class for all components
class Component {
public:
    virtual ~Component() {}
};

// Entity class
class Entity {
public:
    Entity(int id) : id(id) {}

    template <typename T>
    void addComponent(T* component) {
        components[typeid(T).name()] = component;
    }

    template <typename T>
    T* getComponent() {
        return static_cast<T*>(components[typeid(T).name()]);
    }

    int getId() const { return id; }

private:
    int id;
    std::unordered_map<std::string, Component*> components;
};

// EntityManager class to manage all entities
class EntityManager {
public:
    Entity* createEntity() {
        Entity* entity = new Entity(nextId++);
        entities.push_back(entity);
        return entity;
    }
    
    void destroyEntity(Entity* entity) {
        // Use std::remove and std::vector::erase to remove the entity
        auto it = std::remove(entities.begin(), entities.end(), entity);
        if (it != entities.end()) {
            entities.erase(it, entities.end());
        }
        delete entity;
    }

    std::vector<Entity*>& getEntities() {
        return entities;
    }

private:
    std::vector<Entity*> entities;
    int nextId = 0;
};

#endif
