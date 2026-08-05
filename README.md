# IntelliCharge - Predictive Electricity Billing System

IntelliCharge is a **predictive electricity billing system** developed using **C++** and **Java**. The project calculates electricity bills based on **customer type and unit consumption** and also predicts **future electricity usage**.

This system is designed to demonstrate **Object-Oriented Programming(OOP)** concepts, **file handling**, and **cross-language integration** between Java and C++ in a practical way.

---

## Project Objectives

- Calculate accurate electricity bills using different tariff models
- Allow user-defined customer type (Domestic, Commercial, Industrial)
- Predict next month electricity consumption
- Show a detailed and readable billing report
- Demonstrate real-world use of OOP concepts
- Integrate Java and C++ using file-based communication

---

## Key Features

- Supports multiple customer types
  - Domestic
  - Commercial
  - Industrial
- Unit-based bill calculation
- Bill breakdown includes
  - Energy charges
  - Fuel adjustment charges
  - Fixed charges
  - Tax
  - Total bill
- Usage prediction with trend and confidence
- Java executes C++ billing engine automatically
- Clean and structured output report

---

## Technologies Used

### C++

- Object-Oriented Programming
- Abstract classes and inheritance
- Polymorphism (tariff strategy)
- File handling
- Exception handling

### Java

- Object-Oriented Programming
- File I/O operations
- Process execution (running C++ executable)
- Controller-based architecture
- Console-based user interface

---

## Folder Structure

```text
IntelliCharge Predictive Electricity Billing System
│
├── cpp
│   ├── main.cpp # C++ main execution file
│   ├── User.h # User class (customer data)
│   ├── Charge.h # Abstract charge class + tariff types
│   ├── BillCalculator.h # Bill calculation logic
│   ├── Prediction.h # Usage prediction logic
│   └── FileHandler.h # Input/output file handling
│
├── java
│   └── com
│       └── intellicharge
│           ├── Main.java # Java entry point
│           ├── User.java # Java user model
│           ├── FileManager.java # File communication handler
│           └── SystemController.java # Controls Java-C++ workflow
│
├── data
│   ├── input.txt # Input file for C++ engine
│   └── output.txt # Generated billing report
│
├── bin
│   └── calculator.exe # Compiled C++ executable
│
└── README.md # Project documentation

```

## Sample Input

- Customer Name
- Current Month Units
- Previous Month Units
- Customer Type

## Sample Output

- Customer details
- Bill breakdown in PKR
- Total payable amount
- Usage prediction with trend and confidence

## Author Name

**Student Name Muhammad Jahanzaib Azhar**  
**Date 5 Aug,2026**
