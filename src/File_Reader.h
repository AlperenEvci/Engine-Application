#pragma once
#include "File_Operator.h"
#include <fstream>
#include <vector>
using namespace std;

/**
 * @file File_Reader.h
 * @brief Definition of the File_Reader class.
 */

 /**
  * @class File_Reader
  * @brief Reads and processes input files.
  * @details Inherits from File_Operator.
  */
class File_Reader : public File_Operator
{
protected:
	vector<string> unprocessedCommandList; /**< Vector to store unprocessed command list. */
public:
	friend class File_Operator;
    /**
    * @brief Gets input from a file and processes it into a vector of strings.
    * @param fileName A string representing the name of the input file.
    * @return A vector of strings containing unprocessed commands.
    */
    vector<string> getInputs(string);
};
		


