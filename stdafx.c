// stdafx.cpp : 只包括标准包含文件的源文件
// SMS.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include <string.h>
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:exportTable();
* Description:Save the info to Point.dat.
****************************************/
void exportTable(char** cpTableTmp,char fileName[20])
{
	FILE *fp;
	int i = 0;
	//char fileExtension[10] = ".html";
	//strcat(fileName, fileExtension);
	if ((fp = fopen(fileName, "w")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}
	for (i = 0; cpTableTmp[i] != NULL; i++)
	{
		fprintf(fp, "<tr>%s<\\tr>\n", cpTableTmp[i]);
	}
	fclose(fp);
}

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用