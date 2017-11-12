/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"

/****************************************
* Author:SunZT;
* Function:altStudent();				
* Description:Alt info of student.dat.
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO])
{ 
	int i=0;
    int j=0;
	int m=0;
	float sum=0; 
	long lNo;
	char c;
	printf("\n 请输入要修改的学生学号:");
	scanf("%ld",&lNo); 
	for(i=0;(i<MAX_STU_NO) && (ppStu[i]!=NULL);i++) 
	{
	    if(ppStu[i]->m_lNo==lNo)
		{ 
		    printf("\n 存在要修改的学生记录");
			break; 
		}
	}
	if((i==MAX_STU_NO) || (ppStu[i]==NULL)) 
	{
		printf("\n 不存在要修改的学生记录");
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
	Student pUp1602[MAX_STU_NO]={
		{2016016036,"刘晓亮",1,1,4},
		{2016016037,"孙志焘",0,{1,2},4}
	};
	//定义结构体指针，ppStu[i]为第i+1个Student数组的指针
	Student *ppStu[MAX_STU_NO];

	ppStu[0]=pUp1602;

	altStudent(ppStu); 

	return 0;
}
