#include<stdio.h>
#include<conio.h>
#include<math.h>

int MAXSIZE = 7;
int*bang;
float Threshold = 0.5;
int count = 0;
int countMax = MAXSIZE * Threshold;
#define RONG -1
#define DAXOA -2

//vi tri trong laf vi tri chua gia tri -1
//vi tri bi xoa la vi tri chua -2
void initHashTable()
{
	bang = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
		bang[i] = RONG;
	count = 0;
}

int hashFunction(int key)
{
	return key % MAXSIZE;
}

//linear probing P(i)=i;
int P(int i)
{
	return i;
}

//linear probing P(i)=i;
//int P(int i)
//{
//	return i*i;
//}

// Kiểm tra xem một số có phải là số nguyên tố hay không
int kiemTraSNT(int x) {
	if (x < 2)
		return 0;

	for (int i = 2; i <= sqrtf(x); i++) {
		if (x % i == 0) 
			return 0;
	}
	return 1;
}

// Điều chỉnh MAXSIZE thành số nguyên tố gần nhất
void dieuChinhMAXSIZE() {
	while (kiemTraSNT(MAXSIZE) == 0)
	{
		MAXSIZE++;
	}
}

//int dieuChinhMAXSIZE() {
//	while (kiemTraSNT(MAXSIZE) == 0 || MAXSIZE % 4 != 3)
//	{
//		MAXSIZE++;
//	}
//}

void resize()
{
	int cu = MAXSIZE;
	MAXSIZE = MAXSIZE * 2;
	dieuChinhMAXSIZE();
	int* bangMoi = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		bangMoi[i] = RONG;
	}
	count = 0;
	for (int i = 0; i < cu; i++)
	{
			int key = bang[i];
			if (key == RONG || key == DAXOA)
			{
				continue;
			}
			
			int vt = hashFunction(key);
			int index = vt;
			int ii = 1;
			while (bangMoi[vt] != RONG)
			{
				vt = hashFunction(index + P(ii));
				ii++;
			}
			bangMoi[vt] = key;
			count++;
	}
	delete bang;
	bang = bangMoi;
	countMax = Threshold * MAXSIZE;
}

int insertCaiTien(int key)
{
	if (count > countMax)
	{
		printf("\nDa vuot so luong!\n");
		resize();
	}
	int vitri = hashFunction(key);
	int index = vitri;
	int i = 1;
	while (bang[vitri] != RONG && bang[vitri] != DAXOA)
	{
		vitri = hashFunction(index + P(i));
		i++;
	}
	if (bang[vitri] == RONG)
	{
		count++;
	}
	bang[vitri] = key;
	count++;
	return 1;
}

int insert(int key)
{
	if (count > countMax)
	{
		printf("\nDa vuot so luong!\n");
		resize();
	}
	int vitri = hashFunction(key);
	int index = vitri;
	int i = 1;
	while (bang[vitri] != RONG)
	{
		vitri = hashFunction(index + P(i));
		i++;
	}
	bang[vitri] = key;
	count++;
	return 1;
}
//tra ve vi tri tim thay key hoajc -1 neu khong co
int searchCaiTien(int key)
{
	int vt = hashFunction(key);
	int index = vt;
	int i = 1;
	int daXoaDT = -1;
	while (bang[vt] != RONG && bang[vt] != key)
	{
		if (daXoaDT == -1 && bang[vt] == DAXOA)
		{
			daXoaDT = vt;
		}
		vt = hashFunction(index + P(i));
		i++;
	}
	if (bang[vt] == RONG)
		return -1;
	bang[vt] = DAXOA;
	bang[daXoaDT] = key;
	return vt;
}

int search(int key)
{
	int vt = hashFunction(key);
	int index = vt;
	int i = 1;
	while (bang[vt] != RONG && bang[vt] != key)
	{
		vt = hashFunction(index + P(i));
		i++;
	}
	if (bang[vt] == RONG)
		return -1;
	return vt;
}

int xoa(int key)
{
	/*int vt = hashFunction(key);
	int index = vt;
	int i = 1;
	while (bang[vt] != -1 && bang[vt] != key)
	{
	vt = hashFunction(index + P(i));
	i++;
	}*/
	int vt = search(key);
	if (bang[vt] == RONG)
		return 0;
	bang[vt] = DAXOA;
	return 1;
}
void printHashTable()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("bucket[%d]: ", i);
		printf("%5d", bang[i]);
		printf("\n");
	}
}

void docFile(char file[])
{
	initHashTable();
	FILE* f = fopen(file, "r+");
	int n;
	fscanf(f, "%d", &n);
	char c;
	fscanf(f, "%c", &c);
	for (int i = 0; i < n; i++)
	{
		int x;
		fscanf(f, "%d\n", &x);
		insert(x);
	}
	fclose(f);
}

void xuatFile()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("vi tri[%d]: ", i);
		printf("%d\n", bang[i]);
	}
}

void main() {
	char file[] = "data1.txt";
	int chon;
	printf("--------------MENU------------------");
	printf("\n 1. Doc File");
	printf("\n 2. Them mot gia tri x vao bang bam");
	printf("\n 3. Xoa mot phan tu trong bang bam");
	printf("\n 4. Tim kiem mot phan tu trong bang bam");
	printf("\n 5. Thay the phan tu muon chen vao vi tri da xoa dau tien");
	printf("\n Moi ban chon bai: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
		docFile(file);
		xuatFile();
	}break;
	case 2: {
		docFile(file);
		xuatFile();
		int x;
		printf("Nhap phan tu muon them: ");
		scanf("%d", &x);
		insert(x);
		xuatFile();
	}break;
	case 3: {
		/*initHashTable();
		insert(23);
		insert(37);
		insert(42);
		insert(16);
		insert(9);
		insert(5);
		insert(12);
		printHashTable();*/
		docFile(file);
		xuatFile();
		int x;
		printf("Nhap phan tu muon xoa: ");
		scanf("%d", &x);
		xoa(x);
		xuatFile();
	}break;
	case 4: {
		docFile(file);
		xuatFile();
		int x;
		printf("Nhap phan tu muon tim: ");
		scanf("%d", &x);
		if (search(x) == -1)
		{
			printf("Khong tim thay gia tri %d\n", x);
		}
		else
		{
			printf("Tim thay gia tri %d\n", x);
		}
	}break;
	case 5: {
		docFile(file);
		xuatFile();
		int x;
		printf("Nhap phan tu muon xoa: ");
		scanf("%d", &x);
		xoa(x);
		insertCaiTien(x);
		xuatFile();
	}break;
	default:
		break;
	}
	getch();

}