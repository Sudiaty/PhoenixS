/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"

/****************************************
SunZT@Win
* Author:SunZT;
* Function:delStudent();				
* Description:Delete info of student.dat.
****************************************/
void delStudent(Student *stu[MAX_STU_NO])
{
	int i=0; 
	int j=0; 
	long lNo; 
	char c; 
	printf("\n 请输入要删除的学生学号:"); 
	scanf("%ld",&lNo); 
	j=i+1; 
	for(i=0;i<MAX_STU_NO&&stu[i]!=NULL;i++)
	{    
	    if(stu[i]->m_lNo==lNo)
		{
		    printf("\n 存在要删除的学生记录");
			break; 
		} 
	} 
	if((i==MAX_STU_NO)||stu[i]==NULL)
	{ 
	    printf("\n 不存在要删除的学生记录的");
		return; 
	}
}

/****************************************
* Author:LiuXL;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//实例化Student
	Student up1602[MAX_STU_NO]={
		{2016016000,"Debugger",1,1,4},
		{2016016001,"Error",0,{1,2},4}
	};
	
	Student *pTmp=up1602;

	Student *stu[MAX_STU_NO];

	//pTmp=(Student*)malloc(sizeof(Student));

	stu[0]=pTmp;

	delStudent(stu); 

	return 0;
}