#include "Command_Reader.h"

/**
 * @brief Converts unprocessed commands from an input file into a processed form.
 * @param in The name of the input file.
 * @return A vector of strings containing processed commands.
 */
vector<string> Command_Reader::commandConverter(string in)
{	
	unprocessedCommandList = read.getInputs(in);
	for (int i = 0; i < unprocessedCommandList.size(); i++) {
		string command = unprocessedCommandList[i];
		
		int len = command.size();
		char op_array[] = { '<','>',';' };
		for (int i = 0; i < len; i++) {
			for (auto a : op_array) {
				if (command[i] == a) {
					command.erase(i, 1);
					len--;
				}
			}
		}
		processedCommandList.push_back(command);
	}
	return processedCommandList;
}
	

