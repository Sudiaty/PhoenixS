/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
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
	altStudent(ppStu);
	
	return 0;
}