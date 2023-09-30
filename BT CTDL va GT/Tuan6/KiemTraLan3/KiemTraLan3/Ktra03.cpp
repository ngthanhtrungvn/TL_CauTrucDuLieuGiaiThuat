#include<stdio.h>
#include<conio.h>
#include<string>
#include<math.h>
#include<fstream>

using namespace std;
typedef int ItemType;

//khai bao StackNode
struct StackNode
{
	ItemType Info;
	StackNode* Next;
};

//khai bao list
struct Stack
{
	StackNode *Top;
};

//Ktra rong
void initStack(Stack &s)
{
	s.Top= NULL;
}

//them vao stack
int push(Stack &s, StackNode* p)
{
	if(p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}

//bien Node thanh StackNode
StackNode * createStackNode(ItemType x)
{
	StackNode *p= new StackNode;
	if(p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}

//xoa khoi Stack
int pop(Stack &s, ItemType &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode *p= s.Top;
	s.Top= s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}

//doi co so
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
	while(s.Top != NULL)
	{
		int x;
		pop(s, x);
		printf("%X \n", x);
	}
}
//void printfStackNode(StackNode *p)
//{
//	printf("%5d", p->Info);
//}
//void doc(Stack &s, char tenFile[])
//{
//	ifstream in;
//	in.open(tenFile);
//	int n;
//	in >> n;
//	StackNode *p= createStackNode(n);
//	push(s, p);
//	in.close();
//}
//
//void xuat(Stack &s)
//{
//	for(StackNode* i=s.Top; i!=NULL; i=i->Next)
//		printfStackNode(i);
//	printf("\n");
//}

//tinh giai thua
int giaiThua(int n)
{
	ItemType x;
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
	printf("------------------------------------------\n");
	printf("Bai Kiem Tra Lan 3\n");
	printf("1. Doi Co So\n");
	printf("2. Tinh giai thua\n");
	printf("------------------------------------------\n");
}

void main()
{
	Stack s;
	int thoat = 0;
	do
	{
		int chon;
		menu();
		printf("Moi ban chon chuc nang: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			{
				printf("Chuc nang 1\n");
				int n;
				int a;
				printf(" Nhap so can chuyen va he so can chuyen qua: ");
				scanf("%d%d", &n, &a);
				doiCoSo(n, a);
				printf("\n");
				break;
			}
		case 2:
			{
				printf("Chuc nang 2\n");
				int x;
				printf("Nhap x: ");
				scanf("%d", &x);
				int kq=giaiThua(x);
				printf("ket qua: %d", kq);
				printf("\n");
				break;
			}
		case 0:
			{
				printf("Thoat chuong trinh\n");
				thoat = 1;
				break;
			}
		default: printf("Thao tac loi! Thu lai\n");
			break;
		}
	}while(thoat = 1);
	getch();
}

