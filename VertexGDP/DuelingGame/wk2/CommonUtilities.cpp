#include "CommonUtilities.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::numeric_limits;
using std::streamsize;


void AddIntToLastIndex(std::vector<int>& numbers, int IntToAdd)
{
	numbers.push_back(numbers.back() + IntToAdd);
}

void PrintVectorSize(const std::vector<int>& vector)
{
	std::cout << "PrintVectorSize() -> Size of vector is: " << vector.size() << std::endl;
}

int GetUserInt(string error_message)
{
	int user_value = 0;
	cin >> user_value;

	// Check if the input is valid
	while (!cin)
	{
		cin.clear(); // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		cout << "Invalid input. Please enter a valid " << error_message << " : ";
		cin >> user_value;
	}

	return user_value;
}
