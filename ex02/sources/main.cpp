#include <iostream>
#include <Array.hpp>

#define MAX_VAL 10
int main(int, char**)
{
	// Array<int> numbers(MAX_VAL);
	// int* mirror = new int[MAX_VAL];
	// srand(time(NULL));
	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	const int value = i;
	// 	numbers[i] = value;
	// 	mirror[i] = value;
	// }

	// {
	// 	const Array<int> numbers(MAX_VAL);

	// 	try
	// 	{
	// 		std::cout << numbers[9] << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
	
	//SCOPE
	{
		Array<int> numbers(MAX_VAL);
		Array<int> tmp = numbers;
		// numbers[0] = 155;
		// Array<int> test(tmp);
		// test[0] = 0;
		// for (size_t i = 0; i < MAX_VAL; i++)
		// {
		// 	std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
		// 	std::cout << "test[" << i << "]: " << test[i] << std::endl;
		// }
	}

	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	if (mirror[i] != numbers[i])
	// 	{
	// 		std::cerr << "didn't save the same value!!" << std::endl;
	// 		return 1;
	// 	}
	// }
	// try
	// {
	// 	numbers[-2] = 0;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	numbers[MAX_VAL] = 0;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	numbers[i] = rand();
	// }
	// delete [] mirror;//
	return 0;
}