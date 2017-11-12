/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"


/****************************************
* Author:JiaZG;
* Function:getStudent();				
* Description:get a student's record.
****************************************/
void getStudent(Student *stu)
{
	int i = 0;     /*学生记录行号*/
	long lNo;    /*学号*/
	printf("\n请输入要查询学生的学号：");
	scanf("%ld",&lNo);
	for(i=stuNum;i<MAX_STU_NO;i++)
	{
		if(stu->m_lNo==lNo)
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

/****************************************
* Author:LiuXL;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//实例化Student
	Student up1602[MAX_STU_NO]={2016016000,"Debugger",1,1,4};
	/*
	学号：2016016000
	姓名：Debugger
	性别：男
	已选课程编号：1
	GPA：4
	*/
	Student *stu=up1602;

	//
	getStudent(stu);

	return 0;
}