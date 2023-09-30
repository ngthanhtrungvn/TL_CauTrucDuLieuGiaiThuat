#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;
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
	SNode* p= new SNode;
	if(p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}

//ktra rong
void initSList(SList &sl)
{
	sl.Head= NULL;
	sl.Tail= NULL;
}

//xuatSNodes
void xuatSNode(SNode* p)
{
	printf("%5d", p->Info);
}

//chen dau DSLK
int insertHead(SList &sl, SNode* p)
{
	if(p == NULL)
		return NULL;
	if(sl.Head==NULL)
	{
		sl.Head= p;
		sl.Tail =p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}

//chen sau DSLK
int insertTail(SList &sl, SNode* p)
{
	if(p == NULL)
		return NULL;
	if(sl.Head == NULL)
	{
		sl.Head= p;
		sl.Tail= p;
	}
	else
	{
		sl.Tail->Next= p;
		sl.Tail= p;
	}
	return 1;
}

// them q vao sau p
int insertAfter(SList &sl, SNode*p, SNode* q)
{
	if( p==NULL||q==NULL)
		return 0;
	p->Next = q->Next;
	q->Next= p;
	if(q==sl.Tail)
		sl.Tail=p;
	return 1;
}

int insertAfterX(SList &sl, SNode* q, ItemType x)
{
	if(q==NULL)
		return 0;
	SNode* p= createSNode(x);
	if(p==NULL)
		return 0;
	p->Next = q->Next;
	q->Next = p;
	if(q == sl.Tail)
		sl.Tail= p;
	return 1;
}


//xoa dau
int deleteHead(SList &sl/*, int &x*/)
{
	if(sl.Head== NULL)
		return 0;
	SNode* p=sl.Head;
	sl.Head=sl.Head->Next;
	/*x= p->Info;*/
	if(sl.Head==NULL)
		sl.Tail=NULL;
	delete p;
	return 1;
}

int deleteHeadX(SList &sl, int &x)
{
	if(sl.Head== NULL)
		return 0;
	SNode* p=sl.Head;
	sl.Head=sl.Head->Next;
	x= p->Info;
	if(sl.Head==NULL)
		sl.Tail=NULL;
	delete p;
	return 1;
}
//xoa sau
int deleteAfter(SList &sl, SNode* q /*, int &x*/)
{
	/*if(sl.Head==NULL)
		return 0;
	if(q==NULL||q->Next==NULL)
		return 0;
	SNode* p= q->Next;
	q->Next= p->Next;
	x= p->Info;
	if(p=sl.Tail)
		sl.Tail= q;
	delete p;
	return 1;*/
	if(sl.Head==NULL)
		return 0;
	if(q == NULL || q->Next == NULL)
		return 0;
	SNode* p = q->Next;
	q->Next = p->Next;
	if(p == sl.Tail)
		sl.Tail = q;
	delete p;
	return 1;
}

int deleteAfterX(SList &sl, SNode* q , int &x)
{
	if(sl.Head==NULL)
			return 0;
		if(q==NULL||q->Next==NULL)
			return 0;
		SNode* p= q->Next;
		q->Next= p->Next;
		x= p->Info;
		if(p=sl.Tail)
			sl.Tail= q;
		delete p;
		return 1;
}

//xoa X
void xoaX(SList &sl, int x)
{
	//neu x la phan tu dau
	while(sl.Head!=NULL && sl.Head->Info== x)
		deleteHeadX(sl, x);
	SNode* i=sl.Head;
	while(i->Next!=NULL)
	{
		if(i->Next->Info == x)
			deleteAfterX(sl, i, x);
		else
			i=i->Next;
	}
}

//doc file
void docFile(SList &sl, char* tenFile)
{
	sl.Head= sl.Tail= NULL;
	ifstream doc;
	doc.open(tenFile);
	int n;
	doc >> n;
	for(int i=0; i<n; i++)
	{
		int x;
		doc >> x;
		SNode* p=createSNode(x);
		insertHead(sl, p);
	}
}


//xuat file
void xuatFile(SList sl)
{
	for(SNode* i=sl.Head; i!=NULL; i=i->Next)
		xuatSNode(i);
	printf("\n");
}

//tinh tong Chan
int tongChan(SList &sl)
{
	int tong=0;
	for(SNode* i=sl.Head; i!=NULL; i=i->Next)
		if(i->Info%2== 0)
			tong= tong+ i->Info;
	return tong;
}

//ktra SNT
int kTraSNT(int n)
{
	if(n <=1)
		return 0;
	for(int i=2; i<sqrt(n); i++)
		if(n%i ==0)
			return 0;
	return 1;
}

//dem SNT
int demSNT(SList sl)
{
	int dem= 0;
	for(SNode *i=sl.Head; i!=NULL; i=i->Next)
		if(kTraSNT(i->Info)==1)
			dem++;
	return dem;
}

//kTra toan so duong
int ktraToanDuong(SList sl)
{
	for(SNode* i=sl.Head; i!=NULL; i=i->Next)
		if(i->Info<=0)
			return 0;
	return 1;
}

//xoa so lon hon 10
void xoaLonHon10(SList sl)
{
	// xoa cac so lon hon 10 o dau dslk
	while(sl.Head!= NULL && sl.Head->Info > 10)
		deleteHead(sl);

	if(sl.Head == NULL)
		return;

	//xoa cac so lon hon 10 ben trong (khong phai o dau)
	SNode* i=sl.Head;
	while(i->Next!= NULL)
		if(i->Next->Info> 10)
			deleteAfter(sl, i);
		else
			i= i->Next;
}

//them vao sau so chia het cho 3 co gia tri la X
void themXvaoSauSoChiaHetCho3(SList &sl, ItemType x)
{
	if(sl.Head==NULL)
		return;
	SNode* i=sl.Head;
	while(i!=NULL)
	{
	if(i->Info%3 == 0)
		{
			insertAfterX(sl, i, x);
			i= i->Next;
		}
	i= i->Next;
	}
}

void main()
{
	SList lst;
	docFile(lst, "data1.txt");
	xuatFile(lst);

	xoaLonHon10(lst);
	printf("sau khi xoa: ");
	xuatFile(lst);

	int kq= demSNT(lst);
	printf("SNT trong DS: %d so\n", kq);

	int kq1= tongChan(lst);
	printf("tong cac so chan: %d\n", kq1);

	int x;
	printf("Nhap vao x ban muon them vao: ");
	scanf("%d", &x);
	themXvaoSauSoChiaHetCho3(lst, x);
	xuatFile(lst);

	int y;
	printf("nhap so can xoa: ");
	scanf("%d", &y);
	SNode* p=createSNode(y);
	deleteAfter(lst, p);
	xuatFile(lst);


	getch();
}
	





















