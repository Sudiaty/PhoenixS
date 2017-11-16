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
	getStudent(ppStu,&stuNum);		//自动导入数据

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
	char menuList[MAX_ROW][20]={"信息维护","课程管理","成绩管理","退出"};
	char stuMenu[MAX_ROW][20]={"学生列表","新生注册","信息更正","注销学籍","返回","退出"};

	/*Action*/
	int mainItem,stuItem=0,courseItem=0,pointItem=0;
	home:dialog("学生管理系统");
	list(menuList);
	printf("\n请输入菜单项数字(1 - 4):");
	scanf("%d",&mainItem);
	switch(mainItem)
	{
		case 1:
			stuMenu:list(stuMenu);
			//getStudent(ppStu);
			printf("\n请输入菜单项数字(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			dialog("系统正在维护");
			break;
		case 3:
			dialog("系统正在维护");
			break;
		case 4:
			exit(0);
		default:
			dialog("非法输入");
			goto home;
	}
		/*学生信息管理模块*/
	if(stuItem)
	{
		switch(stuItem) 
		{
			char cpNo[10];
			case 1:
				dialog("学生信息显示");
				char **cpStuTmp=echoStudent(ppStu);
				table(cpStuTmp,4);
				break;
			case 2:
				dialog("学生数据录入");
				do
				{
					form(ppStuForm);
					addStudent(ppStu,ppStuForm,&stuNum);
					saveStudent(ppStu);
				}while(alert());
				break;
			case 3:
				dialog("修改学生信息");
				searchStudent(ppStu,cpNo);
				do
				{
					altStudent(ppStu,cpNo);
				}while(alert());
				break;
			case 4:
				dialog("删除学生学籍");
				searchStudent(ppStu,cpNo);
				if(alert()) delStudent(ppStu,cpNo,&stuNum);
				// saveStudent(ppStu);
				break;
			case 5:
				goto home;
				break;
			case 6:
				exit(0);
			default:
				goto stuMenu;
				break;
		}
		goto stuMenu;
	}
    return 0;
}
