#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct SACH
{
	char ma[5];
	char ten[50];
	char ss[51];
	int sotrang;
	float giaban;
	int ssa;
};

typedef SACH ItemType;


int MAXSIZE = 7;
ItemType*bang;
float Threshold = 0.6;
int count = 0;
int countMax = MAXSIZE * Threshold;
#define RONG -1
#define DAXOA -2

//vi tri trong laf vi tri chua gia tri -1
//vi tri bi xoa la vi tri chua -2
void initHashTable()
{
	bang = new ItemType[MAXSIZE];
	ItemType sach;
	sach.sotrang = -1;
	for (int i = 0; i < MAXSIZE; i++)
		bang[i] = sach;
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


void resize()
{
	int cu = MAXSIZE;
	MAXSIZE = MAXSIZE * 2;
	ItemType* bangMoi = new ItemType[MAXSIZE];
	ItemType sach;
	sach.sotrang = -1;
	for (int i = 0; i < MAXSIZE; i++)
	{
		bangMoi[i] = sach;
	}
	count = 0;
	for (int i = 0; i < cu; i++)
	{
		int key = bang[i].sotrang;
		if (key == RONG || key == DAXOA)
		{
			continue;
		}

		int vt = hashFunction(key);
		int index = vt;
		int ii = 1;
		while (bangMoi[vt].sotrang != RONG)
		{
			vt = hashFunction(index + P(ii));
			ii++;
		}
		bangMoi[vt].sotrang = key;

		int a = 0;
		while (true)
		{
			if (bang[i].ten[a])
			{
				bangMoi[vt].ten[a] = bang[i].ten[a];
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
			if (bang[i].ma[b])
			{
				bangMoi[vt].ma[b] = bang[i].ma[b];
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
			if (bang[i].ss[c])
			{
				bangMoi[vt].ss[c] = bang[i].ss[c];
				c++;
			}
			else
			{
				break;
			}
		}

		bangMoi[vt].ssa = bang[i].ssa;
		bangMoi[vt].giaban = bang[i].giaban;
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
	int vitri = hashFunction(key.sotrang);
	int index = vitri;
	int i = 1;
	while (bang[vitri].sotrang != RONG)
	{
		vitri = hashFunction(index + P(i));
		i++;
	}
	bang[vitri].sotrang = key.sotrang;

	int a = 0;
	while (true)
	{
		if (key.ten[a] != NULL)
		{
			bang[vitri].ten[a] = key.ten[a];
			a++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].ten[a] = '\0';

	int b = 0;
	while (true)
	{
		if (key.ma[b])
		{
			bang[vitri].ma[b] = key.ma[b];
			b++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].ma[b] = '\0';

	int c = 0;
	while (true)
	{
		if (key.ss[c])
		{
			bang[vitri].ss[c] = key.ss[c];
			c++;
		}
		else
		{
			break;
		}
	}
	bang[vitri].ss[c] = '\0';

	bang[vitri].ssa = key.ssa;
	bang[vitri].giaban = key.giaban;
	count++;
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
		ItemType x;
		fscanf(f, "%[^#]#%[^#]#%[^#]#%d#%f#%d\n", x.ma, x.ten, x.ss, &x.sotrang, &x.giaban, &x.ssa);
		insert(x);
	}
	fclose(f);
}

void xuatFile()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang != -1)
		{
			printf("vi tri[%d]: ", i);
			printf("%s %s %s %d %.2f %d\n", bang[i].ma, bang[i].ten, bang[i].ss, bang[i].sotrang, bang[i].giaban, bang[i].ssa);
		}
		else
		{
			printf("vi tri[%d]: ", i);
			printf("-1\n");
		}
	}
}

//tra ve vi tri tim thay key hoajc -1 neu khong co
int search(int key)
{
	int vt = hashFunction(key);
	int index = vt;
	int i = 1;
	int daxoaDT = -1;
	while (bang[vt].sotrang != RONG && bang[vt].sotrang != key)
	{
		if (daxoaDT == RONG && bang[vt].sotrang == DAXOA)
		{
			daxoaDT = vt;
		}
		vt = hashFunction(index + P(i));
		i++;
	}
	if (bang[vt].sotrang == RONG)
		return -1;
	bang[vt].sotrang = DAXOA;
	bang[daxoaDT].sotrang = key;
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
	if (bang[vt].sotrang == RONG)
		return 0;
	bang[vt].sotrang = DAXOA;
	return 1;
}

//xoa thong tin cuon sach dua vao ten
int xoaTheoTen(const char* tenSach)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang != RONG && bang[i].sotrang != DAXOA)
		{
			if (strcmp(bang[i].ten, tenSach) == 0)
			{
				bang[i].sotrang = DAXOA;
				return 1; // Đã xóa thành công cuốn sách có tên tương ứng
			}
		}
	}
	return 0; // Không tìm thấy cuốn sách có tên tương ứng trong bảng băm
}

//xóa 1 cuốn sách theo mã sách
int xoaTheoMa(const char* maSach)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang != RONG && bang[i].sotrang != DAXOA)
		{
			if (strcmp(bang[i].ma, maSach) == 0)
			{
				bang[i].sotrang = DAXOA;
				return 1; // Đã xóa thành công cuốn sách có mã tương ứng
			}
		}
	}
	return 0; // Không tìm thấy cuốn sách có mã tương ứng trong bảng băm
}

//Tim kiem thong tin cua mot cuon sach khi biet ma sach
int timKiemTheoMa(const char* maSach)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang != RONG && bang[i].sotrang != DAXOA)
		{
			if (strcmp(bang[i].ma, maSach) == 0)
			{
				return i; // Trả về vị trí của cuốn sách có mã tương ứng
			}
		}
	}
	return -1; // Không tìm thấy cuốn sách có mã tương ứng trong bảng băm
}

//Tim kiem thong tin cua mot cuon sach khi biet so trang
int timKiemTheoSoTrang(int soTrang)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang == soTrang)
		{
			return i; // Trả về vị trí của cuốn sách có số trang tương ứng
		}
	}
	return -1; // Không tìm thấy cuốn sách có số trang tương ứng trong bảng băm
}


//Them 1 cuon sach vao bang bam
int them1cuonSachVaoBangBam(ItemType key)
{
	if (count > countMax)
	{
		printf("\nDa vuot so luong!\n");
		resize();
	}
	int vitri = hashFunction(key.sotrang);
	int index = vitri;
	int i = 1;
	while (bang[vitri].sotrang != RONG)
	{
		vitri = hashFunction(index + P(i));
		i++;
	}
	bang[vitri].sotrang = key.sotrang;
	strcpy(bang[vitri].ma, key.ma);
	strcpy(bang[vitri].ten, key.ten);
	bang[vitri].giaban = key.giaban;
	count++;
	return 1;
}



//xuất thông tin theo mã sách
int xuatThongTinTheoMa(const char* maSach)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang != RONG && bang[i].sotrang != DAXOA)
		{
			if (strcmp(bang[i].ma, maSach) == 0)
			{
				printf("Thong tin cuon sach co ma: %s\n", maSach);
				printf("Ten: %s\n", bang[i].ten);
				printf("So trang: %d\n", bang[i].sotrang);
				printf("Gia ban: %.2f\n", bang[i].giaban);
				return 1; // Xuất thành công thông tin của cuốn sách có mã tương ứng
			}
		}
	}
	return 0; // Không tìm thấy cuốn sách có mã tương ứng trong bảng băm
}


//xuat thong tin theo so trang
void xuatThongTinTheoSoTrang(int soTrang)
{
	printf("Thong tin cac cuon sach co so trang %d:\n", soTrang);
	int timThay = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i].sotrang == soTrang)
		{
			printf("Ma: %s\n", bang[i].ma);
			printf("Ten: %s\n", bang[i].ten);
			printf("So trang: %d\n", bang[i].sotrang);
			printf("Gia ban: %.2f\n", bang[i].giaban);
			printf("-------------------------\n");
			timThay = 1;
		}
	}
	if (!timThay)
	{
		printf("Khong tim thay cuon sach nao co so trang %d\n", soTrang);
	}
}


void main() {
	char file[] = "data.txt";
	int chon;
	printf("--------------MENU------------------");
	printf("\n 1. Doc file");
	printf("\n 2. xoa thong tin cuon sach dua vao so trang");
	printf("\n 3. xoa thong tin cuon sach dua vao ten");
	printf("\n 4. Xoa mot cuon sach theo ma");
	printf("\n 5. Tim kiem thong tin cua mot cuon sach khi biet ma");
	printf("\n 6. Tim kiem thong tin cua mot cuon sach khi biet so trang");
	printf("\n 7. Them mot cuon sach vao bang bam");
	printf("\n 8. Xuat thong tin cua cac cuon sach theo ma sach");
	printf("\n 9. Xuat thong tin cua cac cuon sach theo so trang");
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
		printf("Nhap so trang muon xoa: ");
		scanf("%d", &x);
		xoa(x);
		xuatFile();
	}break;
	case 3: {
		docFile(file);
		xuatFile();
		char a[50];
		printf("Nhap ten cua cuon sach can xoa: ");
		scanf("%s", a);
		int ketQuaXoa = xoaTheoTen(a);
		if (ketQuaXoa)
		{
			printf("Da xoa cuon sach co ten: %s\n", a);
		}
		else
		{
			printf("Khong tim thay cuon sach co ten: %s\n", a);
		}
		xuatFile();
	}break;
	case 4: {
		docFile(file);
		xuatFile();
		char maSachCanXoa[5];
		printf("Nhap ma cua cuon sach can xoa: ");
		scanf("%s", maSachCanXoa);
		int ketQuaXoa = xoaTheoMa(maSachCanXoa);
		if (ketQuaXoa)
		{
			printf("Da xoa cuon sach co ma: %s\n", maSachCanXoa);
		}
		else
		{
			printf("Khong tim thay cuon sach co ma: %s\n", maSachCanXoa);
		}
		xuatFile();
	}break;
	case 5: {
		docFile(file);
		xuatFile();
		char a[5];
		printf("Nhap ma cua cuon sach can tim: ");
		scanf("%s", a);
		int ketQuaTimKiem = timKiemTheoMa(a);
		if (ketQuaTimKiem != -1)
		{
			printf("Tim thay cuon sach co ma: %s\n", a);
			printf("Thong tin cuon sach:\n");
			printf("Ten: %s\n", bang[ketQuaTimKiem].ten);
			printf("So trang: %d\n", bang[ketQuaTimKiem].sotrang);
			printf("Gia ban: %.2f\n", bang[ketQuaTimKiem].giaban);
		}
		else
		{
			printf("Khong tim thay cuon sach co ma: %s\n", a);
		}
		xuatFile();
	} break;
	case 6: {
		docFile(file);
		xuatFile();
		int soTrangCanTim;
		printf("Nhap so trang cua cuon sach can tim: ");
		scanf("%d", &soTrangCanTim);
		int ketQuaTimKiem = timKiemTheoSoTrang(soTrangCanTim);
		if (ketQuaTimKiem != -1)
		{
			printf("Tim thay cuon sach co so trang: %d\n", soTrangCanTim);
			printf("Thong tin cuon sach:\n");
			printf("Ma: %s\n", bang[ketQuaTimKiem].ma);
			printf("Ten: %s\n", bang[ketQuaTimKiem].ten);
			printf("Gia ban: %.2f\n", bang[ketQuaTimKiem].giaban);
		}
		else
		{
			printf("Khong tim thay cuon sach co so trang: %d\n", soTrangCanTim);
		}
	} break;
	case 7: {
		docFile(file);
		xuatFile();
		ItemType sachMoi;
		printf("Nhap thong tin cuon sach moi:\n");
		printf("Ma cuon sach: ");
		scanf("%s", sachMoi.ma);
		printf("Ten cuon sach: ");
		scanf("%s", sachMoi.ten);
		printf("So trang: ");
		scanf("%d", &sachMoi.sotrang);
		printf("Gia ban: ");
		scanf("%f", &sachMoi.giaban);
		int ketQuaThem = insert(sachMoi);
		if (ketQuaThem)
		{
			printf("Da them cuon sach moi vao bang bam.\n");
		}
		else
		{
			printf("Khong the them cuon sach vao bang bam.\n");
		}
		xuatFile();
	}break;
	case 8: {
		docFile(file);
		xuatFile();
		char maSachCanXuat[5];
		printf("Nhap ma cua cuon sach can xuat thong tin: ");
		scanf("%s", maSachCanXuat);
		int ketQuaXuat = xuatThongTinTheoMa(maSachCanXuat);
		if (ketQuaXuat)
		{
			printf("Thong tin cuon sach co ma: %s\n", maSachCanXuat);
		}
		else
		{
			printf("Khong tim thay cuon sach co ma: %s\n", maSachCanXuat);
		}
	}break;
	case 9: {
		docFile(file);
		xuatFile();
		int soTrangCanXuat;
		printf("Nhap so trang cua cuon sach can xuat thong tin: ");
		scanf("%d", &soTrangCanXuat);
		xuatThongTinTheoSoTrang(soTrangCanXuat);
		xuatFile();
	}break;
	default:
		break;
	}
	getch();

}


