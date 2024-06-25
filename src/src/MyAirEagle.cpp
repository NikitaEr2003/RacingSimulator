#include "MyAirEagle.h"

MyAirEagle::MyAirEagle()
{
    m_name = "Eagle";

    m_speed = 8;

}

double MyAirEagle::RoadCalculation(double Distance)
{
    double ResultTime = 0;

    DistanceReductionFactor = 0.06;

    double TempLossDistance = Distance * DistanceReductionFactor;

    Distance = Distance - TempLossDistance;

    ResultTime = Distance/m_speed;

    return ResultTime;
}
