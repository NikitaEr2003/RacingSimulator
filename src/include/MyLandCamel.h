#ifndef MYLANDCAMEL_H
#define MYLANDCAMEL_H
#include "LandVehicle.h"
class MyLandCamel : public LandVehicle
{
public:

     MyLandCamel();

    ~MyLandCamel() override = default;

    double RoadCalculation(double) override;

};
#endif
