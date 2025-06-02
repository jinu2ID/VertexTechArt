#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std; // So we don't have to keep writing std:: before every standard library function

float GetUserFloat(string error_message)
{
	float user_value = 0.0f;
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

int GetUserNameAndAge()
{
	string name = "";

	cout << "Please input your name" << endl;
	getline(cin, name);
	cout << "Thank you " << name << endl;

	int age = 0;
	cout << "Please input your age" << endl;
	age = GetUserInt("age");
	cout << "You are " << age << " years old" << endl;

	return 0;
}

void ConvertCelciusToFahrenheit()
{
	cout << "Please enter a temperature in Celcius: ";
	float celcius_temp = GetUserFloat("temperature in Celcius");
	float fahrenheit = (celcius_temp * 9.0f / 5.0f) + 32.0f;
	cout << celcius_temp << " Celsius is : " << fahrenheit << " Fahrenheit" << endl;
}

void ConvertKilometersToMiles()
{
	cout << "Please enter a distance in Kilometers: ";
	float kilometers = GetUserFloat("distance in Kilometers");
	float miles = kilometers * 0.621371f;
	cout << kilometers << " Kilometers is : " << miles << " Miles" << endl;
}

void ConvertPoundsToKilograms()
{
	cout << "Please enter a weight in Pounds: ";
	float pounds = GetUserFloat("weight in Pounds");
	float kilograms = pounds * 0.453592f;
	cout << pounds << " Pounds is : " << kilograms << " Kilograms" << endl;
}


void ConvertDollarsToEuros()
{
	cout << "Please enter an amount in Dollars: ";
	float dollars = GetUserFloat("amount in Dollars");
	float euros = dollars * 0.88f;
	cout << dollars << " Dollars is : " << euros << " Euros" << endl;
}

void CalculateAvgVector4()
{
	constexpr int vector_size = 4;
	vector<float> numbers(vector_size);

	for (int i = 0; i < vector_size; ++i)
	{
		cout << "Please enter a number " << (i + 1) << ": ";
		numbers[i] = GetUserFloat("number");
	}

	float sum = accumulate(numbers.begin(), numbers.end(), 0.0f); // default accumulate() operation is addition
	float average = sum / static_cast<float>(vector_size);

	cout << "The average of the entered numbers is: " << average << endl;
}

vector<int> GetUserVector5()
{
	constexpr int vector_size = 5;
	vector<int> numbers(vector_size);

	for (int i = 0; i < vector_size; ++i)
	{
		cout << "Please enter a number " << (i + 1) << ": ";
		numbers[i] = GetUserInt("interger");
	}

	return numbers;
}

void GetMinAndMax(vector<int> numbers)
{
	sort(numbers.begin(), numbers.end()); // Sort the vector to find min and max
	cout << "The smallest number is: " << numbers.front() << endl;
	cout << "The largest number is: " << numbers.back() << endl;
}

void SearchVector(vector<int> numbers)
{
	cout << "Please enter a number to search in the vector: ";
	int search_number = GetUserInt("number to search");
	if (find(numbers.begin(), numbers.end(), search_number) != numbers.end())
		cout << "The number " << search_number << " is in the vector." << endl;
	else
		cout << "The number " << search_number << " is not in the vector." << endl;
}

int main()
{
	//	1.  Ask for the name and age of a user-- - print to console
	GetUserNameAndAge();


	// 2.  Ask the user for a temperature in Celcius -- convert to Fh -- print to the console
	ConvertCelciusToFahrenheit();

	// 2b.  Km - Miles -- print to the console
	ConvertKilometersToMiles();
	
	// 2c.  Pounds - Kgs -- print to the console
	ConvertPoundsToKilograms();

	// 2d.  Dollar ammount - convert to Euros -- print to the console
	ConvertDollarsToEuros();


	/* 3. Create a vector of 4 float numbers
		a.Computer the average of the 4 numbers and print it.*/
	CalculateAvgVector4();

	
	// 4.  Ask the user to input 5 integers and store them in a vector(Do this one after week 2 !!)
	vector<int> user_numbers = GetUserVector5();

	// 4a.Print the sum of all the integers(acc***)
	cout << "The sum of the entered numbers is: " << accumulate(user_numbers.begin(), user_numbers.end(), 0) << endl;

	// 4b.Largest and Smallest number in the vector(*...)
	GetMinAndMax(user_numbers);

	// 4c.Ask the user for a number - search it to see if its in the vector()
	SearchVector(user_numbers);


	cout << "Press Enter to exit..." << endl;
	char end = cin.get(); // clear any new lines
	cin.get();

	return 0;
}