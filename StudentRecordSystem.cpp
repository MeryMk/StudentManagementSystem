#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
	string name;
	int id;
	float grade;
};

void addStudent() {
	Student s;
	cout << "Enter the student's name -> ";
	//cin.ignore();
	getline(cin, s.name);
	cout << "Enter the student's ID -> ";
	cin >> s.id;
	cout << "Enter the student's grade -> ";
	cin >> s.grade;

	ofstream outFile("students.txt", ios::app);
	if (outFile.is_open()) {
		outFile << s.name << ", " << s.id << ", " << s.grade << endl;
		outFile.close();
		cout << "Student added successfully!\n";
	}
	else
	{
		cout << "Error opening file.\n";
	}
}

void viewStudents() {
	ifstream inFile("students.txt");
	if (!inFile) {
		cout << "No student records found.\n";
		return;
	}

	string line;
	cout << "\n--- Student List ---\n";
	while (getline(inFile, line)) {
		cout << line << endl;
	}

	inFile.close();
}

void searchStudentByName() {
	string searchName;
	cout << "Enter the student's name to search -> ";
	cin.ignore(); // in case previous input was with cin >>
	getline(cin, searchName);

	ifstream inFile("students.txt");
	if (!inFile) {
		cout << "No student records found.\n";
		return;
	}

	string line;
	bool found = false;
	while (getline(inFile, line)) {
		if (line.find(searchName) != string::npos) {
			cout << "Found: " << line << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "No student with that name was found.\n";
	}

	inFile.close();
}



int main() {
	int choice;

	do {
		cout << "\n--- Student Record System ---\n";
		cout << "1. Add a student\n";
		cout << "2. View all students\n";
		cout << "3. Search student by name\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		cin.ignore();

		switch (choice) {
		case 1:
			addStudent();
			break;
		case 2:
			viewStudents();
			break;
		case 3:
			searchStudentByName();
			break;
		case 4:
			cout << "Exiting program. Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);

	return 0;
}
