/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"view.h"
#include"student.h"
#include"course.h"

//全局变量声明
int stuNum=0;

/****************************************
* Author:LiuXL,SunZT;
* Function:main();
* Description:Debug;
****************************************/
int main()
{
    /*实例化Student对象*/
    Student *ppStu[MAX_STU_NO];
    for(int i=0;i<MAX_STU_NO;i++)
    {
        Student *pTmp=(Student*)malloc(sizeof(Student));
        ppStu[i]=pTmp;
    }

    /*实例化Form对象*/
    Form *ppStuForm[MAX_ROW];
    /*为学生信息表单对象赋初值*/
    for (int i=0; i<STU_FORM_ROW;++i)
    {
        Form *pTmp=(Form*)malloc(sizeof(Form));
        ppStuForm[i]=pTmp;
    }
    strcpy(ppStuForm[0]->m_cpTitle,"学号");
    strcpy(ppStuForm[1]->m_cpTitle,"姓名");
    strcpy(ppStuForm[2]->m_cpTitle,"性别");
    strcpy(ppStuForm[3]->m_cpTitle,"班级");

	/*定义主菜单选项*/
	char menuList[MAX_ROW][15]={"信息维护","课程管理","成绩管理"};

    /*Action*/
	menu:menuSelect();
	/*结束菜单界面输出*/
	//list(menuList);
	int mainItem,stuItem;
	printf("\n请输入菜单项数字(1 - 3):");
	scanf("%d",&mainItem);
	switch(mainItem)
	{
		case 1:
			printf("\n请输入菜单项数字(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			dialog("系统正在维护！");
			break;
		case 3:
			dialog("系统正在维护！");
			break;
		case 4:
			exit(0);
		default:
			goto menu;
	}				
	switch(stuItem) 
	{
		case 1:
			dialog("学生数据录入");
			do
            {
                form(ppStuForm);
                addStudent(ppStu,ppStuForm,&stuNum);
                saveStudent(ppStu);
            }while(alert());
			break;
		case 2:
			dialog("学生信息显示");
			echoStudent(ppStu);
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
		goto menu;
    
    return 0;
}
