#include "Simulation.h"
/*!
 * \brief Default constructor for the Simulation class.
 *
 * Initializes finalsecond to 0 and fuel_per_second to 5.5.
 */
Simulation::Simulation() : finalsecond(0), fuel_per_second(5.5) {}
/*!
 * \brief Stops the simulation.
 *
 * If the engine is already stopped, it prints a message; otherwise, it stops the engine and prints messages for each tank and valve.
 */
void Simulation::stop()20	
{
	if (!engine->getStatus()) {
		string fb = "Engine is already stopped \nSimualtion ending...";
		setFeedBacks(fb);
	}
	else {
		string fb = "Engine is stopped \nSimualtion ending...";
		setFeedBacks(fb);
		wait(1);
		stop_engine();
	}
	for (int i = 0; i < engine->tank_manage.tanks.size(); i++) {
		string fb = "Tank " + to_string(i + 1) + ": Simulation Stopped !\nValve " + to_string(i + 1) + ": Simulation Stopped !";
		setFeedBacks(fb);
	}
}
/*!
 * \brief Starts the engine.
 *
 * Calls the engine's start_engine method and sets feedback accordingly.
 */
void Simulation::start_engine()
{
	string fb = engine->start_engine();
	setFeedBacks(fb);
	
}
/*!
 * \brief Stops the engine.
 *
 * Calls the engine's stop_engine method and sets feedback accordingly.
 */
void Simulation::stop_engine()
{
	string fb = engine->stop_engine();
	setFeedBacks(fb);
}
/*!
 * \brief Gives back fuel to the tanks from the internal tank.
 *
 * If there is not enough fuel in the internal tank, it prints a message. Otherwise, it gives back the specified quantity of fuel.
 */
void Simulation::give_back_fuel(double quantity)
{	
	string fb = "";
	if (engine->internal_tank.getFuelQuantity() < quantity) {
		fb += "There is not enough fuel in the internal tank.\n" +to_string(engine->internal_tank.getFuelQuantity()) + " fuel gived back!";
		engine->internal_tank.setFuelNegative(engine->internal_tank.getFuelQuantity());
	}
	else {
		engine->internal_tank.setFuelNegative(quantity);
		fb += to_string(quantity) + " quantity of fuel is gived back to tanks from internal tank!";
		fb += engine->tank_manage.give_back_fuel(quantity);
	}
	wait(1);
	setFeedBacks(fb);
}
/*!
 * \brief Adds a fuel tank with the specified capacity.
 *
 * Calls the add_fuel_tank method of the tank manager and sets feedback accordingly.
 */
void Simulation::add_fuel_tank(double capacity)
{
	setFeedBacks(engine->tank_manage.add_fuel_tank(capacity));
	wait(1);
}
/*!
 * \brief Adds a fuel tank with the specified capacity.
 *
 * Calls the add_fuel_tank method of the tank manager and sets feedback accordingly.
 */
void Simulation::list_fuel_tanks()
{
	setFeedBacks(engine->tank_manage.list_fuel_tanks());
	wait(1);
}
/*!
 * \brief Removes a fuel tank with the specified ID.
 *
 * Calls the remove_fuel_tank method of the tank manager and sets feedback accordingly.
 */
void Simulation::remove_fuel_tank(int tank_id)
{
	setFeedBacks(engine->tank_manage.remove_fuel_tank(tank_id));
	wait(1);
}
/*!
 * \brief Connects a fuel tank with the specified ID to the engine.
 *
 * Calls the connect_fuel_tank_to_engine method of the tank manager and sets feedback accordingly.
 */
void Simulation::connect_fuel_tank_to_engine(int tank_id)
{
	setFeedBacks(engine->tank_manage.connect_fuel_tank_to_engine(tank_id));
	wait(1);
}
/*!
 * \brief Disconnects a fuel tank with the specified ID from the engine.
 *
 * Calls the disconnect_fuel_tank_from_engine method of the tank manager and sets feedback accordingly.
 */
void Simulation::disconnect_fuel_tank_from_engine(int tank_id)
{
	setFeedBacks(engine->tank_manage.disconnect_fuel_tank_from_engine(tank_id));
	wait(1);
}
/*!
 * \brief Opens the valve of a fuel tank with the specified ID.
 *
 * If the tank with the given ID is not found, it prints an error message; otherwise, it opens the valve and prints a message.
 */
void Simulation::open_valve(int tank_id)
{
	if (engine->tank_manage.find_Tank_Id(tank_id) < 0) {
		string fb = "Invalid Valve Id ! The tank is not exist !";
		setFeedBacks(fb);
	}
	else {
		string fb = "Valve of tank : " + to_string(tank_id) + " is opened!";
		engine->tank_manage.openValve(tank_id);
		setFeedBacks(fb);
	}
	wait(1);
}
/*!
 * \brief Closes the valve of a fuel tank with the specified ID.
 *
 * If the tank with the given ID is not found, it prints an error message; otherwise, it closes the valve and prints a message.
 */
void Simulation::close_valve(int tank_id)
{
	if (engine->tank_manage.find_Tank_Id(tank_id) < 0) {
		string fb = "Invalid Valve Id ! The tank is not exist !";
		setFeedBacks(fb);
	}
	else {
		string fb = "Valve of tank : " + to_string(tank_id) + " is closed!";
		engine->tank_manage.closeValve(tank_id);
		setFeedBacks(fb);
	}
	wait(1);
}
/*!
 * \brief Breaks a fuel tank with the specified ID.
 *
 * Calls the break_fuel_tank method of the tank manager and sets feedback accordingly.
 */
void Simulation::break_fuel_tank(int tank_id)
{
	setFeedBacks(engine->tank_manage.break_fuel_tank(tank_id));
	wait(1);
}
/*!
 * \brief Repairs a fuel tank with the specified ID.
 *
 * Calls the repair_fuel_tank method of the tank manager and sets feedback accordingly.
 */
void Simulation::repair_fuel_tank(int tank_id)
{
	setFeedBacks(engine->tank_manage.repair_fuel_tank(tank_id));
	wait(1);
}
/*!
 * \brief Prints the count of fuel tanks.
 *
 * Calls the print_fuel_tank_count method of the tank manager and returns the count.
 */
int Simulation::print_fuel_tank_count()
{
	wait(1);
	return engine->tank_manage.print_fuel_tank_count();
	
}
/*!
 * \brief Waits for the specified number of seconds and performs fuel distribution.
 *
 * If the engine is working, it simulates fuel distribution based on internal tank and connected tanks.
 * If the engine is not working, it prints an error message.
 */
void Simulation::wait(double seconds)
{
	int flag = 0, is_printed = 0;
	if (engine->getStatus()) {
		finalsecond += seconds;
		while (seconds > 0) {
			if (engine->internal_tank.getFuelQuantity() >= 20) {
				engine->internal_tank.setFuelNegative(fuel_per_second);
			}
			else if (engine->internal_tank.getFuelQuantity() < 20) {
				for (int i = 0; i < engine->tank_manage.tanks.size(); i++)
				{
					if ((engine->tank_manage.tanks[i].getConnectStatus()))
					{
						if ((engine->internal_tank.getCapacity() - engine->internal_tank.getFuelQuantity()) < engine->tank_manage.tanks[i].getFuelQuantity()) {
							double fuel = abs(engine->internal_tank.getCapacity() - engine->internal_tank.getFuelQuantity());
							engine->internal_tank.setFuelQuantity(fuel);
							engine->tank_manage.tanks[i].setFuelNegative(fuel);
						}
						else {
							engine->internal_tank.setFuelQuantity(engine->tank_manage.tanks[i].getFuelQuantity());
						}
						flag = 1;
					}
				}
				if (!flag && !is_printed)
				{
					string fb = "All of the connected tanks are empty now! ";
					setFeedBacks(fb);
					is_printed = 1;
				}
			}
			seconds--;
		}
	}
	else if (seconds > 1 && !engine->getStatus()) {
		string fb = "Engine is not working";
		setFeedBacks(fb);
	}
}
/*!
 * \brief Prints the total consumed fuel quantity during the simulation.
 * \return The total consumed fuel quantity.
 */
double Simulation::print_total_consumed_fuel_quantity()
{
	wait(1);
	return finalsecond * fuel_per_second;
}
/*!
 * \brief Fills a fuel tank with the specified ID and quantity.
 *
 * Calls the fill_tank method of the tank manager and sets feedback accordingly.
 */
void Simulation::fill_tank(int tank_id, double quantity)
{
	setFeedBacks(engine->tank_manage.fill_tank(tank_id, quantity));
	wait(1);
}
/*!
 * \brief Prints information about a fuel tank with the specified ID.
 *
 * Calls the print_tank_info method of the tank manager and sets feedback accordingly.
 */
void Simulation::print_tank_info(int tank_id)
{
	setFeedBacks(engine->tank_manage.print_tank_info(tank_id));
	wait(1);
}
/*!
 * \brief Lists information about connected fuel tanks.
 *
 * Calls the list_connected_tanks method of the tank manager and sets feedback accordingly.
 */
void Simulation::list_connected_tanks()
{
	setFeedBacks(engine->tank_manage.list_connected_tanks());
	wait(1);
}
/*!
 * \brief Prints the total fuel quantity considering the internal tank and connected tanks.
 * \return The total fuel quantity.
 */
double Simulation::print_total_fuel_quantity()
{
	double total = 0.0;
	total += engine->getInternal().getFuelQuantity();

	for (int j = 0; j < engine->tank_manage.tanks.size(); j++) {
		if (engine->tank_manage.tanks[j].getConnectStatus()) {
			total += engine->tank_manage.tanks[j].getFuelQuantity();
		}
	}
	wait(1);
	return total;
	
}
/*!
 * \brief Finds the index of a fuel tank with the specified ID and prints the result.
 */
void Simulation::find_Tank_Id(int tank_id)
{
	engine->tank_manage.find_Tank_Id(tank_id);
	wait(1);
}
/*!
 * \brief Stops the simulation.
 * \return 0 upon successful completion.
 */
int Simulation::stop_simulation()
{	
	setFeedBacks(engine->printInfo());
	if (!engine->getStatus()) {
		string fb = "Engine is already stopped \nSimualtion ending...";
		setFeedBacks(fb);
	}
	else {
		string fb = "Engine is stopped \nSimualtion ending...";
		setFeedBacks(fb);
		stop_engine();
	}
	for (int i = 0; i < engine->tank_manage.tanks.size(); i++) {
		string fb = "Tank " + to_string(engine->tank_manage.tanks[i].Tank_id) + ": Simulation Stopped !\nValve " + to_string(engine->tank_manage.tanks[i].Tank_id) + ": Simulation Stopped !";
		setFeedBacks(fb);
	}
	wait(1);
	return 0;
}
/*!
 * \brief Sets the feedbacks for the simulation.
 * \param fb The feedback string to be added to the feedbacks list.
 */
void Simulation::setFeedBacks(string fb)
{
	file_fbs.push_back(fb);
}
