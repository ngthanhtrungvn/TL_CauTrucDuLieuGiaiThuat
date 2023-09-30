#include<conio.h>
#include<stdio.h>
#include<math.h>
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
int doUuTien(char x)
{
	if(x=='(')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/')
		return 2;
	return 3;
}
void bienThanhPostfix1(char *bieuThuc,char *str)
{	
	Stack s;
	initStack(s);
	int j=0;
	for(int i=0;i<strlen(bieuThuc);i++)
	{
		if(bieuThuc[i]=='(')
			push(s,createStackNode(bieuThuc[i]));
		else
			if(bieuThuc[i]>='0'&&bieuThuc[i]<='9')
				str[j++]=bieuThuc[i];
			else
			if(bieuThuc[i]==')')
				{
					while(1)
					{
						itemtype x;
						pop(s,x);
						if(x=='('||s.Top==NULL) break;
						str[j++]=x;
					}
				}
			else
			{
				while(s.Top!=NULL&&doUuTien(s.Top->Info)>=doUuTien(bieuThuc[i]))
				{
					itemtype x;
					pop(s,x);
					str[j++]=x;
				}
				push(s,createStackNode(bieuThuc[i]));
			}		
	}
	while (s.Top!=NULL)
	{
		char t;
		pop(s,t);
		if(t!='(')
		str[j++]=t;
	}
}
void main()
{
	char bieuthuc[50],str[50]={};
	printf("Nhap vao bieu thuc:");
	scanf("%s",&bieuthuc);
	bienThanhPostfix1(bieuthuc,str);
	printf("Hau to:%s",str);
	getch();
}