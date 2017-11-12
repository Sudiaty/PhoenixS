/****************************************
* Author:LiuXL\				
* Description:Main function
****************************************/

#include "student.h"

//Debug
int main()
{
	//实例化Student
	Student up1602[MAX_STU_NO];
	Student *stu=up1602;

	addStudent(stu);	/*debug*/
    
	saveStudent(stu);	/*debug*/

	return 0;
}