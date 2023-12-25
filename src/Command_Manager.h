#pragma once
#include "Command_Reader.h"
#include "File_Writer.h"
#include <vector>
#include <iostream>
#include "Simulation.h"
using namespace std;

/**
 * @file Command_Manager.h
 * @brief Definition of the Command_Manager class.
 */

 /**
  * @class Command_Manager
  * @brief Manages commands for simulation.
  */
class Command_Manager
{
private:
	Simulation sim; /**< Instance of the Simulation class. */
    vector<string> commands; /**< Vector to store commands. */
    Command_Reader CR; /**< Instance of the Command_Reader class. */
    File_Writer write; /**< Instance of the File_Writer class. */
public:
    /**
     * @brief Gets commands from an external source.
     * @param input A string representing the source of commands.
     */
    void getCommands(string);

    /**
     * @brief Processes the commands.
     * @param input1 A string representing the first input parameter.
     * @param input2 A string representing the second input parameter.
     */
    void commandProcessor(string, string);
};

