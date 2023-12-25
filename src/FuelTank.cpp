#include "FuelTank.h"

/**
 * @brief Default constructor for the FuelTank class.
 * @param cap The capacity of the fuel tank.
 */
FuelTank::FuelTank(double cap) : capacity(cap), fuel_quantity(0.0), broken(false), is_connect(false) {
	valve.is_valve_open = false;
	Tank_id = id;
	id++;
}

/**
 * @brief Parameterized constructor for the FuelTank class.
 * @param cap The capacity of the fuel tank.
 * @param connect The connection status of the fuel tank.
 */
FuelTank::FuelTank(double cap, bool connect) : capacity(cap), fuel_quantity(0.0), broken(false), is_connect(connect) {}  // Use nullptr for modern C++

int FuelTank::id = 1;

/**
 * @brief Gets the current fuel quantity in the tank.
 * @return The current fuel quantity.
 */
double FuelTank::getFuelQuantity()
{
	return fuel_quantity;
}

/**
 * @brief Sets the fuel quantity in the tank.
 * @param quantity The quantity to set.
 */
void FuelTank::setFuelQuantity(double quantity)
{
	fuel_quantity += quantity;
}

/**
 * @brief Decreases the fuel quantity in the tank.
 * @param quantity The quantity to decrease.
 */
void FuelTank::setFuelNegative(double quantity)
{
	fuel_quantity -= quantity;
}

/**
 * @brief Gets the capacity of the fuel tank.
 * @return The capacity of the fuel tank.
 */
double FuelTank::getCapacity()
{
	return capacity;
}

/**
 * @brief Gets the connection status of the fuel tank.
 * @return True if the tank is connected, false otherwise.
 */
bool FuelTank::getConnectStatus() 
{
	return is_connect;
}
/**
 * @brief Sets the connection status of the fuel tank.
 * @param stat The connection status to set.
 */
void FuelTank::setConnectStatus(bool stat)
{
	this->is_connect = stat;
}
/**
 * @brief Gets the broken status of the fuel tank.
 * @return True if the tank is broken, false otherwise.
 */
bool FuelTank::getBrokenStatus()
{
	return broken;
}
/**
 * @brief Sets the broken status of the fuel tank.
 * @param stat The broken status to set.
 */
void FuelTank::setBrokenStatus(bool stat)
{
	this->broken = stat;
}

/**
 * @brief Prints information about the fuel tank.
 * @return A string containing information about the fuel tank.
 */
string FuelTank::printInfo()
{
	string fb = "+-----------------------------------------+\nTank Id : " + to_string(Tank_id)+"\nCapacity : " + to_string(capacity)+"\nFuel Quantity : " + to_string(fuel_quantity)+"\nConnect Status : " + to_string(is_connect)+"\nBroken Status : " + to_string(broken)+"\n" + valve.printInfo() + "\n+-----------------------------------------+\n";
	return fb;
}
/**
 * @brief Gets the valve status of the fuel tank.
 * @return True if the valve is open, false otherwise.
 */
bool FuelTank::getValveStatus()
{
	return valve.is_valve_open;
}
/**
 * @brief Sets the valve status of the fuel tank.
 * @param stat The valve status to set.
 */
void FuelTank::setValveStatus(bool stat)
{
	this->is_connect = stat;
}

