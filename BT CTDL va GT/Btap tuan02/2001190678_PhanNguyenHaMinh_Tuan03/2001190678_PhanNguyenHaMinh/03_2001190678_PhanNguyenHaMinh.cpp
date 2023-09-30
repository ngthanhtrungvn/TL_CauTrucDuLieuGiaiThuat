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
void main()
{
	Sach a[MAX];
	int n;
	nhapFile(a,n,"dataSach.txt");
	xuatFile(a,n);
	getch();
}