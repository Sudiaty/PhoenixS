/*****************************
* Author:LiuXL				
* Description:Point Obeject
*****************************/

#ifndef __VIEW_H
#define __VIEW_H

#include "student.h"

#define MAX_ROW 10
typedef struct FormClass
{
	char m_cpTitle[20];
	char m_cpContent[20]; 
}Form;

void form(Form *cpForm[MAX_ROW]);
void menuSelect(Student *ppStu[MAX_STU_NO]);

#endif