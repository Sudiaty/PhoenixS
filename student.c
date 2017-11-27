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
void addStudent(Student *ppStu[MAX_STU_NO], Form *ppForm[MAX_ROW], int *stuNum)
{
	strcpy(ppStu[*stuNum]->m_cpNo, ppForm[0]->m_cpContent);
	strcpy(ppStu[*stuNum]->m_cpName, ppForm[1]->m_cpContent);
	strcpy(ppStu[*stuNum]->m_cpGender, ppForm[2]->m_cpContent);
	strcpy(ppStu[*stuNum]->m_cpClass, ppForm[3]->m_cpContent);
	(*stuNum)++;
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
			printf("写入失败！\n");
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
long searchStudent(Student *ppStu[MAX_STU_NO], char cpNo[10])
{
	long i = 0;
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
	printf("\n不存在该学生记录！\n");
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
void delStudent(Student *ppStu[MAX_STU_NO], char cpNo[10], int *stuNum)
{

	for (int i = 0; i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			for (int j = i; j<MAX_STU_NO&&strcmp(ppStu[j]->m_cpNo, "\0") != 0; j++)
			{
				ppStu[j] = ppStu[j + 1];
			}
			(*stuNum)--;
			printf("正在删除......\n");
			printf("已经删除学号为%s 的学生记\n", cpNo);
		}
	}
}


/****************************************
* Author:SunZT,JiaZG,LiuXL;
* Function:altStudent();
* Description:alt a student's record.;
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO], long *lNo)
{
	char c,cpTmp[20];
	printf("要修改哪条信息？(姓名n，性别s，班级c)\n");
	scanf("%s", &c);
	printf("\n修改后的信息为：");
	scanf("%s",cpTmp);
	switch (c)
	{
		case 'n':
			strcpy(ppStu[*lNo-1]->m_cpName,cpTmp);
			break;
		case 's':
			strcpy(ppStu[*lNo-1]->m_cpGender,cpTmp);
			break;
		case 'c':
			strcpy(ppStu[*lNo-1]->m_cpClass,cpTmp);
			break;
		default:
			printf("非法输入！\n");
			break;
	}
}