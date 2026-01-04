# Login and Registration System (C++)

## 📌 Overview
This project is a basic Login and Registration System written in C++.  
It demonstrates fundamental concepts such as file handling, user input validation, and menu-driven program flow.

The program allows users to:
- Register with a username and password
- Store credentials in a text file
- Navigate through a simple console menu

---

## 🛠️ Features
- Console-based user interface
- Username and password registration
- Password confirmation validation
- File creation for each registered user
- Menu system with input handling
- Basic error handling for invalid inputs

---

## 📂 How It Works
- When a user registers, they enter a username and password.
- The password is saved to a text file named after the username  
  (e.g., `username.txt`).
- The system confirms user inputs before saving.
- The program loops back to the main menu after registration.

⚠️ Note: The login functionality is currently a placeholder and not fully implemented.

---

## 🧪 Example File Output
If the username is `john`, the program creates:

john.txt

Containing:
password123

---

## ▶️ How to Compile and Run
Use a standard C++ compiler such as g++:

g++ main.cpp -o login_system  
./login_system

---

## 📚 Concepts Used
- C++ Standard Library (`<iostream>`, `<fstream>`, `<string>`)
- File input/output
- Functions and global variables
- Input validation (`cin.fail()`)
- Recursion for retry logic
- Menu-driven program structure

---

## 🚧 Limitations
- Passwords are stored in plain text (not secure)
- No actual login authentication logic
- No input masking for passwords
- Uses global variables (not ideal for large projects)

---

## 🔮 Future Improvements
- Implement real login verification
- Hash and salt passwords
- Replace recursion with loops for better control
- Use classes for better structure
- Improve input security and validation

---

## 📄 License
This project is for educational purposes and learning C++ fundamentals.
