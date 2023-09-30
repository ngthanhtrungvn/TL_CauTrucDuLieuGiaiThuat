#include<conio.h>
#include<stdio.h>
typedef int itemtype;
struct StackNode
{
	itemtype Info;
	StackNode *Next;
};
struct Stack
{
	StackNode *Top;
};
void initStack(Stack &s)
{
	s.Top=NULL;
}
int push(Stack &s,StackNode *p)
{
	if(p==NULL)
		return 0;
	p->Next=s.Top;
	s.Top=p;
	return 1;
}
StackNode *createStackNode(itemtype x)
{
	StackNode *p=new StackNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int pop(Stack &s,itemtype &x)
{
	if(s.Top==NULL)
		return 0;
	StackNode *p=s.Top;
	s.Top=s.Top->Next;
	x=p->Info;
	delete p;
	return 1;
}
void doiCoSo(int n,int a)
{
	Stack s;
	initStack(s);
	int cn=n;
	while(n>0)
	{
		push(s,createStackNode(n%a));
		n/=a;
	}
	int x;
	printf("ket qua %d= ",cn);		
	while (s.Top!=NULL)
	{
		int x;
		pop(s,x);
		printf("%X ",x);
	}
}
void main()
{
	int n;
	int a;
	printf("Nhap vao so can chuyen va he so chuyen qua:");
	scanf("%d%d",&n,&a);
	doiCoSo(n,a);
	getch();
}