#include <iostream>
#include <random>
#include <cstdio>

int roll_dice(const int number_faces)
{
	std::random_device random_device;
	std::default_random_engine random_engine(random_device());
	std::uniform_int_distribution<int> uniform_int_distribution(1, number_faces);

	auto random_int = uniform_int_distribution(random_engine);
	return random_int;
}

int main(int argc, char* argv[])
{
	int number_faces = 6;
	int number_rolls = 10;

	std::cout << "Enter the number of faces: ";
	std::cin >> number_faces;

	std::cout << std::endl;

	std::cout << "Enter the number of times to roll: ";
	std::cin >> number_rolls;
	printf("Rolling dice %d times.\n", number_rolls);
	auto sum = 0;
	auto min_roll = 10000000;
	auto max_roll = -10000000;
	for(auto i = 0; i < number_rolls; i ++)
	{
		auto random_int = roll_dice(number_faces);
		sum += random_int;
		printf("You rolled a %d\n", random_int);
		if (random_int < min_roll) min_roll = random_int;
		if (random_int > max_roll) max_roll = random_int;
	}

	auto average = (double) sum / 10.0;
	printf("Your average roll was %f\n", average);
	printf("You min roll was %d and your max %d\n", min_roll, max_roll);
	return 0;
}
