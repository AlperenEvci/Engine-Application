#pragma once
#include "Valve.h"
#include "Device.h"

/**
 * @file FuelTank.h
 * @brief Definition of the FuelTank class.
 */

 /**
  * @class FuelTank
  * @brief Represents a fuel tank device.
  * @details This class inherits virtually from Device and includes functionalities related to fuel tanks.
  */
class FuelTank : virtual public Device
{
private:
	double capacity; /**< The capacity of the fuel tank. */
	bool broken; /**< Indicates whether the fuel tank is broken. */
	bool is_connect; /**< Indicates whether the fuel tank is connected to the engine. */
    double fuel_quantity; /**< The current quantity of fuel in the tank. */
	Valve valve; /**< Instance of Valve representing the tank's valve. */
public:
	static int id; /**< Static variable to track the number of fuel tanks. */
	int Tank_id; /**< Unique identifier for the fuel tank instance. */
	
    /**
     * @brief Constructor for the FuelTank class.
     * @param capacity The capacity of the fuel tank.
     */
    FuelTank(double);

    /**
     * @brief Constructor for the FuelTank class with broken status.
     * @param capacity The capacity of the fuel tank.
     * @param isBroken The initial broken status of the fuel tank.
     */
    FuelTank(double , bool);

    /**
     * @brief Gets the current quantity of fuel in the tank.
     * @return The current quantity of fuel.
     */
    double getFuelQuantity();

    /**
     * @brief Sets the current quantity of fuel in the tank.
     * @param quantity The new quantity of fuel.
     */
    void setFuelQuantity(double );

    /**
     * @brief Decreases the current quantity of fuel in the tank.
     * @param quantity The amount of fuel to decrease.
     */
    void setFuelNegative(double );

    /**
     * @brief Gets the capacity of the fuel tank.
     * @return The capacity of the fuel tank.
     */
    double getCapacity(); 

    /**
     * @brief Gets the connection status of the fuel tank to the engine.
     * @return True if the fuel tank is connected, false otherwise.
     */
    bool getConnectStatus(); 

    /**
     * @brief Sets the connection status of the fuel tank to the engine.
     * @param status The new connection status.
     */
    void setConnectStatus(bool ); 

    /**
     * @brief Gets the broken status of the fuel tank.
     * @return True if the fuel tank is broken, false otherwise.
     */
    bool getBrokenStatus();

    /**
     * @brief Sets the broken status of the fuel tank.
     * @param status The new broken status.
     */
    void setBrokenStatus(bool );

    /**
     * @brief Gets the status of the valve on the fuel tank.
     * @return True if the valve is open, false if closed.
     */
    bool getValveStatus();

    /**
     * @brief Sets the status of the valve on the fuel tank.
     * @param status The new status of the valve.
     */
    void setValveStatus(bool );

    /**
     * @brief Virtual function to print information about the fuel tank.
     * @return A string containing information about the fuel tank.
     */
    string printInfo();

};

