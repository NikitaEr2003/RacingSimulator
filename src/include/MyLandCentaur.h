#ifndef MYLANDCENTAUR_H
#define MYLANDCENTAUR_H
#include "LandVehicle.h"
class MyLandCentaur : public LandVehicle
{
public:

    MyLandCentaur();

    ~MyLandCentaur() override = default;

    double RoadCalculation(double) override;

};
#endif
