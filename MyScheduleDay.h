#pragma once
#include "MyUnit.h"
#include <chrono>

class MyScheduleDay : public MyUnit
{
private:
	char type;

public:
	// Constructor
	MyScheduleDay();
	~MyScheduleDay();

	// Setter
	void setType(const char newType);
	void reset();

	// Getter
	char getType() const;

	// Overload function
	friend ostream& operator<<(ostream& out, const MyScheduleDay& obj);
};

