/****************************************
* Author:LiuXL;				
* Description:Function related with 
*	student class.
****************************************/

#include <stdio.h>
#include "student.h"


/****************************************
* Author:LiuXL;
* Function:addStudent();				
* Description:Add a student's record.
****************************************/
void addStudent(Student *stu)
{
	int status,sign;	//定义用于判断操作状态的变量
	int i;
	for(i=stuNum;i<MAX_SUB_NO;i++)
	{
		//录入数据
		printf("请输入学号:");
		scanf("%ld",&stu->m_lNo);
		printf("请输入姓名:");
		scanf("%s",&stu->m_cpName);
		printf("请输入性别(男m，女f）:");
		scanf("%d",&stu->m_iGender);

		stuNum++;	//学生人数自增

		//判断是否继续录入数据
		do
		{
			printf("是否继续输入（1.继续/0.终止）？");
			scanf("%d",&sign);
			switch(sign)
			{
				case 1:
					status=0;
					break;
				case 0:
					return;
				default:
					printf("非法输入！\n");
					status=1;
			}
		}while(status);
	}
}


/****************************************
* Author:LiuXL;
* Function:saveStudent();				
* Description:Save the info to student.dat.
****************************************/
void saveStudent(Student *stu)
{
	FILE *fp;
	int i;

	//打开student.dat
	if ((fp=fopen("student.dat","wb+"))==NULL)
	{
		printf("Student.dat不存在！\n");
		exit(0);
	}

	//写入student.dat
	if(fwrite(stu,sizeof(Student),stuNum,fp))
		printf("写入成功！\n");
	else
		printf("写入失败!\n");
}

/****************************************
* Author:JiaZG;
* Function:getStudent();				
* Description:get a student's record.
****************************************/
void getStudent(Student *p)
{
	int i = 0;     /*学生记录行号*/
	char s[11];    /*学号*/
	printf("\n请输入要查询学生的学号：");
	scanf("%s",&s);
	for(i=stuNum;i<MAX_STU_NO;i++)
	{
		if(strncmp(&stu->m_lNo,s,11)==0)
		{
			printf("\n存在要查询的学生记录！");
			break;
		}
	}
	
	if(i==MAX_STU_NO)
	{
		printf("\n不存在要查询的学生记录！");
		return;
	}
	//输出所查学生记录
	printf("\n所查记录如下：");
}

