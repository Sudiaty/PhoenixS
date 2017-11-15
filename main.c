/****************************************
* Author:LiuXL
* Description:Main function
****************************************/
#include"view.h"
#include"student.h"
#include"course.h"

/****************************************
* Author:LiuXL,SunZT;
* Function:main();
* Description:Debug;
****************************************/
int main()
{
    /*实例化Student对象*/
    Student *ppStu[MAX_STU_NO];
    Student *pTmp=(Student*)malloc(sizeof(Student));	//创建一个空的学生记录
    ppStu[0]=pTmp;


    /*实例化Form对象*/
    Form *ppStuForm[MAX_ROW];

    /*为学生信息表单对象赋初值*/
    for (int i=0; i<STU_FORM_ROW;++i)
    {
        Form *pTmp=(Form*)malloc(sizeof(Form));
        ppStuForm[i]=pTmp;
    }
    strcpy(ppStuForm[0]->m_cpTitle,"学号");
    strcpy(ppStuForm[1]->m_cpTitle,"姓名");
    strcpy(ppStuForm[2]->m_cpTitle,"性别");
    strcpy(ppStuForm[3]->m_cpTitle,"班级");

    /*Action*/
    getStudent(ppStu);
    echoStudent(ppStu);
    addCourse(ppStu);
    saveStudent(ppStu);
    echoStudent(ppStu);
    
    return 0;
}
