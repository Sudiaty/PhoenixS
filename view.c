/****************************************
* Author:ZhangLY;				
* Description: 
*	student class.
****************************************/

#include <stdio.h>

/****************************************
* Author:ZhangLY;
* Function:menuSelect();				
* Description:Add a menu.
****************************************/

int main()
{
		int number;                       /*定义输入的数字*/
		printf("\n\n");                   /*在屏幕上输出3个空行*/
		                                  /*开始输出菜单*/
		printf("—————————————————————————————————————————————\n");
		printf("          \033[47;31m                        \033[0m\n");
		printf("          \033[47;31m       学生管理系统       \033[0m\n");
		printf("          \033[47;31m                        \033[0m\n");
		printf("—————————————————————————————————————————————\n");
		printf("\t\t\033[47;31m  *主菜单项*  \033[0m\n");
		printf("\t\t—————————————\n");
		printf("\n");
		printf("\t\033[47;31m1、数据录入\033[0m\t\t\033[47;31m2、数据编辑\033[0m\n");
		printf("\t\033[47;31m3、数据查询\033[0m\t\t\033[47;31m4、数据删除\033[0m\n");
		printf("\t\033[47;31m5、数据保存\033[0m\t\t\033[47;31m0、数据显示\033[0m\n");
		/*结束菜单界面输出*/
		printf("\n\t请输入菜单项数字(1 - 6)(第一次进入系统请先初始化!):");
		scanf("%d",&number);
		switch(number) 
			{
				case 1:
					addStudent(ppStu[MAX_STU_NO]);
					break;
				case 2:
					altStudent(ppStu[MAX_STU_NO]);
					break;
				case 3:
					searchStudent(ppStu[MAX_STU_NO]);
					break;
				case 4:
					delStudent(ppStu[MAX_STU_NO]);
					break;
				case 5:
					saveStudent(ppStu[MAX_STU_NO]);
				    break;
				case 6:
					getStudent(ppStu[MAX_STU_NO]);
					break;
																			
			
			}
}

