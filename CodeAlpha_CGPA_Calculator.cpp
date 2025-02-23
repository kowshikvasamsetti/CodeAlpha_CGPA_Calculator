#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to store course details
struct Course {
    string name;
    int credits;
    char grade;
    double gradePoint;
};

// Function to convert grade to grade points
double getGradePoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 10.0;
        case 'B': return 8.0;
        case 'C': return 6.0;
        case 'D': return 5.0;
        case 'E': return 4.0;
        case 'F': return 0.0;
        default: return -1; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    vector<Course> courses(numCourses);
    double totalCredits = 0, totalGradePoints = 0;
    
    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter details for Course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin >> courses[i].name;
        cout << "Credits: ";
        cin >> courses[i].credits;
        cout << "Grade (A/B/C/D/E/F): ";
        cin >> courses[i].grade;
        
        courses[i].gradePoint = getGradePoint(courses[i].grade);
        if (courses[i].gradePoint == -1) {
            cout << "Invalid grade entered. Please restart the program.\n";
            return 1;
        }
        
        totalCredits += courses[i].credits;
        totalGradePoints += courses[i].credits * courses[i].gradePoint;
    }
    
    double cgpa = totalGradePoints / totalCredits;
    
    cout << "\nCourse Details:\n";
    cout << left << setw(15) << "Course Name" << setw(10) << "Credits" << setw(10) << "Grade" << "Grade Points" << endl;
    for (const auto& course : courses) {
        cout << left << setw(15) << course.name << setw(10) << course.credits << setw(10) << course.grade << course.gradePoint << endl;
    }
    
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;
    
    return 0;
}
