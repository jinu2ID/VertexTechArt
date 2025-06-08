#include "Contact.h"
#include <iostream>

using std::cout;
using std::endl;

Contact::Contact(std::string Name, std::string PhoneNumber)
	: Name(Name), PhoneNumber(PhoneNumber) {
}

void Contact::PrintContactInfo() const {
	cout << "Name: " << Name << endl;
	cout << "Phone Number: " << PhoneNumber << endl;
}
