#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>

using namespace std;

//tao struct Monhoc
struct MONHOC
{
	char ma[11];
	char ten[30];
	int soTC;
	float dtl;
	float dck;
};

//tao Node Monhoc
struct SNodeMH
{
	MONHOC Info;
	SNodeMH* Next;
};

//tao List Monhoc
struct SListMH
{
	SNodeMH* Head;
	SNodeMH* Tail;
};

//tao struct SV
struct SV
{
	char ma[40];
	char ho[25];
	char ten[8];
	int namSinh;
	SListMH lstMH;                               
};

//tao Node SV
struct SNodeSV
{
	SV Info;
	SNodeSV* Next;
};

//tao List SV
struct SListSV
{
	SNodeSV* Head;
	SNodeSV* Tail;
};

//bien thanh Node
SNodeMH* createSNodeMH(MONHOC mh)
{
	SNodeMH* p=new SNodeMH;
	if(p==NULL)
		return NULL;
	p->Info= mh;
	p->Next= NULL;
	return p;
}

//bien thanh SV
SNodeSV* createSNodeSV(SV sv)
{
	SNodeSV* p=new SNodeSV;
	if(p==NULL)
		return NULL;
	p->Info= sv;
	p->Next=NULL;
	return p;
}

//nhap tay Monhoc
void nhapMH(MONHOC &mh)
{
	printf("nhap ma: ");
	flushall();
	gets(mh.ma);

	printf("nhap ten: ");
	flushall();
	gets(mh.ten);

	printf("nhap so TC: ");
	scanf("%d", &mh.soTC);

	printf("nhap diem tieu luan: ");
	scanf("%f", &mh.dtl);

	printf("nhap diem cuoi ky: ");
	scanf("%f", &mh.dck);
}

//chen Monhoc vao sau DSLK
int insertTailMH(SListMH &slmh, SNodeMH *p)
{
	if(p==NULL)
		return 0;
	if(slmh.Head==NULL)
	{
		slmh.Head=p;
		slmh.Tail=p;
	}
	else
	{
		slmh.Tail->Next=p;
		slmh.Tail=p;
	}
	return 1;
}

//tao DS
void createSListMH(SListMH &slmh)
{
	slmh.Head=NULL;
	slmh.Tail=NULL;
	printf("Ban muon nhap bao nhieu mon hoc: ");
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		MONHOC mh1;
		nhapMH(mh1);
		//bien mh1 thanh SNodeMH
		SNodeMH* p=createSNodeMH(mh1);
		//them mh vao duoi ds
		insertTailMH(slmh, p);
	}
}

//xuat 1 Mochoc
void xuatMH(MONHOC mh)
{
	printf("%10s %20s %5d %.2f %.2f\n", mh.ma, mh.ten, mh.soTC, mh.dtl, mh.dck);
}

//xuat DS Monhoc
void xuatSListMH(SListMH slmh)
{
	for(SNodeMH*i=slmh.Head; i!=NULL; i=i->Next)
		printf("%10s %20s %5d %.2f %.2f\n", i->Info.ma, i->Info.ten, i->Info.soTC, i->Info.dtl, i->Info.dck);
		printf("\n");
}

//nhap tay 1 SV
void nhapSV(SV &sv)
{
	printf("nhap ma: ");
	flushall();
	gets(sv.ma);

	printf("nhap ho: ");
	flushall();
	gets(sv.ho);

	printf("nhap ten: ");
	flushall();
	gets(sv.ten);

	printf("nhap nam sinh: ");
	scanf("%d", &sv.namSinh);

	//nhap danh sach cac mon hoc
	createSListMH(sv.lstMH);
}

//chen SV vao sau DSLK
int insertTailSV(SListSV &slsv, SNodeSV *p)
{
	/*SNodeSV* p= new SNodeSV;*/
	if(p == NULL)
		return NULL;
	if(slsv.Head == NULL)
	{
		slsv.Head= p;
		slsv.Tail= p;
	}
	else
	{
		slsv.Tail->Next=p;
		slsv.Tail=p;
	}
	return 1;
}

//tao DSSV
void createSListSV(SListSV &slsv)
{
	slsv.Head= slsv.Tail= NULL;
	printf("Nhap vao so luong SV: ");
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		SV sv1;
		nhapSV(sv1);
		SNodeSV* p=createSNodeSV(sv1);
		insertTailSV(slsv, p);
	}
}

//xuat 1 SV
void xuatSV(SV sv)
{
	printf("%20s %20s %10s %5d\n", sv.ma, sv.ho, sv.ten, sv.namSinh);
	for(SNodeMH* i=sv.lstMH.Head; i!=NULL; i=i->Next)
	{
		printf("\t");
		xuatMH(i->Info);
	}
}

//xuat DSSV
void xuatSListSV(SListSV slsv)
{
	for (SNodeSV* i=slsv.Head; i!=NULL; i=i->Next)
		xuatSV(i->Info);
}

//tinh diem KQ
float diemKQ(SV sv)
{
	float tong=0;
	int stc;
	for(SNodeMH* i=sv.lstMH.Head; i!=NULL; i=i->Next)
	{
		stc= stc + i->Info.soTC;
		tong= tong + i->Info.soTC*(0.3*i->Info.dtl + 0.7*i->Info.dck);
	}
	if(stc==0)
		return 0;
	return tong/stc;
}

void main()
{
	MONHOC mh;
	/*SListMH haminh;
	createSListMH(haminh);*/
	SListSV haminhthuhai;
	createSListSV(haminhthuhai);
	/*xuatSListMH(haminh);*/
	xuatSListSV(haminhthuhai);
	getch();
}