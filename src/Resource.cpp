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
void ResourceManager::sortResourcesByName()
{
    if (resourceCount > 1)
    {
        mergeSort(0, resourceCount - 1);
    }
}
void ResourceManager::mergeSort(int left, int right)
{
    if (left < right)
    {
       int mid = left + (right - left) / 2:

       mergeSort(left, mid);
       mergeSort(mid + 1, right);

       merge(left, mid, right);
    }
}

void ResourceManager::merge(int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Resource* leftArray = new Resource[leftSize];
    Resource* rightArray = new Resource[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = resources[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = resources[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i].getResourceName() <=
            rightArray[j].getResourceName())
        {
            resources[k] + leftArray[i];
            i++;
        }
        else
        {
            resources[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < leftSize)
    {
        resources[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        resources[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}
