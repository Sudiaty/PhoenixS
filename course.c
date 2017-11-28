/****************************************
* Author:LiuXL;
* Description:Function related with
*	Course class.
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
	for (i = 0; i < MAX_SUB_NO *3+3; i++) cpCourseTable[i] = 0x0;
	cpCourseTable[0] = "代码";
	cpCourseTable[1] = "课程名称";
	cpCourseTable[2] = "学分";
	for (int i = 0; i<MAX_STU_NO&&strcmp(ppCourse[i]->m_cpCourseNo, "\0"); i++)
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
* Description:Add a Course for a student.
****************************************/
void addCourse(Student *ppStu[MAX_STU_NO],long stuNo)
{
	char cpMajor[10];
	int j;
	stuNo--;
	for(j=0;j<MAX_SUB_NO&&strcmp(ppStu[stuNo-1]->m_cpMajor[j],"\0")!=0;j++);
	printf("请输入课程代码：");
	scanf("%s",cpMajor);
	strcpy(ppStu[stuNo-1]->m_cpMajor[j],cpMajor);
}



/****************************************
* Author:JiaZG,LiuXL;
* Function:printCourse();				
* Description:print a Course for a student.
****************************************/
char** printCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],long stuNo)
{
	int j=5,m,n;
	char **cpCourseTable;
	stuNo--;
	cpCourseTable=(char **)malloc((MAX_SUB_NO*5+5)*sizeof(char*));
	for (int i= 0; i < MAX_SUB_NO *5+ 5; i++) cpCourseTable[i] = 0x0;
	cpCourseTable[0]="代码";
	cpCourseTable[1]="课程名称";
	cpCourseTable[2]="学分";
	cpCourseTable[3]="地点";
	cpCourseTable[4]="上课时间";
	for(int n=0;n<MAX_SUB_NO&&strcmp(ppStu[stuNo]->m_cpMajor[n],"\0")!=0;n++)
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
* Description:验证课程是否存在
****************************************/
int searchCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],long stuNo,char cpCourseNo[10])
{
	int iCourseNo=0;
	printf("\n请输入课程代码：");
	scanf("%s",cpCourseNo);
	for(iCourseNo=0;iCourseNo<MAX_SUB_NO;iCourseNo++)
	{
		if(strcmp(ppCourse[iCourseNo]->m_cpCourseNo,cpCourseNo)==0)
		{
			printf("该课程记录如下：\n");
			printf("|\t代码\t|\t课程名称\t|\t学分\t|\n");
			printf("|\t%s\t|\t%s\t|\t%2.f\t|\n",ppCourse[iCourseNo]->m_cpCourseNo,ppCourse[iCourseNo]->m_cpCourseName,ppCourse[iCourseNo]->m_fGoal);
			return iCourseNo+1;
		}
	}
	if(iCourseNo==MAX_SUB_NO)
	{
		printf("\n不存在该课程！\n");
		return 0;
	}
}

/****************************************
* Author:JiaZG;
* Function:delCourse();				
* Description:delete a Course for a student.
****************************************/
void delCourse(Student *ppStu[MAX_STU_NO],Course *ppCourse[MAX_SUB_NO],long iStuNo,int iCourseNo)
{
	int iStuCourseNo,k;
	for(iStuCourseNo=0;iStuCourseNo<MAX_SUB_NO;iStuCourseNo++)
	{
		if(strcmp(ppStu[iStuNo-1]->m_cpMajor[iStuCourseNo],ppCourse[iCourseNo-1]->m_cpCourseNo)==0)
		{
			for(k=iStuCourseNo;k<MAX_SUB_NO&&strcmp(ppStu[iStuNo-1]->m_cpMajor[k],"\0")!=0;k++)
			{
				strcpy(ppStu[iStuNo-1]->m_cpMajor[k],ppStu[iStuNo-1]->m_cpMajor[k+1]);
			}
			printf("正在退课......\n");
			printf("退选成功！\n");
			break;
		}
	}
}