#pragma once
#include <string>
#include <random>
class individual_raw
{
public:
	individual_raw(std::string goal);
	~individual_raw();

	int get_fitness();
	void calculate_fitness();
	std::string get_gene();
	void manipulate_gene(int index, char manipulation);
	void mutate(int mutation_chance);

private:
	int _fitness;
	std::string _goal;
	std::string _gene;
	std::string _possible_characters;
	std::mt19937 random_number_generator;
	void generate_random_gene();

};

