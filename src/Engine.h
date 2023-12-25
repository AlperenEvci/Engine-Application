#pragma once
class Tank_Manager;
#include "Device.h"
#include "Tank_Manager.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * @file Engine.h
 * @brief Definition of the Engine class.
 */

 /**
  * @class Engine
  * @brief Represents an engine device.
  * @details This class inherits virtually from Device and includes functionalities related to the engine.
  */
class Engine :virtual public Device
{
protected:
	static Engine* INSTANCE; /**< Static pointer to the singleton instance of Engine. */
	Engine(); /**< Constructor for the Engine class. */

	bool status; /**< Boolean variable representing the status of the engine. */
	FuelTank internal_tank; /**< Instance of FuelTank representing the internal fuel tank. */
	
public:
	friend class Simulation; /**< Friend class Simulation for accessing Engine's private members. */
	friend class Tank_Manager; /**< Friend class Tank_Manager for accessing Engine's private members. */
	Tank_Manager tank_manage; /**< Instance of Tank_Manager for managing tanks. */
	
	/**
	 * @brief Gets the singleton instance of the Engine class.
	 * @return The pointer to the singleton instance of the Engine class.
	 */
	static Engine* getINSTANCE() {
		if (INSTANCE == nullptr) {
			INSTANCE = new Engine();
		}
		return INSTANCE;
	}
    /**
     * @brief Gets the internal fuel tank of the engine.
     * @return The FuelTank object representing the internal fuel tank.
     */
    FuelTank getInternal(); 

    /**
     * @brief Gets the status of the engine.
     * @return True if the engine is running, false otherwise.
     */
    bool getStatus(); 

    /**
     * @brief Starts the engine.
     * @return A string indicating the result of starting the engine.
     */
    string start_engine(); 

    /**
     * @brief Stops the engine.
     * @return A string indicating the result of stopping the engine.
     */
    string stop_engine();

    /**
     * @brief Virtual function to print information about the engine.
     * @return A string containing information about the engine.
     */
    string printInfo();
};

