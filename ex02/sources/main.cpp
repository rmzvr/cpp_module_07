#include <iostream>
#include <string>
#include <Array.hpp>

#define MAX_VAL 750

void test_int_array()
{
	std::cout << "--- Testing Array<int> ---" << std::endl;
	// Test parameterized constructor and size
	Array<int> numbers(MAX_VAL);
	std::cout << "Created an array of " << numbers.size() << " integers." << std::endl;

	// Test default initialization (should be 0)
	std::cout << "Default values:" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Test writing to the array
	int* mirror = new int[MAX_VAL];
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = i * 2;
		numbers[i] = value;
		mirror[i] = value;
	}

	// Test reading from the array
	std::cout << "Values after writing:" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Test copy constructor and assignment operator
	{
		std::cout << "--- Testing copy constructor and assignment ---" << std::endl;
		Array<int> tmp = numbers; // Copy constructor
		Array<int> test(tmp);     // Copy constructor

		// Modify the copy
		tmp[0] = 100;
		test[1] = 200;

		std::cout << "Original array [0]: " << numbers[0] << std::endl;
		std::cout << "Tmp copy [0]: " << tmp[0] << std::endl;
		std::cout << "Original array [1]: " << numbers[1] << std::endl;
		std::cout << "Test copy [1]: " << test[1] << std::endl;

		Array<int> assigned_arr;
		assigned_arr = numbers; // Assignment operator
		assigned_arr[2] = 300;
		std::cout << "Original array [2]: " << numbers[2] << std::endl;
		std::cout << "Assigned copy [2]: " << assigned_arr[2] << std::endl;
		std::cout << "--- End of copy tests ---" << std::endl;
	}

	// Check that original array is unchanged
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "Original array was modified by a copy!" << std::endl;
			break;
		}
	}

	// Test out-of-bounds access
	std::cout << "--- Testing out-of-bounds access ---" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "numbers[-2]: " << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "numbers[MAX_VAL]: " << e.what() << '\n';
	}
	std::cout << "--- End of out-of-bounds tests ---" << std::endl;

	delete [] mirror;
}

void test_empty_array()
{
	std::cout << "\n--- Testing empty Array ---" << std::endl;
	Array<int> empty_array;
	std::cout << "Size of empty array: " << empty_array.size() << std::endl;
	try
	{
		std::cout << "Accessing empty_array[0]" << std::endl;
		empty_array[0] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test_const_array()
{
	std::cout << "\n--- Testing const Array ---" << std::endl;
	Array<int> numbers(3);
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;

	const Array<int> const_numbers(numbers);
	std::cout << "Const array elements: ";
	for (size_t i = 0; i < const_numbers.size(); ++i)
	{
		std::cout << const_numbers[i] << " ";
	}
	std::cout << std::endl;

	// The following line would cause a compilation error:
	// const_numbers[0] = 5;
}

void test_string_array()
{
	std::cout << "\n--- Testing Array<std::string> ---" << std::endl;
	Array<std::string> str_array(3);
	str_array[0] = "Hello";
	str_array[1] = "World";
	str_array[2] = "!";

	std::cout << "String array elements: ";
	for (size_t i = 0; i < str_array.size(); ++i)
	{
		std::cout << str_array[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> str_array_copy = str_array;
	str_array_copy[0] = "Goodbye";
	std::cout << "Original: " << str_array[0] << ", Copy: " << str_array_copy[0] << std::endl;
}

int main(int, char**)
{
	test_int_array();
	test_empty_array();
	test_const_array();
	test_string_array();

	return 0;
}
