#include "FantasyVehicles.h"

FantasyVehicles::FantasyVehicles() : m_name("null"), m_speed(0){}

std::string FantasyVehicles::GetName()
{
    return this->m_name;
}
