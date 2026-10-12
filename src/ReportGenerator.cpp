#include "../include/ReportGenerator.h"
#include <iostream>

using namespace std;

void ReportGenerator::generateActiveReservationsReport(const ReservationManager& manager) const
{
    cout << "\n===== ACTIVE RESERVATIONS REPORT =====" << endl;

    cout << "Total Active Reservations: " << manager.getReservationCount() << endl;

    manager.displayReservationCount();
}

void ReportGenerator::generateResourceUtilizationReport(const ResourceManager& resources, const ReservationManager& manager) const
{
    cout << "\n===== RESOURCE UTILIZATION REPORT ======\n";

    if (resources.getResourceCount() == 0) {
        cout << "No resources available." << endl;
        return;
    }

    for (int i = 0; i < resources.getResourceCount(); i++) {
        Resource resource = resources.getResource(i);
        int count = manager.countForResource(resource.getResourceID());

        cout << "Resource: " << resource.getResourceName()
                << " (ID: " << resource.getResourceID() << ")\n";

        cout << "Active Reservations: " << count << endl;
    }
}

void ReportGenerator::generateMostRequestedResourcesReport(
     const ResourceManager& resources, const ReservationManager& manager) const

{
    cout << "\n===== MOST REQUESTED RESOURCES REPORT ======\n";

    int maxCount = 0;

    for (int i = 0; i < resources.getResourceCount(); i++) {
        Resource resource = resources.getResource(i);
        int count = manager.countForResource(resource.getResourceID());
        if (count > maxCount) {
            maxCount = count;
        }
    }

    if (maxCount == 0) {
        cout << "No active reservation to compare." << endl;
        return;
    }

    cout << "Highest Number of Active Reservations: " << maxCount << endl;

    cout << "Most Requested Resource(s):\n";

    for (int i = 0; i < resources.getResourceCount(); i++) {
        Resource resource = resources.getResource(i);
        int count = manager.countForResource(resource.getResourceID());
        if (count == maxCount) {
            cout << "- " << resource.getResourceName()
                    << " (ID: " << resource.getResourceID() << "), reservations: " << count <<"\n";

        }
    }
}

void ReportGenerator::generateWaitingListReport(const ResourceManager& resources, const WaitingList& waitingList) const
{
    cout << "\n===== WAITING LIST REPORT ======\n";

    int totalWaiting = 0;

    for (int i = 0; i < resources.getResourceCount(); i++) {
        Resource resource = resources.getResource(i);
        int count = waitingList.countForResource(resource.getResourceID());
        totalWaiting += count;

        cout << "Resource: " << resource.getResourceName()
                << " (ID: " << resource.getResourceID() << ")\n";

        cout << "Students waiting: " << count << endl;
    }

    cout << "Total Students waiting for listed resources: " << totalWaiting << endl;

}

void ReportGenerator::generateAllReports(const ResourceManager& resources, const ReservationManager& manager, const WaitingList& waitingList) const
{
    generateActiveReservationsReport(manager);
    generateResourceUtilizationReport(resources, manager);
    generateMostRequestedResourcesReport(resources, manager);
    generateWaitingListReport(resources, waitingList);
}