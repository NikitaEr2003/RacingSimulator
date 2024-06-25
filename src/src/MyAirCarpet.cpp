#include "MyAirCarpet.h"

MyAirCarpet::MyAirCarpet()
{
    m_name = "AirCarpet";

    m_speed = 10;

}

double MyAirCarpet::RoadCalculation(double Distance)
{
    double ResultTime = 0;

 if (Distance == 1000)
 {
     ResultTime = Distance/m_speed;
 }
 else if (Distance < 5000)
 {
     DistanceReductionFactor = 0.03;

     double TempLossDistance = Distance * DistanceReductionFactor;

     Distance = Distance - TempLossDistance;

     ResultTime = Distance/m_speed;

 }
 else if (Distance < 10000)
 {
     DistanceReductionFactor = 0.1;

     double TempLossDistance = Distance * DistanceReductionFactor;

     Distance = Distance - TempLossDistance;

     ResultTime = Distance/m_speed;

 }
 else if (Distance >= 10000)
 {
     DistanceReductionFactor = 0.05;

     double TempLossDistance = Distance * DistanceReductionFactor;

     Distance = Distance - TempLossDistance;

     ResultTime = Distance/m_speed;
 }
    return ResultTime;
}