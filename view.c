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
			printf("\033[47;31m%8s\033[0m%-2d.%-6s"," ", 2 * i + j + 1, ppList[2 * i + j]);		//@ZhangLY£º´ýÓÅ»¯
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
* Author:ZhangLY,LiuXL;
* Function:dialog();
* Description:
****************************************/
void dialog(char content[10])
{
	printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	printf("\033[47;31m%46s\033[0m\n","");
	printf("\033[47;31m%17s%-6s%17s\033[0m\n","",content,"");
	printf("\033[47;31m%46s\033[0m\n","");
	printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
}

/****************************************
* Author:LiuXL;
* Function:form();
* Description:Form used to input.
****************************************/
void form(Form *cpForm[MAX_ROW])
{
	int i;
	for (i = 0; i<MAX_ROW&&cpForm[i]->m_cpTitle!=NULL; i++)
	{
		printf("\t%s:", cpForm[i]->m_cpTitle);
		scanf("%10s", &cpForm[i]->m_cpContent);
	}
}

/****************************************
* Author:LiuXL,ZhangLY;
* Function:alert();
* Description:
****************************************/
int alert()
{
	int sign, status = 0;
	do
	{
		printf("\033[47;31mÊÇ·ñ¼ÌÐø£¿1.¼ÌÐø£¬0.ÖÕÖ¹\033[0m");
		scanf("%d", &sign);
		if (sign != 1 && sign != 0) {
			printf("\033[47;31mÖ¸ÁîÓÐÎó£¬ÇëÖØÐÂÊäÈë£º\033\n");
			status = 1;
		}
		else {
			return sign;
		}
	} while (status);
}