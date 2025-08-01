# patient-portal-cli

A basic C++ command-line application to manage patient records. This project was built to demonstrate foundational C++ programming skills, including object-oriented design, input validation, and modular code organization.

---

## Features

- Add new patient records
- Automatically assign unique patient IDs
- View all stored patient records
- Search for a patient by ID
- Input validation for name, age, and gender
- Menu-driven interface

---

## Technologies Used

- C++ (Standard Library)
- Object-Oriented Programming (Classes, Encapsulation)
- Header file organization (`.h` and `.cpp`)
- Vectors (`std::vector`)
- Input validation using `<cctype>` and standard I/O

---

## Menu Example

---- Patient Portal Menu ----

1. Add New Patient
2. View All Patients
3. Search Patient by ID
4. Exit
Enter your choice: 

---

## How to Compile and Run

1. Clone the repository or download the source files.
2. Open a terminal in the project directory.
3. Compile the program:

   g++ main.cpp Patient.cpp -o PatientPortal

4. Run the program:

   ./PatientPortal

---

$ tree patient-portal-cli
patient-portal-cli
├── main.cpp
├── Patient.h
├── Patient.cpp
└── README.md


