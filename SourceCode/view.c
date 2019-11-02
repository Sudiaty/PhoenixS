/****************************************
* Author:LiuXL
* Description:Functions used to diaplay
items.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL,ZhangLY;
* Function:list();
* Description:List the options.
****************************************/
void list(char ppList[MAX_ROW][20])
{
	for (int i = 0; i <= MAX_ROW&&strcmp(ppList[2 * i], "\0"); i++)
	{
		printf("\n\033[47;31m%46s\033[0m\n"," ");
		for (int j = 0; j<2 && strcmp(ppList[2 * i + j], "\0"); j++)
		{
			printf("\033[47;31m%8s\033[0m%-2d.%-6s"," ", 2 * i + j + 1, ppList[2 * i + j]);		//@ZhangLY：待优化
		}
		printf("\033[47;31m%8s\033[0m"," ");
		printf("\n\033[47;31m%46s\033[0m"," ");
	}
}

/****************************************
* Author:LiuXL,ZhangLY;
* Function:table();
* Description:Show table.
****************************************/
void table(char **cpTable, int iRow)
{
	for (int k = 0; k<iRow; k++)
	{
		printf("|\033[47;31m\t%s\t\033[0m", cpTable[k]);
	}
	printf("|\n");
	for (int i = 1; cpTable[iRow*i] != NULL; i++)
	{
		for (int j = 0; j<iRow&&cpTable[iRow*i + j] != NULL; j++)
		{
			printf("|\t%-s\t",cpTable[iRow*i+j]);
		}
		printf("|\n");
	}
}

/****************************************
* Author:LiuXL;
* Function:echo();
* Description:
****************************************/
void echo(char content[10])
{
	printf("——————————————————————————————————————————————\n");
	printf("\033[47;31m%16s%-8s%16s\033[0m\n","",content,"");
	printf("——————————————————————————————————————————————\n");
}

/****************************************
* Author:ZhangLY,LiuXL;
* Function:dialog();
* Description:
****************************************/
void dialog(char content[10])
{
	printf("——————————————————————————————————————————————\n");
	printf("\033[47;31m%46s\033[0m\n","");
	printf("\033[47;31m%17s%-6s%17s\033[0m\n","",content,"");
	printf("\033[47;31m%46s\033[0m\n","");
	printf("——————————————————————————————————————————————\n");
}

/****************************************
* Author:LiuXL;
* Function:form();
* Description:Form used to input.
****************************************/
void userForm(Form *cpForm[MAX_ROW])
{
	int i;
	for (i = 0; i<MAX_ROW&&cpForm[i]->m_cpTitle!=NULL; i++)
	{
		printf("\t%s:", cpForm[i]->m_cpTitle);
		scanf("%10s", &cpForm[i]->m_cpContent);
	}
}

/****************************************
* Author:LiuXL,ZhangLY
* Function:alert();
* Description:
****************************************/
int alert(char content[20])
{
	int sign, status = 0;
	do
	{
		printf("——————————————————————————————————————————————\n");
		printf("\033[47;31m%6s%10s%s%6s\033[0m\n","",content,"是否继续？1.继续，0.终止","");
		printf("——————————————————————————————————————————————\n");
		scanf("%d", &sign);
		printf("\n");
		if (sign != 1 && sign != 0) {
			printf("指令有误，请重新输入：\n");
			sign = 0;
			status = 1;
		}
		else {
			status = 0;
			return sign;
		}
	} while (status);
}