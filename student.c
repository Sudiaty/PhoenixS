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
	int status,sign;	//å®šä¹‰ç”¨äºåˆ¤æ–­æ“ä½œçŠ¶æ€çš„å˜é‡
	int i;
	for(i=stuNum;i<MAX_STU_NO;i++)
	{
		//å½•å…¥æ•°æ®
		printf("è¯·è¾“å…¥å­¦å·:");
		scanf("%ld",&stu->m_lNo);
		printf("è¯·è¾“å…¥å§“å:");
		scanf("%s",&stu->m_cpName);
		printf("è¯·è¾“å…¥æ€§åˆ«(ç”·mï¼Œå¥³fï¼‰:");
		scanf("%d",&stu->m_iGender);

		stuNum++;	//å­¦ç”Ÿäººæ•°è‡ªå¢

		//åˆ¤æ–­æ˜¯å¦ç»§ç»­å½•å…¥æ•°æ®
		do
		{
			printf("æ˜¯å¦ç»§ç»­è¾“å…¥ï¼ˆ1.ç»§ç»­/0.ç»ˆæ­¢ï¼‰ï¼Ÿ");
			scanf("%d",&sign);
			switch(sign)
			{
				case 1:
					status=0;
					break;
				case 0:
					return;
				default:
					printf("éæ³•è¾“å…¥ï¼\n");
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

	//æ‰“å¼€student.dat
	if ((fp=fopen("student.dat","wb+"))==NULL)
	{
		printf("Student.datä¸å­˜åœ¨ï¼\n");
		exit(0);
	}

	//å†™å…¥student.dat
	if(fwrite(stu,sizeof(Student),stuNum,fp))
		printf("å†™å…¥æˆåŠŸï¼\n");
	else
		printf("å†™å…¥å¤±è´¥!\n");
}

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
	printf("\n ÇëÊäÈëÒªÉ¾³ıµÄÑ§ÉúÑ§ºÅ:"); 
	scanf("%ld",&lNo); 
	j=i+1; 
	for(i=0;i<MAX_STU_NO && ppStu[i]!=NULL;i++)
	{    
	    if(ppStu[i]->m_lNo==lNo)
		{
		    printf("\n ´æÔÚÒªÉ¾³ıµÄÑ§Éú¼ÇÂ¼");
			break; 
		} 
	} 
	if((i==MAX_STU_NO)||(ppStu[i]==NULL))
	{ 
	    printf("\n ²»´æÔÚÒªÉ¾³ıµÄÑ§Éú¼ÇÂ¼µÄ");
		return; 
	}
/*Êä³öÒªÉ¾³ıµÄÑ§ÉúĞÅÏ¢¿ªÊ¼*/ 
	printf("\n********------------********** Õâ ÊÇ Òª É¾ ³ı µÄ ¼Ç Â¼ Âğ?**********------------********\n"); 
	printf("| Ñ§ºÅ | ĞÕÃû | ĞÔ±ğ | ¿ÆÄ¿Ò» | ¿ÆÄ¿¶ş | ¿ÆÄ¿Èı | ¿ÆÄ¿ËÄ |\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n");
	printf("|%-12s|%-6s|%-6s|%6d|%6d|%6d|%6d|\n",ppStu[i]->m_lNo,ppStu[i]->m_cpName,ppStu[i]->m_iGender,ppStu[i]->m_ipMajor[0], ppStu[i]->m_ipMajor[1],ppStu[i]->m_ipMajor[2],ppStu[i]->m_ipMajor[3]);
	printf("\n********------------********** **********------------********\n"); 
	printf("ÄãÈ·¶¨ÒªÉ¾³ı¸Ã¼ÇÂ¼Âğ?Y or N!\n"); 
	scanf("%s",&c);
	if((c=='Y')||(c=='N')) 
	{ 
		for(j=i+1;j<MAX_STU_NO-i;j++) 
		{ ppStu[j-1]=ppStu[j]; } 
		ppStu[j]=NULL;
        printf("ÕıÔÚÉ¾³ı......\n"); 
		printf("\n.......ÒÑ¾­É¾³ıÑ§ºÅÎª%ld µÄÑ§Éú¼ÇÂ¼......\n",lNo); } 
	else 
	{ printf("·µ»ØÖ÷²Ëµ¥"); }
 } 

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
	printf("\n è¯·è¾“å…¥è¦ä¿®æ”¹çš„å­¦ç”Ÿå­¦å·:");
	scanf("%ld",&lNo); 
	for(i=0;(i<MAX_STU_NO) && (ppStu[i]!=NULL);i++) 
	{
	    if(ppStu[i]->m_lNo==lNo)
		{ 
		    printf("\n å­˜åœ¨è¦ä¿®æ”¹çš„å­¦ç”Ÿè®°å½•");
			break; 
		}
	}
	if((i==MAX_STU_NO) || (ppStu[i]==NULL)) 
	{
		printf("\n ä¸å­˜åœ¨è¦ä¿®æ”¹çš„å­¦ç”Ÿè®°å½•");
		return;
	}
}
  
 
/****************************************
* Author:JiaZG;
* Function:getStudent();				
* Description:get the info to student.dat.
****************************************/
void getStudent(Student *stu)
{
	FILE *fp;
	int i;

	//æ‰“å¼€student.dat
	if ((fp=fopen("student.dat","wb+"))==NULL)
	{
		printf("Student.datä¸å­˜åœ¨ï¼\n");
		exit(0);
	}
    for(i=stuNum;i<MAX_STU_NO;i++)
	{
		fread(stu,sizeof(Student),stuNum,fp);
	}
	printf("è·å–æˆåŠŸï¼\n");
}Ã§Ã§

 
/****************************************  
* Author:JiaZG;
* Function:echoStudent();				
* Description:echo a student's record.
****************************************/
void echoStudent(Student *stu)
{
	int i = 0;     /*å­¦ç”Ÿè®°å½•è¡Œå·*/
	long lNo;    /*å­¦å·*/
	printf("\nè¯·è¾“å…¥è¦æŸ¥è¯¢å­¦ç”Ÿçš„å­¦å·ï¼š");
	scanf("%ld",&lNo);
	for(i=stuNum;i<MAX_STU_NO;i++)
	{
		if(stu->m_lNo==lNo)
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

