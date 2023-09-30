#include<conio.h>
#include<stdio.h>
#include<string>
struct HangHoa
{
	char MaHang[11];
	char tenHang[31];
	char DVT[11];
	int sl;
};
typedef HangHoa itemtype;
struct QueueNode 
{
	itemtype Info;
	QueueNode *Next;
};
struct Queue
{
	QueueNode *Head,*Tail;
};
void initQueue(Queue &q)
{
	q.Head=q.Tail=NULL;
}
QueueNode *createQueueNode(itemtype x)
{
	QueueNode *p=new QueueNode;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int insertTail(Queue &q,QueueNode *p)
{
	if(p==NULL)
		return 0;
	if(q.Head==NULL)
		q.Head=p;
	else
		q.Tail->Next=p;
	q.Tail=p;
	return 1;
}
int deleteHead(Queue &q,itemtype &x)
{
	if(q.Head==NULL)
		return 0;
	QueueNode *p=q.Head;
	q.Head=q.Head->Next;
	if(q.Head==NULL)
		q.Tail=NULL;
	x=p->Info;
	delete p;
	return 1;
}
void docFile(Queue &q)
{
	initQueue(q);
	char c;
	int n;
	itemtype x;
	FILE *f=fopen("HH.txt","r");
	fscanf(f,"%d",&n);
	fscanf(f,"%c",&c);	
	for(int i=0;i<n;i++)
	{
		fscanf(f,"%s",&x.MaHang);
		fscanf(f,"%c",&c);	
		fgets(x.tenHang,30,f);
		x.tenHang[strlen(x.tenHang)-1]=NULL;
		fscanf(f,"%s",&x.DVT);
		fscanf(f,"%c",&c);	
		fscanf(f,"%d",&x.sl);
		fscanf(f,"%c",&c);	
		fscanf(f,"%c",&c);	
		QueueNode *p=createQueueNode(x);
		insertTail(q,p);
	}
	fclose(f);
}
void xuat(itemtype x)
{
	printf("Ma hang:%s\n",x.MaHang);
	printf("Ten hang:");
	puts(x.tenHang);
	printf("Don vi tinh:%s\nSo luong:%d\n\n",x.DVT,x.sl);
}
void showQueue(Queue q)
{	
	for(QueueNode *p=q.Head;p!=NULL;p=p->Next)
		xuat(p->Info);
}
int getHead(Queue q,itemtype &x)
{
	if(q.Head==NULL)
		return 0;
	x=q.Head->Info;
	return 1;
}
int getTail(Queue q,itemtype &x)
{
	if(q.Head==NULL)
		return 0;
	x=q.Tail->Info;
	return 1;
}
QueueNode *timTT(Queue q,itemtype x)
{
	for(QueueNode *p=q.Head;p!=NULL;p=p->Next)
		if(x.sl==p->Info.sl&&strcmp(x.DVT,p->Info.DVT)==0&&strcmp(x.MaHang,p->Info.MaHang)==0&&strcmp(x.tenHang,p->Info.tenHang)==0)
		return p;
	return NULL;
}
void nhap1MH(itemtype &x)
{
	printf("Nhap vao ma hang:");
	scanf("%s",&x.MaHang);
	printf("Nhap vao ten hang:");
	fflush(stdin);
	gets(x.tenHang);
	printf("Nhap vao don vi tinh:");
	scanf("%s",&x.DVT);
	printf("Nhap vao so luong:");
	scanf("%d",&x.sl);
}
void xuatALL(Queue &q)
{	
	while (q.Head)
	{
		itemtype x;
		deleteHead(q,x);
		printf("Xoa hang\n");
		xuat(x);	
	}
	printf("Da xuat tat ca hang trong kho\n");
}
void main()
{
	Queue q;
	docFile(q);
	showQueue(q);
	itemtype x;
	getHead(q,x);
	printf("MAT HANG CHUAN BI XUAT KHO\n");
	xuat(x);
	itemtype y;
	deleteHead(q,y);
	printf("MAT HANG DA BI XOA\n");
	xuat(y);
	itemtype z;
	printf("MAT HANG VUA MOI NHAP KHO\n");
	getTail(q,z);
	xuat(z);
	itemtype t;
	printf("Nhap vao thong tin mat hang tim\n");
	nhap1MH(t);
	if(timTT(q,t)==NULL)
		printf("Khong co mat hang nay trong kho\n");
	else
	{
		printf("CO MAT HANG TRONG KHO\n");
		xuat(t);
	}
	printf("XUAT TOAN BO HANG HOA TRONG KHO\n");
	xuatALL(q);
	getch();
}