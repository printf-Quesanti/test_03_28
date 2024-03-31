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
void SListinsert(SLT** phead, SLT* pos, SLTdatatype x)
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

//½Ó¿Úº¯Êý
void SListprintf(SLT* phead);
void SListpushback(SLT** phead, SLTdatatype x);
void SListpushfront(SLT** phead, SLTdatatype x);
void SListpopback(SLT** phead);
void SListpopfront(SLT** phead);
SLT* SListfind(SLT* phead,SLTdatatype x);
void SListinsert(SLT** phead, SLT* pos, SLTdatatype x);
void SListdestroy();