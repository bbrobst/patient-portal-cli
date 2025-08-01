#include <iostream>
#include <vector>
#include <limits>
#include <cctype> // std::isalpha, std::isdigit
#include "Patient.h"

std::vector<Patient> patients;

// Check if string contains letters and spaces only
bool isLetterOnly(const std::string& input) {
    for (char c : input) {
        if (!std::isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Check if string is a positive integer
bool isPositiveInteger(const std::string& input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

void createPatient() {
    char choice;
    do {
        std::string name, gender, ageInput;
        int age;

        // Input validated name
        while (true) {
            std::cout << "Enter patient name: ";
            std::getline(std::cin, name);
            if (isLetterOnly(name)) break;
            std::cout << "Invalid input. Name must contain letters only.\n";
        }

        // Input validated age
        while (true) {
            std::cout << "Enter patient age: ";
            std::getline(std::cin, ageInput);
            if (isPositiveInteger(ageInput)) {
                age = std::stoi(ageInput);
                break;
            }
            std::cout << "Invalid input. Age must be a positive number.\n";
        }

        // Input validated gender
        while (true) {
            std::cout << "Enter patient gender: ";
            std::getline(std::cin, gender);
            if (isLetterOnly(gender)) break;
            std::cout << "Invalid input. Gender must contain letters only.\n";
        }

        std::cout << std::endl;

        patients.emplace_back(name, age, gender);

        std::cout << "Do you want to add another patient? (y/n) ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 'n');
}

void printPatientRecords() {
    std::cout << "\n--- Patient Records ---\n";
    for (const Patient& patient : patients) {
        patient.displayPatientInfo();
        std::cout << std::endl;
    }
}

void searchPatientID() {
    int patient_id;
    do {
        std::cout << "Enter a patient ID to search for (0 to exit):  ";
        std::cin >> patient_id;

        if (patient_id == 0) break;

        bool found = false;
        for (const Patient& patient : patients) {
            if (patient.getID() == patient_id) {
                std::cout << "\n--- Patient Found ---\n";
                patient.displayPatientInfo();
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Patient not found.\n";
        }

    } while (patient_id != 0);
}

int main() {
    int choice;

    do {
        std::cout << "\n---- Patient Portal Menu ----\n";
        std::cout << "1. Add New Patient\n";
        std::cout << "2. View All Patients\n";
        std::cout << "3. Search Patient by ID\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                createPatient();
                break;
            case 2:
                printPatientRecords();
                break;
            case 3:
                searchPatientID();
                break;
            case 4:
                std::cout << "Exiting Patient Portal...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
