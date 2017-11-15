#include "view.h"

/****************************************
* Author:ZhangLY;
* Function:menuSelect();
* Description:Add a menu.
****************************************/
void menuSelect()
{
	int number;                       /*定义输入的数字*/
	printf("\n\n");                   /*在屏幕上输出3个空行*/
	                                  /*开始输出菜单*/
	printf("—————————————————————————————————————————————\n");
	printf("\033[47;31m\t\t                             \033[0m\n");
	printf("\033[47;31m\t\t 学生管理系统                  \033[0m\n");
	printf("\033[47;31m\t\t                             \033[0m\n");
	printf("—————————————————————————————————————————————\n");
	printf("\t\t\033[47;31m  *主菜单项*  \033[0m\n");
	printf("\t\t—————————————\n");
	printf("\n");
	printf("\t\033[47;31m1、数据录入\033[0m\t\t\033[47;31m2、数据编辑\033[0m\n");
	printf("\t\033[47;31m3、数据查询\033[0m\t\t\033[47;31m4、数据删除\033[0m\n");
	printf("\t\033[47;31m5、数据保存\033[0m\t\t\033[47;31m6、数据显示\033[0m\n");
	/*结束菜单界面输出*/
	printf("\n请输入菜单项数字(1 - 6):");
	scanf("%d",&number);			
	switch(number) 
	{
		case 1:
			printf("—————————————————————————————————————————————\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("\033[47;31m\t\t 学生数据录入                  \033[0m\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("—————————————————————————————————————————————\n");
			//addStudent(ppStu[MAX_STU_NO]);
			break;
		case 2:
			printf("—————————————————————————————————————————————\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("\033[47;31m\t\t 学生数据编辑                  \033[0m\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("—————————————————————————————————————————————\n");
			//altStudent(ppStu[MAX_STU_NO]);
			break;
		case 3:
			printf("—————————————————————————————————————————————\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("\033[47;31m\t\t 学生数据查询                  \033[0m\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("—————————————————————————————————————————————\n");
			//searchStudent(ppStu[MAX_STU_NO]);
			break;
		case 4:
			printf("—————————————————————————————————————————————\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("\033[47;31m\t\t 学生数据删除                  \033[0m\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("—————————————————————————————————————————————\n");
			//delStudent(ppStu[MAX_STU_NO]);
			break;
		case 5:
			printf("—————————————————————————————————————————————\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("\033[47;31m\t\t 学生管数据保存                  \033[0m\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("—————————————————————————————————————————————\n");
			// saveStudent(ppStu[MAX_STU_NO]);
		    break;
		case 6:
			printf("—————————————————————————————————————————————\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("\033[47;31m\t\t 学生管理显示                  \033[0m\n");
			printf("\033[47;31m\t\t                             \033[0m\n");
			printf("—————————————————————————————————————————————\n");
			// getStudent(ppStu[MAX_STU_NO]);
			break;
	}
}


/****************************************
* Author:LiuXL;
* Function:form();
* Description:Form used to input.
****************************************/
void form(Form *cpForm[MAX_ROW])
{
    int i;
    for(i=0;i<MAX_ROW&&cpForm[i]!=NULL;i++)
    {
        printf("%s",cpForm[i]->m_cpTitle);
        scanf("%s",&cpForm[i]->m_cpContent);
    }
}
