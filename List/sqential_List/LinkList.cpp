#include <stdio.h>
#include <stdlib.h>
typedef ElemType int;

typedef struct LNode
{
	ElemType data;
	strcut LNode *next;
}LNode, *LinkList;

//get the element
bool GetElem_L(LinkList& L, int i, ElemType& e)
{
	LinkLink p = L->next;
	int j = 1; // 1 to i - 1
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if(!p || j > i)	return 0;
	e = p->data;
	return 1;
}

//insert the element, need to know i-1 elements, ----------->O(n)
bool ListInsert_L(LinkList& L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;   
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)	return 0;
	s = (LinkList)malloc(sizof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

//delete the element, need to know i-1 elements, ----------->O(n)
bool ListDelete_L(LinkList& L, int i, ElemType& e)
{
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)	return 0;
//connect
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	return 1;
}

//create the List
void CreateList_L(LinkList& L, int n)
{
	int i = 0;
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for(i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode))
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

//merge ordered list, -------------------------------------->O(n) = O(La.length + Lb.length)
void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = Lc = La;
	while (pa && pb) {
		if(pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}



