#include <iostream>
#include "Patient.h"

// Initialize patient with given info and assign unique ID
Patient::Patient(std::string name, int age, std::string gender) :
    name(name), age(age), gender(gender), patientID(nextID++) {}

// Initialize static ID counter starting from 1
int Patient::nextID = 1;

// Display all patient details
void Patient::displayPatientInfo() const {
    std::cout << "Patient ID: " << patientID << std::endl;
    std::cout << "Patient name: " << name << std::endl;
    std::cout << "Patient age: " << age << std::endl;
    std::cout << "Patient gender: " << gender << std::endl;
}

// Return patient ID
int Patient::getID() const {
    return patientID;
}
