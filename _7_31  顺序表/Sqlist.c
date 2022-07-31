#include "Sqlist.h"

void SLinit(SL* psl)
{
	//psl���ǿ�ָ�룬���򾯸�
	assert(psl);

	psl->arr1 = NULL;
	psl->SQcapacity = psl->size = 0;
}

void SLdestory(SL* psl)
{
	assert(psl);
	//�Ƚ�������ڴ��ͷŵ����ٽ���ַ��Ϊ0������ͻᷢ���ڴ�й©��
	free(psl->arr1);
	psl->arr1 = NULL;

	psl->SQcapacity = psl->size = 0;
}

void checkSL(SL* psl)
{
	if (psl->size == psl->SQcapacity)
	{
		int newcapacity = psl->SQcapacity == 0 ? 4 : psl->SQcapacity * 2;
		//�ȴ����м����tmp
		SQtype* tmp = (SQtype*)realloc(psl->arr1, newcapacity);
		if (tmp == NULL)
		{
			//�����������perror��s��������s���ַ������������ȴ�ӡs���ڴ�ӡ����ԭ���ַ���
			perror("realloc fail");
			exit(-1);
			//return
			//����Ϊ0�������˳�������Ϊ��0���쳣�˳���
			//return�Ƕ�ջ���أ�exit�ǽ��̷���
			//return��c�����ṩ�ģ�exit�ǲ���ϵͳ�ṩ
		}
		psl->arr1 = tmp;
		psl->SQcapacity = newcapacity;
	}
}
//β��
void SLpushback(SL* psl, SQtype x)
{
	assert(psl);

	checkSL(psl);
	*(psl->arr1 + psl->size) = x;
	//����д��psl->arr1[psl->size] = x;
	psl->size++;
	
}

//βɾ
void SLpopback(SL* psl)
{
	assert(psl);
	//������
	if (psl->size == 0)
	{
		return;
	}
	//����
	assert(psl->size >= 0);
	psl->size--;
}

//ͷ��
void SLpushfront(SL* psl, SQtype x)
{
	assert(psl);

	checkSL(psl);//����Ƿ�������
	int i = 0;
	for (i = psl->size; i > 0; i--)
	{
		psl->arr1[i] = psl->arr1[i - 1];
	}
	psl->arr1[0] = x;
	psl->size++;
}

//ͷɾ
void SLpopfront(SL* psl)
{
	int i = 0;
	for (i = 1; i < psl->size; i++)
	{
		psl->arr1[i - 1] = psl->arr1[i];
	}
	psl->size--;
}

//