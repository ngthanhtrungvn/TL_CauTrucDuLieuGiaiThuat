//#include<stdio.h>
//#include<conio.h>
//#include<stdio.h>
//#include<string>
//typedef char ItemType;
//
//struct StackNode
//{
//	ItemType Info;
//	StackNode *Next;
//};
//
//struct Stack
//{
//	StackNode *Top;
//};
//
//StackNode *createStackNode(ItemType x)
//{
//	StackNode *p= new StackNode;
//	if(p == NULL)
//		return NULL;
//	p->Info= x;
//	p->Next= NULL;
//	return p;
//}
//
//int push(Stack &s, ItemType x)
//{
//	StackNode* p= createStackNode(x);                                     
//	if(p == NULL)
//		return 0;
//	p->Next= s.Top;
//	s.Top= p;
//	return 1;
//}
//
//int pop(Stack &s, ItemType &x)
//{
//	if(s.Top == NULL)
//		return 0;
//	StackNode* p= s.Top;
//	s.Top= s.Top->Next;
//	x=p->Info;
//	delete p;
//	return 1;
//}
//
//int isEmpty(Stack s)
//{
//	if(s.Top == NULL)
//		return 1;
//	return 0;
//}
//void initStack(Stack &s)
//{
//	s.Top=NULL;
//}
//void daoChuoi(char *str)
//{
//	Stack s;
//	initStack(s);
//	for(int i=0;i<strlen(str);i++)
//		push(s,str[i]);
//	printf("Chuoi dao \"%s\":",str);
//	while(s.Top)
//	{
//		char x;
//		pop(s,x);
//		printf("%c",x);
//	}
//}
//void main()
//{
//	char str[50]="HaMinh dangyeu qua diii";
//	daoChuoi(str);
//	getch();
//}


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

//stack
typedef float itemtype1;
struct StackNode1
{
	itemtype1 Info;
	StackNode1 *Next;
};
struct Stack1
{
	StackNode1 *Top;
};
void initStack1(Stack1 &s)
{
	s.Top=NULL;
}
StackNode1 *createStackNode1(itemtype1 x)
{
	StackNode1 *p=new StackNode1;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int push(Stack &s,StackNode *p)
{
	if(p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}
int push1(Stack1 &s,StackNode1 *p)
{
	if(p == NULL)
		return 0;
	p->Next = s.Top;
	s.Top = p;
	return 1;
}
int pop(Stack &s,itemtype &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode *p=s.Top;
	s.Top = s.Top -> Next;
	x = p -> Info;
	delete p;
	return 1;
}
int pop1(Stack1 &s,float &x)
{
	if(s.Top == NULL)
		return 0;
	StackNode1 *p = s.Top;
	s.Top = s.Top -> Next;
	x = p-> Info;
	delete p;
	return 1;
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
			if(bieuThuc[i] >= '0' && bieuThuc[i] <= '9')
				str[j++] = bieuThuc[i];
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
				while(s.Top!=NULL && doUuTien(s.Top->Info)>=doUuTien(bieuThuc[i]))
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
int chuyenKiTuSangSo(char c)
{
	return (int)c-48;
}


void tinhGiaTriBieuThuc(char *postFix,Stack1 &s)
{
	initStack1(s);
	for(int i=0;i<strlen(postFix);i++)
	{
		if(postFix[i]>='0'&&postFix[i]<='9')
			push1(s,createStackNode1(chuyenKiTuSangSo(postFix[i])));
		else
		{
			float x,y;
			pop1(s,x);
			pop1(s,y);
			if(postFix[i]=='^')
			{
				float ketqua=pow(y,x);
				push1(s,createStackNode1(ketqua));
			}
			else
				if(postFix[i]=='+')
				{
					float ketqua=y+x;
					push1(s,createStackNode1(ketqua));
				}
			else
				if(postFix[i]=='-')
				{
					float ketqua=y-x;
					push1(s,createStackNode1(ketqua));
				}
				else
					if(postFix[i]=='*')
					{
						float ketqua=y*x;
						push1(s,createStackNode1(ketqua));
					}
					else						
						{
							float ketqua=(float)y/x;
							push1(s,createStackNode1(ketqua));
						}
		}
	}
}

void main()
{
	char bieuthuc[50],str[50]={};
	printf("Nhap vao bieu thuc:");
	scanf("%s",&bieuthuc);
	bienThanhPostfix1(bieuthuc,str);
	printf("Hau to:%s",str);
	Stack1 s;
	tinhGiaTriBieuThuc(str, s);	
	printf("Ket qua:%.2f",s.Top->Info);
	getch();
} 

//void doiCoSo(int n,int a)
//{
//	Stack s;
//	initStack(s);
//	int cn=n;
//	while(n>0)
//	{
//		push(s,createStackNode(n%a));
//		n/=a;
//	}
//	int x;
//	printf("ket qua %d= ",cn);		
//	while (s.Top!=NULL)
//	{
//		int x;
//		pop(s,x);
//		printf("%X ",x);
//	}
//}
//void main()
//{
//	int n;
//	int a;
//	printf("Nhap vao so can chuyen va he so chuyen qua:");
//	scanf("%d%d",&n,&a);
//	doiCoSo(n,a);
//	getch();
//}