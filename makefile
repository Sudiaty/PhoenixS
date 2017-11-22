#This is make file
build.out:main.c view.c student.c course.c
	gcc main.c view.c student.c course.c point.c -o build.out -g -std=c99
