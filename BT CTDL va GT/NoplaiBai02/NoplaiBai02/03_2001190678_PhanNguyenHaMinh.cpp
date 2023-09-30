#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>

#define MAX 100
using namespace std;

struct Sach
{
	char MaS[10];
	char TenS[50];
	int NamXB;
};

void nhapFile(Sach a[], int &n, char tenFile[])
{
	ifstream in;
	in.open(tenFile);

	in>>n;
	for(int i=0; i<n;i++)
	{
		in>>a[i].MaS;
		in>>a[i].TenS;
		in>>a[i].NamXB;
	}
	in.close();
}

void xuatFile(Sach a[], int n)
{
	printf("Danh sach cac Sach trong thu vien: \n");
	for(int i=0; i<n;i++)
	{	
		printf("Ma: %10s Ten: %20s NamXB: %5d", a[i].MaS, a[i].TenS, a[i].NamXB);
		printf("\n");
	}
}

void xuat(Sach s)
{
	printf("%10s %35s %5d", s.MaS, s.TenS, s.NamXB);
}

int timMaS(Sach a[], int n, char x[])
{
	for(int i=0;i<n;i++)
		if(strcmp(a[i].MaS,x)==0)
			return i;
	return -1;
}

int timNamXB(Sach a[], int n, int y)
{
	for(int i=0;i<n;i++)
	if(a[i].NamXB==y)
		return i;
	return -1;
}

void swap(int &x, int &y)
{
	int t=x;
	x=y;
	y=t;
}
void interchangSortMaS(Sach a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(strcmp(a[i].MaS,a[j].MaS)>0)
				swap(a[i], a[j]);
}

void SeclectionSortMaS(Sach a[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		int min = i;
		for (int j=i+1; j<n; j++)
		if (a[min].MaS > a[j].MaS)
			swap(a[i], a[j]);
	}
}

void interchangSortNamXBGiam(Sach a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].NamXB < a[j].NamXB)
				swap(a[i], a[j]);
}

void SeclectionSortNamXBGiam(Sach a[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		int min = i;
		for (int j=i+1; j<n; j++)
		if (a[min].NamXB < a[j].NamXB)
			swap(a[i], a[j]);
	}
}

void interchangSortCau11(Sach a[], int n)
{
	for(int i=0; i<n; i++)
	for(int j=i+1; j<n; j++)
		if((a[i].NamXB<a[i].NamXB) || ((a[i].NamXB==a[j].NamXB) && (strcmp(a[i].TenS, a[j].TenS)>0)))
			swap(a[i], a[j]);
}
void menu()
{
	printf("------------------------------------THU VIEN---------------------------------------------\N");
	printf("1. Nhap xuat danh sach Sach\n");
	printf("2. Tim cuon sach co MaS=x trong mang\n");
	printf("3. In ra man hinh tat ca sach co NamXB=y \n");
	printf("4. Sap xep tang dan theo MaS bang InterchangSort\n");
	printf("5. Sap xep tang dan theo MaS bang SelectionSort\n");
	printf("6. Sap xep tang dan theo MaS bang QuickSort\n");
	printf("7. Sap xep giam dan theo TenS bang InterchangSort\n");
	printf("8. Sap xep giam dan theo TenS bang SelectionSort\n");
	printf("9. Sap xep giam dan theo TenS bang QuickSort\n");
	printf("10. Tim cuonsach co MaS==x khi mang da sap xep tang dan theo MaS\n");
	printf("11. Sap xep giam dan theo NamXB, neu bang nhau thi sap xep tang dan theo TenS\n");
	printf("------------------------------------THU VIEN---------------------------------------------\N");
}
void main()
{
	Sach a[MAX];
	int n;
	int thoat =0;

	do
	{
		int chon;
		printf("nhap bai tap: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			{
				printf("bai tap 1\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				break;
			}
		case 2:
			{
				printf("bai tap 2\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				char x[30];
				printf("Nhap ma can tim: ");
				flushall();
				gets(x);
				int kq=timMaS(a,n,x);
				if(kq==-1)
					printf("Khong thay\n");
				else
				{
					printf("Ma day: \n");
					xuat(a[kq]);
				}
				break;
			}
		case 3:
			{
				printf("bai tap 3\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				int y;
				printf("nhap vao nam xuat ban can tim: ");
				scanf("%d", &y);
				int kq=timNamXB(a,n,y);
				if(kq==-1)
					printf("Khong thay\n");
				else
				{
					printf("Nam xuat ban day: \n");
					xuat(a[kq]);
				}
				break;
			}
		case 4:
			{
				printf("bai tap 4\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				printf("Ma Sach sau khi sort: \n");
				interchangSortMaS(a, n);
				xuatFile(a,n);
				break;
			}
		case 5:
			{
				printf("bai tap 5\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				printf("Ma Sach sau khi sort: \n");
				SeclectionSortMaS(a,n);
				xuatFile(a,n);
				break;
			}
		case 6:
			{
				printf("bai tap 6\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				//chua xong
				break;
			}
		case 7:
			{
				printf("bai tap 7\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				printf("Ma Sach sau khi sort: \n");
				interchangSortNamXBGiam(a, n);
				xuatFile(a,n);
				break;
			}
		case 8:
			{
				printf("bai tap 8\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				printf("Ma Sach sau khi sort: \n");
				SeclectionSortNamXBGiam(a, n);
				xuatFile(a,n);
				break;
			}
		case 9:
			{
				printf("bai tap 9\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				//chua xong
				break;
			}
		case 10:
			{
				printf("bai tap 10\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				//chua xong
				break;
			}
		case 11:
			{
				printf("bai tap 11\n");
				nhapFile(a,n,"dataSach.txt");
				xuatFile(a,n);
				printf("Danh sach Sach sau khi sort\n");
				interchangSortCau11(a, n);
				xuatFile(a, n);
				break;
			}
		default:
			break;
		}
	}while(thoat==0);
	getch();
}