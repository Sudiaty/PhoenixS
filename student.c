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
    strcpy(ppStu[*stuNum]->m_cpName,ppForm[0]->m_cpContent);
    strcpy(ppStu[*stuNum]->m_cpGender,ppForm[0]->m_cpContent);
    strcpy(ppStu[*stuNum]->m_cpClass,ppForm[0]->m_cpContent);
    stuNum++;
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
void getStudent(Student *ppStu[MAX_STU_NO])
{
    FILE *fp;
    int i;

    //读取Student.dat
    if ((fp=fopen("Student.dat","rb"))==NULL)
    {
        printf("暂无学生记录！\n");
    }
    for(i=0;i<MAX_STU_NO&&ppStu[i]!=NULL;i++)
    {
        fread(ppStu[i],sizeof(Student),1,fp);
    }
    fclose(fp);
}


/****************************************
* Author:JiaZG;
* Function:searchStudent();
* Description:search a student by m_cpNo
****************************************/
void searchStudent(Student *ppStu[MAX_STU_NO])
{
    int i = 0;
    char cpNo[10];
    printf("\n请输入要查询学生的学号：");
    scanf("%s",&cpNo);
    for(i=0;i<MAX_STU_NO;i++)
    {
        if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
        {
            printf("\n存在要查询的学生记录！");
            break;
        }
    }

    if(i==MAX_STU_NO)
    {
        printf("\n不存在要查询的学生记录！");
        return;
    }
    //输出所查学生记录
    printf("\n所查记录如下：");
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
        // for(j=0;j<MAX_SUB_NO&&ppStu[i]->m_lpMajor[j]!=0;j++)
        // {
        //     printf("%ld ",ppStu[i]->m_lpMajor[j]);
        // }
        // printf("\n");
    }
    return cpStuTable;
}


/****************************************
* Author:SunZT;
* Function:delStudent();
* Description:Delete info of Student.txt.
****************************************/
void delStudent(Student *ppStu[MAX_STU_NO])
{
    int i=0;
    int j=0;
    char cpNo[10];
    char c;
    printf("\n 请输入要删除的学生学号:");
    scanf("%s",&cpNo);
    j=i+1;
    for(i=0;i<MAX_STU_NO && ppStu[i]!=NULL;i++)
    {
        if(strcmp(ppStu[i]->m_cpNo,cpNo)==0)
        {
            printf("\n 存在要删除的学生记录");
            break;
        }
    }
    if((i==MAX_STU_NO)||(ppStu[i]==NULL))
    {
        printf("\n 不存在要删除的学生记录的");
        return;
    }
    /*输出要删除的学生信息开始*/
    printf("这 是 要 删 除 的 记 录 吗?\n");
    printf("学号 姓名 性别\n");
    printf("%ld %s %s\n",ppStu[i]->m_cpNo,ppStu[i]->m_cpName,ppStu[i]->m_cpGender);
    printf("你确定要删除该记录吗?Y or N!\n");
    scanf("%s",&c);
    if((c=='Y')||(c=='N'))
    {
        for(j=i+1;j<MAX_STU_NO-i;j++)
        { ppStu[j-1]=ppStu[j]; }
        ppStu[j]=NULL;
        printf("正在删除......\n");
        printf("已经删除学号为%s 的学生记\n",cpNo); }
    else
    { printf("返回主菜单"); }
  }


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
