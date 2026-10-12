#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Resource.h"
#include "ReservationManager.h"
#include "WaitingList.h"

class ReportGenerator {
public:
    void generateActiveReservationsReport(const ReservationManager& manager) const;

    void generateResourceUtilizationReport(const ResourceManager& resources, const ReservationManager& manager) const;

    void generateWaitingListReport(const ResourceManager& resources, const WaitingList& waitingList) const;

    void generateAllReports(const ResourceManager& resources, const ReservationManager& manager, const WaitingList& waitingList) const;
};