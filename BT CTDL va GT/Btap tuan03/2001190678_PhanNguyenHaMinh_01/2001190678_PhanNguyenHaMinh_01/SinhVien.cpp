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
void nhapNS(DATE &d)
{
	printf("nhap ngay: ");
	scanf_s("%d",&d.ngay);
	printf("nhap thang: ");
	scanf_s("%d",&d.thang);
	printf("nhap nam: ");
	scanf_s("%d", &d.nam);
}
void xuatNS(DATE d)
{
	printf(" %2d/%2d/%4d ", d.ngay, d.thang, d.nam);
}
struct SinhVien
{
	char MaSV[11];
	char HoTen[21];
	char DiaChi[31];
	char Nganh[21];
	float Dtb;
	DATE NgaySinh;
};
void nhapSV(SinhVien &sv)
{
	printf("nhap ma: ");
	fflush(stdin);
	gets_s(sv.MaSV);

	printf("nhap ten: ");
	fflush(stdin);
	gets_s(sv.HoTen);

	printf("nhap dia chi: ");
	fflush(stdin);
	gets_s(sv.DiaChi);

	printf("nhap nganh: ");
	fflush(stdin);
	gets_s(sv.Nganh);

	printf("nhap dtb: ");
	scanf_s("%f", &sv.Dtb);
}
void xuat(SinhVien sv)
{
	printf("%11s %21s %20s %20s %5.1f %2d/%2d/%4d \n", sv.MaSV, sv.HoTen, sv.DiaChi, sv.Nganh, sv.Dtb, sv.NgaySinh);
}
void nhapMang(SinhVien a[], int &n)
{
	printf("nhap vao so phan tu cua mang: ");
	scanf_s("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("nhap vao sinh vien thu %d: ", i);
		nhapSV(a[i]);
	}
}
void xuatMang(SinhVien a[], int n)
{
	printf("Danh sach cac sinh vien: \n");
	for (int i = 0; i < n; i++)
		xuat(a[i]);
	printf("\n");
}
void docFile(SinhVien a[], int &n, char tenFile[])
{
	ifstream in;
	in.open(tenFile);
	in >> n;
	for(int i=0; i<n; i++)
	{
		in>>a[i].MaSV;
		in>>a[i].HoTen;
		in>>a[i].DiaChi;
		in>>a[i].Nganh;
		in>>a[i].Dtb;
		in>>a[i].NgaySinh.ngay >> a[i].NgaySinh.thang >> a[i].NgaySinh.nam;
	}
	in.close();
}
void xuatFile(SinhVien a[], int n)
{
	for (int i=0;i<n;i++)
		xuat(a[i]);
	printf("\n");
}
void xuatSvCNTT(SinhVien a[], int n)
{
	for(int i=0; i<n; i++)
		if(strcmp(a[i].Nganh,"cntt")==0)
			xuat(a[i]);
}
void xuatSvTPHCM(SinhVien a[], int n)
{
	for(int i=0; i<n; i++)
		if(strcmp(a[i].DiaChi,"TpHCM")==0)
			xuat(a[i]);
}
int tongNganhHoc(SinhVien a[], int n)
{
	int dem=0;
	for(int i=0; i<n; i++)
		if(strcmp(a[i].Nganh,a[i].Nganh)==0)
			dem++;
	return dem;
}
void xuatSvDTBMax(SinhVien a[], int n)
{
	float max=a[0].Dtb;
		for(int i=0; i<n; i++)
			if(a[i].Dtb>max)
				xuat(a[i]);

}
void timMSSV(SinhVien a[], int n)
{
	for(int i=0; i<n; i++)
		if(strcmp(a[i].MaSV,"012015")==0)
			xuat(a[i]);
			
}
void main()
{
	//SinhVien sv1;
	//nhapSV(sv1);
	//xuat(sv1);

	/*SinhVien a[100];
	int n;
	nhapMang(a, n);
	xuatMang(a, n);*/
	SinhVien a[100];
	int n;
	docFile(a, n, "data.txt");
	xuatFile(a, n);

	printf("Cac sinh vien thuoc nganh CNTT: \n");
	xuatSvCNTT(a, n);

	printf("Cac SV que quan TpHCM: \n");
	xuatSvTPHCM(a, n);

	printf("Sinh Vien co MSSV 012015: \n");
	timMSSV(a, n);

	int kq1= tongNganhHoc(a, n);
	printf("Co tong cong %d nganh hoc \n", kq1);

	printf("Sinh vien co diem trung binh cao nhat: \n");
	xuatSvDTBMax(a, n);

	_getch();
}