#include<conio.h>
#include<stdio.h>
#include<string>
typedef char itemtype;
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
void daoChuoi(char *x)
{
	Stack s;
	initStack(s);
	for(int i=0;i<strlen(x);i++)
	{
		push(s,createStackNode(x[i]));
	}
	char y;
	printf("Dao chuoi %s la chuoi: ",x);
	while(1)
	{
		if(pop(s,y)==0)
			break;
		printf("%c",y);
	}
}
void main()
{
	char x[15];
	printf("Nhap vao chuoi:");
	scanf("%s",&x);
	daoChuoi(x);
	getch();
}