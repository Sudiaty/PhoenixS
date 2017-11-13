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
			}
		}while((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)); 
			
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
* Author:LiuXL,SunZT;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//å®ä¾‹åŒ–Student
	Student pUp1602[MAX_STU_NO]={
		{2016016036,"åˆ˜æ™“äº®",1,1,4},
		{2016016037,"å­™å¿—ç„˜",0,{1,2},4}
	};
	//å®šä¹‰ç»“æ„ä½“æŒ‡é’ˆï¼ŒppStu[i]ä¸ºç¬¬i+1ä¸ªStudentæ•°ç»„çš„æŒ‡é’ˆ
	Student *ppStu[MAX_STU_NO];
	ppStu[0]=pUp1602;
	//µ÷ÓÃÒªµ÷ÊÔµÄº¯Êı
	delStudent(ppstu);
	altStudent(ppStu); 
	return 0;
}
