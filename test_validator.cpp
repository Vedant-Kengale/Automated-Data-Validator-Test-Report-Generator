#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Function to validate a single record (simulating a test case execution)
bool validateRecord(const string& name, const string& email, int age) {
    // Test Conditions: Name not empty, Age between 18-60, Email contains '@'
    if (name.empty() || age < 18 || age > 60 || email.find('@') == string::npos) {
        return false; // Test Failed (Defect Found)
    }
    return true; // Test Passed
}

int main() {
    // 1. Generate dummy test data (simulating application logs or user data)
    ofstream outFile("test_data.csv");
    outFile << "Name,Email,Age\n";
    outFile << "Vedant,vedant@test.com,21\n";       // Valid
    outFile << "InvalidUser,bademail,25\n";         // Defect: Invalid email
    outFile << "Rahul,rahul@test.com,17\n";         // Defect: Age < 18
    outFile.close();

    // 2. Read and validate the file (simulating test execution)
    ifstream inFile("test_data.csv");
    string line;
    int total = 0, passed = 0, failed = 0;

    getline(inFile, line); // Skip header

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, email, ageStr;
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, ageStr, ',');
        
        int age = stoi(ageStr);
        total++;

        if (validateRecord(name, email, age)) {
            passed++;
        } else {
            failed++;
            cout << "[DEFECT FOUND] Invalid data in record: " << name << endl;
        }
    }
    inFile.close();

    // 3. Generate Structured Test Report
    cout << "\n--- TEST EXECUTION REPORT ---\n";
    cout << "Total Test Cases: " << total << "\n";
    cout << "Passed: " << passed << "\n";
    cout << "Failed (Defects): " << failed << "\n";
    cout << "-----------------------------\n";

    return 0;
}
