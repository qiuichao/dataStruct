#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base)	return -1;
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return true;
}

bool GetTop(SqStack& S, SElemType& e)
{
	if (S.base == S.top)	return -1;
	e = *(S.top-1);
	return 1;
}

bool Push(SqStack& S, SElemType e)
{
	if(S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc((S.stacksize + STACKINCREMENTSIZE) * sizeof(SElemType));
		if (!S.base)	return -1;
		S.top = S.base + S.stacksize;  //the stack is full
		S.stacksize += STACKINCREMENTSIZE;
	}
	*S.top++ = e;
	return 1;
}

bool Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base)	return -1;  //the stack is empty
	e = --*S.top;
	return 1;
}


/*--------------------------------------------
**	Hexadecimal conversion, 10 to 8
**
*--------------------------------------------*/
void conversion()
{
	InitStack(S);
	Scanf("%d", &N);
	while(N) {
		push(S, N  % 8);
		N = N / 8;
	}
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d ", e);
	}
}
