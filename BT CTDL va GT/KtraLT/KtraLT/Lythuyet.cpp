#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef int ItemType;

struct SNode
{
	ItemType Info;
	SNode* Next;
};

struct SList
{
	SNode* Head;
	SNode* Tail;
};

SNode* createSNode(ItemType x)
{
	SNode* p=new SNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}

int insertTail(SList &sl, SNode* p)
{
	if(p==NULL)
		return 0;
	if(sl.Head=NULL)
	{
		sl.Head=p;
		sl.Tail=p;
	}
	else
	{
		sl.Tail -> Next = p;
		sl.Tail = p;
	}
}

void createSList(SList &sl)
{
	sl.Head=sl.Tail=NULL;//bien thanh rong
	int n;
	printf("Nhap so luong phan tu DSLK: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		//nhap x
		int x;
		printf("nhap gia tri thu %d: ", i);
		scanf("%d", &x);
		//bien x thanh node 
		SNode* p=createSNode(x);
		//them cuoi
		insertTail(sl, p);
	}
}

void printfSList(SList sl)
{
	for(SNode* i=sl.Head; i!=NULL; i= i->Next)
	{
		printf("%5d", i->Info);
		printf("\n");
	}
}

int tongChan(SList sl)
{
	int t=0;
	for(SNode* i=sl.Head; i!=NULL; i= i->Next)
	{
		if(i -> Info %2 ==0)
			t= t + i -> Info;
	}
	return t;
}
void main()
{
	SList minhcute;
	createSList(minhcute);
	printfSList(minhcute);
	/*int kq=tongChan(minhcute);
	printf("Tong la: %d", kq);*/
	getch();
}