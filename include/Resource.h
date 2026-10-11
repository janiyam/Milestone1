#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
private:
    std::string resourceID;
    std::string resourceName;
    std::string resourceType;
    std::string availabilityStatus;

public:
    Resource();

    Resource(const std::string& id,
             const std::string& name,
             const std::string& type,
             const std::string& status);

    std::string getResourceID() const;
    std::string getResourceName() const;
    std::string getResourceType() const;
    std::string getAvailabilityStatus() const;

    void setAvailabilityStatus(const std::string& status);
    void display() const;
};

class ResourceManager {
private:
    static const int MAX_RESOURCES = 100;

    Resource resources[MAX_RESOURCES];
    int resourceCount;

    void mergeSort(int left, int right);
    void merge(int left, int middle, int right);

public:
    ResourceManager();

    bool loadResources(const std::string& fileName);
    void displayResources() const;

    bool resourceExists(const std::string& resourceID) const;
    int findResourceIndex(const std::string& resourceID) const;

    int getResourceCount() const;
    Resource getResource(int index) const;

    bool setResourceStatus(const std::string& resourceID,
                           const std::string& status);

    void sortResourcesByName();
};

#endif
