#pragma once
#include <iostream>

/**
 * @file Device.h
 * @brief Definition of the Device class.
 */

 /**
  * @class Device
  * @brief Represents a generic device.
  * @details This is an abstract class providing a method to print device information.
  */
class Device
{
public:
    /**
     * @brief Virtual function to print information about the device.
     * @return A string containing information about the device.
     */
	virtual std::string printInfo();
};

