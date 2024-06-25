#include "Menu.h"

void Menu::LandMenu() const
{
    Custom_clear();
    double m_Distance = this->Check_m_Distance();
    
    LandVehicle* ptrArray[size_Land_Vehicle_array];

    for (int i = 0; i < size_Land_Vehicle_array; i++)
    {
        ptrArray[i] = nullptr;
    }

    int m_number;

    std::string registered = "null";

    std::string nicknames = "null";

    std::string Attemp;

    std::string str_array[4];

    for (int i = 0; i < size_Land_Vehicle_array; i++)
    {
        str_array[i] = "0";
    }

    TypeOfVehicles Type_id = Land;

    bool Wrong = false;

    bool RaceAgain = false;

    int CountOfnicknames = 0;

    while (true)
    {
        Custom_clear();
        Wrong = false;

        if ((registered != "null") && (Wrong == false) && (Type_id != Air))
        {
            std::cout << registered << "\n";
        }
        else
        {
            std::cout << Attemp;
        }

        std::cout << "Land race. ";

        std::cout << "Distance: " << m_Distance << "\n";

        if (nicknames != "null")
        {
            std::cout << "Registered vehicles: " << nicknames << "\n";
        }

        std::cout << "AllTerrainBoots -> (1)\n";
        std::cout << "Broom -> (2)\n";
        std::cout << "Camel -> (3)\n";
        std::cout << "Centaur -> (4)\n";
        std::cout << "Eagle -> (5)\n";
        std::cout << "FastCamel -> (6)\n";
        std::cout << "Carpet plane -> (7)\n";
        std::cout << "Exit -> (0)\n";
        std::cout << "Select transport or 0 to complete the registration process: ";

        std::cin >> m_number;

        if (m_number < 0 || m_number > 7 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (m_number == 1)
        {
            if (str_array[1] != "AllTerrainBoots")
            {
                str_array[1] = "AllTerrainBoots";

                registered = "AllTerrainBoots registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", AllTerrainBoots";
                }
                else 
                {
                    nicknames = "AllTerrainBoots";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "AllTerrainBoots is already registered";
            }

            Type_id = Land;

        }
        else if (m_number == 3)
        {
            if (str_array[0] != "Camel")
            {
                str_array[0] = "Camel";

                registered = "Camel registered";

                if (CountOfnicknames >= 1)
                {
                   
                    nicknames += ", Camel";
                }
                else
                {
                    nicknames = "Camel";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Camel is already registered";
            }

            Type_id = Land;

        }
        else if (m_number == 4)
        {
            if (str_array[3] != "Centaur")
            {
                str_array[3] = "Centaur";

                registered = "Centaur registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", Centaur";
                }
                else
                {
                    nicknames = "Centaur";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Centaur is already registered";
            }

            Type_id = Land;

        }
        else if (m_number == 6)
        {
            if (str_array[2] != "FastCamel")
            {
                str_array[2] = "FastCamel";

                registered = "FastCamel registered";

                if (CountOfnicknames >= 1) 
                {
                    nicknames += ", FastCamel";

                } 
                else
                {
                    nicknames = "FastCamel";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "FastCamel is already registered";
            }

            Type_id = Land;

        }
        else if (m_number == 0)
        {
            if (CountOfnicknames < 2)
            {
                std::cout << "At least 2 vehicles are needed\n";
                Custom_sleep();
            }
            else
            {
                bool exit = false;

                while (true)
                {
                    std::cout << "Register transport -> (1)\n";
                    std::cout << "Start the race -> (2)\n";
                    int number_m;

                    std::cin >> number_m;

                    if (number_m < 1 || number_m > 2 || std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } 
                    else if (number_m == 1)
                    {
                        registered = "null";
                        break;
                    } 
                    else if (number_m == 2)
                    {
                        Custom_clear();
                        std::cout << "Race results: \n";

                        int Counter = 1;

                        for (int i = 0; i < size_Land_Vehicle_array; i++)
                        {
                            if (str_array[i] != "0")
                            {
                                if (str_array[i] == "Centaur")
                                {
                                    ptrArray[i] = new MyLandCentaur;
                                } 
                                else if (str_array[i] == "Camel")
                                {
                                    ptrArray[i] = new MyLandCamel;
                                }
                                else if (str_array[i] == "FastCamel")
                                {
                                    ptrArray[i] = new MyLandFastCamel;
                                } 
                                else if (str_array[i] == "AllTerrainBoots")
                                {
                                    ptrArray[i] = new MyLandAllTerrainBoots;
                                }
                            }
                        }
                        for (int i = 0; i < size_Land_Vehicle_array - 1; i++)
                        {
                            for (int j = 0; j < size_Land_Vehicle_array - i - 1; j++)
                            {
                                if (ptrArray[j] == nullptr) {
                                    continue;
                                }

                                if (ptrArray[j + 1] == nullptr) {
                                    std::swap(ptrArray[j], ptrArray[j + 1]);
                                    continue;
                                }

                                double m_first = ptrArray[j]->RoadCalculation(m_Distance);

                                double m_second = ptrArray[j + 1]->RoadCalculation(m_Distance);

                                if (m_first > m_second)
                                {
                                    std::swap(ptrArray[j], ptrArray[j + 1]);
                                }
                            }
                        }
                        int Counter_m = 1;

                        for (int i = 0; i < size_Land_Vehicle_array; i++)
                        {
                            if (ptrArray[i] != nullptr)
                            {
                                double result = ptrArray[i]->RoadCalculation(m_Distance);

                                std::cout << Counter_m++ << ". " << ptrArray[i]->GetName() << " time: " << result << "h" << std::endl;
                            }
                        }
                        int m_num;

                        std::cout << "Hold another race? -> (1)\n";
                        std::cout << "Exit -> (2)\n";

                        std::cin >> m_num;

                        if (m_num == 1)
                        {
                            RaceAgain = true;
                        }
                        else 
                        {
                            std::cout << "Program off\n";
                            return;
                        }
                        break;
                    }
                }
              
            }
        }
        else
        {
            Wrong = true;
            Attemp = "Attempt to register the wrong type of vehicle\n";
            Type_id = Air;
        }

        if (RaceAgain) 
        {
            break;
        }
    }
    for (int i = 0; i < size_Land_Vehicle_array; i++)
    {
        delete ptrArray[i];
        ptrArray[i] = nullptr;
    }
    Custom_clear();
    this->menu();
}

void Menu::AirMenu() const 
{
    Custom_clear();

    double m_Distance = this->Check_m_Distance();

    AirVehicle* ptrArray[size_Air_Vehicle];

    for (int i = 0; i < size_Air_Vehicle; i++)
    {
        ptrArray[i] = nullptr;
    }

    int m_number;

    std::string registered = "null";

    std::string nicknames = "null";

    std::string Attemp;

    std::string str_array[3];

    for (int i = 0; i < size_Air_Vehicle; i++)
    {
        str_array[i] = "0";
    }

    TypeOfVehicles Type_id = Air;

    bool Wrong = false;

    bool RaceAgain = false;

    int CountOfnicknames = 0;

    while (true)
    {
        Custom_clear();
        Wrong = false;

        if ((registered != "null") && (Wrong == false) && (Type_id != Land))
        {
            std::cout << registered << "\n";
        }
        else
        {
            std::cout << Attemp;
        }

        std::cout << "Air race. ";

        std::cout << "Distance: " << m_Distance << "\n";

        if (nicknames != "null")
        {
            std::cout << "Registered vehicles: " << nicknames << "\n";
        }

        std::cout << "AllTerrainBoots -> (1)\n";
        std::cout << "Broom -> (2)\n";
        std::cout << "Camel -> (3)\n";
        std::cout << "Centaur -> (4)\n";
        std::cout << "Eagle -> (5)\n";
        std::cout << "FastCamel -> (6)\n";
        std::cout << "Carpet plane -> (7)\n";
        std::cout << "Exit -> (0)\n";
        std::cout << "Select transport or 0 to complete the registration process: ";

        std::cin >> m_number;

        if (m_number < 0 || m_number > 7 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (m_number == 2)
        {
            if (str_array[1] != "Broom")
            {
                str_array[1] = "Broom";

                registered = "Broom registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", Broom";
                }
                else
                {
                    nicknames = "Broom";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Broom is already registered";
            }

            Type_id = Air;

        }
        else if (m_number == 5)
        {
            if (str_array[0] != "Eagle")
            {
                str_array[0] = "Eagle";

                registered = "Eagle registered";

                if (CountOfnicknames >= 1)
                {

                    nicknames += ", Eagle";
                }
                else
                {
                    nicknames = "Eagle";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Eagle is already registered";
            }

            Type_id = Air;

        }
        else if (m_number == 7)
        {
            if (str_array[2] != "Carpet plane")
            {
                str_array[2] = "Carpet plane";

                registered = "Carpet plane registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", Carpet plane";
                }
                else
                {
                    nicknames = "Carpet plane";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Carpet plane is already registered";
            }

            Type_id = Land;

        }
        else if (m_number == 0)
        {
            if (CountOfnicknames < 2)
            {
                std::cout << "At least 2 vehicles are needed\n";
                Custom_sleep();
            }
            else
            {
                bool exit = false;

                while (true)
                {
                    std::cout << "Register transport -> (1)\n";
                    std::cout << "Start the race -> (2)\n";
                    int number_m;

                    std::cin >> number_m;

                    if (number_m < 1 || number_m > 2 || std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (number_m == 1)
                    {
                        registered = "null";
                        break;
                    }
                    else if (number_m == 2)
                    {
                        Custom_clear();
                        std::cout << "Race results: \n";

                        int Counter = 1;

                        for (int i = 0; i < size_Air_Vehicle; i++)
                        {
                            if (str_array[i] != "0")
                            {
                                if (str_array[i] == "Broom")
                                {
                                    ptrArray[i] = new MyAirBroom;
                                }
                                else if (str_array[i] == "Carpet plane")
                                {
                                    ptrArray[i] = new MyAirCarpet;
                                }
                                else if (str_array[i] == "Eagle")
                                {
                                    ptrArray[i] = new MyAirEagle;
                                }
                               
                            }
                        }
                        for (int i = 0; i < size_Air_Vehicle - 1; i++)
                        {
                            for (int j = 0; j < size_Air_Vehicle - i - 1; j++)
                            {
                                if (ptrArray[j] == nullptr) {
                                    continue;
                                }

                                if (ptrArray[j + 1] == nullptr) {
                                    std::swap(ptrArray[j], ptrArray[j + 1]);
                                    continue;
                                }

                                double m_first = ptrArray[j]->RoadCalculation(m_Distance);

                                double m_second = ptrArray[j + 1]->RoadCalculation(m_Distance);

                                if (m_first > m_second)
                                {
                                    std::swap(ptrArray[j], ptrArray[j + 1]);
                                }
                            }
                        }
                        int Counter_m = 1;

                        for (int i = 0; i < size_Air_Vehicle; i++)
                        {
                            if (ptrArray[i] != nullptr)
                            {
                                double result = ptrArray[i]->RoadCalculation(m_Distance);

                                std::cout << Counter_m++ << ". " << ptrArray[i]->GetName() << " time: " << result << "h" << std::endl;
                            }
                        }
                        int m_num;

                        std::cout << "Hold another race? -> (1)\n";
                        std::cout << "Exit -> (2)\n";

                        std::cin >> m_num;

                        if (m_num == 1)
                        {
                            RaceAgain = true;
                        }
                        else
                        {
                            std::cout << "Program off\n";
                            return;
                        }
                        break;
                    }
                }

            }
        }
        else
        {
            Wrong = true;
            Attemp = "Attempt to register the wrong type of vehicle\n";
            Type_id = Land;
        }

        if (RaceAgain)
        {
            break;
        }
    }
    for (int i = 0; i < size_Air_Vehicle; i++)
    {
        delete ptrArray[i];
        ptrArray[i] = nullptr;
    }
    Custom_clear();
    this->menu();


}


void Menu::Land_And_Air_Menu() const
{
    Custom_clear();

    double m_Distance = this->Check_m_Distance();
    
    const int Count_array = size_Air_Vehicle + size_Land_Vehicle_array;

    FantasyVehicles* ptrArray[Count_array];

    for (int i = 0; i < Count_array; i++)
    {
        ptrArray[i] = nullptr;
    }

    int m_number;

    std::string registered = "null";

    std::string nicknames = "null";

    std::string Attemp;

    std::string str_array[Count_array];

    for (int i = 0; i < Count_array; i++)
    {
        str_array[i] = "0";
    }


    bool Wrong = false;

    bool RaceAgain = false;

    int CountOfnicknames = 0;

    while (true)
    {
        Custom_clear();

        Wrong = false;

        if ((registered != "null") && (Wrong == false))
        {
            std::cout << registered << "\n";
        }
        else
        {
            std::cout << Attemp;
        }

        std::cout << "Land and Air race. ";

        std::cout << "Distance: " << m_Distance << "\n";

        if (nicknames != "null")
        {
            std::cout << "Registered vehicles: " << nicknames << "\n";
        }

        std::cout << "AllTerrainBoots -> (1)\n";
        std::cout << "Broom -> (2)\n";
        std::cout << "Camel -> (3)\n";
        std::cout << "Centaur -> (4)\n";
        std::cout << "Eagle -> (5)\n";
        std::cout << "FastCamel -> (6)\n";
        std::cout << "Carpet plane -> (7)\n";
        std::cout << "Exit -> (0)\n";
        std::cout << "Select transport or 0 to complete the registration process: ";

        std::cin >> m_number;

        if (m_number < 0 || m_number > 7 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (m_number == 1)
        {
            if (str_array[0] != "AllTerrainBoots")
            {
                str_array[0] = "AllTerrainBoots";

                registered = "AllTerrainBoots registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", AllTerrainBoots";
                }
                else 
                {
                    nicknames = "AllTerrainBoots";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "AllTerrainBoots is already registered";
            }


        }
        else if (m_number == 2)
        {
            if (str_array[1] != "Broom")
            {
                str_array[1] = "Broom";

                registered = "Broom registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", Broom";
                }
                else
                {
                    nicknames = "Broom";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Broom is already registered";
            }

        }
        else if (m_number == 3)
        {
            if (str_array[2] != "Camel")
            {
                str_array[2] = "Camel";

                registered = "Camel registered";

                if (CountOfnicknames >= 1)
                {
                   
                    nicknames += ", Camel";
                }
                else
                {
                    nicknames = "Camel";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Camel is already registered";
            }


        }
        else if (m_number == 4)
        {
            if (str_array[3] != "Centaur")
            {
                str_array[3] = "Centaur";

                registered = "Centaur registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", Centaur";
                }
                else
                {
                    nicknames = "Centaur";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Centaur is already registered";
            }


        }
        else if (m_number == 5)
        {
            if (str_array[4] != "Eagle")
            {
                str_array[4] = "Eagle";

                registered = "Eagle registered";

                if (CountOfnicknames >= 1)
                {

                    nicknames += ", Eagle";
                }
                else
                {
                    nicknames = "Eagle";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Eagle is already registered";
            }


            }
        else if (m_number == 6)
        {
            if (str_array[5] != "FastCamel")
            {
                str_array[5] = "FastCamel";

                registered = "FastCamel registered";

                if (CountOfnicknames >= 1) 
                {
                    nicknames += ", FastCamel";

                } 
                else
                {
                    nicknames = "FastCamel";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "FastCamel is already registered";
            }

        }
        else if (m_number == 7)
        {
            if (str_array[6] != "Carpet plane")
            {
                str_array[6] = "Carpet plane";

                registered = "Carpet plane registered";

                if (CountOfnicknames >= 1)
                {
                    nicknames += ", Carpet plane";
                }
                else
                {
                    nicknames = "Carpet plane";
                }

                CountOfnicknames++;

            }
            else
            {
                registered = "Carpet plane is already registered";
            }

            }
        else if (m_number == 0)
        {
            if (CountOfnicknames < 2)
            {
                std::cout << "At least 2 vehicles are needed\n";
                Custom_sleep();
            }
            else
            {
                bool exit = false;

                while (true)
                {
                    std::cout << "Register transport -> (1)\n";
                    std::cout << "Start the race -> (2)\n";
                    int number_m;

                    std::cin >> number_m;

                    if (number_m < 1 || number_m > 2 || std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } 
                    else if (number_m == 1)
                    {
                        registered = "null";
                        break;
                    } 
                    else if (number_m == 2)
                    {
                        Custom_clear();
                        std::cout << "Race results: \n";

                        int Counter = 1;

                        for (int i = 0; i < Count_array; i++)
                        {
                            if (str_array[i] != "0")
                            {
                                if (str_array[i] == "Centaur")
                                {
                                    ptrArray[i] = new MyLandCentaur;
                                } 
                                else if (str_array[i] == "Camel")
                                {
                                    ptrArray[i] = new MyLandCamel;
                                }
                                else if (str_array[i] == "FastCamel")
                                {
                                    ptrArray[i] = new MyLandFastCamel;
                                } 
                                else if (str_array[i] == "AllTerrainBoots")
                                {
                                    ptrArray[i] = new MyLandAllTerrainBoots;
                                } 
                                else if (str_array[i] == "Broom")
                                {
                                    ptrArray[i] = new MyAirBroom;
                                }
                                else if (str_array[i] == "Carpet plane")
                                {
                                    ptrArray[i] = new MyAirCarpet;
                                }
                                else if (str_array[i] == "Eagle")
                                {
                                    ptrArray[i] = new MyAirEagle;
                                }
                            }
                        }
                        for (int i = 0; i < Count_array - 1; i++)
                        {
                            for (int j = 0; j < Count_array - i - 1; j++)
                            {
                                if (ptrArray[j] == nullptr) {
                                    continue;
                                }

                                if (ptrArray[j + 1] == nullptr) {
                                    std::swap(ptrArray[j], ptrArray[j + 1]);
                                    continue;
                                }

                                double m_first = ptrArray[j]->RoadCalculation(m_Distance);

                                double m_second = ptrArray[j + 1]->RoadCalculation(m_Distance);

                                if (m_first > m_second)
                                {
                                    std::swap(ptrArray[j], ptrArray[j + 1]);
                                }
                            }
                        }
                        int Counter_m = 1;

                        for (int i = 0; i < Count_array; i++)
                        {
                            if (ptrArray[i] != nullptr)
                            {
                                double result = ptrArray[i]->RoadCalculation(m_Distance);

                                std::cout << Counter_m++ << ". " << ptrArray[i]->GetName() << " time: " << result << "h" << std::endl;
                            }
                        }
                        int m_num;

                        std::cout << "Hold another race? -> (1)\n";
                        std::cout << "Exit -> (2)\n";

                        std::cin >> m_num;

                        if (m_num == 1)
                        {
                            RaceAgain = true;
                        }
                        else 
                        {
                            std::cout << "Program off\n";
                            return;
                        }
                        break;
                    }
                }
              
            }
        }
     
        if (RaceAgain) 
        {
            break;
        }
    }
    for (int i = 0; i < Count_array; i++)
    {
        delete ptrArray[i];
        ptrArray[i] = nullptr;
    }
    Custom_clear();
    this->menu();


}

double Menu::Check_m_Distance() const
{
    double m_Distance;

    while (true)
    {
        std::cout << "Specify the distance, it must be positive: ";

        std::cin >> m_Distance;

        if (m_Distance <= 0 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    return m_Distance;
}

void Menu::menu() const {
    int  num;
    while(true) {
        Custom_clear();
        std::cout << "\tWelcome to the racing simulator\n";
        std::cout << "Land transport race -> (1)\n";
        std::cout << "Air transport race -> (2)\n";
        std::cout << "Race for land and air transport -> (3)\n";
        std::cout << "Select race type: ";

        std::cin >> num;
        if (num < 1 || num > 3)
        {
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }else
        {
            break;
        }
    }
    if (num == 1)
    {
    LandMenu();
    }else if ( num == 2)
    {
    AirMenu();
    }else if (num == 3)
    {
        Land_And_Air_Menu();
    }


}
