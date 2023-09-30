#include<conio.h>
#include<string>
#include<stdio.h>
struct BAIHAT
{
	char tenBH[51];
	char tacGia[41];
	char caSi[41];
	int thoiLuong;
};
typedef BAIHAT itemtype;
struct SNode
{
	itemtype Info;
	SNode *Next;
};
struct SList
{
	SNode *Head;
	SNode *Tail;
};
void initSList(SList &sl)
{
	sl.Head=sl.Tail=NULL;
}
SNode *createSNode(itemtype x)
{
	SNode *p=new SNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int insertTail(SList &sl,SNode *p)
{
	if(p==NULL)
		return 0;
	if(sl.Head==NULL)
		sl.Head=sl.Tail=p;
	else
	{
		sl.Tail->Next=p;
		sl.Tail=p;
	}
	return 1;
}
void docFile(SList &sl)
{
	itemtype x;
	char c;
	initSList(sl);
	FILE *f=fopen("BH.txt","r");	
	while (!feof(f))
	{
		fgets(x.tenBH,41,f);
		x.tenBH[strlen(x.tenBH)-1]=NULL;
		
		fgets(x.tacGia,31,f);
		x.tacGia[strlen(x.tacGia)-1]=NULL;
		
		fgets(x.caSi,31,f);
		x.caSi[strlen(x.caSi)-1]=NULL;
		
		fscanf(f,"%d",&x.thoiLuong);
		fscanf(f,"%c",&c);
		fscanf(f,"%c",&c);
		SNode *p=createSNode(x);
		insertTail(sl,p);
	}
	fclose(f);
}
void xuat(itemtype x)
{
	puts(x.tenBH);
	puts(x.tacGia);
	puts(x.caSi);
	printf("%d\n\n",x.thoiLuong);
}
void xuatFile(SList sl)
{
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
		xuat(p->Info);
}
int tinhThoiLuong(SList sl)
{
	int tong=0;
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
		tong+=p->Info.thoiLuong;
	return tong;
}
int insertHead(SList &sl,SNode *p)
{
	if(p==NULL)
		return 0;
	if(sl.Head==NULL)
		sl.Head=sl.Tail=p;
	else
	{
		p->Next=sl.Head;
		sl.Head=p;
	}
	return 1;
}
void nhap(itemtype &x)
{
	printf("Nhap vao ten bai hat:");
	fflush(stdin);
	gets(x.tenBH);
	printf("Nhap vao ten tac gia:");
	fflush(stdin);
	gets(x.tacGia);
	printf("Nhap vao ten ca si:");
	fflush(stdin);
	gets(x.caSi);
	printf("Nhap vao thoi luong bai hat:");
	scanf("%d",&x.thoiLuong);
}
int deleteHead(SList &sl,itemtype &x)
{
	if(sl.Head==NULL)
		return 0;
	SNode *p=sl.Head;
	sl.Head=sl.Head->Next;
	if(sl.Head==NULL)
		sl.Tail=NULL;
	x=p->Info;
	delete p;
	return 1;
}
int deleteAfter(SList &sl,SNode *q,itemtype &x)
{
	if(q==NULL||q->Next==NULL)
		return 0;
	SNode *p=q->Next;
	q->Next=p->Next;
	if(sl.Tail==p)
		sl.Tail=q;
	x=p->Info;
	delete p;
	return 1;
}
SNode *timTenBaiHat(SList sl,char *x)
{
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
		if(strcmp(p->Info.tenBH,x)==0)
			return p;
	return NULL;
}
int deleteSNodeX(SList &sl,itemtype x)
{
	if(sl.Head==NULL)
		return 0;
	SNode *p=sl.Head;
	SNode *q=NULL;
	while(p!=NULL&&(strcmp(p->Info.tenBH,x.tenBH)!=0||strcmp(p->Info.tacGia,x.tacGia)!=0||strcmp(p->Info.caSi,x.caSi)!=0||p->Info.thoiLuong!=x.thoiLuong))
	{
		q=p;
		p=p->Next;
	}
	if(p==NULL)
		return 0;
	if(p==sl.Head)
		deleteHead(sl,x);
	else
		deleteAfter(sl,q,x);
	return 1;
}
void swap(itemtype &x,itemtype &y)
{
	itemtype t=x;x=y;y=t;
}
void interchangeSortTen(SList &sl)
{
	for(SNode *p=sl.Head;p!=sl.Tail;p=p->Next)
		for(SNode *q=p->Next;q!=NULL;q=q->Next)
			if(strcmp(p->Info.tenBH,q->Info.tenBH)>0)
				swap(p->Info,q->Info);
	xuatFile(sl);
}
void selectionSortTenCS(SList &sl)
{
	SNode *p,*q,*max;
	for(p=sl.Head;p!=sl.Tail;p=p->Next)
	{
		max=p;
		for(q=p->Next;q!=NULL;q=q->Next)
			if(strcmp(max->Info.caSi,q->Info.caSi)<0)
				max=q;
		swap(max->Info,p->Info);
	}
	xuatFile(sl);
}
SNode *findSNode(SList &sl,itemtype x)
{
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
		if(strcmp(p->Info.tenBH,x.tenBH)==0&&strcmp(p->Info.tacGia,x.tacGia)==0&&strcmp(p->Info.caSi,x.caSi)==0&&p->Info.thoiLuong==x.thoiLuong)
			return p;
	return NULL;
}
void dua1BaiLenHead(SList &sl,itemtype x)
{
	SNode *p=findSNode(sl,x);
	if(p==NULL)
	{printf("Bai nhac khong hop le");return ;}
	else
		swap(sl.Head->Info,p->Info);
	xuatFile(sl);
}
void main()
{
	
	SList sl;
	docFile(sl);
	xuatFile(sl);
	printf("Thoi gian de nghe het:%d\n",tinhThoiLuong(sl));
	printf("Nhap vao thong tin bai hat ban muon them vao dau danh sach\n");
	itemtype x;
	nhap(x);
	insertHead(sl,createSNode(x));
	xuatFile(sl);
	printf("Nhap vao thong tin bai hat ban muon them vao cuoi danh sach\n");
	itemtype y;
	nhap(y);
	insertTail(sl,createSNode(y));
	xuatFile(sl);
	itemtype t;
	printf("Nhap vao bai nhac ban muon xoa\n");
	nhap(t);
	deleteSNodeX(sl,t);
	xuatFile(sl);
	printf("Nhap vao ten bai hat ban muon kiem tra:");
	fflush(stdin);
	char ten[51];
	gets(ten);
	if(timTenBaiHat(sl,ten)==NULL)
		printf("khong co ten bai hat trong danh sach\n");
	else
	{
		printf("co ten bai hat trong danh sach\n");
		xuat(timTenBaiHat(sl,ten)->Info);
	}
	printf("Sau khi sap xep theo ten bai hat\n");
	interchangeSortTen(sl);
	printf("Sau khi sap xep theo ten ca si\n");
	selectionSortTenCS(sl);
	itemtype xyt;
	printf("Nhap vao bai nhac ban muon dua len dau danh sach\n");
	nhap(xyt);
	dua1BaiLenHead(sl,xyt);
	getch();
}
