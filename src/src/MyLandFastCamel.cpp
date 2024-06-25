#include "MyLandFastCamel.h"
MyLandFastCamel::MyLandFastCamel()
{
    m_name = "FastCamel";

    m_speed = 40;

    TimeToRest = 10;

}

double MyLandFastCamel::RoadCalculation(double Distance)
{
    double DistanceInTime = Distance/m_speed;

    int CountOfChill = static_cast<int>(DistanceInTime)/TimeToRest;

    double ResultTime = DistanceInTime;

    for (int i = 0; i < CountOfChill; i++)
    {
        if(i == 0) {
            ResultTime +=5;
        }
        else if (i == 1)
        {
            ResultTime +=6.5;
        }
        else
        {
            ResultTime += 8;
        }
    }
    return ResultTime;
}
