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
StackNode *createStackNode(itemtype x)
{
	StackNode *p=new StackNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int push(Stack &s,StackNode *p)
{
	if(p==NULL)
		return 0;
	p->Next=s.Top;
	s.Top=p;
	return 1;
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
long tinhGiaiThua(Stack &s,int n)
{
	int x;
	int cn=n;
	initStack(s);
	while(n>0)
	{
		push(s,createStackNode(n)); 
		n--;
	}
	long kq=1;
	while(1)
	{
		if(pop(s,x)==0)
			break;
		kq*=x;
	}
	return kq;
}
void main()
{
	int n;
	printf("Nhap vao n=");
	scanf("%d",&n);
	Stack s;
	printf("Ket qua %d=%ld",n,tinhGiaiThua(s,n));
	getch();
}