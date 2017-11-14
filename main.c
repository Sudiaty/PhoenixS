/****************************************
* Author:LiuXL		
* Description:Main function
****************************************/

#include "student.h"
#include "course.h"
#include "view.h"

//Debug
/****************************************
* Author:LiuXL,SunZT;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	/*实例化Student对象*/
	Student *ppStu[MAX_STU_NO];
	Student *pTmp=(Student*)malloc(sizeof(Student));
	ppStu[0]=pTmp;	

	/*实例化Form对象*/
	Form *ppStuForm[MAX_ROW];
	Form *pForm=(Form*)malloc(sizeof(Form));
	ppStuForm[0]=pForm;
	/*为对象赋初值*/
	/*strcpy(ppStuForm[0]->m_cpTitle,"ID");
	strcpy(ppStuForm[1]->m_cpTitle,"Name");
	strcpy(ppStuForm[2]->m_cpTitle,"Sex");*/

	/*Action*/
	addStudent(ppStu);
	echoStudent(ppStu);
	saveStudent(ppStu);
	echoStudent(ppStu);
	return 0;
}
