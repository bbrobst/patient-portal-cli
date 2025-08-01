#ifndef PATIENT_H 
#define PATIENT_H

#include <string>

class Patient {
private:
    std::string name;
    int age;
    std::string gender;
    int patientID;           // Unique patient identifier
    static int nextID;       // Static counter for assigning IDs
    
public:
    // Constructor initializes patient info and assigns unique ID
    Patient(std::string name, int age, std::string gender);
    
    // Display patient details
    void displayPatientInfo() const;
    
    // Get patient's unique ID
    int getID() const;
};

#endif // PATIENT_H
