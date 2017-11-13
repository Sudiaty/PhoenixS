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
	printf("\n ������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%ld",&lNo); 
	for(i=0;(i<MAX_STU_NO) && (stu[i]!=NULL);i++) 
	{
	    if(strncmp(stu[i]->nu,lNo,11)==0)
		{ 
		    printf("\n ����Ҫ�޸ĵ�ѧ����¼!");
			break; 
		}
	}
	if((i==MAX_STU_NO) || (stu[i]==NULL)) 
	{
		printf("\n ������Ҫ�޸ĵ�ѧ����¼!");
		return;
	}
    /*��ʼ�޸�ѧ����Ϣ*/ 
	printf("\n********------------********** �� �� Ҫ �� �� �� �� ¼ ��?**********------------********\n"); 
	printf("| ѧ�� | �༶ | ���� | �Ա� | ���� | ��ѧ | Ӣ�� | ���� | �ܷ� |ƽ����|\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n"); 
	printf("|%-12s|%-6s|%-6s|%-6s|%6d|%6d|%6d|%6d|%6d|%6.2f|\n",stuArray[i]->nu,stuAr ray[i]->cl,stuArray[i]->name,stuArray[i]->sex,stuArray[i]->score[0], stuArray[i]->score[1],stuArray[i]->score[2],stuArray[i]->score[3],stuArray[i]->sum,stuArray[i]>average);
	printf("\n********------------********************------------********\n");
	printf("��ȷ��Ҫ�޸ĸü�¼��?Y or N\n"); 
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
		printf("Ҫ�޸��ĸ���Ŀ�ĳɼ�������Ϊ 1����ѧΪ 2��Ӣ��Ϊ 3������Ϊ 4��\n"); 
		scanf("%d",&j); 
		do
		{
			printf("��Ŀ%d �ɼ�",j); 
			scanf("%d",&stuArray[i]->score[j-1]); 
			if((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)) 
			{ 
				printf("�������ݣ� ����������!\n"); 
			}}while((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)); 
			printf("��Ҫ�����޸Ĵ˼�¼��?Y or N!\n");
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

	//����Ҫ���Եĺ���
	delStudent(stu);

	return 0;
}