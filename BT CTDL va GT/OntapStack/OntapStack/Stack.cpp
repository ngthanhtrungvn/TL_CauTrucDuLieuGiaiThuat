#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>

typedef int ItemType;
using namespace std;

struct StackNode
{
	ItemType Info;
	StackNode* Next;
};

struct Stack
{
	StackNode* Top;
};

//bien gia tri thanh StackNode
StackNode* createStackNode(ItemType x)
{
	StackNode* p= new StackNode;
	if(p==NULL)
		return NULL;
	p->Info= x;
	p->Next= NULL;
	return p;
}

//them vao stack
int push(Stack &s, ItemType x)
{
	StackNode *p= createStackNode(x);
	if(p==NULL)
		return 0;
	p->Next= s.Top;
	s.Top= p;
	return 1;
}

//xoa khoi stack
int pop(Stack &s, ItemType &x)
{
	if(s.Top==NULL)
		return 0;
	StackNode *p= s.Top->Next;
	x= p->Info;
	delete p;
	return 1;
}

//ktra rong
int isEmpty(Stack s)
{
	if(s.Top==NULL)
		return 1;
	return 0;
}

//doi co so
void doiCoSo(int n, int a)
{
	Stack s;
	s.Top= NULL;
	while(n!=0)
	{
		int du=n % a;
		n= n / a;
		push(s, du);
	}
	while (s.Top!= NULL)
	{
		int x;
		pop(s, x);
		printf("%d", x);
	}
}

//chuyen tu 10 sang 16
 void doiCoSo16(int a, int n)
 {
	Stack s;
	n= 16;
	int x= a;
	char chu;
	while(a != 0)
	{
		int sodu= x % 16;
		n = n / a;
		push(s, sodu);
		if(sodu == 10)
			chu= 'A';
		else if(sodu == 11)
			chu= 'B';
		else if(sodu == 12)
			chu= 'C';
		else if(sodu == 13)
			chu= 'D';
		else if(sodu == 14)
			chu= 'E';
		else if(sodu == 15)
			chu= 'F';
	}
	while(s.Top != NULL)
	{
		int e;
		pop(s, e);
		printf("%d", e);
	}
 }

void main()
{
	doiCoSo(130, 2);
	getch();

}


