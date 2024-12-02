#include "MyCalendar.h"


MyCalendar::MyCalendar()
{
    syncToSystemDate();
}

void MyCalendar::setCurrentYear(int newCurrentYear)
{
	currentYear = newCurrentYear;
}

void MyCalendar::setCurrentMonth(int newCurrentMonth)
{
	currentMonth = newCurrentMonth;
}

void MyCalendar::setCurrentDay(int newCurrentDay)
{
	currentDay = newCurrentDay;
}

int MyCalendar::getCurrentYear() const
{
	return currentYear;
}

int MyCalendar::getCurrentDay() const
{
	return currentDay;
}

int MyCalendar::getCurrentMonth() const
{
	return currentMonth;
}

void MyCalendar::printCurrentDate() const
{
    string date = "";
    string postfix;
    if (currentDay % 10 == 1)
        postfix = "st";
    else if (currentDay % 10 == 2)
        postfix = "nd";
    else if (currentDay % 10 == 3)
        postfix = "rd";
    else
        postfix = "th";
    cout << "\n\t" << MyCalendar::getDayInWeek(currentDay, currentMonth, currentYear) << ", " << months[currentMonth]<< " "<<currentDay << "th, " << currentYear
         << "\n\t" << currentMonth << "/" << currentDay << "/" << currentYear << "\n";
}

MyCalendar& MyCalendar::operator++()
{
    currentDay++;
    if (currentDay > getDaysInMonth(currentMonth, currentYear)) {
        currentDay = 1;
        currentMonth++;
        if (currentMonth == 12)
            currentYear++;
    }
    return *this;
}

MyCalendar MyCalendar::operator++(int)
{
    MyCalendar temp = *this;
    currentDay++;
    if (currentDay > getDaysInMonth(currentMonth, currentYear)) {
        currentDay = 1;
        currentMonth++;
        if (currentMonth == 12)
            currentYear++;
    }
    return temp;
}

MyCalendar& MyCalendar::operator--()
{
    currentDay--;
    if (currentDay < 1) {
        if (currentMonth == 1)
            currentYear--;
        currentMonth--;
        currentDay = getDaysInMonth(currentMonth, currentYear);
    }
    return *this;
}

MyCalendar MyCalendar::operator--(int)
{
    MyCalendar temp = *this;
    currentDay--;
    if (currentDay < 1) {
        if (currentMonth == 1)
            currentYear--;
        currentMonth--;
        currentDay = getDaysInMonth(currentMonth, currentYear);
    }
    return temp;
}

void MyCalendar::setCurrentYearMenu() {
    while (true) {
        system("cls");
        cout << "\tCurrent Year: " << currentYear << " - " << currentYear;
        cout << "\n\t" << string(60, char(205));

        cout << "\n\t1. Set current year";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to Main Menu";
        cout << "\n\t" << string(60, char(205));

        int option;
        option = inputInteger("\nOption: ", 0, 1);

        switch (option) {
        case 1: {
            int newYear = 0;
            newYear = inputInteger("\nSpecify a year: 0...9999: ", 0, 9999);
            setCurrentYear(newYear);
            cout << "\n\tCurrent year set to " << newYear << endl;
            break;
        }
        case 0: {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again!";
        }
        system("pause");
    }
}

void MyCalendar::setCurrentMonthMenu() {
    while (true) {
        system("cls");
        cout << "\tCurrent Month: " << currentMonth << " - " << currentMonth;
        cout << "\n\t" << string(60, char(205));

        cout << "\n\t1. Set current month";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to Main Menu";
        cout << "\n\t" << string(60, char(205));

        int option;
        cout << "\nOption: ";
        cin >> option;

        switch (option) {
        case 1: {
            currentMonth = inputInteger("\nSpecify a month (1...12) :", 1, 12);
            cout << "\n\tCurrent month set to " << currentMonth << endl;
            break;
        }
        case 0: {
            return;
        }
        default:
            cout << "\nInvalid option. Please try again.";
        }
        system("pause");
    }
}

void MyCalendar::setCurrentDayMenu() {
    while (true) {
        system("cls");
        cout << "\tCurrent Day: " << currentDay << " - " << currentDay;
        cout << "\n\t" << string(60, char(205));

        cout << "\n\t1. Set current Day";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return to Main Menu";
        cout << "\n\t" << string(60, char(205));

        int option;
        option = inputInteger("\nOption: ", 0, 1);
        switch (option) {
        case 1: {
            currentDay = inputInteger("\nEnter a Day (1...31)",0,31);;
            cout << "\n\tCurrent Day set to " << currentDay << endl;
            break;
        }
        case 0: {
            // Returning to the main menu
            return;
        }
        default:
            cout << "\nInvalid option. Please try again.";
        }
        system("pause");
    }
}

void MyCalendar::setCurrentCalendarMenu()
{
    while (true) {
        system("cls");
        printCurrentDate();
        cout << "\n\tMy Calendar Menu";
        cout << "\n";
        cout << "\n\t" << string(60, char(205));
        cout << "\n\t1. ++ (pre-increment)";
        cout << "\n\t2. ++ (post-increment)";
        cout << "\n\t3. Jump Forward(+n)";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t-1. -- (pre-decrement)";
        cout << "\n\t-2. -- (post-decrement)";
        cout << "\n\t-3. Jump Backward (-n)";
        cout << "\n\t" << string(60, char(196));
        cout << "\n\t0. Return";
        cout << "\n\t" << string(60, char(205));
        int option;
        option = inputInteger("\nOption: ", -3, 3);
        int daysJump = 0;
        switch (option) {
        case 1: {
            cout << "\n\tpre - increment : (++)\n\n";
            ++(*this);
            printCurrentDate();
        }
            break;
        case 2: {
            cout << "\n\tpost - increment : (++)\n\n";
            MyCalendar temp = (*this)++;
            temp.printCurrentDate();
        }
            break;
        case 3: {
            int daysJump = inputInteger("\n\tEnter an integer (n):", true);
            (*this).jumpForward(daysJump);
        }
            break;
        case -1:{
            cout << "\n\tpre - decrement : (--)\n\n";
            --(*this);
            printCurrentDate();
        }
            break;
        case -2:{
            cout << "\n\tpost - decrement : (--)\n\n";
            MyCalendar temp = (*this)--;
            temp.printCurrentDate();
        }
        case -3: {
            int daysJump = inputInteger("\n\tEnter an integer (n):", true);
            (*this).jumpBackward(daysJump);
        }
            break;
        case 0:
            return;
        default:
            cout << "\nInvalid option. Please try again.\n";
        }
        system("pause");
    }
}

void MyCalendar::setScheduleDateMenu()
{
    MyScheduleDay currentScheduleDay;
    int tempMonth = currentMonth;
    int tempDay = currentDay;
    while (true) {
        system("cls");
        cout << "\n\tmonth       : " << months[tempMonth];
        cout << "\n\tday         : " << tempDay;
        cout << "\n\ttype        : " << currentScheduleDay.getType();
        cout << "\n\tdescription : " << currentScheduleDay.getDescription();
        cout << "\n";
        cout << "\n\tSchedule Date";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t1. Schedule a date";
        cout << "\n\t2. Unschedule a date";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t3. display year schedules";
        cout << "\n\t4. display month schedules";
        cout << "\n\t5. display day schedule";
        cout << "\n\t0. return";
        cout << "\n\t" << string(80, char(205));
        cout << "\nOption: ";
        
        switch (inputInteger("\nEnter an integer: ", 0, 5))
        {
        case 0:
            return;

        case 1: {
            tempMonth = inputInteger("\nSpecify a month (1...12) :", 1, 12);
            tempDay = inputInteger("\nSpecify a day (1...31) :", 1, 31);
            string tempDescription = inputString("\nEnter description: ", true);    
            currentScheduleDay.setDescription(tempDescription);
            string options = "RAHP";
            char newType = inputChar("\nSpecify a type (R-return, A-Awareness H-holiday or P-personal) :", options);
            currentScheduleDay.setType(newType);
            if (scheduleDays[currentMonth][currentDay].getValue() == 1) {
                cout << "\nWARNING: overwrite the existing scheduled date to \"Personal\"";
            }
            else
                currentScheduleDay.setValue(1);
            scheduleDays[tempMonth-1][tempDay-1] = currentScheduleDay;
            cout << "\nSUCCESS: Date has successfully been scheduled.";
            cout << scheduleDays[tempMonth-1][tempDay-1];
        }
            break;
        case 2: {
            tempMonth = inputInteger("\nSpecify a month (1...12) :", 1, 12);
            tempDay = inputInteger("\nSpecify a day (1...31) :", 1, 31);
            scheduleDays[tempMonth-1][tempDay-1] = MyScheduleDay();
            cout << "\nSUCCESS: Date has successfully been unscheduled.";
        }
            break;
        case 3: {
            for (int monthIndex = 0; monthIndex < 12;monthIndex++) {
                cout << '\n' << left <<setw(10)<<months[monthIndex + 1] << ": ";
                bool isMonthScheduled = false;
                for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
                    if (scheduleDays[monthIndex][dayIndex].getType() != 'U') {
                        cout << '\n' << dayIndex + 1 << " - " << scheduleDays[monthIndex][dayIndex].getDescription();
                        isMonthScheduled = true;
                    }                 
                }
                if (!isMonthScheduled)
                    cout << "No scheduled dates for the month.";
            }
        }
              break;
        case 4: {
            int inMonth = inputInteger("\nSpecify a month (1...12) :", 1, 12);
            cout << '\n' << left << setw(10) << months[inMonth] << ": ";
            bool isMonthScheduled = false;
            for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
                if (scheduleDays[inMonth - 1][dayIndex].getType() != 'U') {
                    cout << '\n' << dayIndex << " - " << scheduleDays[inMonth -1][dayIndex].getDescription();
                    isMonthScheduled = true;
                }
            }
            if (!isMonthScheduled)
                cout << "No scheduled dates for the month.";
        }
            break;
        case 5: {
            int inMonth = inputInteger("\nSpecify a month (1...12) :", 1, 12);
            int inDay = inputInteger("\nSpecify a day (1...31) :", 1, 31);
            bool isDayScheduled = false;
            if (scheduleDays[inMonth - 1][inDay - 1].getType() != 'U') {
                cout << '\n' << inDay << " - " << scheduleDays[inMonth - 1][inDay - 1].getDescription();
                isDayScheduled = true;
            }
            if (!isDayScheduled)
                cout << months[inMonth] << " - " << inDay << ": No schedule for the date.";
        }
            break;
        default:
            break;
        }
        
        cout << "\n";
        system("pause");
    }
}

void MyCalendar::jumpForward(int daysJump)
{
    while ((daysJump + currentDay) > getDaysInMonth(currentMonth, currentYear)) {
        int tempDaysJump = getDaysInMonth(currentMonth, currentYear) - currentDay;
        currentDay = 0;
        currentMonth++;
        if (currentMonth > 12) {
            currentMonth = 1;
            currentYear++;
        }
        daysJump -= tempDaysJump;
    }
    currentDay += daysJump;
}

void MyCalendar::jumpBackward(int daysJump)
{
    while ((currentDay - daysJump) < 0){
        int tempDaysJump = currentDay;
        currentMonth--;
        currentDay = getDaysInMonth(currentMonth, currentYear);
        if (currentMonth < 1) {
            currentMonth = 12;
            currentYear--;
        }
        daysJump -= tempDaysJump;
    }
    currentDay -= daysJump;
}
void MyCalendar::saveToFile() const {
    string filename = to_string(currentYear) + ".DAT";
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for writing.\n";
        return;
    }

    // Save current date and other relevant information to the DAT file
    outFile.write(reinterpret_cast<const char*>(&currentYear), sizeof(currentYear));
    outFile.write(reinterpret_cast<const char*>(&currentMonth), sizeof(currentMonth));
    outFile.write(reinterpret_cast<const char*>(&currentDay), sizeof(currentDay));

    // Save other relevant information to the file if needed
    outFile.close();
    std::cout << "Calendar saved to "<<  currentYear << ".DAT file successfully.\n";
}
void MyCalendar::restoreFromFile() {
    std::string filename = inputString("\nEnter the filename to restore from : ", false);
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for reading.\n";
        return;
    }

    // Read data from the DAT file and update the calendar
    inFile.read(reinterpret_cast<char*>(&currentYear), sizeof(currentYear));
    inFile.read(reinterpret_cast<char*>(&currentMonth), sizeof(currentMonth));
    inFile.read(reinterpret_cast<char*>(&currentDay), sizeof(currentDay));

    // Read other relevant information from the file if needed

    inFile.close();
    std::cout << "Calendar restored from "<< filename <<"DAT file successfully.\n";
}

void MyCalendar::syncToSystemDate() {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm currentTimeStruct;
    localtime_s(&currentTimeStruct, &currentTimeT);

    // Update the currentYear, currentMonth, and currentDay based on the system date
    currentYear = currentTimeStruct.tm_year + 1900;
    currentMonth = currentTimeStruct.tm_mon + 1;
    currentDay = currentTimeStruct.tm_mday;
}
ostream& operator<<(ostream& out, const MyCalendar& obj)
{
    string daysInWeek[7] = { "Monday", "Tuesday","Wednesday","Thursday", "Friday","Saturday","Sunday" };
    int dayInWeekNum = MyCalendar::getDayInWeek(obj.currentDay, obj.currentMonth, obj.currentYear);
    
    string leap = "";
    if (MyCalendar::isLeap(obj.getCurrentYear())) {
        leap = " - (leap)";
    }
    else
        leap = " - (non - leap)";
    string awarenessMonthStr = MyCalendar::getAwarenessMonth(obj.getCurrentMonth()) + " Month";
    string currentMonthStr = to_string(obj.currentMonth) + " - " + MyCalendar::getMonthString(obj.getCurrentMonth());
    string currentYearStr = to_string(obj.currentYear) + leap;
    string currentDayStr = to_string(obj.currentDay) + " - " + daysInWeek[dayInWeekNum];

    out << "\n\t" << char(218) << string(84, char(196)) << char(191);
    out << "\n\t" << char(179) << left << " Current year : " << setw(21)<< currentYearStr << setw(47) << ' ' << char(179);
    out << "\n\t" << char(195) << string(84, char(196)) << char(180);
    out << "\n\t" << char(179) << setw(15) << " Current month: " << setw(21) << currentMonthStr << setw(47) << ' ' << char(179);
    out << "\n\t" << char(179) << setw(15) << " Awareness    : " << setw(21) << awarenessMonthStr << setw(47)<< ' ' << char(179);
    out << "\n\t" << char(195) << string(84, char(196)) << char(180);
    out << "\n\t" << char(179) << setw(15) << " Current day  : " << setw(21) << currentDayStr << setw(47)  << ' ' << char(179);
    out << "\n\t" << char(179) <<"              : unscheduled" << string(57, ' ') << char(179);
    out << "\n\t" << char(195) << string(84, char(196)) << char(180);
    out << "\n\t" << char(179) << format("{:^11}{}{:^11}{}{:^11}{}{:^11}{}{:^11}{}{:^11}{}{:^11}{}",
        "Sunday",char(179), "Monday", char(179), "Tuesday", char(179), "Wednesday", char(179), "Thursday", char(179), "Friday", char(179), "  Saturday  ", char(179));
    out << "\n\t" << char(195) << string(84, char(196));

    int firstDayInMonth = MyCalendar::getDayInWeek(1, obj.getCurrentMonth(), obj.getCurrentYear());
    int daysInCurrentMonth = MyCalendar::getDaysInMonth(obj.getCurrentMonth(), obj.getCurrentYear());
    int currentDay = 1;
    int count = 0;
    while (currentDay <= daysInCurrentMonth) {
        for (int i = 0; i < 7; i++) {
            if ((count % 7) == 0) {
                out << char(179) << "\n\t" << char(179);
            }
            if (count <= firstDayInMonth) {
                out << setw(12) << " ";
            }
            else if (count <= firstDayInMonth + daysInCurrentMonth) {
                out << internal << setw(7) << currentDay << setw(5) << " ";
                currentDay++;
            }
            else {
                out << setw(12) << " ";
            }
            count++;
        }
    }
    out << char(179);
    out << "\n\t" << char(195) << string(84, char(196)) << char(180);
    return out;
}

bool MyCalendar::isLeap(const unsigned short year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

string MyCalendar::getMonthString(const int month) {
    const std::string months[13] = { "unknown", "January", "February", "March",
                                    "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return months[month];
}

string MyCalendar::getAwarenessMonth(const int month) {
    const std::string awanessMonths[13] = { "Unknown", "Thyroid", "Heart Failure", "Multiple Sclerosis", "Oral Cancer", "Mental Health"
    , "Migrane and Headache", "Juvenile Arthrisis", "Immunization", "Ovarian Cancer", "Breast Cancer", "Lung Cancer", "HIV Aids"};
    return awanessMonths[month];
}

int MyCalendar::getDaysInMonth(const int monthNumber, const int year)
{
    const int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (monthNumber == 2 && isLeap(year)) {
        return 29;
    }
    return daysInMonth[monthNumber];
}

int MyCalendar::getDayInWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1) / 5) + K + (K / 4) + (J / 4) - 2 * J) % 7;
    int weekDay  = (h + 5) % 7;
    return weekDay;

}