/*****************************
* Author:LiuXL				
* Description:Course Obeject
*****************************/

#ifndef __COURSE_H
#define __COURSE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"

//创建课表信息
typedef struct CourseClass
{
	long m_lCourseNo;
	char m_cpCourseName[40];
	float m_fGoal;
	char m_cpAdress[10];
	char m_cpTime[20];
}Course;

//实例化课表
static Course pChem[MAX_SUB_NO]={
	{11600,"普通物理(II)",4.0,"B阶201","Mon.1~2;Fri.1~2"},
	{22901,"毛泽东思想",6.0,"A312","Mon.6~7;THU.3~4"},
	{23500,"有机化学(I)",3.5,"A212","Tue.3~5"},
	{14302,"C语言程序设计",2.5,"B阶102","Fri.8~10"}
};

//声明Course对象具有的方法
void addCourse(Student *ppStu[MAX_STU_NO]);
void delCourse(Student *ppStu[MAX_STU_NO],char cpNo[10],long lCourseNo);
void printCourse(Student *ppStu[MAX_STU_NO],char cpNo[10]);

#endif
