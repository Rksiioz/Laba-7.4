#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct StudentRecord {
    string lastName;
    string initials;
    vector<int> grades;
};

void printAllStudents(const map<string, StudentRecord>& students) {
    cout << "Students:" << endl;
    for (const auto& pair : students) {
        cout << pair.second.lastName << " " << pair.second.initials << endl;
    }
}

void printStudentsWithTopGrades(const map<string, StudentRecord>& students) {
    cout << "Students who have only 5:" << endl;
    for (const auto& pair : students) {
        bool allTopGrades = true;
        for (int grade : pair.second.grades) {
            if (grade != 5) {
                allTopGrades = false;
                break;
            }
        }
        if (allTopGrades) {
            cout << pair.second.lastName << " " << pair.second.initials << endl;
        }
    }
}

void printStudentsWithThrees(const map<string, StudentRecord>& students) {
    cout << "Students who have 3:" << endl;
    for (const auto& pair : students) {
        bool hasThrees = false;
        for (int grade : pair.second.grades) {
            if (grade == 3) {
                hasThrees = true;
                break;
            }
        }
        if (hasThrees) {
            cout << pair.second.lastName << " " << pair.second.initials << endl;
        }
    }
}

void printStudentsWithTwos(const map<string, StudentRecord>& students) {
    cout << "Students who have 2:" << endl;
    for (const auto& pair : students) {
        int countTwos = 0;
        for (int grade : pair.second.grades) {
            if (grade == 2) {
                countTwos++;
            }
        }
        if (countTwos == 1) {
            cout << pair.second.lastName << " " << pair.second.initials << endl;
        }
    }
}

void addStudentRecord(map<string, StudentRecord>& students) {
    StudentRecord student;
    cout << "Last name: ";
    cin >> student.lastName;
    cout << "Initials: ";
    cin >> student.initials;
    cout << "grades from five subjects: ";
    for (int i = 0; i < 5; ++i) {
        int grade;
        cin >> grade;
        student.grades.push_back(grade);
    }
    students[student.lastName] = student;
}

void displayAllStudents(const map<string, StudentRecord>& students) {
    cout << "All students:" << endl;
    for (const auto& pair : students) {
        cout << pair.second.lastName << " " << pair.second.initials << endl;
    }
}

void exitProgram() {
    cout << "Good bye!" << endl;
    exit(0);
}

int main() {
    map<string, StudentRecord> students;

    int choice;
    do {
        cout << endl << endl;
        cout << "[1] Add student" << endl;
        cout << "[2] Show all" << endl;
        cout << "[3] Students who have only 5" << endl;
        cout << "[4] Students who have 3" << endl;
        cout << "[5] Students who have 2" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter value: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentRecord(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                printStudentsWithTopGrades(students);
                break;
            case 4:
                printStudentsWithThrees(students);
                break;
            case 5:
                printStudentsWithTwos(students);
                break;
            case 0:
                exitProgram();
                break;
            default:
                cout << "Try again!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
