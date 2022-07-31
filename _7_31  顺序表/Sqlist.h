#pragma once

#include "Sqlist.h"
#include "assert.h"
#include "malloc.h"
#include "stdlib.h"

//#define N 10

//静态顺序表
//typedef struct SeqList
//{
//	SQtype arr0[N];//定长数组
//	int size;//有效数据个数
//}SeqList;

//动态顺序表
typedef int SQtype;
typedef struct SeqList
{
	SQtype* arr1;
	int size;
	int SQcapacity;
}SL;


//初始化
void SLinit(SL* psl);
//释放
void SLdestory(SL* psl);
//检查是否需要扩容
void checkSL(SL* psl);
//尾插
void SLpushback(SL* psl, SQtype x);
//尾删
void SLpopback(SL* psl);
//头插
void SLpushfront(SL* psl, SQtype x);
//头删
void SLpopfront(SL* psl);




