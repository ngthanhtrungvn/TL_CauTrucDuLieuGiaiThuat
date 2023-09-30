#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string>

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
	s.Top= NULL;
}

StackNode *createStackNode(ItemType x)
{
	StackNode *p=new StackNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}

int push(Stack &s, StackNode *p)
{
	if(p==NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}

int pop(Stack &s, ItemType &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode* p = s.Top;
	s.Top = s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}


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
	s.Top= NULL;
}

StackNode1* CreateStackNode1(ItemType1 x)
{
	StackNode1* p = new StackNode1;
	if(p==NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}
int push1(Stack1 &s, StackNode1* p)
{
	if(p==NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}

int pop1(Stack1 &s, ItemType1 &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode1* p = s.Top;
	s.Top = s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}

typedef char ItemType3;

struct StackNode3
{
	ItemType3 Info;
	StackNode3 *Next;
};

struct Stack3
{
	StackNode3 *Top;
};

StackNode3 *createStackNode3(ItemType3 x)
{
	StackNode3 *p= new StackNode3;
	if(p == NULL)
		return NULL;
	p->Info= x;
	p->Next= NULL;
	return p;
}

int push3(Stack3 &s, ItemType3 x)
{
	StackNode3* p= createStackNode3(x);                                     
	if(p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}

int pop3(Stack3 &s, ItemType3 &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode3* p= s.Top;
	s.Top= s.Top->Next;
	x=p->Info;
	delete p;
	return 1;
}
void initStack3(Stack3 &s)
{
	s.Top=NULL;
}


void daoChuoi(char *chuoi)
{
	Stack3 s;
	initStack3(s);
	for(int i=0; i<strlen(chuoi); i++)
		push3(s, chuoi[i]);
	printf("Chuoi dao \"%s\":", chuoi);
	while(s.Top)
	{
		char x;
		pop3(s, x);
		printf("%c", x);
	}
}

int doUuTien(char x)
{
	if(x == '(')
		return 0;
	if(x == '+'||x == '-')
		return 1;
	if(x == '*'||x == '/')
		return 2;
	return 3;
}

void chuyenSangHauTo(char *bthuc, char *chuoi)
{
	Stack s;
	initStack(s);
	int j=0;
	for(int i=0; i<strlen(bthuc); i++)
	{
		if(bthuc[i]== '(')
			push(s, createStackNode(bthuc[i]));
		else
			if(bthuc[i] >= '0' && bthuc[i] <= '9')
				chuoi[j++] = bthuc [i];

			else
				if(bthuc[i] == ')' )
				{
					while (1)
					{
						ItemType x;
						pop(s, x);
						if(x=='(' || s.Top == NULL) break;
						chuoi[j++] = x;
					}
				}
				else
				{
					while(s.Top != NULL && doUuTien(s.Top->Info) >= doUuTien(bthuc[i]))
					{
						ItemType x;
						pop(s, x);
						chuoi[j++] = x;
					}
					push(s, createStackNode(bthuc[i]));
				}
	}
	while(s.Top != NULL )
	{
		char t;
		pop(s, t);
		if(t!= '(')
			chuoi[j++] = t;
	}
}

int chuyenSangKiTuSo(char c)
{
	return (int) c-48;
}

void chuyenSangKQ(char *HauTo, Stack1 &s)
{
	initStack1(s);
	for(int i=0; i<strlen(HauTo); i++)
	{
		if(HauTo[i] >= '0' && HauTo[i] <= '9')
			push1(s, CreateStackNode1(chuyenSangKiTuSo(HauTo[i])));
		else
		{
			float x, y;
			pop1(s, x);
			pop1(s, y);
			if(HauTo[i] == '^')
			{
				float kq = pow(y, x);
				push1(s, CreateStackNode1(kq));
			}
			else if(HauTo[i] == '+')
			{
				float kq = y + x;
				push1(s, CreateStackNode1(kq));
			}
			else if(HauTo[i] == '-')
			{
				float kq = y - x;
				push1(s, CreateStackNode1(kq));
			}
			else if(HauTo[i] == '*')
			{
				float kq = y * x;
				push1(s, CreateStackNode1(kq));
			}
			else
			{
				float kq = (float)y / x;
				push1(s, CreateStackNode1(kq));
			}
		}
	}
}
void menu()
{
	printf("1. Dao Chuoi\n");
	printf("2. Tinh gia tri bieu thuc\n");
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
				printf("1. Dao chuoi\n");
				char chuoi[100];
				printf("Nhap chuoi can dao: ");
				scanf("%s", &chuoi);
				daoChuoi(chuoi);
				printf("\n");
				/*char chuoi[50]="HaMinh dang yeu qua diii";
				daoChuoi(chuoi);*/
				break;
			}
		case 2:
			{
				printf("2. Tinh gia tri bieu thuc\n");
				char bieuthuc[50],str[50]={};
				printf("Nhap vao bieu thuc:");
				scanf("%s",&bieuthuc);
				chuyenSangHauTo(bieuthuc,str);
				printf("Hau to:%s \n",str);
				Stack1 s;
				chuyenSangKQ(str, s);	
				printf("Ket qua:%.2f \n",s.Top->Info);
				break;
			}
		default: printf("Sai! Nhap lai\n");
			break;
		}
	}while(thoat == 0);
	getch();
}