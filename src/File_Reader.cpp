#include "File_Reader.h"

/**
 * @brief Reads input commands from a file and returns them as a vector of strings.
 * @param in The name of the input file.
 * @return A vector of strings containing unprocessed commands.
 * @throws std::runtime_error if the file cannot be opened.
 */
vector<string> File_Reader::getInputs(string in)
{
	string line;
	input_file = in;
	ifstream inputFile(input_file);
	if (!inputFile.is_open()) {
		throw runtime_error("Error: Unable to open file ");
	}
	while (inputFile >> line) {
		unprocessedCommandList.push_back(line);
	}

	return unprocessedCommandList;
}


