/****************************************
* Author:LiuXL;
* Description:Functions related with
*   Point class.
****************************************/

#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addPoint();
* Description:录入成绩
****************************************/
int addPoint(Student *ppStu[MAX_STU_NO],
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],
	long stuNo,char cpCourseNo[10],int *pointNum)
{
	int iPointNo=0,status=1;
	float fGoal;
	stuNo--;
	for(int j=0;j<MAX_STU_NO;j++)
	{
		if(strcmp(ppStu[stuNo]->m_cpMajor[j],cpCourseNo)==0)
		{
			for (iPointNo = 0; iPointNo < *pointNum; iPointNo++)
			{
				if (strcmp(ppPoint[iPointNo]->m_cpCourseNo, ppStu[stuNo]->m_cpMajor[j]) == 0)
				{
					status = 0;
					break;
				}
			}
			if (status)
			{
				printf("请输入成绩：");
				scanf("%f", &fGoal);
				DST_SPPI(Point, ppPoint, *pointNum)
				strcpy(ppPoint[*pointNum]->m_cpCourseNo, cpCourseNo);
				strcpy(ppPoint[*pointNum]->m_cpNo, ppStu[stuNo]->m_cpNo);
				ppPoint[*pointNum]->m_fGoal = fGoal;
				(*pointNum)++;
				return 1;
			}
			else
			{
				printf("成绩已录入！\n\n");
				return 0;
			}
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
	}while(fread(ppPoint[i++], sizeof(Point), 1, fp)&&i<MAX_STU_NO*MAX_SUB_NO);
	ppPoint[--i]=0x0;
	(*pointNum)=i;
	fclose(fp);
}

/****************************************
* Author:LiuXL;
* Function:calGPA();
* Description:返回指定学生的绩点
****************************************/
float calGPA(Student *ppStu[MAX_STU_NO],
	Course *ppCourse[MAX_SUB_NO],
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],
	long stuNo)
{
	float fpPoint[MAX_SUB_NO][2],fGPA=0,fSumPoint=0,fSumGoal=0;
	int j=0;		//指定学生的课程序数
	stuNo--;
	for(j=0;j<MAX_SUB_NO&&strcmp(ppStu[stuNo]->m_cpMajor[j],"\0");j++)
	{
		for(int k=0;k<MAX_SUB_NO;k++)				//对课程表遍历，k为第j+1们课程在pChem中的序数
		{
			if(!strcmp(ppStu[stuNo]->m_cpMajor[j],ppCourse[k]->m_cpCourseNo))
			{
				fpPoint[j][0]=ppCourse[k]->m_fGoal;				//统计已选课程学分
				for(int m=0;m<MAX_STU_NO*MAX_SUB_NO;m++)				//对成绩数组遍历
				{
					if(ppPoint[m]==NULL)
					{
						printf("没有“%s”的成绩记录！\n",ppCourse[k]->m_cpCourseName);				//Debug
						fpPoint[j][1]=0;
						break;
					}
					if(!strcmp(ppStu[stuNo]->m_cpNo,ppPoint[m]->m_cpNo)&&!strcmp(ppCourse[k]->m_cpCourseNo,ppPoint[m]->m_cpCourseNo))
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
	ppStu[stuNo]->m_fPoint=fGPA;
	// printf("%.2f",fGPA);				//Debug
	return fGPA;
}

/****************************************
* Author:LiuXL;
* Function:echoPoint();
* Description:返回指定学生的成绩单
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
		cpPointTable[0]="课程名称";
		cpPointTable[1]="学分";
		cpPointTable[2]="成绩";
	int j=3;
	for(int n=0;n<MAX_SUB_NO&&strcmp(ppStu[lNo]->m_cpMajor[n],"\0")!=0;n++)				//对指定学生所选课程进行遍历，n为该生所选课程序数
	{
		for(int m=0;m<MAX_SUB_NO;m++)
		{
			if(strcmp(ppCourse[m]->m_cpCourseNo,ppStu[lNo]->m_cpMajor[n])==0)				//匹配课程信息
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
* Function:echoTotalPoint();
* Description:返回指定班级的成绩单
****************************************/
char** echoTotalPoint(Student *ppStu[MAX_STU_NO],char cpClass[20])
{
	float fSum=0,fAvg=0;
	int iNo=0;
	char **cpStuTable;
	int j = 4,Row=0;
	cpStuTable = (char **)malloc((MAX_STU_NO * 4 + 8) * sizeof(char*));
	for (int i = 0; i < MAX_STU_NO * 4 + 4; i++) cpStuTable[i] = 0x0;
	cpStuTable[0] = "学号";
	cpStuTable[1] = "姓名";
	cpStuTable[2] = "班级";
	cpStuTable[3] = "绩点";
	for (int i = 0; i<MAX_STU_NO&&ppStu[i] != NULL; i++)
	{
		if (strcmp(ppStu[i]->m_cpClass, cpClass) == 0 || strcmp("*", cpClass) == 0)
		{
			cpStuTable[4 * Row + 4] = (char *)malloc(20 * sizeof(char));
			strcpy(cpStuTable[j++], ppStu[i]->m_cpNo);
			cpStuTable[4 * Row + 5] = (char *)malloc(20 * sizeof(char));
			strcpy(cpStuTable[j++], ppStu[i]->m_cpName);
			cpStuTable[4 * Row + 6] = (char *)malloc(20 * sizeof(char));
			strcpy(cpStuTable[j++], ppStu[i]->m_cpClass);
			cpStuTable[4 * Row + 7] = (char *)malloc(20 * sizeof(char));
			sprintf(cpStuTable[j++], "%.2f", ppStu[i]->m_fPoint);
			fSum += ppStu[i]->m_fPoint;
			iNo++;
			Row++;
		}
	}
	fAvg = fSum / iNo;
	cpStuTable[4 * Row + 4] = (char *)malloc(20 * sizeof(char));
	cpStuTable[j++] = "平均绩点：";
	cpStuTable[4 * Row + 5] = (char *)malloc(20 * sizeof(char));
	sprintf(cpStuTable[j++], "%.2f", fAvg);
	return cpStuTable;
}

/****************************************
* Author:LiuXL;
* Function:echoSubPoint();
* Description:返回指定班级的成绩单
****************************************/
char** echoSubPoint(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO], Point *ppPoint[MAX_STU_NO*MAX_SUB_NO],char cpClass[20],int courseNo)
{
	float fSum = 0, fAvg = 0;
	int iNo = 0;
	char **cpStuTable;
	int j = 4, Row = 0;
	courseNo--;
	cpStuTable = (char **)malloc((MAX_STU_NO * 4 + 8) * sizeof(char*));
	for (int i = 0; i < MAX_STU_NO * 4 + 4; i++) cpStuTable[i] = 0x0;
	cpStuTable[0] = "学号";
	cpStuTable[1] = "姓名";
	cpStuTable[2] = "班级";
	cpStuTable[3] = "分数";
		for (int iStuNo = 0; ppStu[iStuNo] != NULL; iStuNo++)				//对学生进行遍历，匹配课程代码
		{
			for (int iPointNo = 0; ppPoint[iPointNo] != NULL; iPointNo++)
			{
				if (strcmp(ppStu[iStuNo]->m_cpNo, ppPoint[iPointNo]->m_cpNo) == 0 &&
					strcmp(ppCourse[courseNo]->m_cpCourseNo, ppPoint[iPointNo]->m_cpCourseNo) == 0 && 
					(strcmp(ppStu[iStuNo]->m_cpClass, cpClass) == 0 || strcmp("*", cpClass) == 0))
				{
					cpStuTable[4 * Row + 4] = (char *)malloc(20 * sizeof(char));
					strcpy(cpStuTable[j++], ppStu[iStuNo]->m_cpNo);
					cpStuTable[4 * Row + 5] = (char *)malloc(20 * sizeof(char));
					strcpy(cpStuTable[j++], ppStu[iStuNo]->m_cpName);
					cpStuTable[4 * Row + 6] = (char *)malloc(20 * sizeof(char));
					strcpy(cpStuTable[j++], ppStu[iStuNo]->m_cpClass);
					cpStuTable[4 * Row + 7] = (char *)malloc(20 * sizeof(char));
					sprintf(cpStuTable[j++], "%.2f", ppPoint[iPointNo]->m_fGoal);
					fSum += ppPoint[iPointNo]->m_fGoal;
					iNo++;
					Row++;
			}
		}
	}
	fAvg = fSum / iNo;
	cpStuTable[4 * Row + 4] = (char *)malloc(20 * sizeof(char));
	cpStuTable[j++] = "平均分：";
	cpStuTable[4 * Row + 5] = (char *)malloc(20 * sizeof(char));
	sprintf(cpStuTable[j++], "%.2f", fAvg);
	return cpStuTable;
}