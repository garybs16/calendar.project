#pragma once
#include <iostream>
using namespace std;

class MyUnit
{
private:
	unsigned short value;
	char description[100];
public:
	//Constructor
	MyUnit();
	//Setters
	void setValue(const int newValue);
	void setDescription(const string newDescription);

	//Getters
	int getValue() const;
	string getDescription() const;

	// Overload function
	friend ostream& operator<<(ostream&, const MyUnit&);
};

