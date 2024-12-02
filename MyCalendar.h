#pragma once
#include "MyScheduleDay.h"
#include <iostream>
#include "input.h"
#include <iomanip>
#include <fstream>
#include <format>
#include <chrono>

class MyCalendar
{
	const string months[13] = { "unknown", "January", "February", "March" ,
"April", "May", "June", "July", "August", "September", "October" ,"November",
"December" };
private:
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;
	MyScheduleDay scheduleDays[12][31];
public:
	//Constructor
	MyCalendar();

	// setters
	void setCurrentYear(int newCurrentYear);
	void setCurrentMonth(int newCurrentMonth);
	void setCurrentDay(int newCurrentDay);
	void setCurrentYearMenu();
	void setCurrentMonthMenu();
	void setCurrentDayMenu();
	void setCurrentCalendarMenu();
	void setScheduleDateMenu();
	void jumpForward(int daysJump);
	void jumpBackward(int daysJump);
	void saveToFile() const;
	void restoreFromFile();
	void syncToSystemDate();

	//getters
	int getCurrentYear()const;
	int getCurrentDay() const;
	int getCurrentMonth() const;
	void printCurrentDate() const;

	//overload functions
	MyCalendar& operator++();
	MyCalendar operator++(int);
	MyCalendar& operator--();
	MyCalendar operator--(int);

	friend ostream& operator<<(ostream&, const MyCalendar& obj);

	// static functions

	static bool isLeap(const unsigned short year);
	static int getDaysInMonth(const int monthNumber, const int year);
	static int getDayInWeek(int day, int month, int year);
	static string getMonthString(const int month);
	static string getAwarenessMonth(const int month);

};


