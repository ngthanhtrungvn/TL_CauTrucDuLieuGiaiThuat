#include<stdio.h>
#include<conio.h>
#include<fstream>
using namespace std;

struct DATE
{
	int ngay;
	int thang;
	int nam;
};
void nhapNSX(DATE &d)
{
	printf("nhap ngay: ");
	scanf_s("%d", d.ngay);

	printf("nhap thang: ");
	scanf_s("%d", d.thang);

	printf("nhap nam: ");
	scanf_s("%d", d.nam);
}
void xuatNSX(DATE d)
{
	printf("%2d/%2d/%4d",d.ngay, d.thang, d.nam);
}
struct TAPHOA
{
	char Ma[11];
	char Ten[21];
	float Gia;
	DATE NSX;
	int SL;
	int hanSD;
};
void nhapTapHoa(TAPHOA &th)
{
	printf("nhap ma: ");
	fflush(stdin);
	gets_s(th.Ma);

	printf("nhap ten: ");
	fflush(stdin);
	gets_s(th.Ten);

	printf("nhap gia ban: ");
	scanf_s("%f", &th.Gia);

	printf("nhap ngay sinh: ");
	scanf_s("%d/%d/%d", &th.NSX.ngay, &th.NSX.thang, &th.NSX.nam);

	printf("nhap so luong: ");
	scanf_s("%d", &th.SL);

	printf("nhap han su dung: ");
	scanf_s("%d", &th.hanSD);

}
void xuatTapHoa(TAPHOA th)
{
	printf("Ma: %5s Ten: %10s Gia: %5.3f NSX: %2d/%2d/%4d So luong: %d HSD: %d thang\n", th.Ma, th.Ten, th.Gia, th.NSX, th.SL, th.hanSD);
}
void docFile(TAPHOA a[], int &n, char tenFile[])
{
	ifstream in;
	in.open(tenFile);
	in >> n;
	for( int i=0; i<n; i++)
	{
		char c;
		in >> a[i].Ma;
		in >> a[i].Ten;
		in >> a[i].Gia;
		in >> a[i].NSX.ngay >>c>> a[i].NSX.thang >>c>>a[i].NSX.nam;
		in >> a[i].SL;
		in >> a[i].hanSD;
	}
	in.close();
}
void xuatFile(TAPHOA a[], int n)
{
	for(int i=0; i<n;i++)
		xuatTapHoa(a[i]);
	printf("\n");
}
void xuatMH2va3nam(TAPHOA a[], int n)
{
	for(int i=0;i<n;i++)
		if(a[i].hanSD>24&&a[i].hanSD<72)
			xuatTapHoa(a[i]);
}
void SLuongTren5(TAPHOA a[], int n)
{
	for(int i=0; i<n; i++)
		if(a[i].SL<5)
			xuatTapHoa(a[i]);
}
int demBanhDanisa(TAPHOA a[], int n)
{
	int dem=0;
	for (int i = 0; i < n; i++)
	{
		if(strcmp(a[i].Ten,"BanhDanisa")==0)
			dem++;
	}
	return dem;
}
int tongKH(TAPHOA a[], int n)
{
	int dem=0;
	for(int i=0; i<n; i++)
		dem=dem+a[i].SL;
	return dem;
}
int timTonKhoMax(TAPHOA a[], int n)
{
	int m=a[0].SL;
	for( int i=1; i<n; i++)
		if(m<a[i].SL)
			m=a[i].SL;
	return m;
}
void xuatMHDongGia(TAPHOA a[], int n)
{
	for(int i=0;i<n;i++)
	if(a[i].Gia==40000)
		xuatTapHoa(a[i]);
}
void xuathangHoaHH(TAPHOA a[], int n)
{

}
void main()
{
	/*TAPHOA th1;
	nhapTapHoa(th1);
	xuatTapHoa(th1);*/

	TAPHOA a[100];
	int n;
	docFile(a, n,"data.txt");
	xuatFile(a, n);

	printf("Cac mat hang sap het han\n");
	SLuongTren5(a, n);

	int kq= demBanhDanisa(a, n);
	printf("Co %d mat hang thuoc banh danisa\n", kq); 
	
	int kq1= tongKH(a, n);
	printf("Tong kho hang co %d mat hang\n", kq1);

	printf("Cac mat hang dong gia 40 ngan dong: \n");
	xuatMHDongGia(a,n);

	printf("Cac san pham co han su dung tu 2 den 3 nam: \n");
	xuatMH2va3nam(a, n);

	int kq2= timTonKhoMax(a, n);
	printf("Mat hang ton kho lon nhat: %d \n", kq2);
	_getch();
}