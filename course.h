/*****************************
* Author:LiuXL
* Description:Course Obeject
*****************************/

#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>

#include "student.h"

//创建课表信息
typedef struct CourseClass
{
	char m_cpCourseNo[10];
	char m_cpCourseName[40];
	float m_fGoal;
	char m_cpAdress[10];
	char m_cpTime[20];
}Course;

//实例化课表
static Course pChem[MAX_SUB_NO] = {
	{ "PHY","普通物理",4.0,"B阶201","Mon.1~2;Fri.1~2" },
	{ "MXI","毛泽东思想",6.0,"A312","Mon.6~7;THU.3~4" },
	{ "ORG","有机化学",3.5,"A212","Tue.3~5" },
	{ "CSE","C语言程序设计",2.5,"B阶102","Fri.8~10" },
	{ "EEE","应用电工学",2.5,"A阶203","Wed.8~9" }
};

//声明Course对象具有的方法
char** echoCourse(Course *ppCourse[MAX_SUB_NO]);
void addCourse(Student *ppStu[MAX_STU_NO], Course *ppCourse[MAX_SUB_NO], long stuNo, int courseNo);
int searchCourse(Course *ppCourse[MAX_SUB_NO],char cpCourseNo[10]);
void delCourse(Student *ppStu[MAX_STU_NO], Course *ppCourse[MAX_SUB_NO], long iStuNo, int iCourseNo);
char** printCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],long stuNo);
int searchStuCourse(Student *ppStu[MAX_STU_NO], Course *ppCourse[MAX_SUB_NO], long stuNo, int courseNo);
#endif