#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string>
typedef int ItemType;

struct StackNode
{
	ItemType Info;
	StackNode *Next;
};

struct Stack
{
	StackNode *Top;
};

StackNode *createStackNode(ItemType x)
{
	StackNode *p= new StackNode;
	if(p == NULL)
		return NULL;
	p->Info= x;
	p->Next= NULL;
	return p;
}

int push(Stack &s, ItemType x)
{
	StackNode* p= createStackNode(x);                                     
	if(p == NULL)
		return 0;
	p->Next= s.Top;
	s.Top= p;
	return 1;
}

int pop(Stack &s, ItemType &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode* p= s.Top;
	s.Top= s.Top->Next;
	x=p->Info;
	delete p;
	return 1;
}

int isEmpty(Stack s)
{
	if(s.Top == NULL)
		return 1;
	return 0;
}

//doi so nguyen tu he 10 sang he 16
void doiCoSo16(int n, int a)
{
	Stack s;
	s.Top= NULL;
	char chu;
	while(n > 0)
	{
		int sodu= n % a;
		n= n/a;
		push(s, sodu);	
	}
	while(s.Top != NULL)
	{
		int e;
		pop(s, e);
		printf("%X ", e);
	}
}

void main()
{
	int a,n;
	scanf("%d%d",&n,&a);
	doiCoSo16(n, a);
	/*char str[50]="Phat ngu nhu bo` :)))" ;
	for(int i=0; i< strlen(str); i++)
	{
		printf("%c", str[i]);
		_sleep(500);
	}*/
	// giai thich coi
	getch();
}