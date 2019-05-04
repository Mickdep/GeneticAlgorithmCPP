#include "individual_raw.h"

individual_raw::individual_raw(std::string goal)
{
	_fitness = 0;
	_goal = goal;
	random_number_generator.seed(std::random_device()());
	_possible_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	generate_random_gene();
}

individual_raw::~individual_raw()
{
}

int individual_raw::get_fitness()
{
	return _fitness;
}

void individual_raw::calculate_fitness()
{
	_fitness = 0;
	for (int i = 0; i < _goal.length(); i++) {
		if (_gene[i] == _goal[i]) {
			_fitness++;
		}
	}
}

std::string individual_raw::get_gene()
{
	return _gene;
}

void individual_raw::manipulate_gene(int index, char manipulation)
{
	_gene[index] = manipulation;
}

//Mutates the gene.
//1: Generate random number 0-100
//2: Check if mutation chance is met
//3: Manipulate a random character in the gene
void individual_raw::mutate(int mutation_chance)
{
	std::uniform_int_distribution<std::mt19937::result_type> random_precentage(0, 100);
	std::uniform_int_distribution<std::mt19937::result_type> random_character_index(0, _possible_characters.size() - 1);
	for (int i = 0; i < _goal.length(); i++) {
		if (random_precentage(random_number_generator) <= mutation_chance) {
			auto random_character = _possible_characters[random_character_index(random_number_generator)];
			manipulate_gene(i, random_character);
		}
	}
}

//Generates a random gene by picking a random number from the available characters
void individual_raw::generate_random_gene()
{
	std::uniform_int_distribution<std::mt19937::result_type> random_distribution(0, _possible_characters.size() - 1);
	for (int i = 0; i < _goal.length(); i++) {
		auto random_character = _possible_characters[random_distribution(random_number_generator)];
		_gene += random_character;
	}
}
