#pragma once
/*****************************
* Author:LiuXL
* Description:View Obeject
*****************************/

#ifndef VIEW_H
#define VIEW_H


#include <stdio.h>

#define MAX_ROW 10
#define STU_FORM_ROW 4
typedef struct FormClass
{
	char m_cpTitle[20];
	char m_cpContent[20];
}Form;

void list(char ppList[MAX_ROW][20]);

void table(char **cpTable, int iRow);

void echo(char content[10]);

void dialog(char content[10]);

void userForm(Form *ppForm[MAX_ROW]);

int alert();

#endif // VIEW_H
