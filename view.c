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
}

/****************************************
* Author:ZhangLY,LiuXL;
* Function:form();
* Description:Form used to input.
****************************************/
void dialog(char content[10])
{
	printf("—————————————————————————————————————————————\n");
	printf("\033[47;31m                                             \033[0m\n");
	printf("\033[47;31m                %6s                 \033[0m\n",content);
	printf("\033[47;31m                                             \033[0m\n");
	printf("—————————————————————————————————————————————\n");
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

/****************************************
* Author:LiuXL;
* Function:alert();
* Description:
****************************************/
int alert()
{
	int sign;
	loop:printf("是否继续输入？1.继续，0.终止");
	scanf("%d",&sign);
	if(sign!=1&&sign!=0){
		printf("指令有误，请重新输入：\n");
		goto loop;
	}else{
		return sign;
	}
}