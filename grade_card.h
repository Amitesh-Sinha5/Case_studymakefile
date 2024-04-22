#ifndef GRADE_CARD_H
#define GRADE_CARD_H

typedef struct {
    char name[100];
    float *marks;  // Dynamic array to hold marks for each exam
    int numExams;  // Number of exams
    int subjectsPerExam;  // Number of subjects per exam
} Student;

typedef struct {
    Student *students;
    int numStudents;
} GradeCard;

void fillGradeCard(GradeCard *gradeCard);
void printGradeCard(const GradeCard *gradeCard);
void freeGradeCard(GradeCard *gradeCard);

#endif  // GRADE_CARD_H
