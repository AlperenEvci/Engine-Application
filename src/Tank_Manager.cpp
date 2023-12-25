#include "Tank_Manager.h"
/*!
 * \brief Adds a fuel tank to the manager.
 * \param tank The fuel tank to be added.
 */
void Tank_Manager::setTanks(FuelTank tank)
{
	tanks.push_back(tank);
}
/*!
 * \brief Adds fuel to the tanks.
 * \param quantity The quantity of fuel to be added.
 * \return A string indicating the status of the fuel addition.
 */
string Tank_Manager::give_back_fuel(double quantity)
{
	string fb = "";
	int flag = 0;
	for (int i = 0; i < tanks.size() && tanks[i].getConnectStatus() && tanks[i].getValveStatus();i++) {
		double space = tanks[i].getCapacity() - tanks[i].getFuelQuantity();
		if (quantity <= space && quantity != 0) {
			tanks[i].setFuelQuantity(space);
			fb = to_string(space) + "quantity of fuel added to tank : " + to_string(find_Tank_Id(i));
			return fb;
		}
		else {
			tanks[i].setFuelQuantity(space);
			double overflowed = quantity - space;

			for (int i = 0; i < tanks.size() && overflowed > 0 && tanks[i].getConnectStatus() && tanks[i].getValveStatus(); i++) {
				double next = tanks[i].getCapacity() - tanks[i].getFuelQuantity();
				flag = 1;
				if (next >= overflowed) {
					tanks[i].setFuelQuantity(next); 
					fb = to_string(next) + "quantity of fuel added to tank : " + to_string(find_Tank_Id(i)); 
					return fb; 
				}
				else {
					if (next != 0) {
						fb += to_string(next) + "quantity of fuel added to tank : " + to_string(find_Tank_Id(i));
					}
					tanks[i].setFuelQuantity(next);
					overflowed -= next;
				}
			}
			if (overflowed != 0 && flag) {
				fb = "All of the connected tanks are full right now. " + to_string(overflowed) + " quantity of fuel has overflowed from the tanks !";

			}
			if (!flag && overflowed != 0) {
				fb = "None of the tanks are connected or all valves closed ! " + to_string(overflowed) + " quantity of fuel has overflowed from the tanks !";
			}
		}

	}
	return fb;
}
	
/*!
 * \brief Adds a fuel tank to the manager with the given capacity.
 * \param capacity The capacity of the fuel tank to be added.
 * \return A string indicating the status of the fuel tank addition.
 */
string Tank_Manager::add_fuel_tank(double capacity)
{
	FuelTank tank(capacity);
	setTanks(tank);
	string fb = "Fuel tank added";
	return fb;
}
/*!
 * \brief Adds a fuel tank to the manager with the given capacity.
 * \param capacity The capacity of the fuel tank to be added.
 * \return A string indicating the status of the fuel tank addition.
 */
string Tank_Manager::list_fuel_tanks()
{
	int j = 0;
	string fb = "";

	if (tanks.empty()) {
		fb += "Tanks are empty!\n";
		return fb;
	}
	else {

		while (j < tanks.size()) {
			fb += tanks[j].printInfo();
			j++;
		}
		return fb;
	}
}
/*!
 * \brief Removes a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank to be removed.
 * \return A string indicating the status of the fuel tank removal.
 */
string Tank_Manager::remove_fuel_tank(int tank_id)
{
	int temp_id = find_Tank_Id(tank_id);

	if (tanks.empty()) {
		string fb = "Error : There are not any tank! ";
		return fb;
	}
	else if (temp_id < 0 || temp_id >= tanks.size()) {
		string fb = "Error: You dont have a tank with expected ID.";
		return fb;
	}
	else {
		string fb = "Tank " + to_string(tank_id) + " is removed";
		tanks.erase(tanks.begin() + temp_id);
		return fb;
		
	}
}
/*!
 * \brief Connects a fuel tank with the specified ID to the engine.
 * \param tank_id The ID of the fuel tank to be connected.
 * \return A string indicating the status of the connection.
 */
string Tank_Manager::connect_fuel_tank_to_engine(int tank_id)
{
	int temp_id = find_Tank_Id(tank_id);
	string fb = "";
	if (tanks.empty()) {
		fb += "Error : There are not any tank!";
	}
	else if (temp_id < 0 || temp_id >= tanks.size()) {
		fb += "Error: You dont have a tank with expected ID.";
	}
	else {
		fb += "Tank " + to_string(tank_id) + " is connected to engine";
		tanks[temp_id].setConnectStatus(true);
	}
	return fb;
}
/*!
 * \brief Disconnects a fuel tank with the specified ID from the engine.
 * \param tank_id The ID of the fuel tank to be disconnected.
 * \return A string indicating the status of the disconnection.
 */
string Tank_Manager::disconnect_fuel_tank_from_engine(int tank_id)
{
	string fb;
	int temp_id = find_Tank_Id(tank_id);
	if (tanks.empty()) {
		fb = "Error : There are not any tank! ";
	}
	else if (temp_id < 0 || temp_id >= tanks.size()) {
		fb = "Error: You dont have a tank with expected ID.";	
	}
	else {
		fb = "Tank " + to_string(tank_id) + " is disconnect from engine";
		tanks[temp_id].setConnectStatus(false);
	}
	return fb;
}
/*!
 * \brief Breaks a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank to be broken.
 * \return A string indicating the status of the tank breakage.
 */
string Tank_Manager::break_fuel_tank(int tank_id)
{
	int temp_id = find_Tank_Id(tank_id);
	if (temp_id < 0) {
		string fb = "Invalid tank_id";
		return fb;
	}
	else {
		if (!tanks[temp_id].getConnectStatus()) {
			tanks[temp_id].setConnectStatus(true);
			string fb = "Tank " + to_string(tank_id) + " has been broken";
			return fb;
		}
		else {
			string fb = "Tank " + to_string(tank_id) + "  is already broken";
			return fb;
		}
	}
}
/*!
 * \brief Repairs a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank to be repaired.
 * \return A string indicating the status of the tank repair.
 */
string Tank_Manager::repair_fuel_tank(int tank_id)
{
	int temp_id = find_Tank_Id(tank_id);
	if (temp_id < 0) {
		string fb = "Invalid tank_id";
		return fb;
	}
	else {
		if (tanks[temp_id].getBrokenStatus()) {
			tanks[temp_id].setBrokenStatus(false);
			string fb = "Tank " + to_string(tank_id) + " has been repaired";
			return fb;
		}
		else {
			string fb = "Tank " + to_string(tank_id) + "  is already repaired";
			return fb;
		}
	}
}
/*!
 * \brief Prints the count of fuel tanks.
 * \return The count of fuel tanks.
 */
int Tank_Manager::print_fuel_tank_count()
{	
	return tanks.size();
}
/*!
 * \brief Fills a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank to be filled.
 * \param quantity The quantity of fuel to be added.
 * \return A string indicating the status of the tank filling.
 */
string Tank_Manager::fill_tank(int tank_id, double quantity)
{
	string fb = "";
	int temp_id = find_Tank_Id(tank_id);

	if (temp_id < 0 || temp_id >= tanks.size()) {
		fb += "Invalid tank_id";
		return fb;
	}
	else {
		double tank_space = tanks[temp_id].getCapacity() - tanks[temp_id].getFuelQuantity();

		if (tank_space >= quantity && quantity > 0) {
			fb += to_string(quantity) + " Fuel Added to Tank ID : " + to_string(tank_id);
			tanks[temp_id].setFuelQuantity(quantity);
			return fb;
			
		}
		else if (quantity > 0) {
			double overflowed_fuel = quantity - tank_space;
			tanks[temp_id].setFuelQuantity(tank_space);

			for (int i = temp_id + 1; i < tanks.size() && overflowed_fuel > 0; i++) {
				double next_tank_space = tanks[i].getCapacity() - tanks[i].getFuelQuantity();

				if (next_tank_space >= overflowed_fuel) {
					fb += to_string(overflowed_fuel) + " Fuel Added to Tank ID : " + to_string(tanks[temp_id].Tank_id);
					tanks[i].setFuelQuantity(overflowed_fuel);
					overflowed_fuel = 0;
				}
				else {
					if (next_tank_space != 0) {
						fb += to_string(next_tank_space) + " Fuel Added to Tank ID : " + to_string(tanks[temp_id].Tank_id);
					}
					tanks[i].setFuelQuantity(next_tank_space);
					overflowed_fuel -= next_tank_space;
				}
			}
			if (overflowed_fuel != 0) {
				fb += "All of the tanks are full right now. " + to_string(overflowed_fuel) + " has overflowed from tanks !";
			}
		}
	}
	return fb;
}
/*!
 * \brief Prints information about a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank to be printed.
 * \return A string containing information about the fuel tank.
 */
string Tank_Manager::print_tank_info(int tank_id)
{
	int temp_id = find_Tank_Id(tank_id);
	string fb;

	if (temp_id < tanks.size()) fb = tanks[temp_id].printInfo();
	else fb = "There is not enough tank !\n";
	return fb;
}
/*!
 * \brief Lists information about connected fuel tanks.
 * \return A string containing information about connected fuel tanks.
 */
string Tank_Manager::list_connected_tanks()
{
	copyTanksToList();
	string fb = "";
	if (tanks.empty()) {
		fb += "There is not any connected tanks\n";
	}
	else {
		
		for (FuelTank tank : connectedTankList) {
			fb += tank.printInfo();
		}
	}
	return fb;
}
/*!
 * \brief Finds the index of a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank to be found.
 * \return The index of the fuel tank in the tanks vector, or -1 if not found.
 */
int Tank_Manager::find_Tank_Id(int tank_id)
{
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].Tank_id == tank_id) {
			return i;
		}
	}
	return -1;
}
/*!
 * \brief Opens the valve of a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank whose valve is to be opened.
 */
void Tank_Manager::openValve(int tank_id)
{
	
	tanks[tank_id].setValveStatus(true);
}
/*!
 * \brief Closes the valve of a fuel tank with the specified ID.
 * \param tank_id The ID of the fuel tank whose valve is to be closed.
 */
void Tank_Manager::closeValve(int tank_id)
{
	tanks[tank_id].setValveStatus(false);
}

