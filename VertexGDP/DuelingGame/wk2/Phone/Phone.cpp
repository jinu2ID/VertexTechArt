#include <iostream>
#include "Phone.h"

using std::cout;
using std::endl;

Phone::Phone(std::string Name, int SerialNumber) : Name(Name), SerialNumber(SerialNumber), BatteryLife(15), InternalTemperature(30.0) {}

void Phone::PrintInformation() const
{
	cout << "This is a: " << Name << endl;
	cout << "Serial Number is: " << SerialNumber << endl;
	cout << "Temperature is: " << InternalTemperature << endl;
}

void Phone::PrintBatteryLife() const
{
	cout << Name << " Battery: " << BatteryLife << "%" << endl;
}

void Phone::TakePicture() const
{
	cout << Name << ": "  << "Click" << endl;
}

void Phone::SetFactoryDefaults(float DefaultBatteryLife, float DefaultTemperature)
{
	BatteryLife = DefaultBatteryLife;
	InternalTemperature = DefaultTemperature;

}

float Phone::GetBatteryLife() const { return BatteryLife; };

void Phone::ChargeBattery(int charge)
{
	if (BatteryLife + charge > 100)
	{
		cout << Name << ": " << "Battery is fully charged!" << endl;
		BatteryLife = 100;
	}
	else
	{
		cout << Name << ": " << "Charging battery by " << charge << "%" << endl;
		BatteryLife += charge;
	}
}

void Phone::MakeCall(const string &ContactName)
{
	if (BatteryLife < 5)
	{
		cout << Name << ": " << "Low battery, please charge!" << endl;
	}
	else
	{
		if (ContactMap.find(ContactName) == ContactMap.end())
		{
			cout << Name << ": " << "Contact not found: " << ContactName << endl;
			return;
		}

		cout << Name << ": " << "Calling " << ContactName << "..." << endl;
		BatteryLife -= 5;
	}
}

void Phone::PrintContacts() const {
	cout << Name << ": " << "Contacts List:" << endl;
	for (const auto& contact : ContactMap) {
		contact.second.PrintContactInfo();
	}
	if (ContactMap.empty()) {
		cout << Name << ": " << "No contacts available." << endl;
	}
	else {
		cout << Name << ": " << "Total contacts: " << ContactMap.size() << endl;
	}
}

void Phone::AddContacts(const vector<Contact>& NewContacts) {
	for (const auto& contact : NewContacts) {
		ContactMap.insert({ contact.GetName(), contact });
	}
}

void Phone::RemoveContact(const std::string& ContactName)
{
	auto it = ContactMap.find(ContactName);
	if (it != ContactMap.end()) {
		ContactMap.erase(it);
		cout << Name << ": " << "Removed contact: " << ContactName << endl;
	}
	else {
		cout << Name << ": " << "Contact not found: " << ContactName << endl;
	}
}