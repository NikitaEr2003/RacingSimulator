#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H
#include "FantasyVehicles.h"

class LandVehicle : public FantasyVehicles
{
protected:

     LandVehicle();

     int TimeToRest;

     int Counts;

public:

    ~LandVehicle() override = default;

};
#endif
