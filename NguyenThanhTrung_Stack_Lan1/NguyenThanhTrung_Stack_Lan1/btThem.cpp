#include<conio.h>
#include<stdio.h>
#include<string.h>
typedef int ItemType;
struct StackNode
{
	itemtype Info;
	StackNode* Next;
};
struct Stack
{
	StackNode* Top;
};
void initStack(Stack& s)
{
	s.Top = NULL;
}
StackNode* createStackNode(itemtype x)
{
	StackNode* p = new StackNode;
	if (p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}
int push(Stack& s, StackNode* p)
{
	if (p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}
int pop(Stack& s, itemtype& x)
{
	if (s.Top == NULL)
		return 0;
	StackNode* p = s.Top;
	s.Top = s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}
void initStack(Stack &s) {
	s.Top = NULL;
}
void push(Stack &s, StackNode *p) {

	//StackNode *p = createStackNode(x);
	if (s.top == NULL)
	{
		s.top = p;
	}
	else
	{
		p->next = s.top;
		s.top = p;
	}
}
//a.Tính giai thừa :
long int Stack_TinhGiaiThua(int n)
{//Tính n!
	ItemType x;
	StackNode* p;
	Stack stack;
	initStack(stack);
	while (n > 0)
	{//Thêm lần lượt nội dung vào stack
		p = createStackNode(n);
		if (push(stack, p) == 0)
			break;
		n--;
	}
	long int kq = 1;
	while (1)
	{//Lấy lần lượt nội dung từ stack
		if (pop(stack, x) == 0)
			break;
		kq *= x;
	}
	return kq;
}

// b.Đảo chuỗi :
void Stack_DaoChuoi(char* chuoi)
{
	StackNode* p;
	Stack stack;
	initStack(stack);
	int len = strlen(chuoi);
	for (int i = 0; i < len; i++)
	{
		p = CreateStackNode(chuoi[i]);
		Push(stack, p);
	}
	printf("\nChuoi dao nguoc la: ");
	while (!IsEmpty(stack))
	{
		ItemType ch;
		Pop(stack, ch);
		printf("%c", ch);
	}
}

//d.Khử đệ quy Tháp Hà Nội :
struct Item
{
	int SoDia, Nguon, Dich;
};
typedef Item ItemType;
//=================================================
ItemType SaoChepStackNode(int SoDia, int Nguon, int Dich)
{
	ItemType temp;
	temp.SoDia = SoDia;
	temp.Nguon = Nguon;
	temp.Dich = Dich;
	return temp;
}
//=================================================
void Stack_HaNoiTower(int n, int A, int B, int C)
{
	int solan = 0;
	ItemType x, y;
	StackNode* p;
	Stack S;
	InitStack(S);
	y = SaoChepStackNode(n, A, C);
	p = CreateStackNode(y);
	Push(S, p);
	while (!IsEmpty(S))
	{
		Pop(S, x); //Biến x có 3 phan: {n, Nguon, Dich}
		if (x.SoDia == 1)
			printf("\nLan %2d: Chuyen tu cot %d den cot %d", ++solan, x.Nguon, x.Dich);
		else
		{
			int temp = 6 - (x.Nguon + x.Dich);
			y = SaoChepStackNode(x.SoDia - 1, temp, x.Dich);
			p = CreateStackNode(y);
			Push(S, p);
			y = SaoChepStackNode(1, x.Nguon, x.Dich);
			p = CreateStackNode(y);
			Push(S, p);
			y = SaoChepStackNode(x.SoDia - 1, x.Nguon, temp);
			p = CreateStackNode(y);
			Push(S, p);
		}
	}
}