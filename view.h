/*****************************
* Author:LiuXL
* Description:Point Obeject
*****************************/

#ifndef VIEW_H
#define VIEW_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROW 10
#define STU_FORM_ROW 4
typedef struct FormClass
{
    char m_cpTitle[20];
    char m_cpContent[20];
}Form;

void menuSelect();
void dialog(char content[10]);
void form(Form *ppForm[MAX_ROW]);
int alert();

#endif // VIEW_H
