/*****************************
* Author:LiuXL
* Description:course Obeject
*****************************/

#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>

#include "student.h"

//?????¦Á????
typedef struct CourseClass
{
	char m_cpCourseNo[10];
	char m_cpCourseName[40];
	float m_fGoal;
	char m_cpAdress[10];
	char m_cpTime[20];
}Course;

//??????¦Á?
<<<<<<< HEAD
static Course pChem[MAX_SUB_NO] = {
	{ "PHY2","???????(II)",4.0,"B??201","Mon.1~2;Fri.1~2" },
	{ "MXI","??????",6.0,"A312","Mon.6~7;THU.3~4" },
	{ "ORG1","?§Ý????(I)",3.5,"A212","Tue.3~5" },
=======
static course pChem[MAX_SUB_NO] = {
	{ "PHY","???????",4.0,"B??201","Mon.1~2;Fri.1~2" },
	{ "MXI","??????",6.0,"A312","Mon.6~7;THU.3~4" },
	{ "ORG","?§Ý????",3.5,"A212","Tue.3~5" },
>>>>>>> origin/LiuXL@Win7
	{ "CSE","C??????????",2.5,"B??102","Fri.8~10" },
	{ "EEE","???ÀF?",2.5,"A??203","Wed.8~9" }
};

<<<<<<< HEAD
//????Course??????§Ö????
char** echoCourse(Course *ppCourse[MAX_SUB_NO]);
void addCourse(Student *ppStu[MAX_STU_NO],char cpNo[10]);
char* searchCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],char cpNo[10],char cpCourseNo[10]);
void delCourse(Student *ppStu[MAX_STU_NO],char cpNo[10],char cpCourseNo[10]);
char** printCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],char cpNo[10]);
=======
//????course??????§Ö????
char** echoCourse(course *ppCourse[MAX_SUB_NO]);
void addCourse(Student *ppStu[MAX_STU_NO],long stuNo);
char* searchCourse(Student *ppStu[MAX_STU_NO],course *ppCourse[MAX_SUB_NO],char cpNo[10],char cpCourseNo[10]);
void delCourse(Student *ppStu[MAX_STU_NO],char cpNo[10],char cpCourseNo[10]);
char** printCourse(Student *ppStu[MAX_STU_NO],course *ppCourse[MAX_SUB_NO],long stuNo);
>>>>>>> origin/LiuXL@Win7

#endif