/****************************************
* Author:LiuXL;				
* Description:Function related with 
*	ppStudent class.
****************************************/
#include "course.h"

/****************************************
* Author:LiuXL;
* Function:addCourse();				
* Description:Add a course for a student.
****************************************/
void addCourse(Student *ppStu[MAX_STU_NO])
{
	int i,j,k;
	char cpNo[10];
	int status,sign;
	printf("请输入选课学生的学号：");
	scanf("%s",&cpNo);
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{			
			break;
		}else{
			printf("没有该学生的记录！\n");
			exit(0);
		}
	}

	//打印已有课程
	for(j=0;j<MAX_SUB_NO;j++)
	{
		printf("%ld %s %.1f\n",
			pChem[j].m_lCourseNo,
			pChem[j].m_cpCourseName,
			pChem[j].m_fGoal);
	}

	for(j=0;j<MAX_SUB_NO;j++)
	{	
		long lpMajor[MAX_SUB_NO]={0};
		printf("请输入课程代码：");
		scanf("%ld",&lpMajor[j]);
		ppStu[i]->m_lpMajor[j]=lpMajor[j];	
		do
		{
			printf("是否继续输入？1.继续，0.终止");
			scanf("%d",&sign);
			switch(sign)
			{
				case 1:
					status=0;
					break;
				case 0:
					printf("成功添加课程！\n");
					return;
				default:
					printf("指令有误，请重新输入：");
					status=1;
			}
		}while(status);	
	}
}



/****************************************
* Author:JiaZG;
* Function:printCourse();				
* Description:print a course for a student.
****************************************/
void printCourse(Student *ppStu[MAX_STU_NO],char cpNo[10])
{
	for(int i=0;i<MAX_STU_NO;i++)
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			char **cpCourseTable;
			cpCourseTable=(char **)malloc((MAX_SUB_NO*5+5)*sizeof(char*));
			for (int k=0;k<5;k++)  
				cpCourseTable[k]=(char *)malloc(20*sizeof(char));  
				cpCourseTable[0]="课程代码";
				cpCourseTable[1]="课程名称";
				cpCourseTable[2]="课程学分";
				cpCourseTable[3]="上课地点";
				cpCourseTable[4]="上课时间";
			int j=5;
			for(int i=0;i<MAX_SUB_NO&&strcmp(pChem[i]->m_lCourseNo,"\0");i++)
			{
				cpStuTable[5*i+5]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],pChem[i]->m_cpNo);
				cpStuTable[5*i+6]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],pChem[i]->m_cpCourseName);
				cpStuTable[5*i+7]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],pChem[i]->m_fGoal);
				cpStuTable[5*i+8]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],pChem[i]->m_cpAdress);
				cpStuTable[5*i+9]=(char *)malloc(20*sizeof(char)); 
				strcpy(cpCourseTable[j++],pChem[i]->m_cpTime);
			}
			return cpCourseTable;
		}
		}
	}
}



/****************************************
* Author:JiaZG;
* Function:delCourse();				
* Description:delete a course for a student.
****************************************/
void delCourse(Student *ppStu[MAX_STU_NO],char cpNo[10],long lCourseNo)
{
	
	for(int i=0;i<MAX_STU_NO;i++)
	{
		if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
		{
			int j = 0;
			printf("\n请输入要退选的课程代码：");
			scanf("%s",lCourseNo);
			for(j=0;i<MAX_SUB_NO;j++)
			{
				if(strcmp(pChem[j]->m_lCourseNo,lCourseNo)==0)
				{
					printf("该课程记录如下：\n");
					printf("|\t课程代码\t|\t课程名称\t|\t课程学分\t|\t上课地点\t|\t上课时间\t|\n");
					printf("|%16s|\t%4s\t|\t%4s\t|\t%16s\t|\t%16s\t|\n",pChem[j]->m_lCourseNo,pChem[j]->m_cpCourseName,pChem[j]->m_fGoal,pChem[j]->m_cpAdress,pChem[j]->m_cpTime);
					return lCourseNo;
				}
			}
			if(j==MAX_SUB_NO)
			{
				printf("\n不存在该课程！");
				return NULL;
			}
			for(int k=j;k<MAX_SUB_NO&&strcmp(ppStu[j]->m_lCourseNo,"\0")!=0;k++)
			{
				ppStu[k]=ppStu[k+1];
			}
			printf("正在退课......\n");
			printf("已经退选课程代码为%s 的课程\n",lCourseNo);
		}
	} 
}






		
