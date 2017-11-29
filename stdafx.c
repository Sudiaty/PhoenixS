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

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������