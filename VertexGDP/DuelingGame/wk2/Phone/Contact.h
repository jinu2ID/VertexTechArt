#pragma once
#include <string>

using std::string;

class Contact
{
public:
	Contact(string Name, string PhoneNumber);

	const string& GetName() const { return Name; }
	const string& GetPhoneNumber() const { return PhoneNumber; }

	void SetName(const string& NewName) { Name = NewName; }
	void SetPhoneNumber(const string& NewPhoneNumber) { PhoneNumber = NewPhoneNumber; }

	void PrintContactInfo() const;

private:
	string Name;
	string PhoneNumber;
};

