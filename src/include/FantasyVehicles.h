
#ifndef FANTASYVEHICLES_H
#define FANTASYVEHICLES_H
#include "string"

class FantasyVehicles
{
 protected:

 FantasyVehicles();

 std::string m_name;

 int m_speed;

 public:

 virtual ~FantasyVehicles() = default;

 virtual double RoadCalculation(double) = 0;

 std::string GetName();

};
#endif
