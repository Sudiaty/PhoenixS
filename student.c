/****************************************
* Author:LiuXL;
* Description:Function related with
*	ppStudent class.
****************************************/

#include "student.h"
#include "view.h"

/****************************************
* Author:LiuXL;
* Function:addStudent();
* Description:Add a student's record.
****************************************/
void addStudent(Student *ppStu[MAX_STU_NO],Form *ppForm[MAX_ROW],int *stuNum)
{
    strcpy(ppStu[*stuNum]->m_cpNo,ppForm[0]->m_cpContent);
    strcpy(ppStu[*stuNum]->m_cpName,ppForm[1]->m_cpContent);
    strcpy(ppStu[*stuNum]->m_cpGender,ppForm[2]->m_cpContent);
    strcpy(ppStu[*stuNum]->m_cpClass,ppForm[3]->m_cpContent);
    (*stuNum)++;
}


/****************************************
* Author:LiuXL;
* Function:saveStudent();
* Description:Save the info to Student.txt.
****************************************/
void saveStudent(Student *ppStu[MAX_STU_NO])
{
    FILE *fp;
    int i;

    //读取Student.txt
    if ((fp=fopen("Student.dat","wb"))==NULL)
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    //获取当前学生人数
    for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
    {
        //写入数据至Student.txt
        if(fwrite(ppStu[i],sizeof(Student),1,fp)!=1)
        printf("写入失败！\n");
    }
    fclose(fp);
}


/****************************************
* Author:JiaZG,LiuXL;
* Function:getStudent();
* Description:get the info to Student.txt.
* add return the point of stuct.
****************************************/
void getStudent(Student *ppStu[MAX_STU_NO],int *stuNum)
{
    FILE *fp;
    int i;

    //读取Student.dat
    if ((fp=fopen("Student.dat","rb"))==NULL)
    {
        return;
    }
    for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
    {
        fread(ppStu[i],sizeof(Student),1,fp);
        (*stuNum)++;
    }
    fclose(fp);
}


/****************************************
* Author:JiaZG;
* Function:searchStudent();
* Description:search a student by m_cpNo
****************************************/
char* searchStudent(Student *ppStu[MAX_STU_NO],char cpNo[10])
{
    int i = 0;
    printf("\n请输入学生的学号：");
    scanf("%s",cpNo);
    for(i=0;i<MAX_STU_NO;i++)
    {
        if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
        {
            printf("该学生记录如下：\n");
            printf("|\t学号\t|\t姓名\t|\t性别\t|\n");
            printf("|%16s|\t%4s\t|\t%4s\t|\n",ppStu[i]->m_cpNo,ppStu[i]->m_cpName,ppStu[i]->m_cpGender);
            return cpNo;
        }
    }
    if(i==MAX_STU_NO)
    {
        printf("\n不存在该学生记录！");
        return NULL;
    }
}


/****************************************
* Author:LiuXL;
* Function:echoStudent();
* Description:list all of the students
****************************************/
char **echoStudent(Student *ppStu[MAX_STU_NO])
{
    char **cpStuTable;
    cpStuTable=(char **)malloc((MAX_STU_NO*4+4)*sizeof(char*));
    for (int k=0;k<4;k++)  
        cpStuTable[k]=(char *)malloc(20*sizeof(char));  
    cpStuTable[0]="学号";
    cpStuTable[1]="姓名";
    cpStuTable[2]="性别";
    cpStuTable[3]="班级";
    int j=4;
    for(int i=0;i<MAX_STU_NO&&strcmp(ppStu[i]->m_cpNo,"\0");i++)
    {
        cpStuTable[i+4]=(char *)malloc(20*sizeof(char)); 
        strcpy(cpStuTable[j++],ppStu[i]->m_cpNo);
        cpStuTable[i+5]=(char *)malloc(20*sizeof(char)); 
        strcpy(cpStuTable[j++],ppStu[i]->m_cpName);
        cpStuTable[i+6]=(char *)malloc(20*sizeof(char)); 
        strcpy(cpStuTable[j++],ppStu[i]->m_cpGender);
        cpStuTable[i+7]=(char *)malloc(20*sizeof(char)); 
        strcpy(cpStuTable[j++],ppStu[i]->m_cpClass);
    }
    return cpStuTable;
}


/****************************************
* Author:SunZT;
* Function:delStudent();
* Description:Delete info of Student.txt.
****************************************/
// void delStudent(Student *ppStu[MAX_STU_NO],char cpNo[10])
// {
//     printf("你确定要删除该记录吗?Y or N!\n");
//     scanf("%s",&c);
//     if((c=='Y')||(c=='N'))
//     {
//         for(j=i+1;j<MAX_STU_NO-i;j++)
//         { ppStu[j-1]=ppStu[j]; }
//         ppStu[j]=NULL;
//         printf("正在删除......\n");
//         printf("已经删除学号为%s 的学生记\n",cpNo); }
//     else
//     { printf("返回主菜单"); }
// }


/****************************************
* Author:SunZT,JiaZG,LiuXL;
* Function:altStudent();
* Description:alt a student's record.;
****************************************/
void altStudent(Student *ppStu[MAX_STU_NO])
{
    int i = 0;                /*学生记录行号*/
    int m = 0;             	  /*修改状态标志0不修改*/
    char cpNo[10];                 /*学号*/
    char c;                   /*确认指令Y修改N不修改*/
    printf("\n请输入要修改学生的学号：");
    scanf("%s",&cpNo);

    for(i=0;i<MAX_STU_NO;i++)
    {
        if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
        {
            printf("\n存在要修改的学生记录！");
            break;
        }
    }
    if(i==MAX_STU_NO)
    {
        printf("\n不存在要修改的学生记录！");
        return;
    }
    printf("\n该学生记录如下：");
    printf("%ld %s %s %s\n",
        ppStu[i]->m_cpNo,
        ppStu[i]->m_cpName,
        ppStu[i]->m_cpGender,
        ppStu[i]->m_cpClass);
    printf("是否要修改该记录？y or n\n");
    scanf("%s",&c);
    if((c=='Y'|| c=='y'))
    {
        m=1;
    }
    else
    {
        printf("终止修改！\n");
        return;
    }

    while(m==1)
    {
        printf("要修改哪条信息？(姓名n，性别s，班级c)\n");
        scanf("%s",&c);
        switch(c)
        {
            case 'n':
                printf("\n请输入修改后该学生的姓名：");
                scanf("%s",&ppStu[i]->m_cpName);
                m=0;
                break;
            case 's':
                printf("\n请输入修改后该学生的性别(男m，女f）：");
                scanf("%s",&ppStu[i]->m_cpGender);
                m=0;
                break;
            case 'c':
                printf("\n请输入修改后该学生的班级：");
                scanf("%s",&ppStu[i]->m_cpClass);
                m=0;
                break;
            default:
                printf("非法输入！\n");
                break;
        }
    }
}
