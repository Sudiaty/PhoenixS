/*****************************
* Author:LiuXL;				
* Description:Function related
*	with student class
*****************************/

#include "student.h"

/*****************************
* Author:LiuXL;
* Function:addStudent();				
* Description:Add a student's
*	record;
*****************************/
void addStudent(Student *stu)
{
	int i,status=1;
	for(i=stuNum;i<MAX_SUB_NO;i++)
	{
		printf("请输入学号:");
		scanf("%ld",&stu->m_lNo);
		printf("请输入姓名:");
		scanf("%s",&stu->m_cpName);
		printf("请输入性别(男m，女f）:");
		scanf("%d",&stu->m_iGender);

		stuNum++;	//学生人数自增

		do
		{
			int status=1;
			printf("是否继续输入（1.继续/0.终止）？");
			scanf("%d",&status);
			switch(status)
			{
				case 1:break;
				case 0:return;
				default:
					printf("非法输入！");
					status=1;
			}
		}while(status);
	}
}