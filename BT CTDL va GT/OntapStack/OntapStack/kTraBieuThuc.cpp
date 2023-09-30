#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>

typedef char ItemType;
using namespace std;

struct StackNode
{
	char Info;
	StackNode* Next;
};

struct Stack
{
	StackNode* Top;
};

//bien gia tri thanh StackNode
StackNode* createStackNode(char x)
{
	StackNode* p= new StackNode;
	if(p == NULL)
		return NULL;
	p->Info= x;
	p->Next= NULL;
	return p;
}

void initStack(Stack &s)
{
	s.Top = NULL;
}
//them vao stack
int push(Stack &s,StackNode *p)
{
	/*StackNode *p= createStackNode(s);*/
	if(p==NULL)
		return 0;
	p->Next= s.Top;
	s.Top= p;
	return 1;
}

//int push(Stack &s,StackNode *p)
//{
//	if(!p)
//		return 0;
//	if(s.Top==NULL)
//		s.Top=p;
//	else
//	{
//		p->Next=s.Top;
//		s.Top=p;
//	}
//	return 1;
//}
//xoa khoi stack
int pop(Stack &s, char &x)
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

//kiem tra dau ngoac
//int kTraNgoac(char *bthuc)
//{
//	Stack s;
//	s.Top= NULL;
//	for(int i = 0; i < strlen(bthuc); i++)
//	{
//		char c = bthuc[i];
//		if(c == '(' || c == '[' || c == '{')
//			push(s, c);
//		if(c == ')' || c == ']' || c == '}')
//		{
//			if(isEmpty(s))
//				return 0;
//			char cc;
//			pop(s, cc);
//			if((cc != '(' && c == ')') || (cc != '[' && cc == ']') || (cc != '{' && cc == '}') )
//				return 0;
//		}
//	}
//	if(isEmpty(s) == 1 )
//		return 1;
//	return 0;
//}
//
//void main()
//{
//	char bthuc[100];
//	printf("nhap bieu thuc can kiem tra: "); 
//	flushall();
//	gets(bthuc);
//	int kq= kTraNgoac(bthuc);
//	if(kq == 1 )
//	{
//		printf("Ket qua: %d\n", kq);
//	}
//	else
//	{
//		printf("Sai roi! Lam lai\n");
//	}
//	getch();
//}

int ktra(char *chuoi)
{
	Stack s;
	initStack(s);
	for(int i=0; i<strlen(chuoi); i++)
	{
		char c=chuoi[i];
		
		if(c=='('||c=='{'||c=='[')		
			push(s, createStackNode(c	));
		else
		{
			if(s.Top==NULL)
				return 0;
			char x;
			pop(s,x);
			if(!(x == '(' && c == ')'|| x =='[' && c== ']'||x =='{' && c == '}'))
				return 1;
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
	if(ktra(chuoi)==1)
		printf("Chuoi hop le");
	else
		printf("Chuoi khong hop le");
	getch();
}

