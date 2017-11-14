/*****************************
* Author:LiuXL				
* Description:Student Obeject
*****************************/

#ifndef __COURSE_H
#define __COURSE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//创建课表信息
typedef struct CourseClass
{
	long m_lCouseNo;
	char m_cpCourseName[40];
	float m_fGoal;
}Course;

//实例化课表
static Course pChem[MAX_SUB_NO]={
	{11600,"普通物理(II)",4.0},
	{23500,"有机化学(I)",3.5}
};

//声明Course对象具有的方法
void addCourse(Student *ppStu[MAX_STU_NO]);

#endif