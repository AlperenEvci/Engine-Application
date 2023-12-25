#include "Command_Manager.h"

/**
 * @brief Reads and processes commands from an input file.
 * @param in The name of the input file.
 */
void Command_Manager::getCommands(string in)
{
	commands = CR.commandConverter(in);
}

/**
 * @brief Processes a series of commands and performs corresponding actions in the simulation.
 * @param in The name of the input file containing commands.
 * @param out The name of the output file to write feedback.
 */
void Command_Manager::commandProcessor(string in,string out)
{	
	getCommands(in);
	for (int i = 0; i < commands.size(); ++i) {

		if (commands[i] == "add_fuel_tank") {
			sim.add_fuel_tank(stod(commands[i + 1]));
		}
		else if (commands[i] == "connect_fuel_tank_to_engine") {
			sim.connect_fuel_tank_to_engine(stoi(commands[i + 1]));
		}
		else if (commands[i] == "disconnect_fuel_tank_from_engine") {
			sim.disconnect_fuel_tank_from_engine(stoi(commands[i + 1]));
		}
		else if (commands[i] == "open_valve") {
			sim.open_valve(stoi(commands[i + 1]));
		}
		else if (commands[i] == "close_valve") {
			sim.close_valve(stoi(commands[i + 1]));

		}
		else if (commands[i] == "break_fuel_tank") {
			sim.break_fuel_tank(stoi(commands[i + 1]));
		}
		else if (commands[i] == "repair_fuel_tank") {
			sim.repair_fuel_tank(stoi(commands[i + 1]));
		}
		else if (commands[i] == "remove_fuel_tank") {
			sim.remove_fuel_tank(stoi(commands[i + 1]));
		}
		else if (commands[i] == "give_back_fuel") {
			sim.give_back_fuel(stod(commands[i + 1]));
		}
		else if (commands[i] == "start_engine") {
			sim.start_engine(); 
		}
		else if (commands[i] == "list_fuel_tanks") {
			string fb = "\nList Of Tanks:\n";
			sim.setFeedBacks(fb);
			sim.list_fuel_tanks();
		}
		else if (commands[i] == "stop_engine") {
			sim.stop_engine();
		}
		else if (commands[i] == "wait") {
			string fb = "\nWaiting for " + commands[i + 1] + " seconds...";
			sim.setFeedBacks(fb);
			sim.wait(stod(commands[i + 1]));
		}
		else if (commands[i] == "print_total_consumed_fuel_quantity") {
			double temp = sim.print_total_consumed_fuel_quantity();
			string fb = "Total Consumed Fuel Quantity By The Engine: " + to_string(temp);
			sim.setFeedBacks(fb);
		}
		else if (commands[i] == "print_fuel_tank_count") {
			int temp = sim.print_fuel_tank_count();
			string fb = "Fuel Tank Count: " + to_string(temp);
			sim.setFeedBacks(fb);
		}
		else if (commands[i] == "print_total_fuel_quantity") {
			double temp = sim.print_total_fuel_quantity();
			string fb = "Total Fuel Quantity on The Engine: " + to_string(temp);
			sim.setFeedBacks(fb);
		}
		else if (commands[i] == "fill_tank") {
			sim.fill_tank(stoi(commands[i + 1]), stod(commands[i + 2]));
		}
		else if (commands[i] == "print_tank_info") {
			string fb = "\nTank Info : ";
			sim.setFeedBacks(fb);
			sim.print_tank_info(stoi(commands[i + 1]));

		}
		else if (commands[i] == "list_connected_tanks") {
			string fb = "List of Connected Tanks : ";
			sim.setFeedBacks(fb);
			sim.list_connected_tanks();

		}
		else if (commands[i] == "stop_simulation") {
			string fb = "\nEnd Simulation";
			sim.setFeedBacks(fb);
			sim.stop_simulation(); 
			write.write(sim.file_fbs,out);			
		}
	}
}
