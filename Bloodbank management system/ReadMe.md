# Blood Bank Management System (C++)

A simple console-based **Blood Bank Management System** written in **C++** using basic OOP concepts (classes, objects, arrays, and menus).  
It supports adding donors and hospitals, storing donated blood packets, requesting blood packets, and displaying available stock.

---

## Features

### ✅ Authentication
- Login required to access the system.
- Limited to **3 attempts** before the program exits.

### ✅ Donor Management
- Add donors (name, contact, fitness status, blood group, rhesus factor).
- Update donor details:
  - Fitness status
  - Contact number

### ✅ Hospital Management
- Add hospitals with a generated Hospital ID.
- Hospitals can request blood packets and confirm payment.

### ✅ Blood Packet Handling
- Donors can donate blood if they are **fit**.
- Donated blood is stored based on:
  - Blood type (A, B, O, AB)
  - Rhesus (+ / -)
- Hospitals can request blood packets.
- On successful availability:
  - cost is shown
  - packet is removed from inventory

### ✅ Inventory Display
Shows total available blood packets and count by type:
- A+, A-, B+, B-, O+, O-, AB+, AB-

---

## How the Program Works

### 1. Login
The program prompts:
- username
- password

If credentials match, it opens the main menu.

### 2. Main Menu Options
1. Add Donor  
2. Update Donor Details  
3. Add Hospital  
4. Donate Blood  
5. Request Blood  
6. Display Available Blood Packets  
7. Exit  

---

## Blood Type Representation

Internally the program stores blood types as:
- `'A'` = A
- `'B'` = B
- `'O'` = O
- `'X'` = AB (used because AB is 2 characters)

Rhesus factor:
- `'+'` for positive
- `'-'` for negative

---

## Inventory Storage

Blood packets are stored in a fixed array of 24 slots:

| Blood Type | Slots |
|----------|------|
| A+ | 0–2 |
| A- | 3–5 |
| B+ | 6–8 |
| B- | 9–11 |
| O+ | 12–14 |
| O- | 15–17 |
| AB+ | 18–20 |
| AB- | 21–23 |

Empty slot is identified using:
- `expiry == 2017` (default sentinel value)

---

## Requirements

- C++ compiler (g++, clang++, or MSVC)
- Works on Windows / Linux / Mac

---

## How to Compile and Run

### ✅ Using g++
```bash
g++ main.cpp -o bloodbank
./bloodbank
