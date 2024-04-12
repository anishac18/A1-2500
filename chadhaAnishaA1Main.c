#include "givenA1.h"

int main(int argc, char *argv[])
{
    // all variables used
    struct courseStruct courseInfo[NUMBER_COURSES];
    struct profStruct profInfo[NUMBER_PROFS];
    int courseNum;
    int cNumFound;
    char cNameFound[MAX_STR];
    char cName[MAX_STR];
    char taughtBy[NUMBER_PROFS][MAX_STR];
    int whichTask;
    char profsNCourses[NUMBER_PROFS][MAX_STR];
    int n;
    int count;
    int numProfs;
    int result;
    float avg;

    // TASK 1:

    FILE *fptr = openFileForReading(argv[1]); // opening the file

    char string[MAX_STR];

    if (fptr == NULL) // of file is NULL, print NULL
    {
        printf("NULL\n");
    }

    fclose(fptr);

    // TASK 2:

    int task2 = readCourse(argv[1], courseInfo);

    // Task 3:

    int task3 = readProfAndCoursesTaught(argv[2], profInfo, courseInfo);

    // do while for task 4 - 8

    do
    {
        printf("Enter 4 for task 4 \n");
        printf("Enter 5 for task 5 \n");
        printf("Enter 6 for task 6  \n");
        printf("Enter 7 for task 7 \n");
        printf("Enter 8 for task 8 \n");
        printf("Enter a value between 4 and 8 : ");
        scanf("%d", &whichTask);
        break;

    } while (whichTask >= 4 && whichTask <= 8);

    switch (whichTask) // using the switch statement for tasks 4 to 8
    {
    case 4:

        printf("Enter n: ");
        scanf("%d", &n);
        numProfs = nCourses(n, profInfo, profsNCourses);
        printf("Number of professors who teach %d or more courses: %d\n", n, numProfs);

        for (int i = 0; i < numProfs; i++)
        {
            printf("%s\n", profsNCourses[i]);
        }
        break;

    case 5:

        printf("Enter course number: ");
        scanf("%d", &courseNum);

        result = getCourseName(courseNum, cNameFound, courseInfo);
        if (result == 1)
            printf("Course name found: %s\n", cNameFound);
        else
        {
            printf("Course name not found\n");
        }
        break;

    case 6:
        printf("Enter course name: ");
        getchar();
        fgets(cName, MAX_STR, stdin);
        cName[strlen(cName) - 1] = '\0';
        if (getCourseNum(cName, &cNumFound, courseInfo))
        {
            printf("Course number = %d\n", cNumFound);
        }
        else
        {
            printf("not found\n");
        }
        break;

    case 7:

        printf("Enter course number: ");
        scanf("%d", &courseNum);

        count = profsTeachingCourse(courseNum, profInfo, taughtBy);

        if (count == 0)
        {
            printf("No professor is teaching course %d.\n", courseNum);
        }
        else
        {
            printf("%d professor(s) are teaching %d courses:\n", count, courseNum);

            for (int i = 0; i < count; i++)
            {
                printf("%s\n", taughtBy[i]);
            }
        }
        break;

    case 8:

        avg = avgNumCourses(profInfo);
        printf("The average number of courses taught by a professor is: %.f\n", avg);
        break;
    }

    return 0;
}