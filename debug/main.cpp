/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"

/****************************************
* Author:JiaZG;
* Function:altStudent();				
* Description:alt a student's record.;
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO])
{
	int i = 0;                /*学生记录行号*/
	int m = 0;             	  /*修改状态标志0不修改*/
	long lNo;                 /*学号*/
	char c;                  /*确认指令Y修改N不修改*/
	printf("\n请输入要修改学生的学号：");
	scanf("%ld",&lNo);
	
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(ppStu[i]->m_lNo==lNo)
		{
			printf("\n存在要修改的学生记录！");
			break;
		}
	}
	if(i==MAX_STU_NO)
	{
		printf("\n不存在要修改的学生记录！");
		return;
	}
	printf("\n该学生记录如下：");
	printf("是否要修改该记录？y or n\n");
	scanf("%s",&c);
	if((c=='Y'|| c=='y'))
	{
		m=1;
	}
	else
	{
		printf("终止修改！\n");
		return;
	}
	
	if(m==1)
	{
		printf("要修改该生的姓名还是性别？n or s\n");
		scanf("%s",&c);
		if((c=='n'||c=='N'))
		{
			printf("\n请输入修改后该学生的姓名：");
			scanf("%s",&ppStu[i]->m_cpName);
		}
		if((c=='s'||c=='S'))
		{
			printf("\n请输入修改后该学生的性别(男m，女f）：");
			scanf("%s",&ppStu[i]->m_iGender);
		}
		else
		{
			printf("非法输入！\n");
			return;
		}
	}
}



/****************************************
* Author:LiuXL,SunZT;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//实例化Student
	/*Student pUp1602[MAX_STU_NO]={
		{2016016036,"刘晓亮","男",1,4},
		{2016016037,"孙志焘","男",{1,2},4}
	};*/
	//定义结构体指针，ppStu[i]为第i+1个Student数组的指针
	Student *ppStu[MAX_STU_NO];
	
	//调用需要调试的函数
	altStudent(ppStu);
	return 0;
}



