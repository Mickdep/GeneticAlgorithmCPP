#pragma once
#include <string>
#include "individual_raw.h"
class population_raw
{
public:
	population_raw(std::string goal);
	~population_raw();

	void initialize(int size);
	void calculate_fitness();
	void manipulate(int index, individual_raw* manipulation);
	double get_total_fitness();

	individual_raw* get_individual(int index);
	void set_new_population(std::vector<individual_raw*> new_population);
	individual_raw* get_fittest_individual();

	void print_population();

private:
	std::string _goal;
	std::vector<individual_raw*> _individuals;

};

