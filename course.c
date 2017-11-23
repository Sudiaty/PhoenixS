/****************************************
* Author:LiuXL;
* Description:Function related with
*	course class.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:echoCourse();				
* Description:List the courses exist.
****************************************/
char** echoCourse(Course *ppCourse[MAX_SUB_NO])
{
	int i,j=3;
	char **cpCourseTable;
	cpCourseTable = (char **)malloc((MAX_SUB_NO * 3 + 3) * sizeof(char*));
	cpCourseTable[0] = "�γ̴���";
	cpCourseTable[1] = "�γ�����";
	cpCourseTable[2] = "ѧ��";
	for (i = 0; i<MAX_STU_NO&&strcmp(ppCourse[i]->m_cpCourseNo, "\0"); i++)
	{
		cpCourseTable[3 * i + 3] = (char *)malloc(20 * sizeof(char));
		strcpy(cpCourseTable[j++], ppCourse[i]->m_cpCourseNo);
		cpCourseTable[3 * i + 4] = (char *)malloc(20 * sizeof(char));
		strcpy(cpCourseTable[j++], ppCourse[i]->m_cpCourseName);
		cpCourseTable[3 * i + 5] = (char *)malloc(20 * sizeof(char));
		sprintf(cpCourseTable[j++],"%.2f",ppCourse[i]->m_fGoal);
	}
	return cpCourseTable;
}

/****************************************
* Author:LiuXL;
* Function:addCourse();				
* Description:Add a course for a student.
****************************************/
void addCourse(Student *ppStu[MAX_STU_NO],long stuNo)
{
	char cpMajor[10];
	int j;
	stuNo--;
	for(j=0;j<MAX_SUB_NO&&strcmp(ppStu[stuNo]->m_cpMajor[j],"\0")!=0;j++);
	printf("������γ̴��룺");
	scanf("%s",cpMajor);
	strcpy(ppStu[stuNo]->m_cpMajor[j],cpMajor);
}



/****************************************
* Author:JiaZG,LiuXL;
* Function:printCourse();				
* Description:print a course for a student.
****************************************/
char** printCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],long stuNo)
{
	int j=5,m,n;
	char **cpCourseTable;
	stuNo--;
	cpCourseTable=(char **)malloc((MAX_SUB_NO*5+5)*sizeof(char*));
	cpCourseTable[0]="�γ̴���";
	cpCourseTable[1]="�γ�����";
	cpCourseTable[2]="�γ�ѧ��";
	cpCourseTable[3]="�Ͽεص�";
	cpCourseTable[4]="�Ͽ�ʱ��";
	for(n=0;n<MAX_SUB_NO&&strcmp(ppStu[stuNo]->m_cpMajor[n],"\0")!=0;n++)
	{
		for(m=0;m<MAX_SUB_NO;m++)
		{
			if(strcmp(ppCourse[m]->m_cpCourseNo,ppStu[stuNo]->m_cpMajor[n])==0)
			{
				cpCourseTable[5*n+5]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],ppCourse[m]->m_cpCourseNo);
				cpCourseTable[5*n+6]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],ppCourse[m]->m_cpCourseName);
				cpCourseTable[5*n+7]=(char *)malloc(20*sizeof(char)); 
				sprintf(cpCourseTable[j++],"%.2f",ppCourse[m]->m_fGoal);
				cpCourseTable[5*n+8]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],ppCourse[m]->m_cpAdress);
				cpCourseTable[5*n+9]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],ppCourse[m]->m_cpTime);
				break;
			}
		}
	}
	return cpCourseTable;
}

/****************************************
* Author:JiaZG,LiuXL;
* Function:searchCourse();				
* Description:��֤�γ��Ƿ����
****************************************/
char* searchCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],char cpNo[10],char cpCourseNo[10])
{
	int i,j;
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			printf("\n������γ̴��룺");
			scanf("%s",cpCourseNo);
			for(j=0;j<MAX_SUB_NO;j++)
			{
				if(strcmp(ppCourse[j]->m_cpCourseNo,cpCourseNo)==0)
				{
					printf("�ÿγ̼�¼���£�\n");
					printf("|\t�γ̴���\t|\t�γ�����\t|\t�γ�ѧ��\t|\t�Ͽεص�\t|\t�Ͽ�ʱ��\t|\n");
					printf("|%16s|\t%4s\t|\t%4s\t|\t%16f\t|\t%16s\t|\n",ppCourse[j]->m_cpCourseNo,ppCourse[j]->m_cpCourseName,ppCourse[j]->m_fGoal,ppCourse[j]->m_cpAdress,ppCourse[j]->m_cpTime);
					return cpCourseNo;
				}
			}
			if(j==MAX_SUB_NO)
			{
				printf("\n�����ڸÿγ̣�");
				return NULL;
			}
		}
	}
}

/****************************************
* Author:JiaZG;
* Function:delCourse();				
* Description:delete a course for a student.
****************************************/
void delCourse(Student *ppStu[MAX_STU_NO],char cpNo[10],char cpCourseNo[10])
{
	int i,j,k;
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			for(j=0;j<MAX_STU_NO;j++)
			{
				if(strcmp(ppStu[i]->m_cpMajor[j],cpCourseNo)==0)
				{
					for(k=j;k<MAX_SUB_NO&&strcmp(ppStu[i]->m_cpMajor[k],"\0")!=0;k++)
					{
						strcpy(ppStu[i]->m_cpMajor[k],ppStu[i]->m_cpMajor[k+1]);
					}
					printf("�����˿�......\n");
					printf("�Ѿ���ѡ�γ̴���Ϊ%s �Ŀγ�\n",cpCourseNo);
					break;
				}
			}
		}
	}
}