// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// SMS.pch ����ΪԤ�����ͷ
// stdafx.obj ������Ԥ����������Ϣ

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
	char startHtml[1000]="<!DOCTYPE html><html><head><meta charset=\"gbk\"><title>�����ļ�</title></head><body><style>.midCol{margin: auto;}table{border: 0px;cellpadding:4px;background-color:#cccccc;	}</style><table class = \"midCol\" border = \"1px\">";
	char endHtml[1000]="</table></body></html>";

	//char fileExtension[10] = ".html";
	//strcat(fileName, fileExtension);
	if ((fp = fopen(fileName, "w")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}
	fprintf(fp, "%s",startHtml);
	fprintf(fp,"\n<tr><th colspan = \"%d\">SubPoint.html</th></tr>\n",iRow,fileName);
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

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������