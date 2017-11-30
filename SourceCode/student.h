/*****************************
* Author:LiuXL
* Description:Student Obeject
*****************************/
#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include "view.h"

//创建学生信息结构体
#define MAX_STU_NO 30
#define MAX_SUB_NO 8
typedef struct StudentClass
{
	char m_cpNo[20];
	char m_cpName[20];
	char m_cpGender[4];
	char m_cpClass[20];
	char m_cpMajor[MAX_SUB_NO][10];
	float m_fPoint;
}Student;


//声明对学生信息操作函数
int addStudent(Student *ppStu[MAX_STU_NO], Form *ppForm[MAX_ROW], int *stuNum);

void getStudent(Student *ppStu[MAX_STU_NO], int *stuNum);

void saveStudent(Student *ppStu[MAX_STU_NO]);

char** echoStudent(Student *ppStu[MAX_STU_NO]);

long searchStudent(Student *ppStu[MAX_STU_NO]);

void delStudent(Student *ppStu[MAX_STU_NO], long stuNo, int *stuNum);

int altStudent(Student *ppStu[MAX_STU_NO], long lNo);

char* searchClass(Student *ppStu[MAX_STU_NO], char cpClass[20]);
#endif // MODEL_H
