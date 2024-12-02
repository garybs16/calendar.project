#include "MyScheduleDay.h"

// Preconditions: None.
// Postconditions: Initializes the 'type' member variable to a blank space (' ').
MyScheduleDay::MyScheduleDay(): MyUnit()
{
	type = 'U';
}

MyScheduleDay::~MyScheduleDay()
{
}

// Preconditions: 'newType' should be a valid character.
// Postconditions: Sets the 'type' member variable to the value of 'newType'.
void MyScheduleDay::setType(const char newType)
{
	type = newType;
}

void MyScheduleDay::reset()
{
	MyScheduleDay temp;
	*this = temp;
}


// Preconditions: None.
// Postconditions: Returns the current value of the 'type' member variable.
char MyScheduleDay::getType() const
{
	return type;
}

// Preconditions: None.
// Postconditions: Writes information about the object.
ostream& operator<<(ostream& out, const MyScheduleDay& obj)
{
	out << static_cast<MyUnit>(obj);
	out << "\nType: " << obj.getType() << endl;
	return out;
}
