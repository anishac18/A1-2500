#include "givenA1.h"
#include <string.h>

/* Task 1 */
FILE *openFileForReading(char fileName[MAX_STR])
{
  FILE *fptr = fopen(fileName, "r"); // opening the file
  return fptr;
}

/* Task 2 */
int readCourse(char filename[MAX_STR], struct courseStruct courseInfo[NUMBER_COURSES])
{

  FILE *fptr = openFileForReading(filename);

  int i = 0;
  char course[MAX_STR];
  char string[MAX_STR];
  int d = 0;

  char dummy[MAX_STR];

  if (fptr == NULL) // if file is NULL, return -1
  {
    return -1;
  }

  else
  {
    while (!feof(fptr))
    {

      for (int j = 0; j < NUMBER_COURSES; j++)
      {
        fgets(course, MAX_STR, fptr);
        course[strlen(course) - 1] = '\0';
        strcpy(courseInfo[j].courseName, course);
      }

      for (int j = 0; j < NUMBER_COURSES; j++)
      {
        fscanf(fptr, "%d", &courseInfo[j].courseID);
      }
      i++;
    }
  }
  return 1;
}

//  Task 3 :
int readProfAndCoursesTaught(char filename[MAX_STR], struct profStruct profInfo[NUMBER_PROFS], struct courseStruct courseInfo[NUMBER_COURSES])
{
  FILE *fptr = fopen(filename, "r"); // Open the data.txt file for reading
  int j;
  int i;
  char prof[MAX_STR];
  char data[MAX_STR];

  if (fptr == NULL)
  {
    return -1;
  }

  else
  {
    while (!feof(fptr))
    {

      for (i = 0; i < NUMBER_PROFS; i++)
      {
        fgets(prof, MAX_STR, fptr);
        prof[strlen(prof) - 1] = '\0';
        strcpy(profInfo[i].profName, prof);
      }

      for (i = 0; i < NUMBER_PROFS; i++)
      {

        fgets(data, MAX_STR, fptr);

        for (j = 0; j < NUMBER_COURSES; j++)
        {
          if (tolower(data[j]) == 'y')
          {
            profInfo[i].coursesTaught[j] = courseInfo[j].courseID;
          }
          else
          {
            profInfo[i].coursesTaught[j] = -1;
          }
        }
      }
    }

    // Closing the file
    fclose(fptr);

    return 1;
  }
}

/* Task 4 */
// This tasks populates an array with all the professors who teach more n or more courses

int nCourses(int n, struct profStruct profInfo[NUMBER_PROFS], char profsNCourses[NUMBER_PROFS][MAX_STR])
{
  int count = 0;
  for (int i = 0; i < NUMBER_PROFS; i++)
  {
    int coursesTaught = 0;
    for (int j = 0; j < NUMBER_COURSES; j++)
    {
      if (profInfo[i].coursesTaught[j] == 1)
      {
        coursesTaught++;
      }
    }
    if (coursesTaught >= n)
    {
      strcpy(profsNCourses[count], profInfo[i].profName);
      count++;
    }
  }
  return count;
}

/* Task 5 */
// This tasks takes course number as input

int getCourseName(int courseNum, char cNameFound[50], struct courseStruct courseInfo[NUMBER_COURSES])
{
  int x = 0;
  for (int i = 0; i < NUMBER_COURSES; i++)
  {
    if (courseInfo[i].courseID == courseNum)
    {
      strcpy(cNameFound, courseInfo[i].courseName);
      return 1;
    }
  }
  return 0;
}

/* Task 6 */
// This task takes a course name as input

int getCourseNum(char cName[50], int *cNumFound, struct courseStruct courseInfo[NUMBER_COURSES])
{
  for (int i = 0; i < NUMBER_COURSES; i++)
  {
    if (strcmp(cName, courseInfo[i].courseName) == 0) // compare the entered course name with the course name in the struct courseInfo
    {
      *cNumFound = courseInfo[i].courseID;
      return 1;
    }
  }
  return 0;
}

/* Task 7 */
// The function returns the count of professors teaching the course courseNum.

int profsTeachingCourse(int courseNum, struct profStruct profInfo[NUMBER_PROFS], char taughtBy[NUMBER_PROFS][MAX_STR])
{
  int count = 0;

  for (int i = 0; i < NUMBER_PROFS; i++)
  {
    for (int j = 0; j < NUMBER_COURSES; j++)
    {
      if (profInfo[i].coursesTaught[j] == courseNum)
      {
        strcpy(taughtBy[count], profInfo[i].profName);
        count++;
        break;
      }
    }
  }
  return count;
}

/*Task 8 */
// This function tells the average number of courses taught by a professor

float avgNumCourses(struct profStruct profInfo[NUMBER_PROFS])
{

  int totalCourses = 0;
  int numProfs = 0;

  for (int i = 0; i < NUMBER_PROFS; i++)
  {
    int coursesTaught = 0;
    for (int j = 0; j < NUMBER_COURSES; j++)
    {
      if (profInfo[i].coursesTaught[j] != -1)
      {
        coursesTaught++;
      }
    }
    if (coursesTaught > 0)
    {
      totalCourses = totalCourses + coursesTaught;
      numProfs++;
    }
  }
  return (float)totalCourses / numProfs; // it returns the round off value
}
