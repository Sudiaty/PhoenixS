/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include "stdafx.h"

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
			system("clear");
			stuMenu:
			dialog("学生信息管理");
			list(stuList);
			printf("\n请输入菜单项数字(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			system("clear");
			courseMenu:
			dialog("  课程管理  ");
			list(courseList);
			printf("\n请输入菜单项数字(1 - 4):");
			scanf("%d",&courseItem);
			break;
		case 3:
			system("clear");
			pointMenu:
			dialog("  成绩管理  ");
			list(pointList);
			printf("\n请输入菜单项数字(1 - 4):");
			scanf("%d",&pointItem);
			break;
		case 4:
			exit(0);
		default:
			system("clear");
			echo("  非法输入！  ");
			BACK
			goto home;
	}
			
/*学生信息管理模块*/
	if(stuItem)
	{
		switch(stuItem) 
		{
			case 1:
				system("clear");
				echo(" 学生信息显示 "); 
				cpStuTmp=echoStudent(ppStu);
				table(cpStuTmp,4);
				break;
			case 2:
				system("clear");
				echo(" 学生数据录入 ");
				do
				{
					userForm(ppStuForm);
					if(addStudent(ppStu,ppStuForm,&stuNum))
						saveStudent(ppStu);
					else
					{
						BACK
						break;
					}
				}while(alert("注册成功,"));
				system("clear");
				break;
			case 3:
				system("clear");
				echo(" 修改学生信息 ");
				do
				{
					if ((stuNo = searchStudent(ppStu))&&altStudent(ppStu,stuNo))
					{
						saveStudent(ppStu);
					}
					else
					{
						BACK
						break;
					}
				}while(alert("修改成功，"));
				system("clear");
				break;
			case 4:
				system("clear");
				echo(" 删除学生学籍 ");
				if (stuNo = searchStudent(ppStu))
				{
					if (alert("确认删除？"))
						delStudent(ppStu, stuNo, &stuNum);
					saveStudent(ppStu);
					system("clear");
				}
				else 
				{
					BACK
				}
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
				echo("  非法输入！  ");
				BACK
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
				echo("   添加课程   ");
				if(stuNo=searchStudent(ppStu))				//指定添加课程的学生
				{
					cpCourseTmp=echoCourse(ppCourse);
					table(cpCourseTmp,3);
					do
					{
						if ((courseNo = searchCourse(ppCourse, cpCourseNo))&& addCourse(ppStu, ppCourse, stuNo, courseNo))
						{
							saveStudent(ppStu);
						}
						else
						{
							BACK
							break;
						}
					}while(alert("添加成功"));				//判断是否继续添加
				}
				BACK
				break;
			case 2:
				system("clear");
				echo("   退选课程   ");
				if(stuNo=searchStudent(ppStu))
				{
					courseNo=searchCourse(ppCourse,cpCourseNo);
					if (alert("确定退选？"))
					{
						delCourse(ppStu, ppCourse, stuNo, courseNo);
						saveStudent(ppStu);
					}
					BACK
				}
				else
				{
					BACK
				}
				break;
			case 3:
				system("clear");
				echo("   打印课表   ");
				if(stuNo=searchStudent(ppStu)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					echo(" 个人课表打印 ");
					table(cpCourseTmp,5);
				}
				else
				{
					BACK				//容错处理
				}
				break;
			case 4:
				system("clear");
				courseItem=0;
				goto home;
			default:
				system("clear");
				echo("  非法输入！  ");
				BACK
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
				if(stuNo=searchStudent(ppStu))
				{
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					echo("  已开设课程  ");
					table(cpCourseTmp,5);
					do
					{
						if ((courseNo = searchCourse(ppCourse, cpCourseNo)) && searchStuCourse(ppStu, ppCourse, stuNo, courseNo));				//判断课程代码是否匹配
						else
						{
							echo("  无匹配记录  ");
							BACK
							break;
						}
						if (addPoint(ppStu, ppPoint, stuNo, cpCourseNo, &pointNum));
						else
						{
							BACK
							break;
						}
					}while(alert("录入成功！"));
					savePoint(ppPoint);
					calGPA(ppStu, ppCourse, ppPoint, stuNo);
					saveStudent(ppStu);
					system("clear");
				}
				else
				{
					BACK
				}
				break;
			case 2:
				system("clear");
				dialog("  成绩查询  ");
				stuNo=searchStudent(ppStu);
				if(stuNo)
				{
					stuNo-=1;
					printf("GPA:%.2f\n",ppStu[stuNo]->m_fPoint);
					cpPointTmp=echoPoint(ppStu,ppCourse,ppPoint,stuNo);
					table(cpPointTmp,3);
				}
				else
				{
					BACK
				}
				break;
			case 3:
				system("clear");
				totalMenu:
				echo("   成绩统计   ");
				list(totalList);
				printf("\n请输入菜单项数字(1 - 4):");
				scanf("%d", &pointTotalItem);
				switch (pointTotalItem)
				{
				case 1:
					system("clear");
					echo(" 班级成绩统计 ");
					if (searchClass(ppStu, cpClass))
					{
						cpPointTmp = echoTotalPoint(ppStu, cpClass);
						table(cpPointTmp, 4);
					}
					else
					{
						BACK
					}
					goto totalMenu;
				case 2:
					system("clear");
					echo(" 单科成绩统计 ");
					if (searchClass(ppStu, cpClass) && (courseNo = searchCourse(ppCourse, cpCourseNo)))
					{
						cpPointTmp = echoSubPoint(ppStu, ppCourse, ppPoint, cpClass, courseNo);
						table(cpPointTmp, 4);
						exportTable(cpPointTmp, "SubPoint.html", 4);
					}			
					else
					{
						BACK
					}
					goto totalMenu;
				case 3:
					system("clear");
					pointTotalItem = 0;
					goto pointMenu;
					break;
				case 4:
					exit(0);
				default:
					system("clear");
					echo("  非法输入！  ");
					goto totalMenu;
				}
			case 4:
				system("clear");
				pointItem=0;
				goto home;
			default:
				system("clear");
				echo("  非法输入！  ");
				goto pointMenu;
		}
		goto pointMenu;
	}
    return 0;
}