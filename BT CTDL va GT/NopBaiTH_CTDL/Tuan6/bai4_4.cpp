#include<conio.h>
#include<stdio.h>
struct DC
{
	int n,src,des;
};
typedef DC itemtype;
struct StackNode
{
	itemtype Info;
	StackNode *Next;
};
struct Stack
{
	StackNode *Top;
};
itemtype layRa(int n,int src,int des)
{
	itemtype layRaDC;
	layRaDC.n=n;
	layRaDC.src=src;
	layRaDC.des=des;
	return layRaDC;
}
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
StackNode *createStackNode(itemtype x)
{
	StackNode *p=new StackNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
void xuLy(int n)
{
	Stack s;
	initStack(s);
	push(s,createStackNode(layRa(n,1,3)));
	while(s.Top!=NULL)
	{
		itemtype layRaDC;
		pop(s,layRaDC);
		if(layRaDC.n==1)
			printf("Di chuyen 1 dia tu cot %d sang %d\n",layRaDC.src,layRaDC.des);
		else
		{
			int tam=6-layRaDC.src-layRaDC.des;
			push(s,createStackNode(layRa(layRaDC.n-1,tam,layRaDC.des)));
			push(s,createStackNode(layRa(1,layRaDC.src,layRaDC.des)));
			push(s,createStackNode(layRa(layRaDC.n-1,layRaDC.src,tam)));
		}
	}
}
void main()
{
	int n=3;
	xuLy(n);
	getch();
}