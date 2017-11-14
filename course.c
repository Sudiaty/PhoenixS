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
	long lNo;
	int status,sign;
	printf("请输入选课学生的学号：");
	scanf("%ld",&lNo);
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(ppStu[i]->m_lNo==lNo)
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
