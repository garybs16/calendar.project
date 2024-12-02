#include "MyUnit.h"

// Preconditions : None
// Postconditions: an instance of 'MyUnit' is created with default 'value' and 'description'
MyUnit::MyUnit()
{
	value = 0;
	strncpy_s(description, "Unscheduled", 99);
}

// Preconditions : 'newValue' is a valid integer
// Postconditions: sets the 'value' to 'newValue'
void MyUnit::setValue(const int newValue)
{
	value = newValue;
}

// Preconditions : 'newDescription' is a valid string
// Postconditions: sets the 'description' to the 'newDescription' value
void MyUnit::setDescription(const string newDescription)
{
	strcpy_s(description, newDescription.c_str());
}

// Preconditions : None
// Postconditions: return the value of 'value'
int MyUnit::getValue() const
{
	return value;
}

// Preconditions : None
// Postconditions: return the value of 'description'
string MyUnit::getDescription() const
{
	return string(description);
}

// 
ostream& operator<<(ostream& out, const MyUnit& obj)
{
	out << "\nValue: " << obj.getValue();
	out << "\nDescription: " << obj.getDescription();
	return out;
}
