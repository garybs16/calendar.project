# 📅 Calendar & Scheduling Program — C++

A console-based **calendar and schedule management system** built in **C++**.  
This program allows users to create, view, and manage scheduled events for specific days using a simple, structured interface.

---

## 📜 Overview

This project is designed to handle:
- A **calendar** with month/day navigation
- **Daily schedules** for storing multiple events
- **Units (events)** with details such as description, time, etc.
- Input handling with validation

The codebase is modular, making it easy to extend for more complex scheduling needs.

---

## 🖥 Features

- **Create and store events** for specific days  
- **View daily schedules** and all planned events  
- **Navigate between days/months** within the calendar  
- **Input validation** to prevent invalid dates or times  
- **Object-Oriented Design** with separate classes for:
  - Calendar management
  - Daily schedules
  - Event units

---

## 📂 Project Structure

calendar.project-main/
│
├── main.cpp # Program entry point
├── MyCalendar.cpp/.h # Calendar class: month/day handling
├── MyScheduleDay.cpp/.h # Day schedule class: holds events for one day
├── MyUnit.cpp/.h # Unit class: represents an event/task
├── input.h # Input handling utilities
│
├── EXAM2.vcxproj # Visual Studio project file
├── EXAM2.vcxproj.filters # VS filter settings
└── EXAM2.vcxproj.user # VS user settings



## 🛠 Requirements

- **Compiler:** Visual Studio (MSVC) or any modern C++ compiler supporting C++11+
- **OS:** Windows (project uses Visual Studio solution files)
- **Build System:** MSBuild or Visual Studio IDE

---

## ▶️ How to Build & Run

### Using Visual Studio
1. Open `EXAM2.vcxproj` in Visual Studio.
2. Select **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run the program from **Debug → Start Without Debugging** (`Ctrl+F5`).

### Using Command Line (MSVC)
```bash
cl main.cpp MyCalendar.cpp MyScheduleDay.cpp MyUnit.cpp
