#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "view.h"

//创建学生信息结构体
#define MAX_STU_NO 30
#define MAX_SUB_NO 8
typedef struct StudentClass
{
    char m_cpNo[10];
    char m_cpName[20];
    char m_cpGender[4];
    char m_cpClass[20];
    long m_lpMajor[MAX_SUB_NO];
    float m_fPoint;
}Student;


//声明对学生信息操作函数
void addStudent(Student *ppStu[MAX_STU_NO],Form *ppForm[10],int *stuNum);

void getStudent(Student *ppStu[MAX_STU_NO]);

void saveStudent(Student *ppStu[MAX_STU_NO]);

char** echoStudent(Student *ppStu[MAX_STU_NO]);

void searchStudent(Student *ppStu[MAX_STU_NO]);

void delStudent(Student *ppStu[MAX_STU_NO]);

void altStudent(Student *ppStu[MAX_STU_NO]);

#endif // MODEL_H
