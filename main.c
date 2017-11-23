/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"stdafx.h"

//全局变量声明
int stuNum=0;
int pointNum=0;
long stuNo=-1;

/****************************************
* Author:LiuXL
* Function:main();
* Description:Main function
****************************************/
int main()
{
/****************************************
* 实例化Student对象
****************************************/
    int i;
	Student *ppStu[MAX_STU_NO];
    for(i=0;i<MAX_STU_NO;i++)
    {
        Student *pTmp=(Student*)malloc(sizeof(Student));
        ppStu[i]=pTmp;
	}

/****************************************
* 实例化Course对象
****************************************/
    course *ppCourse[MAX_SUB_NO];
	for(i=0;i<MAX_SUB_NO;i++)
	{
		ppCourse[i]=&pChem[i];
	}

/****************************************
* 实例化Point对象
****************************************/
	point *ppPoint[MAX_STU_NO*MAX_SUB_NO];
	INIT_POINT(MAX_STU_NO*MAX_SUB_NO,ppPoint);
	/*for(i=0;i<MAX_STU_NO*MAX_SUB_NO;i++)
	{
		ppPoint[i]=0x0;
	}*/
	// point *p=(point*)malloc(sizeof(point));
	// ppPoint[0]=p;

/****************************************
* 实例化用于接收信息的表单
****************************************/
    Form *ppStuForm[MAX_ROW];
    
/****************************************
* 实例化表格数组
****************************************/
	
	char **cpStuTmp;			//用于显示学生信息的数组指针，与table函数对接
	
	char **cpCourseTmp;			//用于显示课程信息的数组指针，与table函数对接
	
	char **cpPointTmp;			//用于显示成绩信息的数组指针，与table函数对接

/****************************************
* 定义菜单选项
****************************************/
	char menuList[MAX_ROW][20]={"信息维护","课程管理","成绩管理","  退出  "};
	char stuMenu[MAX_ROW][20]={"学生列表","新生注册","信息更正","注销学籍","  返回  ","  退出  "};
	char courseMenu[MAX_ROW][20]={"添加课程","退选课程","课表查询","  返回  "};
	char pointMenu[MAX_ROW][20]={"成绩录入","成绩查询","成绩统计","  返回  "};

/*变量声明*/
	int mainItem,stuItem=0,courseItem=0,pointItem=0;				//用于判断选项的变量
	char cpNo[10];				//用于查找学生的变量
	char cpCourseNo[10];			//用于查找课程的变量


/****************************************
* 
*				Initial
*
****************************************/



/*初始化学生信息表单*/
for(i=0; i<STU_FORM_ROW;i++)
{
    Form *pTmp=(Form*)malloc(sizeof(Form));
    ppStuForm[i]=pTmp;
}
strcpy(ppStuForm[0]->m_cpTitle,"\033[47;31m学号\033[0m");
strcpy(ppStuForm[1]->m_cpTitle,"\033[47;31m姓名\033[0m");
strcpy(ppStuForm[2]->m_cpTitle,"\033[47;31m性别\033[0m");
strcpy(ppStuForm[3]->m_cpTitle,"\033[47;31m班级\033[0m");


/****************************************
* 
*				Action
*
****************************************/
	getStudent(ppStu,&stuNum);
	getPoint(ppPoint,&pointNum);		//初始化，自动导入数据


/*显示主菜单*/
	home:dialog("学生管理系统");
	list(menuList);
	printf("\n请输入菜单项数字(1 - 4):");
	scanf("%d",&mainItem);
	switch(mainItem)
	{
		case 1:
			system("clear");
			stuMenu:list(stuMenu);
			printf("\n请输入菜单项数字(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			system("clear");
			courseMenu:list(courseMenu);
			printf("\n请输入菜单项数字(1 - 4):");
			scanf("%d",&courseItem);
			break;
		case 3:
			system("clear");
			pointMenu:list(pointMenu);
			printf("\n请输入菜单项数字(1 - 4):");
			scanf("%d",&pointItem);
			break;
		case 4:
			exit(0);
		default:
			system("clear");
			dialog("  非法输入！");
			goto home;
	}
			
/*学生信息管理模块*/
	if(stuItem)
	{
		switch(stuItem) 
		{
			case 1:
				system("clear");
				dialog("学生信息显示"); 
				cpStuTmp=echoStudent(ppStu);
				table(cpStuTmp,4);
				break;
			case 2:
				system("clear");
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
				do
				{
					if(stuNo=searchStudent(ppStu,cpNo))
						altStudent(ppStu,stuNo);
						saveStudent(ppStu);
				}while(alert());
				system("clear");
				break;
			case 4:
				dialog("删除学生学籍");
				if(searchStudent(ppStu,cpNo)&&alert())
				delStudent(ppStu,cpNo,&stuNum);
				saveStudent(ppStu);
				system("clear");
				break;
			case 5:
				system("clear");
				stuItem=0;
				goto home;
				break;
			case 6:
				exit(0);
			default:
				system("clear");
				dialog("  非法输入！");
				goto stuMenu;
		}
		goto stuMenu;
	}

/*课程信息管理模块*/
	if(courseItem)
	{
		switch(courseItem)
		{
			case 1:
				system("clear");
				dialog("  添加课程  ");
				if(stuNo=searchStudent(ppStu,cpNo))
				{
					cpCourseTmp=echoCourse(ppCourse);
					table(cpCourseTmp,3);
					do
					{
						addCourse(ppStu,stuNo);
					}while(alert());
					saveStudent(ppStu);
				}
				break;
			case 2:
				system("clear");
				dialog("  退选课程  ");
				if(searchStudent(ppStu,cpNo))
				{
					searchCourse(ppStu,ppCourse,cpNo,cpCourseNo);
					if(alert())
					delCourse(ppStu,cpNo,cpCourseNo);
					saveStudent(ppStu);
				}
				break;
			case 3:
				system("clear");
				dialog("  打印课表  ");
				if(stuNo=searchStudent(ppStu,cpNo)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					table(cpCourseTmp,5);
				}
				break;
			case 4:
				system("clear");
				courseItem=0;
				goto home;
			default:
				system("clear");
				dialog("  非法输入！");
				goto courseMenu;
		}
		goto courseMenu;
	}

/*成绩管理模块*/
	if(pointItem)
	{
		switch(pointItem)
		{
			case 1:
				system("clear");
				dialog("  成绩录入  ");
				if(stuNo=searchStudent(ppStu,cpNo)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					table(cpCourseTmp,5);
					do
					{
						searchCourse(ppStu,ppCourse,cpNo,cpCourseNo);
						point *pTmp=(point*)malloc(sizeof(point));
        				ppPoint[pointNum]=pTmp;
						addPoint(ppStu,ppPoint,cpNo,cpCourseNo,&pointNum);
					}while(alert());
					savePoint(ppPoint);
					calGPA(ppStu,ppCourse,ppPoint,cpNo);
					saveStudent(ppStu);
				}
				break;
			case 2:
				system("clear");
				dialog("  成绩查询  ");
				stuNo=searchStudent(ppStu,cpNo);
				if(stuNo)
				{
					stuNo-=1;
					printf("GPA:%.2f\n",ppStu[stuNo]->m_fPoint);
					
					cpPointTmp=echoPoint(ppStu,ppCourse,ppPoint,stuNo);
					table(cpPointTmp,3);
				}
				break;
			case 3:
				system("clear");
				dialog("系统正在维护");
				
				break;
			case 4:
				system("clear");
				pointItem=0;
				goto home;
			default:
				system("clear");
				dialog("  非法输入！");
				goto pointMenu;
		}
		goto pointMenu;
	}
    return 0;
}