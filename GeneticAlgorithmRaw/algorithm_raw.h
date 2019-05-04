#pragma once
#include <string>
#include "population_raw.h"
class algorithm_raw
{
public:
	algorithm_raw(std::string goal, int population_size, int mutation_chance);
	~algorithm_raw();

	void run();

private:
	std::string _goal;
	int _generation_count;
	int _mutation_chance;
	int _population_size;
	
	population_raw* _population;
	std::mt19937 random_number_generator;
	std::vector<individual_raw*> _mating_pool;

	void selection();
	individual_raw* crossover(individual_raw& parent_a, individual_raw& parent_b);
	void create_new_generation();
};

