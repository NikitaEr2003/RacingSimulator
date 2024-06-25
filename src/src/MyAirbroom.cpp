#include "MyAirbroom.h"

MyAirBroom::MyAirBroom()
{
    m_name = "Broom";

    m_speed = 20;

}

double MyAirBroom::RoadCalculation(double Distance)
{
    double ResultTime = 0;

    DistanceReductionFactor = 0.09;

    if (DistanceReductionFactor != 0)
    {
        DistanceReductionFactor /= 100;
        double TempLossDistance = Distance * DistanceReductionFactor;

        Distance = Distance - TempLossDistance;
    }

    ResultTime = Distance/m_speed;

    return ResultTime;
}
