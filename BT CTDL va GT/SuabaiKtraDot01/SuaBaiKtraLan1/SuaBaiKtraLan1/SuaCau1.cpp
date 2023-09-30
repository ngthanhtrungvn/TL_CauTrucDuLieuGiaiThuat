#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;
#define MAX 100

struct DATE
{
	int ngay;
	int thang;
	int nam;
};
void nhapNS(DATE &d)
{
	printf("nhap ngay: ");
	scanf("%d",&d.ngay);
	printf("nhap thang: ");
	scanf("%d",&d.thang);
	printf("nhap nam: ");
	scanf("%d",&d.nam);
}
void xuatNS(DATE d)
{
	printf(" %2d/%2d/%4d ",d.ngay, d.thang, d.nam);
}
struct HOCSINH
{
	char Ma[10];
	char Ten[50];
	int GTinh;
	DATE NgSinh;
};
void nhapFile(HOCSINH a[], int &n, char tenfile[])
{
	ifstream in;
	in.open(tenfile);
	in >> n;
	for(int i=0; i<n; i++)
	{
		in >> a[i].Ma;
		in >> a[i].Ten;
		in >> a[i].GTinh;
		in >>a[i].NgSinh.ngay >> a[i].NgSinh.thang >> a[i].NgSinh.nam;
	}
	in.close();
}
void xuatSV(HOCSINH hs)
{
	printf(" %10s %30s %d %2d/%2d/%4d \n",hs.Ma, hs.Ten, hs.GTinh, hs.NgSinh);
}
void xuatFile(HOCSINH a[], int n)
{
	for(int i=0; i<n; i++)
		xuatSV(a[i]);
	printf("\n");
}

float demHS(HOCSINH a[], int n)
{
	float demNam=0;
	float demNu=0;
	for(int i=0; i<n; i++)
		if(a[i].GTinh==1)
			demNam++;
		else
			demNu++;
	return demNam; demNu;
	return demNam/demNu;
}
int timX(HOCSINH a[], int n, char x[])
{
	for(int i=0; i<n; i++)
		if(strcmp(a[i].Ma, x)==0)
			return i;
	return -1;
}
void sapXep(HOCSINH a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].NgSinh.ngay>a[j].NgSinh.ngay && a[i].NgSinh.thang>a[j].NgSinh.thang && a[i].NgSinh.nam>a[j].NgSinh.nam || a[i].NgSinh.ngay==a[j].NgSinh.ngay && a[i].NgSinh.thang==a[j].NgSinh.thang && a[i].NgSinh.nam==a[j].NgSinh.nam && strcmp(a[i].Ten, a[j].Ten)>0)
				swap(a[i], a[j]);
}
void main()
{
	HOCSINH a[MAX];
	int n;
	nhapFile(a,n,"data.txt");
	xuatFile(a, n);
	/*int kq=demHS(a,n);
	printf("Ti le so hs nam tren hs nu la: %3.2f \n", kq);
	char x[10];
	printf("nhap ma can tim: ");
	flushall();
	gets(x);
	int kq1=timX(a,n,x);
	if(kq==-1)
		printf("Khong thay hoc sinh nay: \n");
	else
	{
		printf("Hoc sinh nay day: \n");
		xuatSV(a[kq1]);
	}*/
	printf("Danh sach sau khi sort\n");
	sapXep(a, n);
	xuatFile(a, n);
	getch();
}
