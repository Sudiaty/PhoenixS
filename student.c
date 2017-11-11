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