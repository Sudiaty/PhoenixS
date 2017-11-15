/****************************************
* Author:LiuXL;				
* Description:Function related with 
*	ppStudent class.
****************************************/

#include <stdio.h>
#include "student.h"


/****************************************
* Author:LiuXL;
* Function:addStudent();				
* Description:Add a student's record.
****************************************/
void addStudent(Student *ppStu[MAX_STU_NO])
{
	int status,sign;
	int i;
	for(i=0;i<MAX_STU_NO;i++)
	{
		//录入数据
		Student *pInfoTmp=(Student *)malloc(sizeof(Student));
		printf("请输入学号：");
		scanf("%ld",&pInfoTmp->m_lNo);
		printf("请输入姓名：");
		scanf("%s",&pInfoTmp->m_cpName);
		printf("请输入性别：");
		scanf("%s",&pInfoTmp->m_cpGender);
		printf("请输入班级：");
		scanf("%s",&pInfoTmp->m_cpClass);
		ppStu[i]=pInfoTmp;

		stuNum++;

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
					free(pInfoTmp);
					return;
				default:
					printf("指令有误，请重新输入：\n");
					status=1;
			}
		}while(status);
	}
	return;
}


/****************************************
* Author:LiuXL;
* Function:saveStudent();				
* Description:Save the info to Student.dat.
****************************************/
void saveStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//读取Student.dat
	if ((fp=fopen("Student.dat","wb+"))==NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}

	//获取当前学生人数
	for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
	{
		//写入数据至Student.dat
		fwrite(ppStu[i],sizeof(Student),1,fp);
	}
	fclose(fp);
}


/****************************************
* Author:JiaZG,LiuXL;
* Function:getStudent();				
* Description:get the info to Student.dat.
* add return the point of stuct.
****************************************/
void getStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//读取Student.dat
	if ((fp=fopen("Student.dat","wb+"))==NULL)
	{
		printf("暂无学生记录！\n");
		exit(0);
	}
    for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
	{
		fread(ppStu[i],sizeof(Student),1,fp);
	}
	fclose(fp);
}


/****************************************  
* Author:JiaZG;
* Function:searchStudent();				
* Description:search a student by m_lNo
****************************************/
void searchStudent(Student *ppStu[MAX_STU_NO])
{
	int i = 0;
	long lNo;
	printf("\n请输入要查询学生的学号：");
	scanf("%ld",&lNo);
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(ppStu[i]->m_lNo==lNo)
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
* Function:echoStudent();				
* Description:list all of the students
****************************************/
void echoStudent(Student *ppStu[MAX_STU_NO])
{
	int i,j;
	for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
	{
		printf("%ld %s %s %s",
			ppStu[i]->m_lNo,
			ppStu[i]->m_cpName,
			ppStu[i]->m_cpGender,
			ppStu[i]->m_cpClass);
		for(j=0;j<MAX_SUB_NO&&ppStu[i]->m_lpMajor[j]!=0;j++)
		{
			printf("%ld ",ppStu[i]->m_lpMajor[j]);
		}
		printf("\n");
	}
}


/****************************************
* Author:SunZT;
* Function:delStudent();				
* Description:Delete info of Student.dat.
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
	printf("这 是 要 删 除 的 记 录 吗?\n"); 
	printf("学号 姓名 性别\n"); 
 	printf("%ld %s %s\n",ppStu[i]->m_lNo,ppStu[i]->m_cpName,ppStu[i]->m_cpGender); 
	printf("你确定要删除该记录吗?Y or N!\n");
 	scanf("%s",&c);
 	if((c=='Y')||(c=='N')) 
 	{ 
 		for(j=i+1;j<MAX_STU_NO-i;j++) 
 		{ ppStu[j-1]=ppStu[j]; } 
 		ppStu[j]=NULL;
        printf("正在删除......\n"); 
		printf("已经删除学号为%ld 的学生记\n",lNo); } 
	else 
	{ printf("返回主菜单"); }
  } 


/****************************************
* Author:SunZT,JiaZG,LiuXL;
* Function:altStudent();				
* Description:alt a student's record.;
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO])
{
	int i = 0;                /*学生记录行号*/
 	int m = 0;             	  /*修改状态标志0不修改*/
 	long lNo;                 /*学号*/
 	char c;                   /*确认指令Y修改N不修改*/
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
	printf("%ld %s %s %s\n",
		ppStu[i]->m_lNo,
		ppStu[i]->m_cpName,
		ppStu[i]->m_cpGender,
		ppStu[i]->m_cpClass); 
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
	
	while(m==1)
	{
		printf("要修改哪条信息？(姓名n，性别s，班级c)\n");
		scanf("%s",&c);
		switch(c)
		{
			case 'n':
				printf("\n请输入修改后该学生的姓名：");
				scanf("%s",&ppStu[i]->m_cpName);
				m=0;
				break;
			case 's':
				printf("\n请输入修改后该学生的性别(男m，女f）：");
				scanf("%s",&ppStu[i]->m_cpGender);
				m=0;
				break;
			case 'c':
				printf("\n请输入修改后该学生的班级：");
				scanf("%s",&ppStu[i]->m_cpClass);
				m=0;
				break;
			default:
				printf("非法输入！\n");
				break;
		}
	}
}