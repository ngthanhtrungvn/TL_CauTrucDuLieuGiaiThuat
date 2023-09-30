#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>

using namespace std;
typedef int ItemType;

//tao struct SNode va SList
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

//ham ktra rong
void initSList(SList &sl)
{
	sl.Head=NULL;
	sl.Tail=NULL;
}

//bien 1 gia tri x thanh node
SNode* createSNode(ItemType x)
{
	SNode*p=new SNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}

//xuat SNode
void printfSNode(SNode* p)
{
	printf("%5d", p->Info);
}

//tao ham chen dau
int insertHead(SList &sl, SNode* p)
{
	if(p==NULL)
		return 0;
	if(sl.Head==NULL)
	{
		sl.Head=p;
		sl.Tail=p;
	}
	else
	{
		p->Next=sl.Head;
		sl.Head=p;
	}
	return 1;
}

//tao ham chen sau
int insertTail(SList &sl, SNode* p)
{
	if(p==NULL)
		return 0;
	if(sl.Head==NULL)
	{
		sl.Head=p;
		sl.Tail=p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail=p;
	}
	return 1;
}

//them q vao sau p
int insertAfter(SList &sl, SNode* p, SNode* q)
{
	if(p==NULL||q==NULL)
		return 0;
	p->Next=q->Next;
	q->Next=p;
	if(q==sl.Tail)
		sl.Tail=p;
	return 1;
}

//xoa dau
int deleteHead(SList &sl, int &x)
{
	if(sl.Head==NULL)
		return 0;
	SNode* p=sl.Head;
	sl.Head=sl.Head->Next;
	x=p->Info;
	if(sl.Head==NULL)
		sl.Tail=NULL;
	delete p;
	return 1;
}

//xoa sau
int deleteAfter(SList &sl, SNode* q, int &x)
{
	if(sl.Head==NULL)
		return 0;
	if(q==NULL||q->Next==NULL)
		return 0;
	SNode* p=q->Next;
	q->Next=p->Next;
	x=p->Info;
	if(p==sl.Tail)
		sl.Tail=q;
	delete p;
	return 1;
}
//xoa X
void xoaX(SList &sl, int x)
{
	//neu X la phan tu dau
	while(sl.Head!=NULL&&sl.Head->Info==x)
		deleteHead(sl,x);
	SNode* i=sl.Head;
	while (i->Next!=NULL)
	{
		if(i->Next->Info==x)
			deleteAfter(sl,i,x);
		else
			i=i->Next;
	}
}

//doc File
void docFile(SList &sl, char* tenFile)
{
	sl.Head=sl.Tail=NULL;
	int n;
	ifstream doc;
	doc.open(tenFile);
	doc >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		doc >> x;
		SNode* p=createSNode(x);
		insertTail(sl, p);
	}
	doc.close();
}

//xuat File
void xuatFile(SList sl)
{
	for(SNode* i=sl.Head; i!=NULL; i=i->Next)
		printfSNode(i);
	printf("\n");
}

//tao SList
void createSList(SList &sl)
{
	sl.Head=sl.Tail=NULL;
	int n;
	printf("nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		//nhap gia tri
		int x;
		printf("nhap gia tri thu %d: ", i);
		scanf("%d", &x);
		//bien gia tri thanh node
		SNode*p=createSNode(x);
		//them vao dau DSLK
		insertTail(sl, p);
	}
}

int tinhTong(SList sl)
{
	int tong=0;
	for(SNode* i=sl.Head; i!=NULL; i=i->Next)
		tong=tong+i->Info;
	return tong;
}

//tinh tong chan
int tongChan(SList sl)
{
	int tong=0;
	for(SNode* i=sl.Head; i!=NULL; i=i->Next)
	{
		if(i->Info%2==0)
			tong=tong+i->Info;
	}
	return tong;
}

//dem phan tu sau lon hon
int demPTuSauLonHon(SList &sl)
{
	int dem =0;
	for(SNode *i=sl.Head; i!=sl.Tail; i=i->Next)
	{
		SNode* q= i->Next;
		if(i->Info < q->Info)
			dem++;
	}
	return dem;
}
void main()
{
	//doc tu File data.txt
	SList haminh;
	docFile(haminh, "data.txt");
	xuatFile(haminh);

	////nhap tay
	//SList haminhh;
	//createSList(haminhh);
	//xuatFile(haminhh);
	
	//xuat xoa 1 so == x
	//int x;
	//printf("tim x can xoa:");
	//scanf("%d", &x);
	//xoaX(haminh, x);
	//xuatFile(haminh);

	////xuat tong
	//int kq=tinhTong(haminh);
	//printf("tong la: %d\n", kq);

	////xuat tong chan
	//int kq1=tongChan(haminh);
	//printf("Tong chan: %d\n", kq1);

	////xuat demPTuLonHon
	//int kq2=demPTuSauLonHon(haminh);
	//printf("co %d phan tu\n", kq2);
	getch();

}

