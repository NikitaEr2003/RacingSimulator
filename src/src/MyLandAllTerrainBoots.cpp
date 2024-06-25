#include "MyLandAllTerrainBoots.h"
MyLandAllTerrainBoots::MyLandAllTerrainBoots()
{
    m_name = "AllTerrainBoots";

    m_speed = 6;

    TimeToRest = 60;

}

double MyLandAllTerrainBoots::RoadCalculation(double Distance)
{
    double DistanceInTime = Distance/m_speed;

    int CountOfChill = static_cast<int>(DistanceInTime)/TimeToRest;

    double ResultTime = DistanceInTime;

    for (int i =0; i < CountOfChill; i++)
    {
        if (i == 0)
        {
          ResultTime += 10;
        }else
        {
            ResultTime += 5;
        }
    }
    return ResultTime;
}
