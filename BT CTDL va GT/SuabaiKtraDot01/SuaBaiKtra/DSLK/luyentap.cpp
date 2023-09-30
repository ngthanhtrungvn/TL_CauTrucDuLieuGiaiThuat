#include<stdio.h>
#include<conio.h>
#include<fstream>

#define MAX 100
using namespace std;

void nhapFile(int a[], int &n, char tenFile[])
{
	ifstream in;
	in.open(tenFile);
	in >> n;
	for(int i=0; i<n; i++)
	in >> a[i];
	in.close();
}
void xuatFile(int a[], int n)
{
	printf("Danh sach cac so nguyen: \n");
	for(int i=0; i<n; i++)
	printf("%d\t", a[i]);
}

float tongTB(int a[], int n)
{
	float tong=0;
	for(int i=0; i<n; i++)
		tong = tong+a[i];
	return tong/n;
}
int timX( int a[], int n, int x)
{
	for(int i=0; i<n; i++)
		if(a[i]==x)
			return i;
	return -1;
}
void swap(int &x, int &y)
{
	int t=x; x=y; y=t;
}
void selectTionSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int min=i;
		for(int j=i+1; j<n; j++)
			if(a[i]<a[j])
				swap(a[i], a[j]);
	}
}
void main()
{
	int a[MAX];
	int n;
	nhapFile(a, n, "input.txt");
	xuatFile(a, n);
	float kq= tongTB(a,n);
	printf("Tong: %3.2f \n", kq);
	int x;
	printf("Nhap x can tim: ");
	scanf("%d", &x);
	int kq1=timX(a,n,x);
	printf("X nam o vi tri %d", kq1);
	printf("Danh sach so nguyen sau khi sort: \n");
	selectTionSort(a, n);
	xuatFile(a, n);
	getch();
}