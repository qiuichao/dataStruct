#ifndef		 _STACK_H_
#define		 _STACK_H_

#define STACK_INIT_SIZE		100
#define STACKINCREMENT		10
typedef struct {
	SElemType	*base;
	SElemTYpe	*top;
	int 		stackSize;
}SqStack; 

bool	InitStack(SqStack& S);
bool 	DestroyStack(SqStack& S);
bool 	ClearStatck(SqStack& S);
bool 	StackEmpty(SqStack& S);
bool	StackLength(SqStack& S);
bool	GetTop(Sqstack& S, SqElemType& e);
bool	Push(SqStack& S, SqElemType e);
bool	Pop(SqStack& S, SqElemType& e);
bool	TravelStack(SqStack& S, bool (*visit)());

#endif
