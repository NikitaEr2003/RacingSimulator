#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H
#include "FantasyVehicles.h"

class AirVehicle : public FantasyVehicles
{
protected:

	AirVehicle();

	double DistanceReductionFactor;

public:

	~AirVehicle() override = default;

};
#endif
