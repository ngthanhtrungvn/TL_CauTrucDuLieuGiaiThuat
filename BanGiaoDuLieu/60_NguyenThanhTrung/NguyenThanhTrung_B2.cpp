#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct BACSI
{
	char tenDN[11];
	char hoten[51];
	char matma[7];
	char khoa[31];
};

typedef BACSI ItemType;


int MAXSIZE = 20;
ItemType* bang;
float Threshold = 0.6;
int count = 0;
int countMax = MAXSIZE * Threshold;
#define RONG -1
#define DAXOA -2

void initHashTable()
{
	bang = new ItemType[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
		strcpy(bang[i].tenDN, "");
	count = 0;
}


int hashFunction(int key)
{
	return key % MAXSIZE;
}

int P(int i)
{
	return i;
}


void resize()
{
	int cu = MAXSIZE;
	MAXSIZE = MAXSIZE * 2;
	ItemType* bangMoi = new ItemType[MAXSIZE];
	ItemType bacsi;
	strcpy(bacsi.tenDN, "");
	for (int i = 0; i < MAXSIZE; i++)
	{
		bangMoi[i] = bacsi;
	}
	count = 0;
	for (int i = 0; i < cu; i++)
	{
		int key = bang[i].tenDN;
		if (key == RONG || key == DAXOA)
		{
			continue;
		}

		int vt = hashFunction(key);
		int index = vt;
		int ii = 1;
		while (bangMoi[vt].tenDN != "")
		{
			vt = hashFunction(index + P(ii));
			ii++;
		}
		bangMoi[vt].tenDN = key;

		int a = 0;
		while (true)
		{
			if (bang[i].hoten[a])
			{
				bangMoi[vt].hoten[a] = bang[i].hoten[a];
				a++;
			}
			else
			{
				break;
			}
		}

		int b = 0;
		while (true)
		{
			if (bang[i].matma[b])
			{
				bangMoi[vt].matma[b] = bang[i].matma[b];
				b++;
			}
			else
			{
				break;
			}
		}

		int c = 0;
		while (true)
		{
			if (bang[i].khoa[b])
			{
				bangMoi[vt].khoa[b] = bang[i].khoa[b];
				c++;
			}
			else
			{
				break;
			}
		}
		count++;
	}
	delete bang;
	bang = bangMoi;
	countMax = Threshold * MAXSIZE;
}

int insert(ItemType key)
{
	if (count > countMax)
	{
		printf("\nDa vuot so luong!\n");
		resize();
	}
	int vitri = hashFunction(key.tenDN);
	int index = vitri;
	int i = 1;
	while (bang[vitri].tenDN != RONG)
	{
		vitri = hashFunction(index + P(i));
		i++;
	}
	int a = 0;
	while (true)
	{
		if (key.tenDN[a] != NULL)
		{
			bang[vitri].tenDN[a] = key.tenDN[a];
			a++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].tenDN[a] = '\0';

	int b = 0;
	while (true)
	{
		if (key.hoten[a] != NULL)
		{
			bang[vitri].hoten[a] = key.hoten[a];
			a++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].hoten[a] = '\0';

	int c = 0;
	while (true)
	{
		if (key.matma[b])
		{
			bang[vitri].matma[b] = key.matma[b];
			b++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].matma[b] = '\0';

	int d = 0;
	while (true)
	{
		if (key.khoa[b])
		{
			bang[vitri].khoa[b] = key.khoa[b];
			b++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].khoa[b] = '\0';
	count++;
	return 1;
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
		ItemType x;
		fscanf(f, "%[^#]# %[^#]# %[^#]# %[^#]\n", x.tenDN, x.hoten, x.matma, x.khoa);
		insert(x);
	}
	fclose(f);
}

void xuatFile()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].tenDN != "")
		{
			printf("vi tri[%d]: ", i);
			printf("%s %s %d %.2f\n", bang[i].tenDN, bang[i].hoten, bang[i].matma, bang[i].khoa);
		}
		else
		{
			printf("vi tri[%d]: ", i);
			printf("-1\n");
		}
	}
}




void main() {
	char file[] = "DSBacSi.txt";
	int chon;
	printf("--------------MENU------------------");
	printf("\n 1. Xay dung bang bam su dung phuong phap dia chi mo la Linear probing (P(i) = i) de xu ly dung do co kich thuoc ban dau la 20 phan tu va nguong luu tru la 0.6.");
	printf("\n 2. Xay dung ham them mot bac si vao bang bam");
	printf("\n 3. Nhap thong tin file");
	printf("\n Moi ban chon bai: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
		docFile(file);
		xuatFile();
	}break;
	case 2: {
		
	}break;
	
	default:
		break;
	}
	getch();

}


