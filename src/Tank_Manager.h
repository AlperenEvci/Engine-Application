#pragma once

class Engine;

#include "FuelTank.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * @file Tank_Manager.h
 * @brief Definition of the Tank_Manager class.
 */

 /**
  * @class Tank_Manager
  * @brief Manages fuel tanks in the simulation.
  */
class Tank_Manager
{
private:
	list<FuelTank> connectedTankList; /**< List of connected fuel tanks. */
public:
    vector<FuelTank> tanks; /**< Vector to store all fuel tanks. */
    friend class Fuel_Tank;
    /**
     * @brief Sets a fuel tank in the vector of all fuel tanks.
     * @param tank The fuel tank to set.
     */
    void setTanks(FuelTank);

    /**
     * @brief Gives back a specified amount of fuel to connected fuel tanks.
     * @param quantity The amount of fuel to give back.
     * @return A string indicating the result of giving back fuel.
     */
    string give_back_fuel(double);

    /**
     * @brief Adds a new fuel tank to the vector of all fuel tanks.
     * @param capacity The capacity of the new fuel tank.
     * @return A string indicating the result of adding a fuel tank.
     */
    string add_fuel_tank(double);

    /**
     * @brief Lists information about all fuel tanks.
     * @return A string containing information about all fuel tanks.
     */
    string list_fuel_tanks();

    /**
     * @brief Removes a fuel tank from the vector of all fuel tanks.
     * @param tankId The ID of the fuel tank to remove.
     * @return A string indicating the result of removing a fuel tank.
     */
    string remove_fuel_tank(int);

    /**
     * @brief Connects a fuel tank to the engine.
     * @param tankId The ID of the fuel tank to connect.
     * @return A string indicating the result of connecting a fuel tank to the engine.
     */
    string connect_fuel_tank_to_engine(int);

    /**
     * @brief Disconnects a fuel tank from the engine.
     * @param tankId The ID of the fuel tank to disconnect.
     * @return A string indicating the result of disconnecting a fuel tank from the engine.
     */
    string disconnect_fuel_tank_from_engine(int);

    /**
     * @brief Breaks a fuel tank.
     * @param tankId The ID of the fuel tank to break.
     * @return A string indicating the result of breaking a fuel tank.
     */
    string break_fuel_tank(int);

    /**
     * @brief Repairs a broken fuel tank.
     * @param tankId The ID of the fuel tank to repair.
     * @return A string indicating the result of repairing a fuel tank.
     */
    string repair_fuel_tank(int);

    /**
     * @brief Prints the count of fuel tanks.
     * @return The count of fuel tanks.
     */
    int print_fuel_tank_count();

    /**
     * @brief Fills a fuel tank to a specified quantity.
     * @param tankId The ID of the fuel tank to fill.
     * @param quantity The quantity to fill the fuel tank.
     * @return A string indicating the result of filling a fuel tank.
     */
    string fill_tank(int, double);

    /**
     * @brief Prints information about a specific fuel tank.
     * @param tankId The ID of the fuel tank to print information.
     * @return A string containing information about the fuel tank.
     */
    string print_tank_info(int);

    /**
     * @brief Lists information about connected fuel tanks.
     * @return A string containing information about connected fuel tanks.
     */
    string list_connected_tanks();

    /**
     * @brief Finds the Tank Id of a fuel tank based on its ID.
     * @param id The ID of the fuel tank.
     * @return The Tank Id of the fuel tank.
     */
    int find_Tank_Id(int);

    /**
     * @brief Opens the valve on a fuel tank.
     * @param tankId The ID of the fuel tank to open the valve.
     */
    void openValve(int);

    /**
     * @brief Closes the valve on a fuel tank.
     * @param tankId The ID of the fuel tank to close the valve.
     */
    void closeValve(int);

    /**
     * @brief Copies connected fuel tanks to the connectedTankList.
     */
    void copyTanksToList() {
        for (auto element : tanks)
            if (element.getConnectStatus())
                connectedTankList.push_back(element);
    }
};

