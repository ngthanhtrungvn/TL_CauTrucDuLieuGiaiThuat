#include<conio.h>
#include<stdio.h>
#include<string>
struct StackNode
{
	char Info;
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
StackNode* createStackNode(char x)
{
	StackNode *p=new StackNode;	
	if(!p)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int push(Stack &s,StackNode *p)
{
	if(!p)
		return 0;
	if(s.Top==NULL)
		s.Top=p;
	else
	{
		p->Next=s.Top;
		s.Top=p;
	}return 1;
}
int pop(Stack &s,char &x)
{
	if(s.Top==NULL)
		return 0;
	StackNode *p=s.Top;
	s.Top=s.Top->Next;
	x=p->Info;
	delete p;
	return 1;
}
int ktra(char *chuoi)
{
	Stack s;
	initStack(s);
	for(int i=0;i<strlen(chuoi);i++)
	{
		char c=chuoi[i];
		
		if(c=='('||c=='{'||c=='[')		
			push(s,createStackNode(c));
		else
		{
			if(s.Top==NULL)
				return 0;
			char x;
			pop(s,x);
			if(!(x == '(' && c == ')'|| x =='[' && c== ']'||x =='{' && c == '}'))
				return 0;
		}
	}
	if(s.Top!=NULL) 
		return 0;
	return 1;
}
void main()
{
	char chuoi[50];
	printf("Nhap vao chuoi:");
	scanf("%s",&chuoi);
	if(ktra(chuoi)==0)
		printf("Chuoi khong hop le");
	else
		printf("Chuoi hop le");
	getch();
}