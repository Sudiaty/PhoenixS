#This is make file
build.exe:main.c view.c student.c course.c
	gcc main.c view.c student.c course.c point.c -o build.exe -g -std=c99
