#ifndef MENU_H
#define MENU_H
#include "MyAirbroom.h"
#include "MyAirCarpet.h"
#include "MyAirEagle.h"
#include "MyLandCentaur.h"
#include "MyLandCamel.h"
#include "MyLandAllTerrainBoots.h"
#include "MyLandFastCamel.h"
#include "Custom_clear.h"
#include "Custom_sleep.h"
#include "iostream"
#include "limits"
#define size_Land_Vehicle_array 4
#define size_Air_Vehicle 3

class Menu
{
public:

    Menu() =default;

    ~Menu() = default;

    enum TypeOfVehicles
    {
        Land = 1, Air,
    };

    void menu() const;

    double Check_m_Distance() const;

    void LandMenu() const;

    void AirMenu() const;

    void Land_And_Air_Menu() const;

};
#endif
