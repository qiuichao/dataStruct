#include <stdio.h>
#define LIST_INT_SIZE	100
#define LISTINCREMENT	10
#define ElemType	int

typedef struct
{
	ElemType * 	elem;
	int		length;
	int		listSize;
}SqList;

bool InitSqList(SqList& L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)	exit(0);
	l.length = 0;
	l.listsize = LIST_INIT_SIZE;
	return true;
}

bool ListInsert_Sq(SqList& L, int i, ElemType e)
{
	ElemType* p, *q;
	ElemType* newbase;
	if(i < 1 || i > L.length + 1)
		return ERROR;
	if(L.length >= L.listSize)  {
		newbase = realloc(L.elem, (L.length + LISTINCREMENT) * sizeof(ElemType));
		if(!newbase)	return 0;
		L.elem = newbase;
		L.listSize = L.length + LISTINCREMENT;
	}
	q = &(L.elem[i]-1);
	for(p = &(L.elem[L.length-1]); p <= q; p++)
		*(p+1) = *p;
	*p = e;
	++L.length;
	return true;

}

bool ListDel_Sq(SqList& L, int i, ElemType &e)
{
	if(i < 1 || i > L.length)	return 0;
	q = &(L.elem[L.length-1]);
	for(p = &(L.elem[i-1]; p < q; p++))
	{
		*(p-1) = *p;
	}
	--L.length;
	e = *p;
	return ture;
}


