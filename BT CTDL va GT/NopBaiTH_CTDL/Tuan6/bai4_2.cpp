#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string>
typedef float itemtype;
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
struct QueueNode
{
	itemtype Info;
	QueueNode *Next;
};
int chuyenKiTuSangSo(char c)
{
	return (int)c -48;
}

void tinhGiaTriBieuThuc(char *postFix,Stack &s)
{
	initStack(s);
	for(int i=0;i<strlen(postFix);i++)
	{
		if(postFix[i]>='0'&&postFix[i]<='9')
			push(s,createStackNode(chuyenKiTuSangSo(postFix[i])));
		else
		{
			float x,y;
			pop(s,x);
			pop(s,y);
			if(postFix[i]=='^')
			{
				float ketqua=pow(y,x);
				push(s,createStackNode(ketqua));
			}
			else
				if(postFix[i]=='+')
				{
					float ketqua=y+x;
					push(s,createStackNode(ketqua));
				}
			else
				if(postFix[i]=='-')
				{
					float ketqua=y-x;
					push(s,createStackNode(ketqua));
				}
				else
					if(postFix[i]=='*')
					{
						float ketqua=y*x;
						push(s,createStackNode(ketqua));
					}
					else						
						{
							float ketqua=(float)y/x;
							push(s,createStackNode(ketqua));
						}
		}
	}
}
void main()
{
	char postFix[100];
	printf("Nhap vao bieu thuc:");
	scanf("%s",&postFix);
	printf("\n");
	Stack s;
	tinhGiaTriBieuThuc(postFix,s);	
	printf("Ket qua:%.2f",s.Top->Info);
	getch();
}