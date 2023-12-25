#include "Valve.h"

/*!
 * \brief Prints information about the valve status.
 * \return A string containing the valve status information.
 */	
string Valve::printInfo()
{
	string fb = "Valve Status : " + to_string(is_valve_open);
	return fb;
}
