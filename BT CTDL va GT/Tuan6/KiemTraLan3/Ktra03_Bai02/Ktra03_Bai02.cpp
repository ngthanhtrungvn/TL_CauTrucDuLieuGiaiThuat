#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;
//Stack
typedef char ItemType;

struct StackNode
{
	ItemType Info;
	StackNode* Next;
};

struct Stack
{
	StackNode* Top;
};

void initStack(Stack &s)
{
	s.Top = NULL;
}

StackNode* createStackNode(ItemType x)
{
	StackNode* p= new StackNode;
	if(p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}

int push(Stack &s, StackNode* p)
{
	if(p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}

int pop(Stack &s, ItemType &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode* p= s.Top;
	s.Top = s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}

//Stack1
typedef float ItemType1;

struct StackNode1
{
	ItemType1 Info;
	StackNode1* Next;
};

struct Stack1
{
	StackNode1* Top;
};

void initStack1(Stack1 &s)
{
	s.Top = NULL;
}

StackNode1* createStackNode1(ItemType1 x)
{
	StackNode1 *p= new StackNode1;
	if(p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}

int push1(Stack1 &s, StackNode1* p)
{
	if(p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}

int pop1(Stack1 &s, ItemType1 &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode1* p= s.Top;
	s.Top = s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}
//xet dau
int xetDau(char *chuoi)
{
	Stack s;
	initStack(s);
	for(int i=0; i<strlen(chuoi); i++)
	{
		char c = chuoi[i];
		if( c== '(' || c == '{' || c == '[')
			push(s, createStackNode(c));
		else
		{
			if(s.Top == NULL)
				return 0;
			char x;
			pop(s, x);
			if(!(x == '(' && c == ')'||x == '[' && c == ']'||x == '{' && c == '}'))
				return 1;
		}
	}
	if(s.Top != NULL)
		return 0;
	return 1;
}

//xet do uu tien ve dau
int doUuTien(char x)
{
	if(x == '(' )
		return 0;
	if(x == '+' || x == '-' )
		return 1;
	if(x == '*' || x == '/' )
		return 2;
	return 3;
}

//chuyen tu tien to sang hau to
void chuyenSangHauTo(char *bthuc, char *chuoi)
{
	Stack s;
	initStack(s);
	int j=0;
	for(int i=0; i<strlen(bthuc); i++)
	{
		if(bthuc[i] == '(' )
			push(s, createStackNode(bthuc[i]));
		else
			if(bthuc[i] >='0' && bthuc[i] <= '9')
				chuoi[j++] = bthuc[i];
			else if(bthuc[i] == ')' )
			{
				while (1)
				{
					ItemType x;
					pop(s, x);
					if(x == '(' || s.Top == NULL)
						break;
					chuoi[j++] = x;
				}
			}
			else
			{
				while(s.Top!= NULL&& doUuTien(s.Top->Info) >= doUuTien(bthuc[i]))
				{
					ItemType x;
					pop(s, x);
					chuoi[j++] =x;

				}
				push(s, createStackNode(bthuc[i]));
			}
	}
	while(s.Top != NULL)
			{
				char t;
				pop(s, t);
				if(t!= '(' )
					chuoi[j++] = t;
			}
}

int chuyensangKiTuSo(char x)
{
	return (int)x-48;
}
void tinhGTBT(char *postFix, Stack1 &s)
{
	initStack1(s);
	for(int i=0; i<strlen(postFix); i++)
	{
		if(postFix[i] >= '0' && postFix[i] <= '9')
			push1(s, createStackNode1(chuyensangKiTuSo(postFix[i])));
		else
		{
			float x, y;
			pop1(s, x);
			pop1(s, y);
			if(postFix[i] == '^')
			{
				float kq = pow(y, x);
				push1(s, createStackNode1(kq));
			}
			else if (postFix[i] == '+')
			{
				float kq = y + x;
				push1(s, createStackNode1(kq));
			}
			else if(postFix[i] == '-')
			{
				float kq = y - x;
				push1(s, createStackNode1(kq));
			}
			else if(postFix[i] == '*')
			{
				float kq = y * x;
				push1(s, createStackNode1(kq));
			}
			else
			{
				float kq = y / x;
				push1(s, createStackNode1(kq));
			}
		}
	}
}

//dao chuoi
void daoChuoi(char *chuoi)
{
	Stack s;
	initStack(s);
	for(int i=0; i<strlen(chuoi);i++)
		push(s, createStackNode(chuoi[i]));
	printf("Chuoi dao \"%s\": ", chuoi);
	while(s.Top)
	{
		char x;
		pop(s, x);
		printf("%c", x);
	}
}
void menu()
{
	printf("----------------------------------------\n");
	printf("1. Xet dau\n");
	printf("2 Chuyen bthuc thanh hau to\n");
	printf("3. Tinh gia tri bieu thuc\n");
	printf("4. Dao chuoi\n");
	printf("----------------------------------------\n");
}

void main()
{
	Stack s;
	int thoat = 0;
	do{
		int chon;
		menu();
		printf("Moi ban chon so: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			{
				printf("Bai tap 1\n");
				char str[50];
				printf("Moi ban nhap chuoi: ");
				scanf("%s", &str);
				int kq= xetDau(str);
				if(kq == 1)
					printf("Chuoi hop le\n");
				else
					printf("Sai chuoi roi!\n");
				break;
			}
		case 2:
			{
				printf("Bai tap 2\n");
				char bieuthuc[50],str[50]={};
				printf("Nhap vao bieu thuc:");
				scanf("%s",&bieuthuc);
				chuyenSangHauTo(bieuthuc,str);
				printf("Hau to:%s \n",str);
				break;
			}
			case 3:
			{
				printf("Bai tap 3\n");
				char bieuthuc[50],str[50]={};
				printf("Nhap vao bieu thuc:");
				scanf("%s",&bieuthuc);
				chuyenSangHauTo(bieuthuc,str);
				printf("Hau to:%s \n",str);
				Stack1 s;
				tinhGTBT(str, s);	
				printf("Ket qua:%.2f \n",s.Top->Info);
				break;
			}
			case 4:
			{
				printf("Bai tap 4\n");
				char chuoi[50]= "HaMinh de tu VinhDC\n";
				daoChuoi(chuoi);
				printf("\n");
				break;
			}

			case 0:
				{
					printf("Thoat chuong trinh \n");
					thoat = 1;
					break;
				}
		default: printf("Sai du lieu! Nhap lai\n");
			break;
		}
	}while(thoat == 0);
	getch();
}