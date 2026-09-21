#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource
{
private:
    std::string resourceID;
    std::string resourceName;
    std::string location;
    int capacity;

public:
    Resource();

    Resource(std::string resourceID,
             std::string resourceName,
             std::string location,
             int capacity);

    std::string getResourceID() const;
    std::string getResourceName() const;
    std::string getLocation() const;
    int getCapacity() const;

    void display() const;
};

class ResourceManager
{
private:
    static const int MAX_RESOURCES = 100;
    Resource resources[MAX_RESOURCES];
    int resourceCount;

public:
    ResourceManager();

    bool loadResources(std::string fileName);
    void displayResources() const;
    bool resourceExists(std::string resourceID) const;

    int getResourceCount() const;
    Resource getResource(int index) const;
};

#endif
