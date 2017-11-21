/****************************************
* Author:LiuXL;
* Description:Function related with
*	ppStudent class.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addStudent();
* Description:Add a student's record.
****************************************/
void addStudent(Student *ppStu[MAX_STU_NO], Form *ppForm[MAX_ROW], int *stuNum)
{
	strcpy(ppStu[*stuNum]->m_cpNo, ppForm[0]->m_cpContent);
	strcpy(ppStu[*stuNum]->m_cpName, ppForm[1]->m_cpContent);
	strcpy(ppStu[*stuNum]->m_cpGender, ppForm[2]->m_cpContent);
	strcpy(ppStu[*stuNum]->m_cpClass, ppForm[3]->m_cpContent);
	(*stuNum)++;
}


/****************************************
* Author:LiuXL;
* Function:saveStudent();
* Description:Save the info to Student.dat.
****************************************/
void saveStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//��ȡStudent.txt
	if ((fp = fopen("Student.dat", "wb")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}

	//��ȡ��ǰѧ������
	for (i = 0; i<MAX_STU_NO&&strcmp(ppStu[i]->m_cpNo, "\0") != 0; i++)
	{
		//д��������Student.txt
		if (fwrite(ppStu[i], sizeof(Student), 1, fp) != 1)
			printf("д��ʧ�ܣ�\n");
	}
	fclose(fp);
}


/****************************************
* Author:JiaZG,LiuXL;
* Function:getStudent();
* Description:get the info to Student.txt.
* add return the point of stuct.
****************************************/
void getStudent(Student *ppStu[MAX_STU_NO], int *stuNum)
{
	FILE *fp;
	int i, j;

	//��ȡStudent.dat
	if ((fp = fopen("Student.dat", "rb")) == NULL)
	{
		return;
	}
	for (i = 0; i<MAX_STU_NO; i++)
	{
		fread(ppStu[i], sizeof(Student), 1, fp);
	}
	for (j = 0; j<MAX_STU_NO&&strcmp(ppStu[j]->m_cpNo, "\0") != 0; j++)
	{
		(*stuNum)++;
	}
	fclose(fp);
}


/****************************************
* Author:JiaZG;
* Function:searchStudent();
* Description:search a student by m_cpNo
****************************************/
char* searchStudent(Student *ppStu[MAX_STU_NO], char cpNo[10])
{
	int i = 0;
	printf("\n������ѧ����ѧ�ţ�");
	scanf("%s", cpNo);
	for (i = 0; i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			printf("��ѧ����¼���£�\n");
			printf("|\tѧ��\t|\t����\t|\t�Ա�\t|\n");
			printf("|%16s|\t%4s\t|\t%4s\t|\n", ppStu[i]->m_cpNo, ppStu[i]->m_cpName, ppStu[i]->m_cpGender);
			return cpNo;
		}
	}
	if (i == MAX_STU_NO)
	{
		printf("\n�����ڸ�ѧ����¼��");
		return NULL;
	}
}


/****************************************
* Author:LiuXL;
* Function:echoStudent();
* Description:list all of the students
****************************************/
char **echoStudent(Student *ppStu[MAX_STU_NO])
{
	char **cpStuTable;
	cpStuTable = (char **)malloc((MAX_STU_NO * 4 + 4) * sizeof(char*));
	for (int k = 0; k<4; k++)
		cpStuTable[k] = (char *)malloc(20 * sizeof(char));
	cpStuTable[0] = "ѧ��";
	cpStuTable[1] = "����";
	cpStuTable[2] = "�Ա�";
	cpStuTable[3] = "�༶";
	int j = 4;
	for (int i = 0; i<MAX_STU_NO&&strcmp(ppStu[i]->m_cpNo, "\0"); i++)
	{
		cpStuTable[4 * i + 4] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpNo);
		cpStuTable[4 * i + 5] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpName);
		cpStuTable[4 * i + 6] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpGender);
		cpStuTable[4 * i + 7] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpClass);
	}
	return cpStuTable;
}


/****************************************
* Author:SunZT,LiuXL;
* Function:delStudent();
* Description:Delete info of Student.txt.
****************************************/
void delStudent(Student *ppStu[MAX_STU_NO], char cpNo[10], int *stuNum)
{

	for (int i = 0; i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			for (int j = i; j<MAX_STU_NO&&strcmp(ppStu[j]->m_cpNo, "\0") != 0; j++)
			{
				ppStu[j] = ppStu[j + 1];
			}
			(*stuNum)--;
			printf("����ɾ��......\n");
			printf("�Ѿ�ɾ��ѧ��Ϊ%s ��ѧ����\n", cpNo);
		}
	}
}


/****************************************
* Author:SunZT,JiaZG,LiuXL;
* Function:altStudent();
* Description:alt a student's record.;
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO], char cpNo[10])
{
	char c;
	for (int i = 0; i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			printf("Ҫ�޸�������Ϣ��(����n���Ա�s���༶c)\n");
			scanf("%s", &c);
			switch (c)
			{
			case 'n':
				printf("\n�������޸ĺ��ѧ����������");
				scanf("%s", &ppStu[i]->m_cpName);
				break;
			case 's':
				printf("\n�������޸ĺ��ѧ�����Ա�(��m��Ůf����");
				scanf("%s", &ppStu[i]->m_cpGender);
				break;
			case 'c':
				printf("\n�������޸ĺ��ѧ���İ༶��");
				scanf("%s", &ppStu[i]->m_cpClass);
				break;
			default:
				printf("�Ƿ����룡\n");
				break;
			}
		}
	}
}