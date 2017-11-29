/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"stdafx.h"

//ȫ�ֱ�������
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
* ʵ����Student����
****************************************/
    int i;
	Student *ppStu[MAX_STU_NO];
	INIT_SPP(ppStu,MAX_STU_NO);

/****************************************
* ʵ����Course����
****************************************/
    Course *ppCourse[MAX_SUB_NO];
	for(i=0;i<MAX_SUB_NO;i++) ppCourse[i]=&pChem[i];

/****************************************
* ʵ����Point����
****************************************/
	Point *ppPoint[MAX_STU_NO*MAX_SUB_NO];
	INIT_SPP(ppPoint,MAX_STU_NO*MAX_SUB_NO);

/****************************************
* ʵ�������ڽ�����Ϣ�ı�
****************************************/
    Form *ppStuForm[MAX_ROW];
	INIT_SPP(ppStuForm,MAX_ROW);
    
/****************************************
* �������ڴ������ݸ��ı����ַ�������ָ��
****************************************/
	char **cpStuTmp;			//������ʾѧ����Ϣ������ָ�룬��table�����Խ�
	char **cpCourseTmp;			//������ʾ�γ���Ϣ������ָ�룬��table�����Խ�	
	char **cpPointTmp;			//������ʾ�ɼ���Ϣ������ָ�룬��table�����Խ�

/****************************************
* ����˵�ѡ��
****************************************/
	char menuList[MAX_ROW][20]={"��Ϣά��","�γ̹���","�ɼ�����","  �˳�  "};
	char stuList[MAX_ROW][20]={"ѧ���б�","����ע��","��Ϣ����","ע��ѧ��","  ����  ","  �˳�  "};
	char courseList[MAX_ROW][20]={"��ӿγ�","��ѡ�γ�","�α��ѯ","  ����  "};
	char pointList[MAX_ROW][20]={"�ɼ�¼��","�ɼ���ѯ","�ɼ�ͳ��","  ����  "};
	char totalList[MAX_ROW][20] = { "�༶�ɼ�","���Ƴɼ�","  ����  ","  �˳�  "};

/*��������ر�������*/
	int mainItem, stuItem = 0, courseItem = 0, pointItem = 0,pointTotalItem = 0;				//�����ж�ѡ��ı���
	char cpCourseNo[10];			//���ڲ��ҿγ̵ı���
	char cpClass[20];

/****************************************
* 
*				Initial
*
****************************************/
/*��ʼ��ѧ����Ϣ��*/
DST_SPP(Form,ppStuForm,4)
strcpy(ppStuForm[0]->m_cpTitle,"ѧ��");
strcpy(ppStuForm[1]->m_cpTitle,"����");
strcpy(ppStuForm[2]->m_cpTitle,"�Ա�");
strcpy(ppStuForm[3]->m_cpTitle,"�༶");

/****************************************
* 
*				Action
*
****************************************/
	getStudent(ppStu,&stuNum);
	getPoint(ppPoint,&pointNum);		//��ʼ�����Զ���������

/*��ʾ���˵�*/
	home:dialog("ѧ������ϵͳ");
	list(menuList);
	printf("\n������˵�������(1 - 4):");
	scanf("%d",&mainItem);
	switch(mainItem)
	{
		case 1:
			system("cls");
			stuMenu:
			dialog("ѧ����Ϣ����");
			list(stuList);
			printf("\n������˵�������(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			system("cls");
			dialog("  �γ̹���  ");
			courseMenu:list(courseList);
			printf("\n������˵�������(1 - 4):");
			scanf("%d",&courseItem);
			break;
		case 3:
			system("cls");
			pointMenu:
			dialog("  �ɼ�����  ");
			list(pointList);
			printf("\n������˵�������(1 - 4):");
			scanf("%d",&pointItem);
			break;
		case 4:
			exit(0);
		default:
			system("cls");
			dialog("  �Ƿ����룡");
			goto home;
	}
			
/*ѧ����Ϣ����ģ��*/
	if(stuItem)
	{
		switch(stuItem) 
		{
			case 1:
				system("cls");
				dialog("ѧ����Ϣ��ʾ"); 
				cpStuTmp=echoStudent(ppStu);
				table(cpStuTmp,4);
				break;
			case 2:
				system("cls");
				dialog("ѧ������¼��");
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
				dialog("�޸�ѧ����Ϣ");
				do
				{
					if(stuNo=searchStudent(ppStu))
						altStudent(ppStu,&stuNo);
						saveStudent(ppStu);
				}while(alert());
				//system("cls");
				break;
			case 4:
				dialog("ɾ��ѧ��ѧ��");
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
				dialog("  �Ƿ����룡");
				goto stuMenu;
		}
		goto stuMenu;
	}

/*�γ���Ϣ����ģ��*/
	if(courseItem)
	{
		switch(courseItem)
		{
			case 1:
				system("cls");
				dialog("  ��ӿγ�  ");
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
				dialog("  ��ѡ�γ�  ");
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
				dialog("  ��ӡ�α�  ");
				if(stuNo=searchStudent(ppStu)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					echo("���˿α��ӡ");
					table(cpCourseTmp,5);
				}
				break;
			case 4:
				system("cls");
				courseItem=0;
				goto home;
			default:
				system("cls");
				dialog("  �Ƿ����룡");
				goto courseMenu;
		}
		goto courseMenu;
	}

/*�ɼ�����ģ��*/
	if(pointItem)
	{
		switch(pointItem)
		{
			case 1:
				system("cls");
				dialog("  �ɼ�¼��  ");
				if(stuNo=searchStudent(ppStu)){
					cpCourseTmp=printCourse(ppStu,ppCourse,stuNo);
					echo("�ѿ���γ�");
					table(cpCourseTmp,5);
					do
					{
						searchCourse(ppCourse,cpCourseNo);
						DST_SPPI(Point,ppPoint,pointNum)
						addPoint(ppStu,ppPoint,stuNo,cpCourseNo,&pointNum);			//searchCourse��������
					}while(alert());
					savePoint(ppPoint);
					calGPA(ppStu,ppCourse,ppPoint,stuNo);
					saveStudent(ppStu);
					system("cls");
				}
				break;
			case 2:
				system("cls");
				dialog("  �ɼ���ѯ  ");
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
				dialog("  �ɼ�ͳ��  ");
				list(totalList);
				printf("\n������˵�������(1 - 4):");
				scanf("%d", &pointTotalItem);
				switch (pointTotalItem)
				{
				case 1:
					system("cls");
					dialog("�༶�ɼ�ͳ��");
					if (searchClass(ppStu, cpClass))
						cpPointTmp = echoTotalPoint(ppStu, cpClass);
					table(cpPointTmp, 4);
					goto totalMenu;
				case 2:
					system("cls");
					dialog("���Ƴɼ�ͳ��");
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
					dialog("  �Ƿ����룡");
					goto totalMenu;
				}
			case 4:
				system("cls");
				pointItem=0;
				goto home;
			default:
				system("cls");
				dialog("  �Ƿ����룡");
				goto pointMenu;
		}
		goto pointMenu;
	}
    return 0;
}