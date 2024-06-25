#include "MyLandCentaur.h"
MyLandCentaur::MyLandCentaur()
{
    m_name = "Centaur";

    m_speed = 15;

    TimeToRest = 8;

}

double MyLandCentaur::RoadCalculation(double Distance)
{
    double DistanceInTime = Distance/m_speed;

    int CountOfChill = static_cast<int>(DistanceInTime)/TimeToRest;

    double ResultTime = DistanceInTime;

    for (int i = 0; i < CountOfChill; i++)
    {
      ResultTime += 2;
    }
    return ResultTime;
}
