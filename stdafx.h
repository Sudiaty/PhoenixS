// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

// ���� SDKDDKVer.h ��������õ���߰汾�� Windows ƽ̨��

// ���ҪΪ��ǰ�� Windows ƽ̨����Ӧ�ó�������� WinSDKVer.h������
// �� _WIN32_WINNT ������ΪҪ֧�ֵ�ƽ̨��Ȼ���ٰ��� SDKDDKVer.h��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <Windows.h>

#include "view.h"
#include "student.h"
#include "course.h"
#include "Point.h"

#define INIT_SPP(pp,top) for(int i=0;i<top;i++)pp[i]=0x0                //��ʼ���ṹ��ָ�룬���Windows�δ���δ��ʼ���Ľṹ��ָ�����鲻ȫΪ�գ�

#define DST_SPP(type,pp,top) for(int i=0;i<top;i++){type*pTmp=(type*)malloc(sizeof(type));pp[i]=pTmp;}              //Ϊ�ṹͼָ����������ڴ棻
#define DST_SPPI(type,pp,no) type*pTmp=(type*)malloc(sizeof(type));pp[no]=pTmp;

void exportTable(char** cpTableTmp, char fileName[20]);

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
