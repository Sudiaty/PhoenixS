/****************************************
* Author:LiuXL;
* Description:Function related with
*	ppStudent class.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addCourse();
* Description:Add a course for a student.
****************************************/
void addCourse(Student *ppStu[MAX_STU_NO])
{
	int i, j;
	char cpNo[10];
	int status, sign;
	printf("������ѡ��ѧ����ѧ�ţ�");
	scanf("%s", &cpNo);
	for (i = 0; i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			break;
		}
		else {
			printf("û�и�ѧ���ļ�¼��\n");
			exit(0);
		}
	}

	//��ӡ���пγ�
	for (j = 0; j<MAX_SUB_NO; j++)
	{
		printf("%ld %s %.1f\n",
			pChem[j].m_lCourseNo,
			pChem[j].m_cpCourseName,
			pChem[j].m_fGoal);
	}

	for (j = 0; j<MAX_SUB_NO; j++)
	{
		long lpMajor[MAX_SUB_NO] = { 0 };
		printf("������γ̴��룺");
		scanf("%ld", &lpMajor[j]);
		ppStu[i]->m_lpMajor[j] = lpMajor[j];
		do
		{
			printf("�Ƿ�������룿1.������0.��ֹ");
			scanf("%d", &sign);
			switch (sign)
			{
			case 1:
				status = 0;
				break;
			case 0:
				printf("�ɹ���ӿγ̣�\n");
				return;
			default:
				printf("ָ���������������룺");
				status = 1;
			}
		} while (status);
	}
}
