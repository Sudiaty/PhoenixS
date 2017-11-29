/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"stdafx.h"

//全局变量声明
int stuNum=0;
int pointNum=0;
long stuNo=-1;
int courseNo=-1;
long pointNo=0;

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
	INIT_SPP(ppStu,MAX_STU_NO);

/****************************************
* 实例化Course对象
****************************************/
    Course *ppCourse[MAX_SUB_NO];
	for(i=0;i<MAX_SUB_NO;i++) ppCourse[i]=&pChem[i];

/****************************************
* 实例化Point对象
****************************************/
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO];
	INIT_SPP(ppPoint,MAX_STU_NO*MAX_SUB_NO);

/****************************************
* 实例化用于接收信息的表单
****************************************/
    Form *ppStuForm[MAX_ROW];
	INIT_SPP(ppStuForm,MAX_ROW);
    
/****************************************
* 定义用于传递数据给的表格的字符串数组指针
****************************************/
	char **cpStuTmp;			//用于显示学生信息的数组指针，与table函数对接
	char **cpCourseTmp;			//用于显示课程信息的数组指针，与table函数对接	
	char **cpPointTmp;			//用于显示成绩信息的数组指针，与table函数对接

/****************************************
* 定义菜单选项
****************************************/
	char menuList[MAX_ROW][20]={"信息维护","课程管理","成绩管理","  退出  "};
	char stuList[MAX_ROW][20]={"学生列表","新生注册","信息更正","注销学籍","  返回  ","  退出  "};
	char courseList[MAX_ROW][20]={"添加课程","退选课程","课表查询","  返回  "};
	char pointList[MAX_ROW][20]={"成绩录入","成绩查询","成绩统计","  返回  "};
	char totalList[MAX_ROW][20] = { "班级成绩","单科成绩","  返回  ","  退出  "};

/*主界面相关变量声明*/
	int mainItem, stuItem = 0, courseItem = 0, pointItem = 0,pointTotalItem = 0;				//用于判断选项的变量
	char cpCourseNo[10];			//用于查找课程的变量
	char cpClass[20];

/****************************************
* 
*				Initial
*
****************************************/
/*初始化学生信息表单*/
DST_SPP(Form,ppStuForm,4)
strcpy(ppStuForm[0]->m_cpTitle,"学号");
strcpy(ppStuForm[1]->m_cpTitle,"姓名");
strcpy(ppStuForm[2]->m_cpTitle,"性别");
strcpy(ppStuForm[3]->m_cpTitle,"班级");

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
			system("cls");
			stuMenu:
			dialog("学生信息管理");
			list(stuList);
			printf("\n请输入菜单项数字(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			system("cls");
			dialog("  课程管理  ");
			courseMenu:list(courseList);
			printf("\n请输入菜单项数字(1 - 4):");
			scanf("%d",&courseItem);
			break;
		case 3:
			system("cls");
			pointMenu:
			dialog("  成绩管理  ");
			list(pointList);
			printf("\n请输入菜单项数字(1 - 4):");
			scanf("%d",&pointItem);
			break;
		case 4:
			exit(0);
		default:
			system("cls");
			dialog("  非法输入！");
			goto home;
	}
			
/*学生信息管理模块*/
	if(stuItem)
	{
		switch(stuItem) 
		{
			case 1:
				system("cls");
				dialog("学生信息显示"); 
				cpStuTmp=echoStudent(ppStu);
				table(cpStuTmp,4);
				break;
			case 2:
				system("cls");
				dialog("学生数据录入");
				do
				{
					userForm(ppStuForm);
					DST_SPPI(Student,ppStu,stuNum);
					addStudent(ppStu,ppStuForm,&stuNum);
					saveStudent(ppStu);
				}while(alert());
				system("cls");
				break;
			case 3:
				dialog("修改学生信息");
				do
				{
					if(stuNo=searchStudent(ppStu))
						altStudent(ppStu,&stuNo);
						saveStudent(ppStu);
				}while(alert());
				//system("cls");
				break;
			case 4:
				dialog("删除学生学籍");
				stuNo = searchStudent(ppStu);
				if(alert())
				delStudent(ppStu,stuNo,&stuNum);
				saveStudent(ppStu);
				system("cls");
				break;
			case 5:
				system("cls");
				stuItem=0;
				goto home;
				break;
			case 6:
				exit(0);
			default:
				system("cls");
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
				system("cls");
				dialog("  添加课程  ");
				if(stuNo=searchStudent(ppStu))
				{
					cpCourseTmp=echoCourse(ppCourse);
					table(cpCourseTmp,3);
					do
					{
						addCourse(ppStu,stuNo);
					}while(alert());
					saveStudent(ppStu);
					system("cls");
				}
				break;
			case 2:
				system("cls");
				dialog("  退选课程  ");
				if(stuNo=searchStudent(ppStu))
				{
					courseNo=searchCourse(ppCourse,cpCourseNo);
					if(alert())
					delCourse(ppStu,ppCourse,stuNo,courseNo);
					saveStudent(ppStu);
				}
				break;
			case 3:
				system("cls");
				dialog("  打印课表  ");
				if(stuNo=searchStudent(ppStu)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					echo("个人课表打印");
					table(cpCourseTmp,5);
				}
				break;
			case 4:
				system("cls");
				courseItem=0;
				goto home;
			default:
				system("cls");
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
				system("cls");
				dialog("  成绩录入  ");
				if(stuNo=searchStudent(ppStu)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					echo("已开设课程");
					table(cpCourseTmp,5);
					do
					{
						searchCourse(ppCourse,cpCourseNo);
						DST_SPPI(Point,ppPoint,pointNum)
						addPoint(ppStu,ppPoint,stuNo,cpCourseNo,&pointNum);			//searchCourse参数传递
					}while(alert());
					savePoint(ppPoint);
					calGPA(ppStu,ppCourse,ppPoint,stuNo);
					saveStudent(ppStu);
					system("cls");
				}
				break;
			case 2:
				system("cls");
				dialog("  成绩查询  ");
				stuNo=searchStudent(ppStu);
				if(stuNo)
				{
					stuNo-=1;
					printf("GPA:%.2f\n",ppStu[stuNo]->m_fPoint);
					cpPointTmp=echoPoint(ppStu,ppCourse,ppPoint,stuNo);
					table(cpPointTmp,3);
				}
				break;
			case 3:
				system("cls");
				totalMenu:
				dialog("  成绩统计  ");
				list(totalList);
				printf("\n请输入菜单项数字(1 - 4):");
				scanf("%d", &pointTotalItem);
				switch (pointTotalItem)
				{
				case 1:
					system("cls");
					dialog("班级成绩统计");
					if (searchClass(ppStu, cpClass))
						cpPointTmp = echoTotalPoint(ppStu, cpClass);
					table(cpPointTmp, 4);
					goto totalMenu;
				case 2:
					system("cls");
					dialog("单科成绩统计");
					if (searchClass(ppStu, cpClass)&&(courseNo=searchCourse(ppCourse,cpCourseNo)))
						cpPointTmp = echoSubPoint(ppStu,ppCourse,ppPoint,cpClass,courseNo);
					table(cpPointTmp, 4);
					exportTable(cpPointTmp,"SubPoint.html",4);
					goto totalMenu;
				case 3:
					system("cls");
					pointTotalItem = 0;
					goto pointMenu;
					break;
				case 4:
					exit(0);
				default:
					system("cls");
					dialog("  非法输入！");
					goto totalMenu;
				}
			case 4:
				system("cls");
				pointItem=0;
				goto home;
			default:
				system("cls");
				dialog("  非法输入！");
				goto pointMenu;
		}
		goto pointMenu;
	}
    return 0;
}