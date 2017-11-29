// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。

// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
//#include <conio.h>
//#include <Windows.h>

#include "view.h"
#include "student.h"
#include "course.h"
#include "point.h"

#define INIT_SPP(pp,top) for(int i=0;i<top;i++)pp[i]=0x0                //初始化结构体指针，解决Windows段错误（未初始化的结构体指针数组不全为空；

#define DST_SPP(type,pp,top) for(int i=0;i<top;i++){type*pTmp=(type*)malloc(sizeof(type));pp[i]=pTmp;}              //为结构图指针数组分配内存；
#define DST_SPPI(type,pp,no) type*pTmp=(type*)malloc(sizeof(type));pp[no]=pTmp;

void exportTable(char** cpTableTmp, char fileName[20],int iRow);

// TODO: 在此处引用程序需要的其他头文件
