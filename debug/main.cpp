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
			}
		}while((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)); 
			
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
	//����Ҫ���Եĺ���
	delStudent(ppstu);
	altStudent(ppStu); 
	return 0;
}
