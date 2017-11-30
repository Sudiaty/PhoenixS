/****************************************
* Author:LiuXL;
* Description:Function related with
*	ppStudent class.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addStudent();
* Description:Add a student's record.
****************************************/
int addStudent(Student *ppStu[MAX_STU_NO], Form *ppForm[MAX_ROW], int *stuNum)
{
	int iStuCourseNo = 0,iStuNo=0,status=1;
	if (strcmp(ppForm[2]->m_cpContent, "男")&&strcmp(ppForm[2]->m_cpContent, "女")&&strcmp(ppForm[2]->m_cpContent, "f")&&strcmp(ppForm[2]->m_cpContent, "m"))
		status = -1;
	for (iStuNo = 0; iStuNo < MAX_STU_NO&&ppStu[iStuNo]!=NULL; iStuNo++)
	{
		if (strcmp(ppStu[iStuNo]->m_cpNo, ppForm[0]->m_cpContent) == 0)
		{
			status = 0;
			break;
		}
	}
	if (status==1)
	{
		DST_SPPI(Student, ppStu, *stuNum);
		strcpy(ppStu[*stuNum]->m_cpNo, ppForm[0]->m_cpContent);
		strcpy(ppStu[*stuNum]->m_cpName, ppForm[1]->m_cpContent);
		strcpy(ppStu[*stuNum]->m_cpGender, ppForm[2]->m_cpContent);
		strcpy(ppStu[*stuNum]->m_cpClass, ppForm[3]->m_cpContent);
		for (iStuCourseNo = 0; iStuCourseNo<MAX_SUB_NO; iStuCourseNo++) strcpy(ppStu[*stuNum]->m_cpMajor[iStuCourseNo], "\0");
		(*stuNum)++;
		return 1;
	}
	else if(status==0)
	{
		printf("学号已注册！\n\n");
		return 0;
	}
	else
	{
		printf("性别不合法（“男/女”、“f/m”）！\n\n");
		return 0;
	}
}


/****************************************
* Author:LiuXL;
* Function:saveStudent();
* Description:Save the info to Student.dat.
****************************************/
void saveStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//读取Student.txt
	if ((fp = fopen("Student.dat", "wb")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}

	for (i = 0; i<MAX_STU_NO&&ppStu[i]!=NULL; i++)
	{
		//写入数据至Student.dat
		if (fwrite(ppStu[i], sizeof(Student), 1, fp) != 1)
			printf("写入失败！\n\n");
	}
	fclose(fp);
}


/****************************************
* Author:JiaZG,LiuXL;
* Function:getStudent();
* Description:get the info to Student.txt.
****************************************/
void getStudent(Student *ppStu[MAX_STU_NO], int *stuNum)
{
	FILE *fp;
	int i=0;
	//读取Student.dat
	if ((fp = fopen("Student.dat", "rb")) == NULL)
	{
		return;
	}
	do
	{
		Student *pTmp=(Student*)malloc(sizeof(Student));
		ppStu[i]=pTmp;
	}while(fread(ppStu[i++],sizeof(Student),1,fp)&&i<MAX_STU_NO);
	ppStu[--i]=0x0;
	(*stuNum)=i;
	fclose(fp);
}

/****************************************
* Author:JiaZG;
* Function:searchStudent();
* Description:通过学号获取学生序数
****************************************/
long searchStudent(Student *ppStu[MAX_STU_NO])
{
	long i = 0;
	char cpNo[10];
	printf("\n请输入学生的学号：");
	scanf("%s", cpNo);
	for (i = 0; ppStu[i]!=NULL&&i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			printf("\n该学生记录如下：\n");
			printf("|\t学号\t|\t姓名\t|\t性别\t|\n");
			printf("|\t%s\t|\t%s\t|\t%s\t|\n\n", ppStu[i]->m_cpNo, ppStu[i]->m_cpName, ppStu[i]->m_cpGender);
			return i+1;
		}
	}
	printf("\n不存在该学生记录！\n\n");
	return 0;
}

/****************************************
* Author:LiuXL;
* Function:echoStudent();
* Description:list all of the students
****************************************/
char **echoStudent(Student *ppStu[MAX_STU_NO])
{
	char **cpStuTable;
	cpStuTable = (char **)malloc((MAX_STU_NO * 4 + 4) * sizeof(char*));
	for (int i = 0; i < MAX_STU_NO*4+4; i++) cpStuTable[i] = 0x0;
	cpStuTable[0] = "学号";
	cpStuTable[1] = "姓名";
	cpStuTable[2] = "性别";
	cpStuTable[3] = "班级";
	int j = 4;
	for (int i = 0; i<MAX_STU_NO&&ppStu[i]!=NULL; i++)
	{
		cpStuTable[4 * i + 4] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpNo);
		cpStuTable[4 * i + 5] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpName);
		cpStuTable[4 * i + 6] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpGender);
		cpStuTable[4 * i + 7] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpClass);
	}
	return cpStuTable;
}


/****************************************
* Author:SunZT,LiuXL;
* Function:delStudent();
* Description:Delete info of Student.txt.
****************************************/
void delStudent(Student *ppStu[MAX_STU_NO], long stuNo, int *stuNum)
{
	for (int j = stuNo-1; j<MAX_STU_NO&&ppStu[j]->m_cpNo!=NULL; j++)
	{
		ppStu[j] = ppStu[j + 1];
	}
	(*stuNum)--;
}


/****************************************
* Author:SunZT,JiaZG,LiuXL;
* Function:altStudent();
* Description:alt a student's record.;
****************************************/
int altStudent(Student *ppStu[MAX_STU_NO], long lNo)
{
	char c,cpTmp[20];
	int status=0;
	lNo--;
	printf("要修改哪条信息？(姓名n，性别s，班级c)\n");
	scanf("%s", &c);
	switch (c)
	{
	case 'n':
		printf("\n修改后的姓名为：");
		scanf("%s", ppStu[lNo]->m_cpName);
		break;
	case 's':
		printf("\n修改后的性别为：");
		scanf("%s", ppStu[lNo]->m_cpGender);
		break;
	case 'c':
		printf("\n修改后的班级为：");
		scanf("%s", ppStu[lNo]->m_cpClass);
		break;
	default:
		printf("非法输入！\n\n");
		return 0;
	}
	return 1;
}

/****************************************
* Author:JiaZG;
* Function:searchClass();
* Description:查询班级是否存在
****************************************/
char* searchClass(Student *ppStu[MAX_STU_NO],char cpClass[20])
{
	int i = 0;
	printf("\n请输入班级(*表示所有班级)：");
	scanf("%s", cpClass);
	for (i = 0; ppStu[i]!= NULL&&i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpClass, cpClass) == 0 || strcmp("*", cpClass) == 0)
			return cpClass;
	}
	printf("\n不存在该班级！\n\n");
	return NULL;
}