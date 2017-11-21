/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"stdafx.h"

//ȫ�ֱ�������
int stuNum=0;

/****************************************
* Author:LiuXL
* Function:main();
* Description:Main function
****************************************/
int main()
{
    /*ʵ����Student����*/
    Student *ppStu[MAX_STU_NO];
    for(int i=0;i<MAX_STU_NO;i++)
    {
        Student *pTmp=(Student*)malloc(sizeof(Student));
        ppStu[i]=pTmp;
	}
	getStudent(ppStu,&stuNum);		//��ʼ�����Զ���������

    /*ʵ����Form����*/
    Form *ppStuForm[MAX_ROW];
    /*Ϊѧ����Ϣ�����󸳳�ֵ*/
    for (int j=0; j<STU_FORM_ROW;++j)
    {
        Form *pTmp=(Form*)malloc(sizeof(Form));
        ppStuForm[j]=pTmp;
    }
    strcpy(ppStuForm[0]->m_cpTitle,"ѧ��");
    strcpy(ppStuForm[1]->m_cpTitle,"����");
    strcpy(ppStuForm[2]->m_cpTitle,"�Ա�");
    strcpy(ppStuForm[3]->m_cpTitle,"�༶");

	/*����˵�ѡ��*/
	char menuList[MAX_ROW][20]={"��Ϣά��","�γ̹���","�ɼ�����","�˳�    "};
	char stuMenu[MAX_ROW][20]={"ѧ���б�","����ע��","��Ϣ����","ע��ѧ��","����    ","�˳�    "};
	char courseMenu[MAX_ROW][20]={"��ӿγ�","��ѡ�γ�","�α��ѯ","����    "};

	/*Action*/
	int mainItem,stuItem=0,courseItem=0,pointItem=0;				//�����ж�ѡ��ı���
	char cpNo[10];				//�������ڲ���ѧ���ı���
	char **cpStuTmp;				//����������table�������ݲ���������

	home:dialog("ѧ������ϵͳ");
	list(menuList);				//��ʾ���˵�
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
			dialog("ϵͳ����ά��");
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
				system("clear");
				dialog("�޸�ѧ����Ϣ");
				do
				{
					if(searchStudent(ppStu,cpNo));
						altStudent(ppStu,cpNo);
						saveStudent(ppStu);
				}while(alert());
				break;
			case 4:
				system("clear");
				dialog("ɾ��ѧ��ѧ��");
				if(searchStudent(ppStu,cpNo)&&alert())
				delStudent(ppStu,cpNo,&stuNum);
				saveStudent(ppStu);
				break;
			case 5:
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
		system("clear");
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
				do
				{
					if(searchStudent(ppStu,cpNo));
				}while(alert());

				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				courseItem=0;
				goto home;
			default:
				system("clear");
				dialog("  �Ƿ����룡");
				goto courseMenu;
		}
		system("clear");
		goto courseMenu;
	}
    return 0;
}