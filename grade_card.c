#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_card.h"

// Function to calculate CGPA based on average marks
float calculateCGPA(float avgm) {
    if (avgm >= 90.0) {
        return 4.0;  
    } else if (avgm >= 80.0) {
        return 3.5;  
    } else if (avgm >= 70.0) {
        return 3.0;  
    } else if (avgm >= 60.0) {
        return 2.5;  
    } else if (avgm >= 50.0) {
        return 2.0;  
    } else if (avgm >= 40.0) {
        return 1.5;  
    } else {
        return 0.0;  
    }
}

// Function to determine remarks based on CGPA
const char *getRemarks(float cgpa) {
    if (cgpa >= 4.0) {
        return "Excellent";
    } else if (cgpa >= 3.5) {
        return "Very Good";
    } else if (cgpa >= 3.0) {
        return "Good";
    } else if (cgpa >= 2.0) {
        return "Average";
    } else {
        return "Below Average";
    }
}

void fillGradeCard(GradeCard *gradeCard) {
    // Assume input for one student
    gradeCard->numStudents = 1;
    gradeCard->students = (Student *)malloc(gradeCard->numStudents * sizeof(Student));
    if (gradeCard->students == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    Student *student = &gradeCard->students[0];

    // Input student name
    printf("Enter student name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';  // Remove newline character

    // Input number of exams
    printf("Enter number of exams: ");
    scanf("%d", &student->numExams);

    // Input number of subjects per exam
    printf("Enter number of subjects per exam: ");
    scanf("%d", &student->subjectsPerExam);

    // Allocate memory for marks array based on number of exams
    student->marks = (float *)malloc(student->numExams * student->subjectsPerExam * sizeof(float));
    if (student->marks == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Input marks for each exam and subject
    for (int i = 0; i < student->numExams; i++) {
        printf("Enter marks for Exam %d subjects:\n", i + 1);
        for (int j = 0; j < student->subjectsPerExam; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%f", &student->marks[i * student->subjectsPerExam + j]);
        }
    }
}

void printGradeCard(const GradeCard *gradeCard) {
    const Student *student = &gradeCard->students[0];

    printf("\nGrade Card for %s - PES University\n", student->name);
    printf("-------------------------------------\n");
    printf("Teacher: Mr. Biwas\n");
    printf("Principal: Dr. Subhash Kulkarni\n");
    printf("University: PES University\n\n");
    
    printf("Number of Exams: %d\n", student->numExams);
    printf("Subjects per Exam: %d\n\n", student->subjectsPerExam);

    printf("*****Exam-wise*****\n\n");
    for (int i = 0; i < student->numExams; i++) {
        printf("Exam %d:\n", i + 1);
        printf("-----------\n");
        
        float totalMarks = 0.0;
        for (int j = 0; j < student->subjectsPerExam; j++) {
            float marks = student->marks[i * student->subjectsPerExam + j];
            printf("Subject %d: %.2f\n", j + 1, marks);
            totalMarks += marks;
        }
        
        // Calculate average marks for the exam
        float avgm = totalMarks / student->subjectsPerExam;
        printf("Average Marks: %.2f\n", avgm);

        // Calculate CGPA based on average marks
        float cgpa = calculateCGPA(avgm);
        printf("CGPA: %.2f\n", cgpa);

        // Get remarks based on CGPA
        const char *remarks = getRemarks(cgpa);
        printf("Remarks: %s\n\n", remarks);
    }
}

void freeGradeCard(GradeCard *gradeCard) {
    if (gradeCard->students != NULL) {
        for (int i = 0; i < gradeCard->numStudents; i++) {
            if (gradeCard->students[i].marks != NULL) {
                free(gradeCard->students[i].marks);
                gradeCard->students[i].marks = NULL;
            }
        }
        free(gradeCard->students);
        gradeCard->students = NULL;
    }
    gradeCard->numStudents = 0;
}
