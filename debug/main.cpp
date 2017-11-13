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
	printf("\n ������Ҫɾ���ѧ��ѧ��:"); 
	scanf("%ld",&lNo); 
	j=i+1; 
	for(i=0;i<MAX_STU_NO && ppStu[i]!=NULL;i++)
	{    
	    if(ppStu[i]->m_lNo==lNo)
		{
		    printf("\n ����Ҫɾ���ѧ���¼");
			break; 
		} 

	} 
	if((i==MAX_STU_NO)||(ppStu[i]==NULL))
	{ 
	    printf("\n ������Ҫɾ���ѧ���¼��");
		return; 
	}
/*���Ҫɾ���ѧ����Ϣ��ʼ*/ 
	printf("\n********------------********** �� �� Ҫ ɾ �� �� �� ¼ ��?**********------------********\n"); 
	printf("| ѧ�� | ���� | �Ա� | ��Ŀһ | ��Ŀ�� | ��Ŀ�� | ��Ŀ�� |\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n");
	printf("|%-12s|%-6s|%-6s|%6d|%6d|%6d|%6d|\n",ppStu[i]->m_lNo,ppStu[i]->m_cpName,ppStu[i]->m_iGender,ppStu[i]->m_ipMajor[0], ppStu[i]->m_ipMajor[1],ppStu[i]->m_ipMajor[2],ppStu[i]->m_ipMajor[3]);
	printf("\n********------------********** **********------------********\n"); 
	printf("��ȷ��Ҫɾ��ü�¼��?Y or N!\n"); 
	scanf("%s",&c);
	if((c=='Y')||(c=='N')) 
	{ 
		for(j=i+1;j<MAX_STU_NO-i;j++) 
		{ ppStu[j-1]=ppStu[j]; } 
		ppStu[j]=NULL;
        printf("����ɾ��......\n"); 
		printf("\n.......�Ѿ�ɾ��ѧ��Ϊ%ld ��ѧ���¼......\n",lNo); } 
	else 
	{ printf("������˵�"); }
 } 


/****************************************
* Author:LiuXL,SunZT;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//实例化Student
	/*Student pUp1602[MAX_STU_NO]={
		{2016016036,"刘晓亮","男",1,4},
		{2016016037,"孙志焘","男",{1,2},4}
	};*/
	//定义结构体指针，ppStu[i]为第i+1个Student数组的指针
	Student *ppStu[MAX_STU_NO];
	
	//调用需要调试的函数
	addStudent(ppStu);
	saveStudent(ppStu);
	getStudent(ppStu); 
  delStudent(ppStu);
	return 0;
}