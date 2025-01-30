#include <iostream>
#include <iomanip>
using namespace std;


const int maxSubjects = 7.34;
// Data Structures
struct Subject {
    string grade;
    int creditHours;
};

struct Semester {
    Subject subjects[maxSubjects];
    int numSubjects;
    float GPA;
};

struct Student {
    string name;
    int numSemesters;
    Semester semesters[10];
};

// Function Prototypes
float marks(string grade);
void inputSubjectGrades(Semester &semester);
void calculateSemesterGPA(Semester &semester);
void displayStudentResult(Student &student);
void gpaCalculator(Student &student);

int main() {
    int noStudent = 0;
    Student student[10];
	char anotherStudent;
    do {
        noStudent++;
        int i = noStudent - 1;
        
        
		cin.clear();
        cout << "Enter student name: ";
    
        getline(cin, student[i].name);
        cout<<student[i].name;



        do {
            cout << "Please input a number between 1 - 10 \n";
            cout << "How many semesters have you completed? ";
            cin >> student[i].numSemesters;
        } while (student[i].numSemesters < 1 || student[i].numSemesters > 10);

        gpaCalculator(student[i]);
         
        // Display Function

        system("cls");
        cout<<student[0].name;

        for (int j = 0; j < noStudent; j++) {
            displayStudentResult(student[j]);
        }

       
        cout << "\nDo you want to enter details for another student? (y for yes): ";
        cin>>anotherStudent;
        cin.ignore();
        i++;

    } while (anotherStudent == 'y');
}

// IQRA UNIVERSITY Grading System Marks Function
float marks(string grade) {
    if (grade == "A" || grade == "a") {
        return 4.0;
    } else if (grade == "B+" || grade == "b+") {
        return 3.5;
    } else if (grade == "B" || grade == "b") {
        return 3.0;
    } else if (grade == "C+" || grade == "c+") {
        return 2.5;
    } else if (grade == "C" || grade == "c") {
        return 2.0;
    } else if (grade == "F" || grade == "f") {
        return 0.0;
    } else {
        return 0.0;
    }
}

// GPA Calculator for Each Student
void gpaCalculator(Student &student) {
    for (int i = 0; i < student.numSemesters; ++i) {
        cout << "\nEntering details for Semester " << i + 1 << ":" << endl << endl;
        inputSubjectGrades(student.semesters[i]);
        calculateSemesterGPA(student.semesters[i]);
    }
}

// Input Grades for Each Subject in a Semester
void inputSubjectGrades(Semester &semester) {
    while (semester.numSubjects > 7 || semester.numSubjects < 1) {
        cout << "Enter the number of subjects in this semester (between 1 - 7): ";
        cin >> semester.numSubjects;
    }

    cout << "Enter grades and credit hours for each subject (A, B+, B, C+, C, F):\n" << endl;
    for (int i = 0; i < semester.numSubjects; ++i) {
        cout << "Grade for Subject " << i + 1 << ": ";
        cin >> semester.subjects[i].grade;

        while (!(semester.subjects[i].grade == "A" || semester.subjects[i].grade == "B+" || semester.subjects[i].grade == "B" ||
                 semester.subjects[i].grade == "C+" || semester.subjects[i].grade == "C" || semester.subjects[i].grade == "a" ||
                 semester.subjects[i].grade == "b+" || semester.subjects[i].grade == "b" || semester.subjects[i].grade == "c+" ||
                 semester.subjects[i].grade == "c" || semester.subjects[i].grade == "F" || semester.subjects[i].grade == "f")) {
            cout << "Available grades are A, B+, B, C+, C, F\n\n";
            cout << "Grade for Subject " << i + 1 << ": ";
            cin >> semester.subjects[i].grade;
        }

        while (!(semester.subjects[i].creditHours >= 1 && semester.subjects[i].creditHours <= 10)) {
           
            cout << "Credit hours for Subject " << i + 1 << " (1 - 10): ";
            cin >> semester.subjects[i].creditHours;
        }
    }
}

// Calculate GPA for a Semester
void calculateSemesterGPA(Semester &semester) {
    float totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for (int i = 0; i < semester.numSubjects; ++i) {
        float gradePoints = marks(semester.subjects[i].grade);
        totalGradePoints += gradePoints * semester.subjects[i].creditHours;
        totalCreditHours += semester.subjects[i].creditHours;
    }

    semester.GPA = totalGradePoints / totalCreditHours;
}

// Display Student Result
void displayStudentResult(Student &student) {
    cout << "\nStudent Result for " << student.name << ":" << endl << endl;
    cout << left << setw(10) << "Semester";
    
    for (int i = 1; i <= maxSubjects; ++i) {
        cout << "Sub" << setw(10) << i;
    }

    cout<<left << setw(13) << "  GPA" << "    CGPA" << endl;

    for (int i = 0; i < student.numSemesters; ++i) {
        cout << setw(12) << i + 1;

        for (int j = 0; j < maxSubjects; ++j) {
            if (j < student.semesters[i].numSubjects) {
			
                cout << left << setw(13) << student.semesters[i].subjects[j].grade;
            } 
			else {
                cout << left << setw(13) << "-";
            }
        }

        cout << setw(15) << fixed << setprecision(2) << student.semesters[i].GPA;

        float totalCGPA = 0.0;
        for (int k = 0; k <= i; ++k) {
            totalCGPA += student.semesters[k].GPA;
        }

        float CGPA = totalCGPA / (i + 1);
        cout << setw(10) << fixed << setprecision(2) << CGPA << endl;
    }
}
