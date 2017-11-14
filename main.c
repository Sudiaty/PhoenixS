/****************************************
* Author:LiuXL		
* Description:Main function
****************************************/

#include "student.h"
#include "course.h"

//Debug
/****************************************
* Author:LiuXL,SunZT;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//实例化Student
	Student pChemUp[MAX_STU_NO]={
		{2016016036,"刘晓亮","男",1,4},
		{2016016037,"孙志焘","男",{1,2},4}
	};
	//定义结构体指针，ppStu[i]为第i+1个Student数组的指针
	Student *ppStu[MAX_STU_NO];
	*ppStu=pChemUp;

	//调用需要调试的函数
	
	echoStudent(ppStu);
	addStudent(ppStu);
	saveStudent(ppStu);
	echoStudent(ppStu);
	getStudent(ppStu);
	echoStudent(ppStu);
	addCourse(ppStu);
	return 0;
}
