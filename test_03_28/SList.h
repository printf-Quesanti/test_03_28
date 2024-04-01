#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTdatatype;

typedef struct SListnode
{
	SLTdatatype data;
	struct SListnode* next;
}SLT;

SLT* buySList(SLTdatatype x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListpushback(SLT** phead,SLTdatatype x)
{
	SLT* newnode = buySList(x);
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLT* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListpushfront(SLT** phead, SLTdatatype x)
{
	SLT* newnode = buySList(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SListpopback(SLT** phead)
{
	assert(*phead != NULL);
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLT* tail = *phead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListpopfront(SLT** phead)
{
	assert(*phead != NULL);
	SLT* next = (*phead)->next;
	free(*phead);
	*phead = next;
}
void SListinsert(SLT** phead, SLT* pos, SLTdatatype x)//前插
{
	SLT* newnode = buySList(x);
	if (pos == *phead)
	{
		newnode->next = pos;
		*phead = newnode;
	}
	else
	{
		SLT* cur = *phead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = newnode;
		newnode->next = pos;
	}
}

void SListinsertafter(SLT** phead, SLT* pos, SLTdatatype x)//后插
{
	assert(phead);
	SLT* newnode = buySList(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListerase(SLT** phead, SLT* pos)//删除
{
	assert(phead);
	assert(pos);
	if (*phead == pos)
	{
		*phead = pos->next;
		free(pos);
	}
	else
	{
		SLT* cur = *phead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}

void SListeraseafter(SLT** phead, SLT* pos)//后删
{
	assert(pos);
	assert(phead);
	SLT* cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}

SLT* SListfind(SLT* phead,SLTdatatype x)
{
	SLT* cul = phead;
	while (cul!=NULL)
	{
		if (cul->data == x)
		{
			return cul;
		}
		else
		{
			cul = cul->next;
		}
	}
	return NULL;
}

void SListprintf(SLT* phead)
{
	SLT* cul = phead;
	while (cul != NULL)
	{
		printf("%d->", cul->data);
		cul = cul->next;
	}
	printf("NULL\n");
}

void SListdestory(SLT** phead)//销毁链表
{
	assert(phead);
	SLT* cur = *phead;
	while (cur)
	{
		SLT* next = cur->next;
		free(cur);
		cur = next;
	}
	*phead = NULL;
}

//接口函数
void SListprintf(SLT* phead);
void SListpushback(SLT** phead, SLTdatatype x);
void SListpushfront(SLT** phead, SLTdatatype x);
void SListpopback(SLT** phead);
void SListpopfront(SLT** phead);
SLT* SListfind(SLT* phead,SLTdatatype x);
void SListinsert(SLT** phead, SLT* pos, SLTdatatype x);
void SListinsertafter(SLT** phead, SLT* pos, SLTdatatype x);
void SListdestory(SLT** phead);
void SListerase(SLT** phead, SLT* pos);
void SListeraseafter(SLT** phead, SLT* pos);