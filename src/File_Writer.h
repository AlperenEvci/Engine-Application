#pragma once
#include "File_Operator.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

/**
 * @file File_Writer.h
 * @brief Definition of the File_Writer class.
 */

 /**
  * @class File_Writer
  * @brief Writes data to an output file.
  * @details Inherits from File_Operator.
  */
class File_Writer : public File_Operator
{
private: 
	ofstream out; /**< Output file stream for writing data. */
public:
	friend class File_Operator;
    /**
     * @brief Writes data to an output file.
     * @param data A vector of strings containing data to be written.
     * @param fileName A string representing the name of the output file.
     */
    void write(vector<string>&, string);
};

	