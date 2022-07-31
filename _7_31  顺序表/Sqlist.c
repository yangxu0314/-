#include "Sqlist.h"

void SLinit(SL* psl)
{
	//psl不是空指针，否则警告
	assert(psl);

	psl->arr1 = NULL;
	psl->SQcapacity = psl->size = 0;
}

void SLdestory(SL* psl)
{
	assert(psl);
	//先将分配的内存释放掉，再将地址变为0；否则就会发生内存泄漏；
	free(psl->arr1);
	psl->arr1 = NULL;

	psl->SQcapacity = psl->size = 0;
}

void checkSL(SL* psl)
{
	if (psl->size == psl->SQcapacity)
	{
		int newcapacity = psl->SQcapacity == 0 ? 4 : psl->SQcapacity * 2;
		//先创建中间变量tmp
		SQtype* tmp = (SQtype*)realloc(psl->arr1, newcapacity);
		if (tmp == NULL)
		{
			//错误输出函数perror（s），参数s是字符串；功能是先打印s，在打印错误原因字符串
			perror("realloc fail");
			exit(-1);
			//return
			//参数为0，正常退出；参数为非0，异常退出；
			//return是堆栈返回，exit是进程返回
			//return是c语言提供的，exit是操作系统提供
		}
		psl->arr1 = tmp;
		psl->SQcapacity = newcapacity;
	}
}
//尾插
void SLpushback(SL* psl, SQtype x)
{
	assert(psl);

	checkSL(psl);
	*(psl->arr1 + psl->size) = x;
	//或者写成psl->arr1[psl->size] = x;
	psl->size++;
	
}

//尾删
void SLpopback(SL* psl)
{
	assert(psl);
	//温柔检查
	if (psl->size == 0)
	{
		return;
	}
	//暴力
	assert(psl->size >= 0);
	psl->size--;
}

//头插
void SLpushfront(SL* psl, SQtype x)
{
	assert(psl);

	checkSL(psl);//检查是否还有容量
	int i = 0;
	for (i = psl->size; i > 0; i--)
	{
		psl->arr1[i] = psl->arr1[i - 1];
	}
	psl->arr1[0] = x;
	psl->size++;
}

//头删
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