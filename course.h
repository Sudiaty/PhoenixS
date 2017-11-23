/*****************************
* Author:LiuXL
* Description:Course Obeject
*****************************/

#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>

#include "student.h"

//�����α���Ϣ
typedef struct CourseClass
{
	char m_cpCourseNo[10];
	char m_cpCourseName[40];
	float m_fGoal;
	char m_cpAdress[10];
	char m_cpTime[20];
}Course;

//ʵ�����α�
static Course pChem[MAX_SUB_NO] = {
	{ "PHY2","��ͨ����(II)",4.0,"B��201","Mon.1~2;Fri.1~2" },
	{ "MXI","ë��˼��",6.0,"A312","Mon.6~7;THU.3~4" },
	{ "ORG1","�л���ѧ(I)",3.5,"A212","Tue.3~5" },
	{ "CSE","C���Գ������",2.5,"B��102","Fri.8~10" },
	{ "EEE","Ӧ�õ繤ѧ",2.5,"A��203","Wed.8~9" }
};

//����Course������еķ���
char** echoCourse(Course *ppCourse[MAX_SUB_NO]);
void addCourse(Student *ppStu[MAX_STU_NO],char cpNo[10]);
char* searchCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],char cpNo[10],char cpCourseNo[10]);
void delCourse(Student *ppStu[MAX_STU_NO],char cpNo[10],char cpCourseNo[10]);
char** printCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],char cpNo[10]);

#endif