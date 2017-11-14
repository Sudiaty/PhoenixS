/*****************************
* Author:LiuXL				
* Description:Student Obeject
*****************************/

#ifndef __STUDENT_H
#define __STUDENT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STU_NO 30
#define MAX_SUB_NO 8
int stuNum;

//创建学生信息结构体
typedef struct StudentClass
{
	long m_lNo;
	char m_cpName[20];
	char m_cpGender[4];
	long m_lpMajor[MAX_SUB_NO];
	float m_fPoint; 
}Student;

//声明对学生信息操作函数
void addStudent(Student *ppStu[MAX_STU_NO]);

void saveStudent(Student *ppStu[MAX_STU_NO]);

void getStudent(Student *ppStu[MAX_STU_NO]);

void searchStudent(Student *ppStu[MAX_STU_NO]);

void echoStudent(Student *ppStu[MAX_STU_NO]);

void delStudent(Student *ppStu[MAX_STU_NO]);

void altStudent(Student *ppStu[MAX_STU_NO]);

#endif
