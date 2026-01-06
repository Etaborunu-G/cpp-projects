# C++ Command-Line Calculator

A lightweight, interactive command-line calculator implemented in C++. This application performs basic arithmetic operations and allows continuous user interaction until the program is explicitly exited.

## Overview

This project demonstrates core C++ programming fundamentals through a clean and maintainable console application. The calculator accepts user input, evaluates arithmetic expressions, and safely handles common runtime errors.

The code is structured for clarity, readability, and extensibility, aligning with industry-standard best practices for beginner-level C++ applications.

## Features

- Interactive command-line interface
- Supported arithmetic operations:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
- Safe handling of division by zero
- Loop-based execution allowing multiple calculations per run
- Clear and user-friendly prompts

## Technologies Used

- Language: C++
- Standard Libraries:
  - iostream (input/output handling)
  - string (operation parsing)
  - cmath (included for future mathematical extensions)

## Program Flow

1. Prompt the user to enter the first number
2. Prompt the user to select an arithmetic operation
3. Prompt the user to enter the second number
4. Perform the requested calculation
5. Display the result
6. Ask the user whether to continue or exit
7. Repeat or terminate based on user input

## Example Execution

Enter first number: 8  
Enter Operation (+, -, *, /): *  
Enter second number: 5  
Result: 40  

Do you want to perform another calculation? (y/n): n  
Exiting calculator. Goodbye!

## Error Handling

- Division by zero is explicitly detected and prevented
- Invalid arithmetic operations produce informative error messages
- Unexpected continuation input results in a graceful program exit

## Build and Run Instructions

Compile the program using a C++ compiler such as g++:

g++ calculator.cpp -o calculator

Run the executable:

./calculator

Note: Replace calculator.cpp with the actual filename if different.

## Code Quality Considerations

- Clear and consistent variable naming
- Structured control flow using loops and conditionals
- Defensive programming practices
- Readable and maintainable code layout

## Potential Enhancements

- Input validation for non-numeric values
- Additional mathematical operations (power, modulus, square root)
- Refactoring arithmetic logic into dedicated functions
- Menu-based user interface
- Unit testing support

## License

This project is provided for educational and demonstrative purposes. You are free to modify, extend, and reuse the code as needed.

