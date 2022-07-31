#include "Sqlist.h"
#include <stdio.h>

void SLtest1()
{
	SL a;//∂®“Â
	SL* ptr = &a;
	SLinit(&a);
	SLpushback(&a, 1);
	SLpushback(&a, 2);
	SLpushback(&a, 3);
	//SLpopback(ptr);
	SLpushfront(ptr, 4);
	/*SLpopfront(ptr);
	SLpopfront(ptr);*/

	int i = 0;
	for (i = 0; i < ptr->size; i++)
	{
		printf("%d ", ptr->arr1[i]);
	}
}

int main()
{
	SLtest1();
	return 0;
}