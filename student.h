/*****************************
* Author:LiuXL				
* Description:Student Obeject
*****************************/

#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//创建学生信息结构体
#define MAX_STU_NO 30
#define MAX_SUB_NO 8
int stuNum;
typedef struct StudentClass
{
	long m_lNo;
	char m_cpName[20];
	char m_cpGender[4];
	int m_ipMajor[MAX_SUB_NO];
	float m_fPoint; 
}Student;

//声明对学生信息操作函数
void addStudent(Student *ppStu[MAX_STU_NO]);

void saveStudent(Student *ppStu[MAX_STU_NO]);

void getStudent(Student *ppStu[MAX_STU_NO]);

void echoStudent(Student *ppStu[MAX_STU_NO]);

void delStudent(Student *ppStu[MAX_STU_NO]);

void altStudent(Student *ppStu[MAX_STU_NO]);

#endif
