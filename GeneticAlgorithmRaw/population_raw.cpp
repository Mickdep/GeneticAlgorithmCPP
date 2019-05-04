#include "population_raw.h"
#include <iostream>

population_raw::population_raw(std::string goal)
{
	_goal = goal;
}

population_raw::~population_raw()
{
	//Delete all individuals from memory.
	for (individual_raw* individual : _individuals) {
		delete individual;
	}
}

void population_raw::initialize(int size)
{
	_individuals.reserve(size);
	for (int i = 0; i < size; i++) {
		_individuals.push_back(new individual_raw(_goal));
	}
}

void population_raw::calculate_fitness()
{
	for (auto individual : _individuals) {
		individual->calculate_fitness();
	}
}

void population_raw::manipulate(int index, individual_raw* manipulation)
{
	delete _individuals[index];
	_individuals[index] = manipulation;
}

double population_raw::get_total_fitness()
{
	double total = 0.0;
	for (individual_raw* individual : _individuals) {
		total += individual->get_fitness();
	}
	return total;
}

individual_raw* population_raw::get_individual(int index)
{
	// TODO: insert return statement here
	return _individuals[index];
}

void population_raw::set_new_population(std::vector<individual_raw*> new_population)
{
	for (individual_raw* individual : _individuals) {
		delete individual;
	}
	_individuals.clear();
	_individuals = new_population;
}

individual_raw* population_raw::get_fittest_individual()
{
	// TODO: insert return statement here
	int fittest_individual_index = 0;
	int highest_fitness = 0;
	for (int i = 0; i < _individuals.size(); i++) {
		int individual_fitness = _individuals[i]->get_fitness();

		if (individual_fitness > highest_fitness) {
			highest_fitness = individual_fitness;
			fittest_individual_index = i;
		}
	}

	return _individuals[fittest_individual_index];
}

void population_raw::print_population() {
	for (auto indiv : _individuals) {
		std::cout << indiv << "(" << indiv->get_gene() << ")" << std::endl;
	}
}
