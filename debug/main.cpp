/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"


/****************************************
* Author:SunZT;
* Function:altStudent();				
* Description:Alt info student.dat.
****************************************/
void altStudent(Student *stu)
{ 
	int i=0;
    int j=0;
	int m=0;
	float sum=0; 
	long lNo;
	char c;
	printf("\n ÇëÊäÈëÒªĞŞ¸ÄµÄÑ§ÉúÑ§ºÅ:");
	scanf("%ld",&lNo); 
	for(i=0;(i<MAX_STU_NO) && (stu[i]!=NULL);i++) 
	{
	    if(strncmp(stu[i]->nu,lNo,11)==0)
		{ 
		    printf("\n ´æÔÚÒªĞŞ¸ÄµÄÑ§Éú¼ÇÂ¼!");
			break; 
		}
	}
	if((i==MAX_STU_NO) || (stu[i]==NULL)) 
	{
		printf("\n ²»´æÔÚÒªĞŞ¸ÄµÄÑ§Éú¼ÇÂ¼!");
		return;
	}
    /*¿ªÊ¼ĞŞ¸ÄÑ§ÉúĞÅÏ¢*/ 
	printf("\n********------------********** Õâ ÊÇ Òª ĞŞ ¸Ä µÄ ¼Ç Â¼ Âğ?**********------------********\n"); 
	printf("| Ñ§ºÅ | °à¼¶ | ĞÕÃû | ĞÔ±ğ | ÓïÎÄ | ÊıÑ§ | Ó¢Óï | ÕşÖÎ | ×Ü·Ö |Æ½¾ù·Ö|\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n"); 
	printf("|%-12s|%-6s|%-6s|%-6s|%6d|%6d|%6d|%6d|%6d|%6.2f|\n",stuArray[i]->nu,stuAr ray[i]->cl,stuArray[i]->name,stuArray[i]->sex,stuArray[i]->score[0], stuArray[i]->score[1],stuArray[i]->score[2],stuArray[i]->score[3],stuArray[i]->sum,stuArray[i]>average);
	printf("\n********------------********************------------********\n");
	printf("ÄãÈ·¶¨ÒªĞŞ¸Ä¸Ã¼ÇÂ¼Âğ?Y or N\n"); 
	scanf("%s",&c); 
	if((c=='Y') || (c=='y'))
	{ 
		m=1;
	} 
	else
	{ 
		editmenu(stuArray);
	}
	while(m==1)
	{ 
		printf("ÒªĞŞ¸ÄÄÄ¸ö¿ÆÄ¿µÄ³É¼¨£¨ÓïÎÄÎª 1£¬ÊıÑ§Îª 2£¬Ó¢ÓïÎª 3£¬ÕşÖÎÎª 4£©\n"); 
		scanf("%d",&j); 
		do
		{
			printf("¿ÆÄ¿%d ³É¼¨",j); 
			scanf("%d",&stuArray[i]->score[j-1]); 
			if((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)) 
			{ 
				printf("´íÎóÊı¾İ£¬ ÇëÖØĞÂÊäÈë!\n"); 
			}}while((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)); 
			printf("»¹Òª¼ÌĞøĞŞ¸Ä´Ë¼ÇÂ¼Âğ?Y or N!\n");
			scanf("%s",&c);
			if((c=='Y') || (c=='y')) 
			{ 
				m=1; } 
			else  { break;} 
			for(j=0;j<MAXSUB;j++)
			{ 
				sum+=stuArray[i]->score[j];
			} 
			stuArray[i]->average=sum/MAXSUB}
            return stuArray[i]; 
/****************************************
* Author:LiuXL;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//å®ä¾‹åŒ–Student
	Student up1602[MAX_STU_NO]={2016016000,"Debugger",1,1,4};
	/*
	å­¦å·ï¼š2016016000
	å§“åï¼šDebugger
	æ€§åˆ«ï¼šç”·
	å·²é€‰è¯¾ç¨‹ç¼–å·ï¼š1
	GPAï¼š4
	*/
	Student *stu=up1602;

	//µ÷ÓÃÒªµ÷ÊÔµÄº¯Êı
	delStudent(stu);

	return 0;
}