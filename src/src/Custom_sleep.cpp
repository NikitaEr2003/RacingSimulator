#include "Custom_sleep.h"
#ifdef _WIN32

void Custom_sleep()
{
	Sleep(1000);
}

#else
void Custom_sleep()
{
	sleep(2);
}
#endif