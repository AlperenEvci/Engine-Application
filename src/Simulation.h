#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Engine.h"
#include "Tank_Manager.h"

using namespace std;

/**
 * @file Simulation.h
 * @brief Definition of the Simulation class.
 */

 /**
  * @class Simulation
  * @brief Simulates the operation of an engine with fuel tanks.
  */
class Simulation
{
private:
	Engine* engine = Engine::getINSTANCE(); /**< Pointer to the singleton instance of the Engine class. */
	double finalsecond; /**< The final second of the simulation. */
	double fuel_per_second; /**< The fuel consumption rate per second. */
	
public:
    vector<string> file_fbs; /**< Vector to store feedbacks from files. */
    friend class Tank_Manager; /**< Friend class Tank_Manager for accessing Simulation's private members. */
    friend class Engine; /**< Friend class Engine for accessing Simulation's private members. */

    /**
     * @brief Constructor for the Simulation class.
     */
    Simulation();

    /**
     * @brief Stops the simulation.
     */
    void stop();

    /**
     * @brief Starts the engine in the simulation.
     */
    void start_engine();

    /**
     * @brief Stops the engine in the simulation.
     */
    void stop_engine();

    /**
     * @brief Gives back a specified amount of fuel to the engine.
     * @param quantity The amount of fuel to give back.
     */
    void give_back_fuel(double);

    /**
     * @brief Adds a new fuel tank to the simulation.
     * @param capacity The capacity of the new fuel tank.
     */
    void add_fuel_tank(double);

    /**
     * @brief Lists information about all fuel tanks in the simulation.
     */
    void list_fuel_tanks();

    /**
     * @brief Removes a fuel tank from the simulation.
     * @param tankId The ID of the fuel tank to remove.
     */
    void remove_fuel_tank(int);

    /**
     * @brief Connects a fuel tank to the engine in the simulation.
     * @param tankId The ID of the fuel tank to connect.
     */
    void connect_fuel_tank_to_engine(int);

    /**
     * @brief Disconnects a fuel tank from the engine in the simulation.
     * @param tankId The ID of the fuel tank to disconnect.
     */
    void disconnect_fuel_tank_from_engine(int);

    /**
     * @brief Opens the valve on a fuel tank in the simulation.
     * @param tankId The ID of the fuel tank to open the valve.
     */
    void open_valve(int);

    /**
     * @brief Closes the valve on a fuel tank in the simulation.
     * @param tankId The ID of the fuel tank to close the valve.
     */
    void close_valve(int);

    /**
     * @brief Breaks a fuel tank in the simulation.
     * @param tankId The ID of the fuel tank to break.
     */
    void break_fuel_tank(int);

    /**
     * @brief Repairs a broken fuel tank in the simulation.
     * @param tankId The ID of the fuel tank to repair.
     */
    void repair_fuel_tank(int);

    /**
     * @brief Prints the count of fuel tanks in the simulation.
     * @return The count of fuel tanks.
     */
    int print_fuel_tank_count();

    /**
     * @brief Waits for a specified duration in the simulation.
     * @param seconds The duration to wait in seconds.
     */
    void wait(double);

    /**
     * @brief Prints the total consumed fuel quantity in the simulation.
     * @return The total consumed fuel quantity.
     */
    double print_total_consumed_fuel_quantity();

    /**
     * @brief Fills a fuel tank in the simulation to a specified quantity.
     * @param tankId The ID of the fuel tank to fill.
     * @param quantity The quantity to fill the fuel tank.
     */
    void fill_tank(int, double);

    /**
     * @brief Prints information about a specific fuel tank in the simulation.
     * @param tankId The ID of the fuel tank to print information.
     */
    void print_tank_info(int);

    /**
     * @brief Lists information about connected fuel tanks in the simulation.
     */
    void list_connected_tanks();

    /**
     * @brief Prints the total fuel quantity in all fuel tanks in the simulation.
     * @return The total fuel quantity.
     */
    double print_total_fuel_quantity();

    /**
     * @brief Finds the Tank Id of a fuel tank based on its ID.
     * @param id The ID of the fuel tank.
     */
    void find_Tank_Id(int);

    /**
     * @brief Stops the simulation and prints the feedbacks from files.
     * @return The simulation stop code.
     */
    int stop_simulation();

    /**
     * @brief Sets feedbacks for the simulation from a file.
     * @param fileName The name of the file containing feedbacks.
     */
    void setFeedBacks(string);
};
