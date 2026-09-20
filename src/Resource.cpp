#include "../include/Resource.h"
#include <iostream>
#include <fstream>

Resource::Resource()
{
    resourceID = "";
    resourceName = "";
    location = "";
    capacity = 0;
}

Resource::Resource(std::string id,
                   std::string name,
                   std::string loc,
                   int cap)
{
    resourceID = id;
    resourceName = name;
    location = loc;
    capacity = cap;
}

std::string Resource::getResourceID() const
{
    return resourceID;
}

std::string Resource::getResourceName() const
{
    return resourceName;
}

std::string Resource::getLocation() const
{
    return location;
}

int Resource::getCapacity() const
{
    return capacity;
}

void Resource::display() const
{
    std::cout << "Resource ID: " << resourceID << std::endl;
    std::cout << "Resource Name: " << resourceName << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << std::endl;
}

ResourceManager::ResourceManager()
{
    resourceCount = 0;
}

bool ResourceManager::loadResources(std::string fileName)
{
    std::ifstream inputFile(fileName);

    if (!inputFile)
    {
        std::cout << "Could not open resource file." << std::endl;
        return false;
    }

    resourceCount = 0;

    std::string id;
    std::string name;
    std::string location;
    std::string capacityText;

    while (std::getline(inputFile, id, '|') &&
           std::getline(inputFile, name, '|') &&
           std::getline(inputFile, location, '|') &&
           std::getline(inputFile, capacityText))
    {
        if (resourceCount < MAX_RESOURCES)
        {
            int capacity = std::stoi(capacityText);

            resources[resourceCount] =
                Resource(id, name, location, capacity);

            resourceCount++;
        }
    }

    inputFile.close();

    return true;
}

void ResourceManager::displayResources() const
{
    if (resourceCount == 0)
    {
        std::cout << "No resources found." << std::endl;
        return;
    }

    for (int i = 0; i < resourceCount; i++)
    {
        resources[i].display();
    }
}

bool ResourceManager::resourceExists(std::string id) const
{
    for (int i = 0; i < resourceCount; i++)
    {
        if (resources[i].getResourceID() == id)
        {
            return true;
        }
    }

    return false;
}

int ResourceManager::getResourceCount() const
{
    return resourceCount;
}

Resource ResourceManager::getResource(int index) const
{
    return resources[index];
}
