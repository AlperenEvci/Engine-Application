#pragma once
#include "File_Reader.h"

/**
 * @file Command_Reader.h
 * @brief Definition of the Command_Reader class.
 */

 /**
  * @class Command_Reader
  * @brief Reads and processes commands from a file.
  * @details Inherits from File_Reader.
  */
class Command_Reader : public File_Reader
{
protected:
	vector<string> processedCommandList; /**< Vector to store processed commands. */
	File_Reader read; /**< Instance of the File_Reader class. */
public:
	/**
	 * @brief Converts a file containing commands into a vector of strings.
	 * @param fileName A string representing the name of the file to be read.
	 * @return A vector of strings containing the processed commands.
	 */
	vector<string> commandConverter(string);

};

