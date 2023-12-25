#include "File_Writer.h"

/**
 * @brief Writes feedback to an output file.
 * @param feed A vector of strings containing feedback to be written.
 * @param output The name of the output file.
 */
void File_Writer::write(vector<string>& feed,string output)
{	
	output_file = output;
	out.open(output_file);
	string result = "";
	int num = feed.size();
	for (int i = 0; i < feed.size(); i++) {
		result = feed[i];
		out << result << endl;
	}
	out.close();

}
