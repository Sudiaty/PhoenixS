/****************************************
* Author:LiuXL;
* Description:Functions related with
*   Point class.
****************************************/

#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addPoint();
* Description:¼��ɼ�
****************************************/
void addPoint(Student *ppStu[MAX_STU_NO],
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],
	char cpNo[10],char cpCourseNo[10],int *pointNum)
{
	float fGoal;
    for(int i=0;i<MAX_STU_NO;i++)
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			for(int j=0;j<MAX_STU_NO;j++)
			{
				if(strcmp(ppStu[i]->m_cpMajor[j],cpCourseNo)==0)
				{
					printf("������ɼ���");
					scanf("%f",&fGoal);
					strcpy(ppPoint[*pointNum]->m_cpCourseNo,cpCourseNo);
					strcpy(ppPoint[*pointNum]->m_cpNo,cpNo);
					ppPoint[*pointNum]->m_fGoal=fGoal;
					(*pointNum)++;
					break;
				}
			}
			break;
		}
	}
}

/****************************************
* Author:LiuXL;
* Function:savePoint();
* Description:Save the info to Point.dat.
****************************************/
void savePoint(Point *ppPoint[MAX_STU_NO*MAX_SUB_NO])
{
	FILE *fp;
	int i=0;

	if ((fp = fopen("Point.dat", "wb")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}
	for (i = 0;i<MAX_STU_NO*MAX_SUB_NO&&ppPoint[i]!=NULL;i++)
	{
		if (fwrite(ppPoint[i], sizeof(Point), 1, fp) != 1)
			printf("д��ʧ�ܣ�\n");
	}
	fclose(fp);
}

/****************************************
* Author:LiuXL;
* Function:getPoint();
* Description:get the info from Point.dat
****************************************/
void getPoint(Point *ppPoint[MAX_STU_NO*MAX_SUB_NO], int *pointNum)
{
	FILE *fp;
	int i=0;
	if ((fp = fopen("Point.dat", "rb")) == NULL)
	{
		return;
	}
	do
	{
		Point *pTmp=(Point*)malloc(sizeof(Point));
		ppPoint[i]=pTmp;
	}while(fread(ppPoint[i++], sizeof(Point), 1, fp)&&i<MAX_STU_NO*MAX_SUB_NO);
	ppPoint[--i]=0x0;
	(*pointNum)=i;
	fclose(fp);
}

/****************************************
* Author:LiuXL;
* Function:calGPA();
* Description:����ָ��ѧ���ļ���
****************************************/
float calGPA(Student *ppStu[MAX_STU_NO],
	Course *ppCourse[MAX_SUB_NO],
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],
	char cpNo[10])
{
	float fpPoint[MAX_SUB_NO][2],fGPA=0,fSumPoint=0,fSumGoal=0;
	for(int i=0;i<MAX_STU_NO;i++)			//��ѧ�������
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			int j=0;		//ָ��ѧ���Ŀγ�����
			for(j=0;j<MAX_SUB_NO&&strcmp(ppStu[i]->m_cpMajor[j],"\0");j++)
			{
				for(int k=0;k<MAX_SUB_NO;k++)				//�Կγ̱������kΪ��j+1�ǿγ���pChem�е�����
				{
					if(!strcmp(ppStu[i]->m_cpMajor[j],ppCourse[k]->m_cpCourseNo))
					{
						fpPoint[j][0]=ppCourse[k]->m_fGoal;				//ͳ����ѡ�γ�ѧ��
						for(int m=0;m<MAX_STU_NO*MAX_SUB_NO;m++)				//�Գɼ��������
						{
							if(ppPoint[m]==NULL)
							{
								printf("û�С�%s���ĳɼ���¼��\n",ppCourse[k]->m_cpCourseName);				//Debug
								fpPoint[j][1]=0;
								break;
							}
							if(!strcmp(cpNo,ppPoint[m]->m_cpNo)&&!strcmp(ppCourse[k]->m_cpCourseNo,ppPoint[m]->m_cpCourseNo))
							{
								// printf("1\n");		//Debug
								fpPoint[j][1]=0.05*ppPoint[m]->m_fGoal;
								break;
							}
						}
						break;				//�ҵ�ָ���γ̺�����ѭ��
					}
				}
			}
			for(int n=0;n<j;n++)
			{
				fSumPoint+=fpPoint[n][0];
				fSumGoal+=fpPoint[n][1]*fpPoint[n][0];
			}
			fGPA=fSumGoal/fSumPoint;
			ppStu[i]->m_fPoint=fGPA;
			// printf("%.2f",fGPA);				//Debug
			break;			//�ҵ�ָ��ѧ��������ѭ��
		}
	}
	return fGPA;
}

/****************************************
* Author:LiuXL;
* Function:echoPoint();
* Description:����ָ��ѧ���ĳɼ���
****************************************/
char** echoPoint(Student *ppStu[MAX_STU_NO],
	Course *ppCourse[MAX_SUB_NO],
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],
	long lNo)
{
	char **cpPointTable;
	cpPointTable=(char **)malloc((MAX_SUB_NO*3+3)*sizeof(char*));
	for (int k=0;k<3;k++)  
		cpPointTable[k]=(char *)malloc(20*sizeof(char));  
		cpPointTable[0]="�γ�����";
		cpPointTable[1]="ѧ��";
		cpPointTable[2]="�ɼ�";
	int j=3;
	for(int n=0;n<MAX_SUB_NO&&strcmp(ppStu[lNo]->m_cpMajor[n],"\0")!=0;n++)				//��ָ��ѧ����ѡ�γ̽��б�����nΪ������ѡ�γ�����
	{
		for(int m=0;m<MAX_SUB_NO;m++)
		{
			if(strcmp(ppCourse[m]->m_cpCourseNo,ppStu[lNo]->m_cpMajor[n])==0)				//ƥ��γ���Ϣ
			{
				cpPointTable[3*n+3]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpPointTable[j++],ppCourse[m]->m_cpCourseName);
				cpPointTable[3*n+4]=(char *)malloc(20*sizeof(char)); 
				sprintf(cpPointTable[j++],"%.2f",ppCourse[m]->m_fGoal);
				cpPointTable[3*n+5]=(char *)malloc(20*sizeof(char));
				for(int pNo=0;pNo<MAX_STU_NO*MAX_SUB_NO;pNo++)
				{
					if(ppPoint[pNo]==NULL)
					{
						strcpy(cpPointTable[j++],"0");
						break;
					}
					if(!strcmp(ppPoint[pNo]->m_cpNo,ppStu[lNo]->m_cpNo)&&!strcmp(ppCourse[m]->m_cpCourseNo,ppPoint[pNo]->m_cpCourseNo))
					{
						sprintf(cpPointTable[j++],"%.1f",ppPoint[pNo]->m_fGoal);
						break;
					}
				}
				break;
			}
		}
	}
	return cpPointTable;
}

/****************************************
* Author:LiuXL;
* Function:echoPoint();
* Description:����ָ��ѧ���ĳɼ���
****************************************/