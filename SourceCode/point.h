#pragma once
/*****************************
* Author:LiuXL
* Description:Point Obeject
*****************************/

#ifndef POINT_H
#define POINT_H

#include <stdio.h>

#include "student.h"

//创建成绩信息
typedef struct PointClass
{
	char m_cpCourseNo[10];
	char m_cpNo[10];
	float m_fGoal;
}Point;

//声明Point对象具有的方法
int addPoint(Student *ppStu[MAX_STU_NO],Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],long stuNo,char cpCourseNo[10],int *pointNum);

void savePoint(Point *ppPoint[MAX_STU_NO*MAX_SUB_NO]);

void getPoint(Point *ppPoint[MAX_STU_NO*MAX_SUB_NO], int *pointNum);

float calGPA(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],long stuNo);

char** echoPoint(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],long lNo);

char** echoTotalPoint(Student *ppStu[MAX_STU_NO], char cpClass[20]);

char** echoSubPoint(Student *ppStu[MAX_STU_NO], Course *ppCourse[MAX_SUB_NO], Point *ppPoint[MAX_STU_NO*MAX_SUB_NO], char cpClass[20], int courseNo);

#endif