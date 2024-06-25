#ifndef MYLANDFASTCAMEL_H
#define MYLANDFASTCAMEL_H
#include "LandVehicle.h"
class MyLandFastCamel : public LandVehicle
{
public:

    MyLandFastCamel();

    ~MyLandFastCamel() override = default;

    double RoadCalculation(double) override;

};
#endif
