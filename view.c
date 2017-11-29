/****************************************
* Author:LiuXL
* Description:Functions used to diaplay
items.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:theme();
* Description:Windows»·¾³ÏÂÊä³ö²ÊÉ«×ÖÌå
****************************************/
void theme(int color)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color>0&&color<256){
		SetConsoleTextAttribute(hOut, color);
	}else{
		SetConsoleTextAttribute(hOut, 0x0007);
	}
}

/****************************************
* Author:LiuXL,ZhangLY;
* Function:list();
* Description:List the options.
****************************************/
void list(char ppList[MAX_ROW][20])
{
	for (int i = 0; i <= MAX_ROW&&strcmp(ppList[2 * i], "\0"); i++)
	{
		theme(124);
		printf("%46s\n"," ");
		for (int j = 0; j<2 && strcmp(ppList[2 * i + j], "\0"); j++)
		{
			printf("%8s%-2d.%-6s"," ", 2 * i + j + 1, ppList[2 * i + j]);		//@ZhangLY£º´ýÓÅ»¯
		}

		printf("%8s"," ");
		printf("\n%46s\n"," ");
		theme(0);
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
		theme(124);
		printf("|\t%s\t", cpTable[k]);
		theme(0);
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
	printf("\n");
}

/****************************************
* Author:LiuXL;
* Function:echo();
* Description:
****************************************/
void echo(char content[10])
{
	theme(252);
	printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	printf("%42s%-7s%42s\n","",content,"");
	printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	theme(0);
	printf("\n");
}

/****************************************
* Author:ZhangLY,LiuXL;
* Function:dialog();
* Description:
****************************************/
void dialog(char content[10])
{
	theme(252);
	printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	printf("%46s\n","");
	printf("%17s%-6s%17s\n","",content,"");
	printf("%46s\n","");
	printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	theme(0);
	printf("\n");
}

/****************************************
* Author:LiuXL;
* Function:Form();
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
	printf("\n");
}

/****************************************
* Author:LiuXL,ZhangLY;
* Function:alert("");
* Description:
****************************************/
int alert(char content[20])
{
	int sign, status = 0;
	do
	{
		theme(207);
		printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
		printf("%6s%10s%s%6s\n","",content,"ÊÇ·ñ¼ÌÐø£¿1.¼ÌÐø£¬0.ÖÕÖ¹","");
		printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");	
		theme(0);
		scanf("%d", &sign);
		printf("\n");
		if (sign != 1 && sign != 0) {
			printf("Ö¸ÁîÓÐÎó£¬ÇëÖØÐÂÊäÈë£º\n");
			sign = 0;
			status = 1;
		}
		else {
			status = 0;
			return sign;
		}
	} while (status);
}