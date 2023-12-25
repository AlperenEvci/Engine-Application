#pragma once
#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @file Valve.h
 * @brief Definition of the Valve class.
 */

 /**
  * @class Valve
  * @brief Represents a valve device.
  * @details This class inherits virtually from Device and includes functionalities related to valves.
  */
class Valve:virtual public Device
{
public:
	bool is_valve_open; /**< Indicates whether the valve is open. */

	/**
	 * @brief Virtual function to print information about the valve.
	 * @return A string containing information about the valve.
	 */
	string printInfo();
}; 

