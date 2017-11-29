#This is make file
build.exe:main.c stdafx.o view.c student.c course.c
	gcc main.c view.c student.c course.c point.c -o build.exe -g -std=c99
stdafx.o:stdafx.c
	gcc stdafx.c -o stdafx.o

