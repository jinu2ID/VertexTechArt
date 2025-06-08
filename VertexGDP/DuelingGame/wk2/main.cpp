#include <vector>
#include <iostream>
#include "Phone.h"
#include "CommonUtilities.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Phone Iphone("Iphone16", 8382123);
	Phone Galaxy("Samsung Galaxy 15", 112344);

	vector<Phone> Phones = { Iphone, Galaxy };

	for (const Phone& phone : Phones)
	{
		phone.PrintInformation();
		phone.PrintBatteryLife();
		cout << endl;
	}

	vector<Contact> Contacts = {
		Contact("John", "555-123-4567"),
		Contact("Sharif", "555-987-6543"),
		Contact("Alice", "555-555-5555")
	};

	Iphone.AddContacts(Contacts);
	Iphone.PrintContacts();
	cout << endl;
	Iphone.MakeCall("John");
	Iphone.MakeCall("Lu"); // Contact not found

	Galaxy.SetFactoryDefaults(1, 43);
	Galaxy.AddContacts(Contacts);
	Galaxy.PrintBatteryLife();
	Galaxy.MakeCall("Sharif"); // Not enough battery
	cout << endl;

	while (Galaxy.GetBatteryLife() < 50)
	{
		Galaxy.ChargeBattery(10);
		Galaxy.PrintBatteryLife();
	}
	cout << endl;

	Galaxy.MakeCall("Sharif");
	cout << endl;

	cout << "Galaxy Old Serial Number: " << Galaxy.GetSerialNumber() << endl;
	cout << "Please enter a new serial number for the Galaxy phone: ";
	int new_serial_number = GetUserInt("serial number");
	Galaxy.SetSerialNumber(new_serial_number);
	cout << "Galaxy New Serial Number: " << Galaxy.GetSerialNumber() << endl << endl;

	Iphone.TakePicture();

	return 0;
}

