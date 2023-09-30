#include<conio.h>
#include<stdio.h>

struct HashNode
{
	int key;
	HashNode* next;
};

typedef HashNode* NodePtr;
int MAXSIZE = 10;
NodePtr* bang;
int countNode = 0;
double threshold = 0.6;
int countMax = MAXSIZE * threshold;

int HashFunction(int key) {
	return key % MAXSIZE;
}

HashNode* createHashNode(int x) {
	HashNode* p = new HashNode;
	if (p == NULL)
	{
		return NULL;
	}
	p->key = x;
	p->next = NULL;
	return p;
}

void resize()
{
	int cu = MAXSIZE;
	MAXSIZE = MAXSIZE * 2;
	countMax = MAXSIZE * threshold;
	NodePtr* bangMoi = new NodePtr[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		bangMoi[i] = NULL;
	}

	for (int i = 0; i < cu; i++)
	{
		if (bang[i] != NULL)
		{
			while (bang[i] != NULL) {
				int key = bang[i]->key;
				int vt = HashFunction(key);
				HashNode* p = createHashNode(key);
				p->next = bangMoi[vt];
				bangMoi[vt] = p;
				p = bang[i];
				bang[i] = bang[i]->next;
				delete p;
			}
		}
	}
	delete bang;
	bang = bangMoi;
}

void insert(int key)
{
	if (countNode > countMax)
	{
		printf("\nDa vuot so luong!\n");
		resize();
	}
	int vt = HashFunction(key);
	HashNode* p = createHashNode(key);
	if (p == NULL)
	{
		return;
	}
	if (bang[vt] == NULL)
	{
		bang[vt] = p;
	}
	else
	{
		p->next = bang[vt];
		bang[vt] = p;
	}
	countNode++;
}

void initBucket()
{
	bang = new NodePtr[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		bang[i] = NULL;
	}
}

void docFile(char file[]) {
	initBucket();
	FILE* f = fopen(file, "r+");
	int n;
	fscanf(f, "%d", &n);
	char c;
	fscanf(f, "%c", &c);
	for (int i = 0; i < n; i++)
	{
		int x;
		fscanf(f, "%d\n", &x);
		HashNode* p = createHashNode(x);
		insert(x);
	}

	fclose(f);
}

void XuatFile()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i] == NULL)
		{
			printf("bucket[%d]:\n", i);
		}
		else
		{
			printf("bucket[%d]: ", i);
			for (HashNode* p = bang[i]; p != NULL; p = p->next)
			{
				printf("%d ", p->key);
			}
			printf("\n");
		}
	}
}

NodePtr search(int k)
{
	int b = HashFunction(k);
	NodePtr p = bang[b];
	while (p != NULL && p->key != k) {
		p = p->next;
	}
	return p;
}

int xuatMax()
{
	HashNode* max = bang[0];
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (HashNode* p = bang[i]; p != NULL; p = p->next)
		{
			if (p > max)
			{
				max = p;
			}
		}
	}
	return max;
}




void main() {
	char file[] = "data.txt";
	int chon;
	printf("------------------------MENU------------------------");
	printf("\n 1. Doc file");
	printf("\n 2. Them 1 phan tu vao bang bam");
	printf("\n 3. Tim phan tu trong bang bam");
	printf("\n 4. Xuat gia tri trong bang bam");
	printf("\n 5. Xuat gia tri lon nhat");
	printf("\n Moi ban chon bai: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
				docFile(file);
				XuatFile();
	}break;
	case 2: {
				docFile(file);
				XuatFile();
				int x;
				printf("Moi ban nhap x: ");
				scanf("%d", &x);
				insert(x);
				XuatFile();
	}break;
	case 3: {
				docFile(file);
				XuatFile();
				int x;
				printf("Nhap x can tim: ");
				scanf("%d", &x);
				HashNode* node = search(x);
				if (node != NULL) {
					printf("Tim thay %d trong bucket\n", x);
				}
				else {
					printf("Khong tim thay %d trong bucket\n", x);
				}
	}break;
	case 4: {
				docFile(file);
				XuatFile();
	}break;
	
	default:
		break;
	}
	getch();
}