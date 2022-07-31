#pragma once

#include "Sqlist.h"
#include "assert.h"
#include "malloc.h"
#include "stdlib.h"

//#define N 10

//��̬˳���
//typedef struct SeqList
//{
//	SQtype arr0[N];//��������
//	int size;//��Ч���ݸ���
//}SeqList;

//��̬˳���
typedef int SQtype;
typedef struct SeqList
{
	SQtype* arr1;
	int size;
	int SQcapacity;
}SL;


//��ʼ��
void SLinit(SL* psl);
//�ͷ�
void SLdestory(SL* psl);
//����Ƿ���Ҫ����
void checkSL(SL* psl);
//β��
void SLpushback(SL* psl, SQtype x);
//βɾ
void SLpopback(SL* psl);
//ͷ��
void SLpushfront(SL* psl, SQtype x);
//ͷɾ
void SLpopfront(SL* psl);




