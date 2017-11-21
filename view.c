/****************************************
* Author:LiuXL
* Description:Functions used to diaplay
items.
****************************************/
#include "stdafx.h"

/****************************************
* Author:ZhangLY;
* Function:menuSelect();
* Description:Add a menu.
****************************************/
void menuSelect()
{

	int number;                       /*�������������*/
	printf("\n\n");                   /*����Ļ�����3������*/
									  /*��ʼ����˵�*/
	printf("������������������������������������������������������������������������������������������\n");
	printf("\033[47;31m\t\t                             \033[0m\n");
	printf("\033[47;31m\t\t ѧ������ϵͳ                  \033[0m\n");
	printf("\033[47;31m\t\t                             \033[0m\n");
	printf("������������������������������������������������������������������������������������������\n");
	printf("\t\t\033[47;31m  *���˵���*  \033[0m\n");
	printf("\t\t��������������������������\n");
	printf("\n");
	printf("\t\033[47;31m1������¼��\033[0m\t\t\033[47;31m2�����ݱ༭\033[0m\n");
	printf("\t\033[47;31m3�����ݲ�ѯ\033[0m\t\t\033[47;31m4������ɾ��\033[0m\n");
	printf("\t\033[47;31m5�����ݱ���\033[0m\t\t\033[47;31m6��������ʾ\033[0m\n");
}

/****************************************
* Author:ZhangLY,LiuXL;
* Function:list();
* Description:Form used to input.
****************************************/
void stuMenu();

/****************************************
* Author:LiuXL;
* Function:list();
* Description:List the options.
****************************************/
void list(char ppList[MAX_ROW][20])
{
	for (int i = 0; i <= MAX_ROW&&strcmp(ppList[2 * i], "\0"); i++)
	{
		printf("\n\033[47;31m                                             \033[0m\n");
		for (int j = 0; j<2 && strcmp(ppList[2 * i + j], "\0"); j++)
		{
			printf("\033[47;31m        \033[0m%2d.%6s", 2 * i + j + 1, ppList[2 * i + j]);		//@ZhangLY�����Ż�
		}
		printf("\033[47;31m       \033[0m");
		printf("\n\033[47;31m                                             \033[0m\n");
	}
}

/****************************************
* Author:LiuXL;
* Function:table();
* Description:Show table.
****************************************/
void table(char **cpTable, int iRow)
{
	for (int k = 0; k<iRow; k++)
	{
		printf("\033[47;31m|%12s\033[0m", cpTable[k]);
	}
	printf("|\n");
	for (int i = 1; cpTable[iRow*i] != NULL; i++)
	{
		for (int j = 0; j<iRow&&cpTable[iRow*i + j] != NULL; j++)
		{
			printf("|%10s", cpTable[iRow*i + j]);
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
	printf("������������������������������������������������������������������������������������������\n");
	printf("\033[47;31m                                             \033[0m\n");
	printf("\033[47;31m                %6s                 \033[0m\n", content);
	printf("\033[47;31m                                             \033[0m\n");
	printf("������������������������������������������������������������������������������������������\n");
}

/****************************************
* Author:LiuXL;
* Function:form();
* Description:Form used to input.
****************************************/
void form(Form *cpForm[MAX_ROW])
{
	int i;
	for (i = 0; i<MAX_ROW&&cpForm[i] != NULL; i++)
	{
		printf("%s", cpForm[i]->m_cpTitle);
		scanf("%s", &cpForm[i]->m_cpContent);
	}
}

/****************************************
* Author:LiuXL;
* Function:alert();
* Description:
****************************************/
int alert()
{
	int sign, status = 0;
loop:
	do
	{
		printf("�Ƿ������1.������0.��ֹ");
		scanf("%d", &sign);
		if (sign != 1 && sign != 0) {
			printf("ָ���������������룺\n");
			status = 1;
		}
		else {
			return sign;
		}
	} while (status);
}
