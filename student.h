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
	int m_iGender;
	int m_ipMajor[MAX_SUB_NO];
	int m_iPoint; 
}Student;

//定义对学生信息操作函数
void addStudent(Student *stu);

void saveStudent(Student *stu);

void getStudent(Student *p);

void delStudent(Student *p);

void altStudent();

#endif