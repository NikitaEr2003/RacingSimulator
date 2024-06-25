#include "Custom_clear.h"
#include <cstdlib>
#include <iostream>
void Custom_clear()
{
#ifdef _WIN32
    system ("cls");
#else
    system ("clear");
#endif
}
