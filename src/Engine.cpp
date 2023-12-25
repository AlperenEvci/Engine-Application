#include "Engine.h"

/**
 * @brief Default constructor for the Engine class.
 * @details Initializes the Engine with a default status of 'false' and an internal fuel tank of 55.0 capacity.
 */
Engine::Engine() : status(false), internal_tank(55.0, true) {}

Engine* Engine::INSTANCE = nullptr;

/**
 * @brief Gets the internal fuel tank of the engine.
 * @return The internal fuel tank.
 */	
FuelTank Engine::getInternal()
{
	return internal_tank;
}

/**
 * @brief Gets the status of the engine.
 * @return True if the engine is running, false otherwise.
 */
bool Engine::getStatus()
{
	return status;
}

/**
 * @brief Starts the engine and updates the feedback.
 * @return A string indicating the result of starting the engine.
 */
string Engine::start_engine()
{
	string fb;
	if (tank_manage.tanks.empty()) {
		fb = "Engine can not start, you do not have tank";
	}
	else {
		if (internal_tank.getFuelQuantity() != 0) {
			for (int i = 0; i < tank_manage.tanks.size(); i++) {
				if (tank_manage.tanks[i].getConnectStatus()) {
					fb = "Engine is starting... \nQuantity of internal tank is " + to_string(internal_tank.getFuelQuantity());
					status = true;
					break;
				}
				else {
					fb = "Engine can not start!! There are not any connected tanks !";
					status = false;
				}
			}
		}
		else {
			for (int i = 0; i < tank_manage.tanks.size(); i++) {
				if (tank_manage.tanks[i].getFuelQuantity() > 0 && tank_manage.tanks[i].getConnectStatus()) {
					int fuel_space = internal_tank.getCapacity() - internal_tank.getFuelQuantity();
					internal_tank.setFuelQuantity(fuel_space);
					tank_manage.tanks[i].setFuelNegative(fuel_space);
					fb = "Engine is starting... \nQuantity of internal tank is " + to_string(internal_tank.getFuelQuantity());
					status = true;
					break;
				}
				else {
					fb = "Engine can not start!! There are not enough fuel !";
					status = false;
				}
			}
		}
	}
	return fb;
}

/**
 * @brief Stops the engine and updates the feedback.
 * @return A string indicating the result of stopping the engine.
 */
string Engine::stop_engine()
{
	status = false;
	string fb = "Engine Stopped!";
	return fb;
}
/**
 * @brief Prints information about the engine.
 * @return A string containing information about the engine.
 */
string Engine::printInfo() {

	string fb = "+-----------------------------------------+\nEngine Working Status : " + to_string(status) + "\nInternal Tank Infos : \n" + internal_tank.printInfo();
	return fb;
}