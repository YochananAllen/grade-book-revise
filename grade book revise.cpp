// grade book revise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//modify the grade book application in programming challenge 12 so it drops each students lowest score when determining the test score averages and letter grades
// Name: Yochanan Allen 

#include <iostream>
#include <string>
#include <iomanip> 
#include <algorithm> 

using namespace std;


double calculateAverage(double scores[], int size) {
    
    double minScore = *min_element(scores, scores + size);

    double total = 0;
    int count = 0;

    
    for (int i = 0; i < size; i++) {
        if (scores[i] != minScore || count > 0) { 
            total += scores[i];
            count++;
        }
        else {
            count++;
        }
    }

    return total / 3; 
}


char getLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

int main() {
    const int NUM_STUDENTS = 5;
    const int NUM_TESTS = 4;

    string studentNames[NUM_STUDENTS];
    char grades[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter the name of student #" << (i + 1) << ": ";
        cin >> studentNames[i];

        cout << "Enter the 4 test scores for " << studentNames[i] << ":" << endl;
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << "Test score #" << (j + 1) << ": ";
            cin >> testScores[i][j];
        }
    }

    
    cout << "\nStudent Scores and Grades:\n";
    cout << fixed << setprecision(2); 

    for (int i = 0; i < NUM_STUDENTS; i++) {
       
        double average = calculateAverage(testScores[i], NUM_TESTS);
        
        grades[i] = getLetterGrade(average);

        
        cout << studentNames[i] << " - Average Score (lowest dropped): " << average << " - Grade: " << grades[i] << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
