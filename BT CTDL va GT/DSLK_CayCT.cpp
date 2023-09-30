#include<conio.h>
#include<stdio.h>
#include<string>
#include<math.h>
struct MONHOC
{
	char maMH[11];
	char tenMH[51];
	int soTC;
	float DTL;
	float DCK;
	float diemMH;
};
typedef MONHOC itemtype1;
struct SNode1 
{
	itemtype1 Info;
	SNode1 *Next;
};
struct SList1
{
	SNode1 *Head;
	SNode1 *Tail;
};
struct SinhVien
{
	char maSV[11];
	char hoDem[26];
	char ten[9];
	int namSinh;
	SList1 mh;
	float diemKQ;
};
typedef SinhVien itemtype;
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
int isEmpty(SList sl)
{
	if(sl.Head==NULL)
		return 1;
	else
		return 0;
}
SNode *createSnode(itemtype x)
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
void initSList1(SList1 &sl)
{
	sl.Head=sl.Tail=NULL;
}
SNode1 *createSnode1(itemtype1 x)
{
	SNode1 *p=new SNode1;
	if(p==NULL)
		return NULL;
	p->Info=x;
	p->Next=NULL;
	return p;
}
int insertTail1(SList1 &sl,SNode1 *p)
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
void nhapMH(MONHOC &mh)
{
	printf("\t\tNhap vao ma mon hoc:");
	scanf("%s",&mh.maMH);
	printf("\t\tNhap vao ten mon hoc:");
	fflush(stdin);
	gets(mh.tenMH);
	printf("\t\tNhap vao so tin chi:");
	scanf("%d",&mh.soTC);
	printf("\t\tNhap vao diem tieu luan:");
	scanf("%f",&mh.DTL);
	printf("\t\tNhap vao diem cuoi ki:");
	scanf("%f",&mh.DCK);
}
void nhapDSMonHoc(SList1 &sl)
{
	initSList1(sl);
	itemtype1 x;
	int n;
	printf("Nhap vao so luong mon hoc:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\tNhap vao mon hoc thu %d\n",i+1);		
		nhapMH(x);
		SNode1 *p=createSnode1(x);
		insertTail1(sl,p);
	}
}
void xuatMH(itemtype1 mh)
{
	printf("\tMa mon hoc:%s\n",mh.maMH);
	printf("\t");
	printf("Ten mon hoc:");
	puts(mh.tenMH);
	printf("\tSo tin chi:%d\n\tDiem tieu luan:%.2f\n\tDiem cuoi ki:%.2f\n",mh.soTC,mh.DTL,mh.DCK);
}
void tinhDiemMH(SList1 &sl)
{
	for(SNode1 *p=sl.Head;p!=NULL;p=p->Next)
		p->Info.diemMH=p->Info.DTL*0.3+p->Info.DCK*0.7;
}
void xuatDSMH(SList1 sl)
{
	tinhDiemMH(sl);
	int i=1;
	for(SNode1 *p=sl.Head;p!=NULL;p=p->Next)
	{
		printf("Mon hoc thu %d\n",i);xuatMH(p->Info);
	printf("\tDiem mon hoc:%.2f\n",p->Info.diemMH);
	i++;}
}
void nhapTT1SV(itemtype &sv)
{
	printf("nhap vao ma so sinh vien:");
	scanf("%s",&sv.maSV);
	printf("Nhap vao ho dem:");
	flushall();
	gets(sv.hoDem);
	printf("Nhap vao ten sinh vien:");
	scanf("%s",&sv.ten);
	printf("Nhap vao nam sinh:");
	scanf("%d",&sv.namSinh);
}
float tinhdiemKQ(itemtype &sv)
{	
	float diem=0;
	int dem=0;
	for(SNode1 *p=sv.mh.Head;p!=NULL;p=p->Next)
	{diem+=p->Info.diemMH*p->Info.soTC;dem+=p->Info.soTC;}
	sv.diemKQ=diem/(float)dem;	
	return sv.diemKQ;
}
void nhapDSSV(SList &sl)
{
	initSList(sl);
	int n;
	itemtype x;
	printf("Nhap vao so luong sinh vien:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao thong tin sinh vien thu %d\n",i+1);
		nhapTT1SV(x);
		nhapDSMonHoc(x.mh);		
		SNode *p=createSnode(x);
		insertTail(sl,p);
	}
}
void xuatSV(itemtype sv)
{	
	printf("Ma sinh vien:%s\n",sv.maSV);
	printf("Ho dem:");
	puts(sv.hoDem);
	printf("Ten sinh vien:%s\nNam sinh:%d\n",sv.ten,sv.namSinh);
	xuatDSMH(sv.mh);
	printf("Diem ket qua hoc tap:%.2f\n\n",tinhdiemKQ(sv));
}
void xuatDSSV(SList &sl)
{
	int i=1;
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
	{						
		printf("THONG TIN SINH VIEN THU %d\n",i);
		i++;
		xuatSV(p->Info);		
	}
}
//cho biết họ tên và điểm kết quả học tập của sinh viên co mã só là x
void timMaSV(SList sl,char*ma)
{
	int i=0;
	for(SNode*p=sl.Head;p!=NULL;p=p->Next)
		if(strcmp(p->Info.maSV,ma)==0)
		{
			int i=1;
			printf("\nNhap ho:");
			puts(p->Info.hoDem);
			printf("\nTen :%s",p->Info.ten);
			printf("\nDiem ket qua:%.2f",p->Info.diemKQ);
			return;
		}
		if(i==0)
			printf("Ma sinh vien ko hop le:");

}
//cho biết các thông tin về sinh viên có tên là x
void timTenSV(SList sl,char*ten)
{
	int i=0;
	for(SNode*p=sl.Head;p!=NULL;p=p->Next)
		if(strcmp(p->Info.ten,ten)==0)
		{
			int i=1;
			xuatSV(p->Info);
			printf("\nDiem ket qua:%.2f",p->Info.diemKQ);
			return;
		}
		if(i==0)
			printf("Ma sinh vien ko hop le:");

}
//sắp xếp DSSV theo chiều tằng dần theo MáSV
void swap(itemtype &a,itemtype &b)
{
	itemtype t=a;a=b;b=t;
}
void interchngeSort_Tang_Ma(SList sl)
{
	for(SNode*p=sl.Head;p!=NULL;p=p->Next)
		for(SNode*k=p->Next;k!=NULL;k=k->Next)
			if(strcmp(p->Info.maSV,k->Info.maSV)>0)
				swap(p->Info,k->Info);
	printf("Sau khi sap xep tang dan theo ma so sinh vien:\n");
	xuatDSSV(sl);
}
//Sắp xếp DSSV theo chiều tăng dần của tên sinh viên
void interchngeSort_Tang_Ten(SList sl)
{
	for(SNode*p=sl.Head;p!=NULL;p=p->Next)
		for(SNode*k=p->Next;k!=NULL;k=k->Next)
			if(strcmp(p->Info.ten,k->Info.ten)>0)
				swap(p->Info,k->Info);
	printf("Sau khi sap xep tang dan theo ten so sinh vien:\n");
	xuatDSSV(sl);
}
// thêm một sinh viên sao cho vẫn giữ nguyên thứ tự tăng dần của mã sinh viên(có kiểm tra trùng khóa)
int insertHead(SList &sl,SNode*p)
{
	if(p==NULL)
		return 0;
	if(isEmpty(sl)==1)
	{
		sl.Head=sl.Tail=p;
	}
	else
	{
		p->Next=sl.Head;
		sl.Head=p;
	}
	return 1;
	
}
int insertAfter(SList &sl,SNode*q,SNode*p)
{
	if(p==NULL||q==NULL)
		return 0;
	p->Next=q->Next;
	q->Next=p;
	if(sl.Tail==q)
		sl.Tail=p;
	return 1;
}
int insertBefore(SList &sl,SNode*q,SNode*p)
{
	if(p==NULL||q==NULL)
		return 0;
	if(q==sl.Head)
		insertHead(sl,p);
	else
	{
		SNode*k=sl.Head;
		while(k->Next!=q)

			k=k->Next;
		insertAfter(sl,k,p);
	}
}
int insert_Giu_ThuTu(SList &sl)
{
	itemtype x;
	int i;
	do
	{
		i=1;
		printf("nhap thong itn sinh vien can them:");
		nhapTT1SV(x);
		nhapDSMonHoc(x.mh);
		for(SNode*p=sl.Head;p!=NULL;p=p->Next)
			if(strcmp(x.maSV,p->Info.maSV)==0)
			{
				i=0;
				break;
			}
			if(i=0)
				printf("Nhap lai->trung ma r kia");

	}while(i==0);
	SNode*p=createSnode(x);
	if(p==NULL)
		return 0;
	if(sl.Head==NULL)
		sl.Head=sl.Tail=p;
	else
	{
		SNode*q=sl.Head;
		SNode*a=NULL;
		while(strcmp(x.maSV,q->Info.maSV)>0&&q!=sl.Tail)
		{
			a=q;q=q->Next;
		}
		if(strcmp(x.maSV,q->Info.maSV)>0)
			insertTail(sl,p);
		else
			insertBefore(sl,q,p);
	}
	return 1;

}
//xóa sinh viên có MáSV=x;
SNode*findSnode(SList &sl,char*ma)
{
	for(SNode*p=sl.Head;p!=NULL;p=p->Next)
		if(strcmp(ma,p->Info.maSV)==0)
			return p;
	return NULL;
}
int deleteHead(SList &sl,itemtype &x)
{
	if(sl.Head==NULL)
		return 0;
	SNode*p=sl.Head;
	sl.Head=sl.Head->Next;
	if(sl.Head==NULL)
		sl.Tail=NULL;
	x=p->Info;
	delete p;
	return 1;
}
int deleteAfter(SList &sl, SNode*q, itemtype &x)
{
	if(q==NULL||q->Next==NULL)
		return 0;
	SNode*p = q->Next;
	q->Next = p->Next;
	x=p->Info;
	if(sl.Tail==p)
		sl.Tail=q;
	delete p;
	return 1;
}
int deleteSnodeX(SList &sl,char *x)
{
	itemtype y;
	SNode *q=NULL;
	SNode *p=sl.Head;
	while (p!=NULL &&strcmp(p->Info.maSV,x)!=0)
	{
		q=p;
		p=p->Next;
	}
	if(p==NULL)
		return 0;
	if(p==sl.Head)
		deleteHead(sl,y);
	else
		deleteAfter(sl,q,y);
	return 1;
}
int deleteSnodeX1(SList &sl,char *x)
{
	itemtype y;
	SNode *q=NULL;
	SNode *p=sl.Head;
	while (p!=NULL &&strcmp(p->Info.ten,x)!=0)
	{
		q=p;
		p=p->Next;
	}
	if(p==NULL)
		return 0;
	if(p==sl.Head)
		deleteHead(sl,y);
	else
		deleteAfter(sl,q,y);
	return 1;
}
//xóa tất cả các sinh viên có tên là x;
void xoaALLTenX(SList &sl,char *x)
{
	
	SNode *p=sl.Head;
	SNode *g=new SNode;
	while(p!=NULL)
	{
		g->Next=p->Next;
		if(strcmpi(p->Info.ten,x)==0)
			deleteSnodeX1(sl,p->Info.ten);
		p=g;
		p=p->Next;
	}
}
//tạo danh sách mới từ danh sách đã cho sao cho danh sách mới giảm dần theo điểm kết quả học tập
int insertKQHT(SList &sl,itemtype x)
{
	SNode *p=createSnode(x);
	if(p==NULL)
	return 0;
	if(sl.Head==NULL)
		sl.Head=sl.Tail=p;
	else
	{	
		SNode *q=sl.Head;
		while(x.diemKQ<q->Info.diemKQ && q!=sl.Tail)
			q=q->Next;
		if(q->Info.diemKQ>x.diemKQ)
			insertTail(sl,p);
		else
			insertBefore(sl,q,p);
	}
	return 1;
}
void taoDSMoi(SList sl,SList &sl1)
{
	printf("Danh sach moi ket qua hoc tap giam dan\n");
	initSList(sl1);
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
		insertKQHT(sl1,p->Info);	
	for(SNode *p=sl1.Head;p->Next!=NULL;p=p->Next)
		for(SNode *q=p->Next;q!=NULL;q=q->Next)
			if(tinhdiemKQ(p->Info)<tinhdiemKQ(p->Info))
				swap(p->Info,q->Info);
}
//in danh sach các sinh viên được xếp loại khá(sinh viên xếp loại khá nếu thỏa điêug kiện: 7.0<=0 điểm kết quả học tập>=8.5)
void indsKha(SList sl)
{	
	printf("Danh sach sinh vien xep loai kha\n");
	int i=1;
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
	{		tinhdiemKQ(p->Info);
		if(p->Info.diemKQ>=7&&p->Info.diemKQ<=8.5)
		{
			
			printf("THONG TIN SINH VIEN THU %d\n",i);
			i++;
			xuatSV(p->Info);
		}	
	}
}
//cho biết sinh viên có điểm kết quả học tập cao nhất 
itemtype findMaxKQHT(SList sl)
{
	tinhdiemKQ(sl.Head->Info);
	itemtype max=sl.Head->Info;
	for(SNode *p=sl.Head->Next;p!=NULL;p=p->Next)
	{tinhdiemKQ(p->Info);if(max.diemKQ<p->Info.diemKQ)
	max=p->Info;}
	return max;
}
//cho biết sinh viên có điểm kết quả thấp nhất
itemtype findMinKQHT(SList sl)
{
	tinhdiemKQ(sl.Head->Info);
	itemtype min=sl.Head->Info;
	for(SNode *p=sl.Head->Next;p!=NULL;p=p->Next)
		{tinhdiemKQ(p->Info);if(min.diemKQ>p->Info.diemKQ)
		min=p->Info;}
	return min;
}
//cho biết sinh viên có điểm kết quả học tập thấp nhất trong danh số các sinh viên xếp loại giỏi
int ktraGioi(itemtype x)
{
	tinhdiemKQ(x);
	if(x.diemKQ>=8.5)
		return 1;
	return 0;
}
SNode *findMinGioi(SList sl)
{
	SNode *min=NULL;
	for(SNode*p=sl.Head;p!=NULL;p=p->Next)
		if(ktraGioi(p->Info)==1)
		{
			min=p;break;
		}
		if(min==NULL)
				return NULL;
		for(SNode*p=min->Next;p!=NULL;p=p->Next)
			if(ktraGioi(p->Info)==1)
			{
				if(min->Info.diemKQ>p->Info.diemKQ)
					min=p;
			}			
			return min;
}
//cho biết sinh viên có điểm kết quả học tập gần x nhất(x là số thực)
float tinhMin(itemtype sv,float x)
{
	tinhdiemKQ(sv);
	return abs(sv.diemKQ-x);
}
itemtype ganNhat(SList sl,float x)
{	
	float min=tinhMin(sl.Head->Info,x);
	for(SNode *p=sl.Head->Next;p!=NULL;p=p->Next)
		if(min>tinhMin(p->Info,x))
			min=tinhMin(p->Info,x);
	for(SNode *p=sl.Head;p!=NULL;p=p->Next)
		if(min==tinhMin(p->Info,x))
			return p->Info;
}
void main()
{
	SList sl;
	initSList(sl);
	nhapDSSV(sl);
	xuatDSSV(sl);
	itemtype x;
	char ma[31];
	printf("nhap ma sinh vien ma ban muon tim:");
	scanf("%s",&ma);
	timMaSV(sl,ma);
	
	char ten[31];
	printf("nhap ten sinh vien ma ban muon tim:");
	scanf("%s",&ten);
	timTenSV(sl,ten);

	interchngeSort_Tang_Ma(sl);
	interchngeSort_Tang_Ten(sl);

	insert(sl);
	xuatDSSV(sl);
	char t[41];
	printf("Nhap vao ma sinh vien ban muon xoa:");
	scanf("%s",&t);

	if(deleteSnodeX(sl,t)==0)
		printf("Ma sinh vien nhap vao khong hop le\n");
	else
	{
		printf("Sau khi xoa thanh cong\n");
		xuatDSSV(sl);
	}
	char tent[9];
	printf("Nhap vao ten ban muon xoa:");
	scanf("%s",&tent);
	printf("Sau khi xoa tat ca ten %s\n",tent);
	xoaALLTenX(sl,tent);
	xuatDSSV(sl);

	SList sl1;
	taoDSMoi(sl,sl1);
	xuatDSSV(sl1);	

		if(findMinGioi(sl)==NULL)
		printf("Khong co hoc sinh gioi trong danh sach\n");
	else
	{
		printf("Sinh vien co diem thap nhat trong sinh vien loai gioi\n");
		xuatSV(findMinGioi(sl)->Info);
	}

	float gan;
	printf("Nhap vao diem muon xuat gan nhat:");
	scanf("%f",&gan);
	printf("Thong tin sinh vien co diem gan %.2f nhat\n",gan);
	xuatSV(ganNhat(sl,gan));

	_getch();
}