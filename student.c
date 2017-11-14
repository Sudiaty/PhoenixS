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
		//å½•å…¥æ•°æ®
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

	//æ‰“å¼€ppStudent.dat
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
		fread(*ppStu,sizeof(Student),1,fp);
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
	printf("请输入学生学号：");
	scanf("%ld",&lNo);
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(ppStu[i]->m_lNo==lNo)
		{
			printf("\nå­˜åœ¨è¦æŸ¥è¯¢çš„å­¦ç”Ÿè®°å½•ï¼");
			break;
		}
	}
	
	if(i==MAX_STU_NO)
	{
		printf("\nä¸å­˜åœ¨è¦æŸ¥è¯¢çš„å­¦ç”Ÿè®°å½•ï¼");
		return;
	}
	//è¾“å‡ºæ‰€æŸ¥å­¦ç”Ÿè®°å½•
	printf("\næ‰€æŸ¥è®°å½•å¦‚ä¸‹ï¼š");
}


/****************************************  
* Author:LiuXL;
* Function:echoStudent();				
* Description:list all of the students
****************************************/
void echoStudent(Student *ppStu[MAX_STU_NO])
{
	int i = 0;
	for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
	{
		printf("%ld %s %s %s\n",
			ppStu[i]->m_lNo,
			ppStu[i]->m_cpName,
			ppStu[i]->m_cpGender,
			ppStu[i]->m_cpClass);
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
	printf("\n********------------********** 这 是 要 删 除 的 记 录 吗?**********------------********\n"); 
	printf("| 学号 | 姓名 | 性别 | 科目一 | 科目二 | 科目三 | 科目四 |\n"); 
 	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n");
 	printf("|%-12s|%-6s|%-6s|%6d|%6d|%6d|%6d|\n",ppStu[i]->m_lNo,ppStu[i]->m_cpName,ppStu[i]->m_cpGender,ppStu[i]->m_fpMajor[0], ppStu[i]->m_fpMajor[1],ppStu[i]->m_fpMajor[2],ppStu[i]->m_fpMajor[3]);
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
* Author:SunZT,JiaZG;
* Function:altStudent();				
* Description:alt a student's record.;
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO])
{
	int i = 0;                /*å­¦ç”Ÿè®°å½•è¡Œå·*/
	int m = 0;             	  /*ä¿®æ”¹çŠ¶æ€æ ‡å¿—0ä¸ä¿®æ”¹*/
	long lNo;                 /*å­¦å·*/
	char c;                   /*ç¡®è®¤æŒ‡ä»¤Yä¿®æ”¹Nä¸ä¿®æ”¹*/
	printf("\nè¯·è¾“å…¥è¦ä¿®æ”¹å­¦ç”Ÿçš„å­¦å·ï¼š");
	scanf("%ld",&lNo);
	
	for(i=0;i<MAX_STU_NO;i++)
	{
		if(ppStu[i]->m_lNo==lNo)
		{
			printf("\nå­˜åœ¨è¦ä¿®æ”¹çš„å­¦ç”Ÿè®°å½•ï¼");
			break;
		}
	}
	if(i==MAX_STU_NO)
	{
		printf("\nä¸å­˜åœ¨è¦ä¿®æ”¹çš„å­¦ç”Ÿè®°å½•ï¼");
		return;
	}
	printf("\nè¯¥å­¦ç”Ÿè®°å½•å¦‚ä¸‹ï¼š");
	printf("æ˜¯å¦è¦ä¿®æ”¹è¯¥è®°å½•ï¼Ÿy or n\n");
	scanf("%s",&c);
	if((c=='Y'|| c=='y'))
	{
		m=1;
	}
	else
	{
		printf("ç»ˆæ­¢ä¿®æ”¹ï¼\n");
		return;
	}
	
	if(m==1)
	{
		printf("è¦ä¿®æ”¹è¯¥ç”Ÿçš„å§“åè¿˜æ˜¯æ€§åˆ«ï¼Ÿn or s\n");
		scanf("%s",&c);
		if((c=='n'||c=='N'))
		{
			printf("\nè¯·è¾“å…¥ä¿®æ”¹åŽè¯¥å­¦ç”Ÿçš„å§“åï¼š");
			scanf("%s",&ppStu[i]->m_cpName);
		}
		if((c=='s'||c=='S'))
		{
			printf("\nè¯·è¾“å…¥ä¿®æ”¹åŽè¯¥å­¦ç”Ÿçš„æ€§åˆ«(ç”·mï¼Œå¥³fï¼‰ï¼š");
			scanf("%s",&ppStu[i]->m_cpGender);
		}
		else
		{
			printf("éžæ³•è¾“å…¥ï¼\n");
			return;
		}
	}
}
