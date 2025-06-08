#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Contact.h"

using std::string;
using std::vector;
using std::unordered_map;

class Phone
{

public:
	Phone(std::string Name, int SerialNumber);

	const int GetSerialNumber() const { return SerialNumber; }
	void SetSerialNumber(int NewSerialNumber) { SerialNumber = NewSerialNumber; }
	void PrintInformation() const;
	void PrintBatteryLife() const;
	float GetBatteryLife() const;
	
	void ChargeBattery(int charge);
	void SetFactoryDefaults(float DefaultBatteryLife, float DefaultTemperature);
	void TakePicture() const;
	void MakeCall(const std::string& ContactName);

	void AddContact(const Contact& NewContact) { ContactMap.insert({ NewContact.GetName(), NewContact }); }
	void AddContacts(const vector<Contact>& NewContacts);
	void RemoveContact(const std::string& ContactName);
	void PrintContacts() const;
	
private:
	std::string Name;
	int SerialNumber;
	float BatteryLife;
	float InternalTemperature;
	vector<Contact> Contacts;
	unordered_map<std::string, Contact> ContactMap;
};

