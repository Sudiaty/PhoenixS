/*****************************
* Author:LiuXL
* Description:Student Obeject
*****************************/
#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include "view.h"

//����ѧ����Ϣ�ṹ��
#define MAX_STU_NO 5
#define MAX_SUB_NO 5
typedef struct StudentClass
{
	char m_cpNo[10];
	char m_cpName[20];
	char m_cpGender[4];
	char m_cpClass[20];
	char m_cpMajor[MAX_SUB_NO][10];
	float m_fPoint;
}Student;


//������ѧ����Ϣ��������
void addStudent(Student *ppStu[MAX_STU_NO], Form *ppForm[MAX_ROW], int *stuNum);

void getStudent(Student *ppStu[MAX_STU_NO], int *stuNum);

void saveStudent(Student *ppStu[MAX_STU_NO]);

char** echoStudent(Student *ppStu[MAX_STU_NO]);

long searchStudent(Student *ppStu[MAX_STU_NO], char cpNo[10]);

void delStudent(Student *ppStu[MAX_STU_NO], char cpNo[10], int *stuNum);

void altStudent(Student *ppStu[MAX_STU_NO], long lNo);

#endif // MODEL_H
