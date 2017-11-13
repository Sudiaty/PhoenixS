/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"

/****************************************
* Author:SunZT;
* Function:delStudent();				
* Description:Delete info of student.dat.
****************************************/
void delStudent(Student *ppStu[MAX_STU_NO])
{
	int i=0; 
	int j=0; 
	long lNo; 
	char c; 
	printf("\n 请输入要删除的学生学号:"); 
	scanf("%ld",&lNo); 
	j=i+1; 
	for(i=0;i<MAX_STU_NO && ppStu[i]!=NULL;i++)
	{    
	    if(ppStu[i]->m_lNo==lNo)
		{
		    printf("\n 存在要删除的学生记录");
			break; 
		} 
	} 
	if((i==MAX_STU_NO)||(ppStu[i]==NULL))
	{ 
	    printf("\n 不存在要删除的学生记录的");
		return; 
	}
/*输出要删除的学生信息开始*/ 
	printf("\n********------------********** 这 是 要 删 除 的 记 录 吗?**********------------********\n"); 
	printf("| 学号 | 姓名 | 性别 | 科目一 | 科目二 | 科目三 | 科目四 |\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n");
	printf("|%-12s|%-6s|%-6s|%6d|%6d|%6d|%6d|\n",ppStu[i]->m_lNo,ppStu[i]->m_cpName,ppStu[i]->m_iGender,ppStu[i]->m_ipMajor[0], ppStu[i]->m_ipMajor[1],ppStu[i]->m_ipMajor[2],ppStu[i]->m_ipMajor[3]);
	printf("\n********------------********** **********------------********\n"); 
	printf("你确定要删除该记录吗?Y or N!\n"); 
	scanf("%s",&c);
	if((c=='Y')||(c=='N')) 
	{ 
		for(j=i+1;j<MAX_STU_NO-i;j++) 
		{ ppStu[j-1]=ppStu[j]; } 
		ppStu[j]=NULL;
        printf("正在删除......\n"); 
		printf("\n.......已经删除学号为%ld 的学生记录......\n",lNo); } 
	else 
	{ printf("返回主菜单"); }
 } 

/****************************************
* Author:LiuXL,SunZT;
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
	//?????????????
	delStudent(ppStu);
	return 0;
}