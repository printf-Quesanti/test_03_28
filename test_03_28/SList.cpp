#include"SList.h"
void Test1()
{
	SLT* s = NULL;
	SListpushback(&s, 1);
	SListpushback(&s, 2);
	SListpushback(&s, 3);
	SListpushback(&s, 4);
	SListprintf(s);
	SListpushfront(&s, 1);
	SListpushfront(&s, 2);
	SListpushfront(&s, 3);
	SListpushfront(&s, 4);
	SListprintf(s);
}

void Test2()
{
	SLT* s = NULL;
	SListpushback(&s, 1);
	SListpushback(&s, 2);
	SListpushback(&s, 3);
	SListpushback(&s, 4);
	SListprintf(s);

	SListpopback(&s);
	SListpopback(&s);
	SListpopback(&s);
	SListpopback(&s);

	SListprintf(s);
}

void Test3()
{
	SLT* s = NULL;
	SListpushback(&s, 1);
	SListpushback(&s, 2);
	SListpushback(&s, 3);
	SListpushback(&s, 4);
	SListpopfront(&s);
	SListprintf(s);
	SListpopfront(&s);
	SListprintf(s);
	SListpopfront(&s);
	SListprintf(s);
	SListpopfront(&s);
	SListprintf(s);
}

void Test4()
{
	SLT* s = NULL;
	SListpushback(&s, 1);
	SListpushback(&s, 2);
	SListpushback(&s, 3);
	SListpushback(&s, 3);
	SListpushback(&s, 1);
	SListpushback(&s, 3);
	SListpushback(&s, 3);
	SListpushback(&s, 4);
	SLT* pos = SListfind(s, 3);//²éÕÒ
	int i = 1;
	while (pos!=NULL)
	{
		printf("%d %p \n", i++, pos);
		pos = SListfind(pos->next, 3);
	}

	pos = SListfind(s, 4);//ÐÞ¸Ä
	if (pos)
	{
		pos->data = 40;
	}
	SListprintf(s);
}

void Test5()
{
	SLT* s = NULL;
	SListpushback(&s, 1);
	SListpushback(&s, 2);
	SListpushback(&s, 3);
	SLT* pos = SListfind(s, 1);
	if (pos)
	{
		 SListinsert(&s, pos, 40);
	}
	SListprintf(s);
 }
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	return 0;
}