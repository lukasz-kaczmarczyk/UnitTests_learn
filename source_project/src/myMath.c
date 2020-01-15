#include "myMath.h"


int add(int a, int b)
{
	return a + b;
}

void swapNum(int *num1, int *num2)
{
   int tmp;

   tmp = *num1;
   *num1 = *num2;
   *num2 = tmp;
}
