/****************************************
* Author:LiuXL;
* Description:Functions related with
*   point class.
****************************************/

#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addPoint();
* Description:录入成绩
****************************************/
void addPoint(Student *ppStu[MAX_STU_NO],Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],char cpNo[10],char cpCourseNo[10],int *pointNum)
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
					printf("请输入成绩：");
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
* Description:Save the info to point.dat.
****************************************/
void savePoint(Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],int *pointNum)
{
	FILE *fp;
	int i=0;

	if ((fp = fopen("Point.dat", "wb")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}
	for (i = 0; i<MAX_STU_NO*MAX_SUB_NO&&ppPoint[i]!=NULL; i++)
	{
		if (fwrite(ppPoint[i], sizeof(Point), 1, fp) != 1)
			printf("写入失败！\n");
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
		fread(ppPoint[i], sizeof(Point), 1, fp);
	}while(!strcmp(ppPoint[i++]->m_cpNo, "\0")&&i<MAX_STU_NO*MAX_SUB_NO);
	(*pointNum)=i;
}

/****************************************
* Author:LiuXL;
* Function:calGPA();
* Description:返回指定学生的成绩
****************************************/
void calGPA(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],char cpNo[10])
{
	float fpPoint[MAX_SUB_NO][2],fGPA=0,fSumPoint=0,fSumGoal=0;
	for(int i=0;i<MAX_STU_NO;i++)			//对学生表遍历
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			int j=0;		//指定学生的课程序数
			for(j=0;j<MAX_SUB_NO&&strcmp(ppStu[i]->m_cpMajor[j],"\0");j++)
			{
				for(int k=0;k<MAX_SUB_NO;k++)				//对课程表遍历，k为第j+1们课程在pChem中的序数
				{
					if(!strcmp(ppStu[i]->m_cpMajor[j],ppCourse[k]->m_cpCourseNo))
					{
						fpPoint[j][0]=ppCourse[k]->m_fGoal;				//统计已选课程学分
						for(int m=0;m<MAX_STU_NO*MAX_SUB_NO;m++)				//对成绩数组遍历
						{
							if(!strcmp(ppPoint[m]->m_cpNo, "\0"))
							{
								//printf("没有相应成绩记录！")；				//Debug
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
						break;				//找到指定课程后跳出循环
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
			printf("%.2f",fGPA);
			break;			//找到指定学生后跳出循环
		}
	}
}

/****************************************
* Author:LiuXL;
* Function:echoPoint();
* Description:返回指定学生的成绩
****************************************/