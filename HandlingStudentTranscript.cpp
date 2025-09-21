#include <stdio.h>

struct Course
{
    char sub[50];
    char code[10];
    float grade;
};

struct Semester
{
    struct Course courses[6];
    int numCourses;
};

void inputCourse(struct Course *course)
{
    printf("Enter course name: ");
    scanf_s("%s", course->sub, sizeof(course->sub));
    printf("Enter course code: ");
    scanf_s("%s", course->code, sizeof(course->code));
    printf("Enter grade: ");
    scanf_s("%f", &(course->grade));
}

void inputSemester(struct Semester *semester)
{
    printf("Enter the number of courses for this semester (maximum 6): ");
    scanf_s("%d", &(semester->numCourses));
    for (int i = 0; i < semester->numCourses; i++)
    {
        printf("Enter details for course %d:\n", i + 1);
        inputCourse(&(semester->courses[i]));
    }
}

float calculateGPA(struct Semester semester)
{
    float totalGrade = 0.0;
    for (int i = 0; i < semester.numCourses; i++)
    {
        totalGrade += semester.courses[i].grade;
    }
    return totalGrade / semester.numCourses;
}

void displayTranscript(struct Semester semesters[], int numSemesters)
{
    FILE* file;
    fopen_s(&file, "gpa.txt", "w"); // Open the file in write mode
    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return;
    }
    fprintf(file, "\tFATIMA JINNAH WOMEN UNIVERSITY \n");
    fprintf(file, "\tDate Issued: December 24, 2020 \n\n");
    fprintf(file, "\t\tTranscript:\n\n");
    for (int i = 0; i < numSemesters; i++)
    {
        fprintf(file, "\t\tSemester %d:\n", i + 1);
        fprintf(file, "____________________________________________\n\n");
        for (int j = 0; j < semesters[i].numCourses; j++) {
            fprintf(file, "Course %d:\n", j + 1);
            fprintf(file, "Name: %s \t| Code: %s\t| Grade: %.2f \n\n", semesters[i].courses[j].sub, semesters[i].courses[j].code, semesters[i].courses[j].grade);
        }
        fprintf(file, "GPA: %.2f\n\n", calculateGPA(semesters[i]));
        fprintf(file, "____________________________________________\n\n");
        fprintf(file, "\n");
    }
    fclose(file); // Close the file
    printf("Transcript has been stored in the file 'gpa.txt' successfully.\n");
}

int main()
{
    printf("\t \t \t \t \t FATIMA JINNAH WOMEN UNIVERSITY \t \t \t \t \t \tOld Presidency\n");
    printf("\t \t \t \t \t Date Issued: December 24, 2020 \t \t \t \t \t \t \t     The Mall\n");
    printf("\t \t \t \t \t \t \t \t \t \t \t \t \t \t \t kachari Chowk\n");
    printf("\t \t \t \t \t \t \t \t \t \t \t \t \t \t \t    Rawalpindi \n");
    printf("\t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t46000 \n");
    printf("Student Name: Farah Naz \t \t \t DOB: 023-05-2003 \t \t \t \n");
    printf("Sreet Address: Hafizabad RWP \t \t \t Place of Birth: Rawalpindi \t \t B.Form: 37304-XXXXXXX-X \n");
    printf("Province: Punjab \t \t \t \t Gender: Female \n");
    printf("City: Rawalpindi \n \n");
    printf("\t \t \t \t \t \t \t  Session 2016 - 2020 \t \t \t \t \t \n \n \n");

    struct Semester semesters[8];
    for (int i = 0; i < 8; i++) {
        printf("Enter details for semester %d:\n", i + 1);
        inputSemester(&(semesters[i]));
        printf("\n");
    }
    displayTranscript(semesters, 8);
    return 0;
}