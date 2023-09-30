//chac chan co ham them va xoa
//2 tim kiem
// 3 sap xep
//DSLK: 2cau 1.Ve hinh 2.Tinh tong, tich,...
//Stack: chuyen tu trung ho sang hau to hoac hau to sang kq
//        doi co so
//Cay NP: 2 cau 1.Ve hinh 2.Vietcode( 2 y)
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<fstream>

using namespace std;

typedef int itemType;
struct SNode
{
	itemType Info;
	SNode* Next;
};

struct SList
{
	SNode* Head;
	SNode* Tail;
};

SNode* createSNode(itemType x)
{
	SNode* p=new SNode;
	if(p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}

int insertTail(SList &sl, SNode* p)
{
	if(p == NULL)
		return 0;
	if(sl.Head==NULL)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}

int insertHead(SList &sl, SNode* p)
{
	if(p == NULL)
		return 0;
	if(sl.Head==NULL)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}
int insertTail2(SList &sl, itemType x)
{
	SNode* p= createSNode(x);
	return insertTail(sl, p);
}

void taoList(SList &sl, char tenFile[])
{
	sl.Head=sl.Tail=NULL;
	int n;
	ifstream in;
	in.open(tenFile);
	in >> n;

	for(int i=0; i<n; i++)
	{
		int x;
		in >> x;
		SNode* p= createSNode(x);
		insertHead(sl, p);
	}
	in.close();
}
void print(SNode* p)
{
	printf("%5d", p->Info);
}
void xuat(SList sl)
{
	for(SNode* i=sl.Head; i!=NULL; i =i->Next)
		print(i);
	printf("\n");
}

void main()
{
	SList sl;
	taoList(sl, "songuyen.txt");
	xuat(sl);
	getch();
}