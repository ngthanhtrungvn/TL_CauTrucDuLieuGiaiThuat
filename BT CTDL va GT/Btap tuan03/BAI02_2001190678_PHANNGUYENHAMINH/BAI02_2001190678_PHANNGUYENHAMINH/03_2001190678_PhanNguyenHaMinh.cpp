#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>

#define MAX 100
using namespace std;

void menu()
{
	printf("-----------------TRUONG HOC--------------------\n");
	printf("1. Nhap xuat mang 1 chieu thong tin 1 truong hoc\n");
	printf("2. Tim truong hoc co MaT=x trong mang\n");
	printf("3. Tim truong hoc co TenT=y trong mang\n");
	printf("4. Sap xep mang tang theo MaT bang InterchangSort\n");
	printf("5. Sap xep mang tang theo MaT bang SelectionSort\n");
	printf("6. Sap xep mang tang theo MaT bang QuickSort\n");
	printf("7. Sap xep mang giam theo TenT bang InterchangSort\n");
	printf("8. Sap xep mang giam theo TenT bang SelectionSort\n");
	printf("9. Sap xep mang giam theo TenT bang QuickSort\n");
	printf("10. Sap xep mang tang theo NamTL bang InterchangSort\n");
	printf("11. Sap xep mang tang theo NamTL bang SelectionSort\n");
	printf("12. Sap xep mang tang theo NamTL bang QuickSort\n");
	printf("13. Tim truong hoc co MaT=x (Sau khi sap xep tang theo MaT)\n");
	printf("14. Tim truong hoc co TenT=y (Neu co nhieu truong trung ten thi lay truong dau tien)\n");
	printf("15. Liet ke cac man hinh danh nhung truong hoc co NamTL tu z den nay\n");
}

struct THoc
{
	char MaT[10];
	char TenT[50];
	int NamTL;
};

void nhapFile(THoc a[], int &n, char tenfile[])
{
	ifstream in;
	in.open(tenfile);
	in>>n;
	for(int i=0; i<n; i++)
	{
	in>>a[i].MaT;
	in>>a[i].TenT;
	in>>a[i].NamTL;
	}
	in.close();
}

void xuatFile(THoc a[], int n)
{
	printf("Danh sach cac ngoi truong trong nuoc: \n");
	for(int i=0; i<n; i++)
	{
		printf("%10s %35s %5d", a[i].MaT, a[i].TenT, a[i].NamTL);
		printf("\n");
	}
}

void xuat(THoc th)
{
	printf("%10s %35s %5d\n", th.MaT, th.TenT, th.NamTL);
}

int lietKeNamTLY(THoc a[], int n, int z)
{
	for(int i=0; i<n;i++)
		if(a[i].NamTL < z)
		{
			return i;
			return -1;
		}
}

int LinearSearchMaT(THoc a[], int n, char x[])
{
	for(int i=0; i<n; i++)
		if(strcmp(a[i].MaT, x)==0)
			return i;
	return -1;
}

int timTenT(THoc a[], int n, char y[])
{
	for(int i=0; i<n; i++)
		if(strcmp(a[i].TenT, y)==0)
			return i; 
	return -1;
}

void swap(int &x, int &y)
{
	int t=x; 
	x=y;
	y=t;
}

void inietchangSortMaT(THoc a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(strcmp(a[i].MaT, a[j].MaT)>0)
				swap(a[i], a[j]);
}

void selectTionSortMaT(THoc a[], int n)
{
	for(int i=0; i< n-1; i++)
	{
		int min= i;
		for(int j=i+1; j<n;j++)
			if(strcmp(a[i].MaT, a[j].MaT)>0)
				swap(a[i], a[j]);

	}
}

void quickSortMaT(THoc a[], int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	do
	{
		while (strcmp(a[i].MaT, a[mid].MaT)<0) i++;
		while (strcmp(a[j].MaT, a[mid].MaT)>0) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i<j);
	if (left<j) quickSortMaT(a, left, j);
	if (i<right) quickSortMaT(a, i, right);
}

void interchangSortGiamTenT(THoc a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
		if(strcmp(a[i].TenT, a[j].TenT)<0)
			swap(a[i], a[j]);
}

void selectTionGiamTenT(THoc a[], int n)
{
	for(int i=0; i< n-1; i++)
	{
		int min= i;
		for(int j=i+1; j<n;j++)
			if(strcmp(a[i].TenT, a[j].TenT)<0)
				swap(a[i], a[j]);

	}
}

void quickSortGiamTenT(THoc a[], int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	do
	{
		while (strcmp(a[i].TenT, a[mid].TenT)>0) i++;
		while (strcmp(a[j].TenT, a[mid].TenT)<0) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i<j);
	if (left<j) quickSortGiamTenT(a, left, j);
	if (i<right) quickSortGiamTenT(a, i, right);
}

void inietchangSortNamTL(THoc a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].NamTL < a[j].NamTL)
				swap(a[i], a[j]);
}

void selectTionSortNamTL(THoc a[], int n)
{
	for(int i=0; i< n-1; i++)
	{
		int min= i;
		for(int j=i+1; j<n;j++)
			if(a[i].NamTL > a[j].NamTL)
				swap(a[i], a[j]);

	}
}

void quickSortNamTL(THoc a[], int left, int right)
{
	int i = left, j = right, mid = (left + right) / 2;
	do
	{
		while (a[i].NamTL<a[j].NamTL) i++;
		while (a[i].NamTL>a[j].NamTL) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i<j);
	if (left<j) quickSortNamTL(a, left, j);
	if (i<right) quickSortNamTL(a, i, right);
}

int binarySearchMaT(THoc a[], int left,int right,char z[])
{
	if (left>right)
		return -1;
	int mid = (left + right) / 2;
	if (strcmp(z, a[mid].MaT) == 0)
		return mid;
	if (strcmp(z, a[mid].MaT) < 0)
		return binarySearchMaT(a, left, mid - 1, z);
	return binarySearchMaT(a, mid + 1, right, z);
}


void main()
{
	THoc a[MAX];
	int n;
	int thoat=0;

	do
	{
	int chon;
	menu();
	printf("Chon cau: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1:
		{
			printf("Cau 1\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			break;
		}
	case 2:
		{
			printf("Cau 2\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			char x[10];
			printf("nhap maT ban can tim: ");
			flushall();
			gets(x);
			int kq=LinearSearchMaT(a, n, x);
			if(kq==-1)
				printf("Khong thay\n");
			else
			{
				printf("Day ne: \n");
				xuat(a[kq]);
			}
			break;
		}
	case 3:
		{
			printf("cau 3\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			char y[40];
			printf("nhap TenT ban can tim: ");
			flushall();
			gets(y);
			int kq=timTenT(a, n, y);
			if(kq==-1)
				printf("Khong thay\n");
			else
			{
				printf("Day ne: \n");
				xuat(a[kq]);
			}
			break;
		}
	case 4:
		{
			printf("bai tap 4\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			inietchangSortMaT(a, n);
			xuatFile(a, n);
			break;
		}
	case 5:
		{
			printf("bai tap 5\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			selectTionSortMaT(a, n);
			xuatFile(a, n);
			break;
		}
	case 6:
		{
			printf("bai tap 6\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			quickSortMaT(a, 0, n-1);
			xuatFile(a, n);
			break;
		}
	case 7:
		{
			printf("bai tap 7\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			interchangSortGiamTenT(a, n);
			xuatFile(a, n);
			break;
		}
	case 8:
		{
			printf("bai tap 8\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			selectTionGiamTenT(a, n);
			xuatFile(a, n);
			break;
		}
	case 9:
		{
			printf("bai tap 9\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			quickSortGiamTenT(a, 0, n-1);
			xuatFile(a, n);
			break;
		}
	case 10:
		{
			printf("bai tap 10\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			inietchangSortNamTL(a, n);
			xuatFile(a, n);
			break;
		}
	case 11:
		{
			printf("bai tap 11\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			selectTionSortNamTL(a, n);
			xuatFile(a, n);
			break;
		}
	case 12:
		{
			printf("bai tap 12\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			printf("Truong sau khi da sort :\n");
			quickSortNamTL(a, 0, n-1);
			xuatFile(a, n);
			break;
		}
	case 13:
		{
			printf("Cau 13\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			char z[10];
			printf("nhap maT ban can tim: ");
			flushall();
			gets(z);
			int kq=binarySearchMaT(a, 0, n-1, z);
			if(kq==-1)
				printf("Khong thay\n");
			else
			{
				printf("Day ne: \n");
				xuat(a[kq]);
			}
			break;
		}
	case 15:
		{
			printf("bai tap 15\n");
			nhapFile(a, n, "dataTruong.txt");
			xuatFile(a, n);
			int z;
			printf("Nhap nam TL can xuat: ");
			scanf("%d", &z);
			int kq= lietKeNamTLY(a,n,z);
			if(kq==-1)
				printf("Nam nay khong co: ");
			else
			{
				printf("Day ne: \n");
				xuatFile(a, n);
			}
			break;
		}
	case 0:
		{
			printf("thoat chuong trinh\n");
			thoat =1;
			break;
		}
	default:	printf("sai so roi!\n");
		break;
	}
	}while (thoat==0);
	getch();
}
