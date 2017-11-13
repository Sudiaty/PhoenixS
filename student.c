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
	int status,sign;	//定义用于判断操作状态的变量
	int i;
	for(i=0;i<MAX_STU_NO;i++)
	{
		//录入数据
		Student *pInfoTmp=(Student *)malloc(sizeof(Student));
		printf("请输入学号:");
		scanf("%ld",&pInfoTmp->m_lNo);
		printf("请输入姓名:");
		scanf("%s",&pInfoTmp->m_cpName);
		printf("请输入性别(男m，女f）:");
		scanf("%s",&pInfoTmp->m_cpGender);
		ppStu[i]=pInfoTmp;

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
					free(pInfoTmp);
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
* Description:Save the info to Student.dat.
****************************************/
void saveStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//打开ppStudent.dat
	if ((fp=fopen("Student.dat","wb+"))==NULL)
	{
		printf("Student.dat不存在！\n");
		exit(0);
	}

	//写入ppStudent.dat
	if(fwrite(ppStu,sizeof(Student),stuNum,fp))
		printf("写入成功！\n");
	else
		printf("写入失败!\n");
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
	printf("\n ������Ҫɾ����ѧ��ѧ��:"); 
	scanf("%ld",&lNo); 
	j=i+1; 
	for(i=0;i<MAX_STU_NO && ppStu[i]!=NULL;i++)
	{    
	    if(ppStu[i]->m_lNo==lNo)
		{
		    printf("\n ����Ҫɾ����ѧ����¼");
			break; 
		} 
	} 
	if((i==MAX_STU_NO)||(ppStu[i]==NULL))
	{ 
	    printf("\n ������Ҫɾ����ѧ����¼��");
		return; 
	}
/*���Ҫɾ����ѧ����Ϣ��ʼ*/ 
	printf("\n********------------********** �� �� Ҫ ɾ �� �� �� ¼ ��?**********------------********\n"); 
	printf("| ѧ�� | ���� | �Ա� | ��Ŀһ | ��Ŀ�� | ��Ŀ�� | ��Ŀ�� |\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n");
	printf("|%-12s|%-6s|%-6s|%6d|%6d|%6d|%6d|\n",ppStu[i]->m_lNo,ppStu[i]->m_cpName,ppStu[i]->m_iGender,ppStu[i]->m_ipMajor[0], ppStu[i]->m_ipMajor[1],ppStu[i]->m_ipMajor[2],ppStu[i]->m_ipMajor[3]);
	printf("\n********------------********** **********------------********\n"); 
	printf("��ȷ��Ҫɾ���ü�¼��?Y or N!\n"); 
	scanf("%s",&c);
	if((c=='Y')||(c=='N')) 
	{ 
		for(j=i+1;j<MAX_STU_NO-i;j++) 
		{ ppStu[j-1]=ppStu[j]; } 
		ppStu[j]=NULL;
        printf("����ɾ��......\n"); 
		printf("\n.......�Ѿ�ɾ��ѧ��Ϊ%ld ��ѧ����¼......\n",lNo); } 
	else 
	{ printf("�������˵�"); }
 } 

/****************************************
* Author:SunZT,JiaZG;
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
			scanf("%s",&ppStu[i]->m_cpGender);
		}
		else
		{
			printf("非法输入！\n");
			return;
		}
	}
}


/****************************************
* Author:JiaZG;
* Function:getStudent();				
* Description:get the info to Student.dat.
****************************************/
void getStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//打开Student.dat
	if ((fp=fopen("Student.dat","wb+"))==NULL)
	{
		printf("Student.dat不存在！\n");
		exit(0);
	}
    for(i=0;i<MAX_STU_NO;i++)
	{
		fread(ppStu,sizeof(Student),stuNum,fp);
	}
	printf("获取成功！\n");
}


 
/****************************************  
* Author:JiaZG;
* Function:echoStudent();				
* Description:echo a ppStudent's record.
****************************************/
void echoStudent(Student *ppStu[MAX_STU_NO])
{
	int i = 0;     /*学生记录行号*/
	long lNo;    /*学号*/
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
