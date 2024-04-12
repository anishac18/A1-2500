/*
  Student Name: Anisha Chadha
  Student ID: 1236856
  Due Date: 3 Feb 2022 Friday,2022
  Course: CIS*2500
  I have exclusive control over this submission via my password.
  By including this header comment, I certify that:
   1) I have read and understood the policy on academic integrity.
   2) I have completed Moodle's module on academic integrity.
   3) I have achieved at least 80% on the academic integrity quiz
  I assert that this work is my own. I have appropriate acknowledged
  any and all material that I have used, be it directly quoted or
  paraphrased. Furthermore, I certify that this assignment was written
  by me in its entirety.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMBER_PROFS 6
#define NUMBER_COURSES 10
#define MAX_STR 50


//if course “Programming” has a course id 1300, then courseStruct used
//would have courseName as “Programming” and courseID as 1300

struct courseStruct {
   char courseName [MAX_STR];
   int courseID;
};


// Ritu teaches 1300, 1500 and 3530 this year, the profStruct used would
// have profName = "Ritu" and courses taught = {1300, 1500, 3530}


 struct profStruct {
   char profName [MAX_STR];
   int  coursesTaught [NUMBER_COURSES];
};

/* Task 1 */
FILE *openFileForReading(char fileName [MAX_STR]);

/* Task 2 */
int readCourse (char filename [MAX_STR],
                struct courseStruct courseInfo [NUMBER_COURSES]
                );

/* Task 3 */
int readProfAndCoursesTaught (char filename [MAX_STR],
                               struct profStruct profInfo [NUMBER_PROFS],
                              struct courseStruct courseInfo [NUMBER_COURSES]
                               );

/* Task 4 */
int nCourses (int n,
              struct profStruct profInfo [NUMBER_PROFS],
              char profsNCourses [NUMBER_PROFS][MAX_STR]
              );

/* Task 5 */
int getCourseName (int courseNum,
                   char cNameFound [50],
                   struct courseStruct courseInfo [NUMBER_COURSES]
                   );

/* Task 6 */
int getCourseNum (char cName [50],
                  int * cNumFound,
                  struct courseStruct courseInfo [NUMBER_COURSES]
                  );

/* Task 7 */
int profsTeachingCourse (int courseNum,
                         struct profStruct profInfo [NUMBER_PROFS],
                         char taughtBy [NUMBER_PROFS][MAX_STR]
                         );


/*Task 8 */
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]);
