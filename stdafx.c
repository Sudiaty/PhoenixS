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
void exportTable(char** cpTableTmp,char fileName[20],int iRow)
{
	FILE *fp;
	int i = 0,j=0;
	char startHtml[1000]="<!DOCTYPE html><html><head><meta charset=\"gbk\"><title>导出文件</title></head><body><table>";
	char endHtml[1000]="</table></body></html>";

	//char fileExtension[10] = ".html";
	//strcat(fileName, fileExtension);
	if ((fp = fopen(fileName, "w")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}
	fprintf(fp, "%s",startHtml);
	fprintf(fp,"\n<thead>%s</thead>\n",fileName);
	for (i = 0; cpTableTmp[i*iRow] != NULL; i++)
	{	
		fprintf(fp, "<tr>\n");
		for(j=0;j<iRow;j++)
			fprintf(fp, "<th>%s</th>\n", cpTableTmp[iRow*i+j]);
		fprintf(fp, "</tr>\n");
	}
	fprintf(fp, "%s",endHtml);
	fclose(fp);
}

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用