#include <iostream>
#include <vector>
#include <string>
#include "Command_Manager.h"

using namespace std;

/**
 * @brief The main function for the simulation program.
 * @details It creates instances of File_Operator and Command_Manager, then invokes the commandProcessor method.
 * @return 0 on successful execution.
 */
int main(int argc, char *argv[])
{
    Command_Manager CM;
    CM.commandProcessor(argv[1], argv[2]);
    return 0;
}