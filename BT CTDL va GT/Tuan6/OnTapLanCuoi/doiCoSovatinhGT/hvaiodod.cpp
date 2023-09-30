#include<stdio.h>
#include<conio.h>

typedef int Itemtype;

struct StackNode
{
	Itemtype info;
	StackNode *next;
};

struct Stack
{
	StackNode *top;
};

StackNode * createStackNode(Itemtype x)
{
	StackNode *p= new StackNode;
	if(p==NULL)
		return NULL;
	p->info=x;
	p->next=NULL;
	return p;
}

void initStack(Stack &s)
{
	s.top=NULL;
}

int push(Stack &s, StackNode *p)
{
	if(p==NULL)
		return 0;
	p->next=s.top;
	s.top=p;
	return 1;
}

//int push3(Stack3 &s, ItemType3 x)
//{
//	StackNode3* p= createStackNode3(x);                                     
//	if(p == NULL)
//		return 0;
//	p->Next = s.Top;
//	s.Top = p;
//	return 1;
//}
int pop(Stack &s, Itemtype &x)
{
	if(s.top == NULL)
		return 0;
	StackNode *p= s.top;
	s.top= s.top->next;
	x=p->info;
	delete p;
	return 1;
}


void doiCoSo(int n, int a)
{
	Stack s;
	initStack(s);
	int cn = n;
	while(n>0)
	{
		push(s, createStackNode(n%a));
		n/=a;
	}

	int x;
	printf("Ket qua %d= ", cn);
	while(s.top != NULL)
	{
		int x;
		pop(s, x);
		printf("%X ", x);
	}
}


int tinhGT(int n)
{
	Itemtype x;
	Stack s;
	initStack(s);
	while(n>0)
	{
		StackNode* p= createStackNode(n);
		if(push(s, p) == 0)
			break;
		n--;
	}
	int gThua = 1;
	while(1)
	{
		if(pop(s, x) == 0)
			break;
		gThua = gThua * x;
	}
	return gThua;
}

void menu()
{
	printf("1. Doi Co So\n");
	printf("2. Tinh Giai Thua\n");
}


void main()
{
	Stack s;
	int thoat = 0;
	do{
		int chon;
		menu();
		printf("Moi ban chon 2 bai tren: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			{
				printf("1. Doi Co So a\n");
				int a, n;
				scanf("%d%d", &n,&a);
				doiCoSo(n, a);
				printf("\n");
				break;
			}
		case 2:
			{
				int x;
				printf("Nhap x: ");
				scanf("%d", &x);
				int kq=tinhGT(x);
				printf("ket qua: %d ", kq);
				printf("\n");
				break;
			}
		case 0:
			{
				printf("Thoat chuong trinh \n");
				thoat = 1;
				break;
			}
		default: printf("Sai! Nhap lai\n");
			break;
		}
	}while(thoat == 0);
	getch();
}