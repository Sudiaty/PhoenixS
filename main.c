/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"stdafx.h"

//ȫ�ֱ�������
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
* ʵ����Student����
****************************************/
    int i;
	Student *ppStu[MAX_STU_NO];
    for(i=0;i<MAX_STU_NO;i++)
    {
        Student *pTmp=(Student*)malloc(sizeof(Student));
        ppStu[i]=pTmp;
	}

/****************************************
* ʵ����Course����
****************************************/
    course *ppCourse[MAX_SUB_NO];
	for(i=0;i<MAX_SUB_NO;i++)
	{
		ppCourse[i]=&pChem[i];
	}

/****************************************
* ʵ����Point����
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
* ʵ�������ڽ�����Ϣ�ı�
****************************************/
    Form *ppStuForm[MAX_ROW];
    
/****************************************
* ʵ�����������
****************************************/
	
	char **cpStuTmp;			//������ʾѧ����Ϣ������ָ�룬��table�����Խ�
	
	char **cpCourseTmp;			//������ʾ�γ���Ϣ������ָ�룬��table�����Խ�
	
	char **cpPointTmp;			//������ʾ�ɼ���Ϣ������ָ�룬��table�����Խ�

/****************************************
* ����˵�ѡ��
****************************************/
	char menuList[MAX_ROW][20]={"��Ϣά��","�γ̹���","�ɼ�����","  �˳�  "};
	char stuMenu[MAX_ROW][20]={"ѧ���б�","����ע��","��Ϣ����","ע��ѧ��","  ����  ","  �˳�  "};
	char courseMenu[MAX_ROW][20]={"��ӿγ�","��ѡ�γ�","�α��ѯ","  ����  "};
	char pointMenu[MAX_ROW][20]={"�ɼ�¼��","�ɼ���ѯ","�ɼ�ͳ��","  ����  "};

/*��������*/
	int mainItem,stuItem=0,courseItem=0,pointItem=0;				//�����ж�ѡ��ı���
	char cpNo[10];				//���ڲ���ѧ���ı���
	char cpCourseNo[10];			//���ڲ��ҿγ̵ı���


/****************************************
* 
*				Initial
*
****************************************/



/*��ʼ��ѧ����Ϣ��*/
for(i=0; i<STU_FORM_ROW;i++)
{
    Form *pTmp=(Form*)malloc(sizeof(Form));
    ppStuForm[i]=pTmp;
}
strcpy(ppStuForm[0]->m_cpTitle,"\033[47;31mѧ��\033[0m");
strcpy(ppStuForm[1]->m_cpTitle,"\033[47;31m����\033[0m");
strcpy(ppStuForm[2]->m_cpTitle,"\033[47;31m�Ա�\033[0m");
strcpy(ppStuForm[3]->m_cpTitle,"\033[47;31m�༶\033[0m");


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
			system("clear");
			stuMenu:list(stuMenu);
			printf("\n������˵�������(1 - 6):");
			scanf("%d",&stuItem);
			break;
		case 2:
			system("clear");
			courseMenu:list(courseMenu);
			printf("\n������˵�������(1 - 4):");
			scanf("%d",&courseItem);
			break;
		case 3:
			system("clear");
			pointMenu:list(pointMenu);
			printf("\n������˵�������(1 - 4):");
			scanf("%d",&pointItem);
			break;
		case 4:
			exit(0);
		default:
			system("clear");
			dialog("  �Ƿ����룡");
			goto home;
	}
			
/*ѧ����Ϣ����ģ��*/
	if(stuItem)
	{
		switch(stuItem) 
		{
			case 1:
				system("clear");
				dialog("ѧ����Ϣ��ʾ"); 
				cpStuTmp=echoStudent(ppStu);
				table(cpStuTmp,4);
				break;
			case 2:
				system("clear");
				dialog("ѧ������¼��");
				do
				{
					form(ppStuForm);
					addStudent(ppStu,ppStuForm,&stuNum);
					saveStudent(ppStu);
				}while(alert());
				break;
			case 3:
				dialog("�޸�ѧ����Ϣ");
				do
				{
					if(stuNo=searchStudent(ppStu,cpNo))
						altStudent(ppStu,stuNo);
						saveStudent(ppStu);
				}while(alert());
				system("clear");
				break;
			case 4:
				dialog("ɾ��ѧ��ѧ��");
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
				system("clear");
				dialog("  ��ӿγ�  ");
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
				dialog("  ��ѡ�γ�  ");
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
				dialog("  ��ӡ�α�  ");
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
				system("clear");
				dialog("  �ɼ�¼��  ");
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
				dialog("  �ɼ���ѯ  ");
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
				dialog("ϵͳ����ά��");
				
				break;
			case 4:
				system("clear");
				pointItem=0;
				goto home;
			default:
				system("clear");
				dialog("  �Ƿ����룡");
				goto pointMenu;
		}
		goto pointMenu;
	}
    return 0;
}