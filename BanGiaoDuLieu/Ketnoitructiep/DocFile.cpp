#include<stdio.h>
#include<conio.h>
#include<string.h>

struct SinhVien
{
	char MSSV[10];
	char HoTen[25];
	int namSinh;
	int Diem;
};

typedef SinhVien ItemType;

struct HashNode
{
	ItemType key;
	HashNode* next;
};

typedef HashNode* NodePtr;

int MAXSIZE = 10;
NodePtr* bang;
int countNode = 0;
double threshold = 0.6;
int countMax = threshold * MAXSIZE;

int HashFuntion(int Key)
{
	return (Key % MAXSIZE);
}

HashNode* createHashNode(ItemType x)
{
	HashNode* p = new HashNode;
	if (p == NULL)
	{
		return NULL;
	}
	p->key = x;
	p->next = NULL;
	return p;
}

void initBucket()
{
	bang = new NodePtr[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		bang[i] = NULL;
	}
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
				//lay phan tu dau cua bang[i]
				ItemType key = bang[i]->key;
				//them phan tu vua lay vao bang moi theo dung cach
				int vt = HashFuntion(key.Diem);
				HashNode* p = createHashNode(key);
				p->next = bangMoi[vt];
				bangMoi[vt] = p;
				// xoa phan tu dau o bang[i]
				p = bang[i];
				bang[i] = bang[i]->next;
				delete p;
			}
		}
	}
	delete bang;
	bang = bangMoi;
}


void insert(ItemType key)
{
	if (countNode > countMax)
	{
		printf("\nDa vuot so luong!\n");
		resize();
	}
	int vt = HashFuntion(key.Diem);
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

HashNode* search(int key)
{
	int vt = HashFuntion(key);
	HashNode*p = bang[vt];
	while (p != NULL && p->key.Diem != key)
	{
		p = p->next;
	}
	return p;
}


//doc file
void docFile(char file[])
{
	initBucket();
	FILE* f = fopen(file, "r+");
	int n;
	fscanf(f, "%d", &n);
	char c;
	fscanf(f, "%c", &c);
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		fscanf(f, "%[^#]#%[^#]#%d#%d\n", x.MSSV, x.HoTen, &x.namSinh, &x.Diem);
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
				printf("\n%20s %20s %5d %5d\n", p->key.MSSV, p->key.HoTen, p->key.namSinh, p->key.Diem);
			}
			printf("\n");
		}
	}
}

void XuatNhomDiemGiongNhau()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bang[i] != NULL)
		{
			printf("Nhom diem %d: \n", bang[i]->key.Diem);
			for (HashNode* p = bang[i]; p != NULL; p = p->next)
			{
				printf("%20s %20s %5d %5d \n", p->key.MSSV, p->key.HoTen, p->key.namSinh, p->key.Diem);
			}
			printf("\n");
		}
	}
}

void XuatSinhVienXuatSac()
{
	int hasExcellent = 0; 
	for (int i = MAXSIZE -1 ; i>= 0; i--)
	{
		for (HashNode* p = bang[i]; p != NULL; p = p->next)
		{
			if (p->key.Diem > 90)
			{
				printf("%20s %20s %5d %5d\n", p->key.MSSV, p->key.HoTen, p->key.namSinh, p->key.Diem);
				hasExcellent = 1;
			}
		}
	}
}

//tim kiem sinh vien co diem bang x
HashNode* searchX(int key)
{
	int vt = HashFuntion(key);
	HashNode* p = bang[vt];
	while (p != NULL)
	{
		if (p->key.Diem == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL; // Return NULL if the student with the specified score is not found
}



void RemoveDiemAll(int k) {
	for (int i = 0; i < MAXSIZE; i++) {
		NodePtr q = NULL; // Previous node
		NodePtr p = bang[i]; // Current node
		while (p != NULL) {
			if (p->key.Diem == k) {
				// Node with key k found, remove it from the list
				if (q == NULL) {
					// If the node to be deleted is the first node in the bucket
					bang[i] = p->next;
					delete p;
					p = bang[i];
				}
				else {
					// Node to be deleted is not the first node in the bucket
					q->next = p->next;
					delete p;
					p = q->next;
				}
				countNode--;
			}
			else {
				// Move to the next node in the list
				q = p;
				p = p->next;
			}
		}
	}
}

HashNode* searchByMSSV(const char* mssv)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		HashNode* p = bang[i];
		while (p != NULL)
		{
			if (strcmp(p->key.MSSV, mssv) == 0)
			{
				return p;
			}
			p = p->next;
		}
	}
	return NULL; // Return NULL if the student with the specified MSSV is not found
}

int Pop(int b) {
	if (bang[b] == NULL) {
		return 0;
	}
	HashNode* p = bang[b];
	bang[b] = p->next;
	delete p;
	countNode--;
}

int DeleteAfter(NodePtr p) {
	NodePtr q;
	ItemType k;
	if (p == NULL || p->next == NULL) {
		printf("\n Khong xoa Node duoc!");
		return 0;
	}
	q = p->next;
	k = q->key;
	p->next = q->next;
	delete q;
	return k.Diem;
	countNode--;
}

int RemoveDiem(int k) {
	NodePtr q, p;
	int b = HashFuntion(k);
	p = bang[b];
	while (p != NULL && p->key.Diem != k) {
		q = p;
		p = p->next;
	}
	if (p == NULL)
		printf("\n khong co nut co khoa %d", k);
	else {
		countNode--;
		if (p == bang[b])
			return Pop(b);
		else
			return DeleteAfter(q); //xoa nut
	}
}

//xóa bucket trong bảng băm
void ClearBucket(int b) {
	NodePtr p, q; //q la nut truoc,p la nut sau
	q = NULL;
	p = bang[b];
	while (p != NULL) {
		q = p;
		p = p->next;
		delete q;
	}
	bang[b] = NULL; //khoi dong lai bucket b
}

//Phép toán xóa tất cả các phần tử trong bảng băm.
void ClearAll() {
	for (int b = 0; b < MAXSIZE; b++)
		ClearBucket(b);
}

//them sinh vien
void addStudent() {
	ItemType newStudent;

	printf("Nhap MSSV: ");
	scanf("%s", newStudent.MSSV);
	printf("Nhap Ho va Ten: ");
	scanf(" %[^\n]", newStudent.HoTen);
	printf("Nhap nam sinh: ");
	scanf("%d", &newStudent.namSinh);
	printf("Nhap diem: ");
	scanf("%d", &newStudent.Diem);

	insert(newStudent);

	printf("Sinh vien da duoc them vao bang.\n");
}

// Function to remove the first student in a specific bucket
void removeFirstStudentInBucket(int bucketIndex) {
	if (bang[bucketIndex] == NULL) {
		printf("Bucket rong.\n", bucketIndex);
		return;
	}

	NodePtr p = bang[bucketIndex];
	bang[bucketIndex] = p->next;
	delete p;
	countNode--;

	printf("xoa sinh vien dau tien trong bucket %d.\n", bucketIndex);
}

// Function to remove the student after a specific student in a given bucket
void removeStudentAfter(int bucketIndex, const char* mssv) {
	HashNode* p = bang[bucketIndex];
	while (p != NULL && strcmp(p->key.MSSV, mssv) != 0) {
		p = p->next;
	}

	if (p == NULL || p->next == NULL) {
		printf("Student with MSSV %s not found or has no student after.\n", mssv);
		return;
	}

	NodePtr q = p->next;
	p->next = q->next;
	delete q;
	countNode--;

	printf("Removed the student after MSSV %s in bucket %d.\n", mssv, bucketIndex);
}


void main()
{
	char file[] = "data.txt";
	int chon;
	printf("\n-------------------------MENU---------------------");
	printf("\n 1. Doc file");
	printf("\n 2. Xuat thong tin tat ca sinh vien theo nhom co cung diem so.");
	printf("\n 3. Liet ke danh sach sinh vien dat loai xuat sac theo thu tu diem giam dan. Biet rang sinh vien loai xuat sac la sinh vien co diem lon hon 90.");
	printf("\n 4. Xoa tat ca cac sinh vien co diem bang x");
	printf("\n 5. Tim kiem sinh vien co diem bang x");
	printf("\n 6. Tim kiem sinh vien bang MSSV ");
	printf("\n 7. Them 1 sinh vien");
	printf("\n 8. Xoa vi tri dau cua sinh vien");
	printf("\n 9. Clear 1 bucket");
	printf("\n 10. Clear All bucket");
	printf("\nMoi ban chon chuong trinh: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1:
	{
		docFile(file);
		XuatFile();
	}break;
	case 2:
	{
		docFile(file);
		XuatNhomDiemGiongNhau();
	}break;
	case 3:
	{
		docFile(file);
		XuatSinhVienXuatSac();
	}break;
	case 4: {
		docFile(file);
		XuatFile();
		int x;
		printf("Nhap x can xoa: ");
		scanf("%d", &x);
		RemoveDiemAll(x);
		XuatFile();
	}break;
	case 5: {
		docFile(file);
		XuatFile();
		int x; // the score to search for
		printf("Nhap diem can tim kiem: ");
		scanf("%d", &x);
		HashNode* result = searchX(x);

		if (result != NULL)
		{
			printf("Sinh vien co diem %d la: %s %s\n", x, result->key.HoTen, result->key.MSSV);
		}
		else
		{
			printf("Khong tim thay sinh vien co diem %d.\n", x);
		}
	}break;
	case 6: {
		docFile(file);
		XuatFile();
		char mssvToSearch[10];
		printf("Nhap MSSV can tim kiem: ");
		scanf("%9s", mssvToSearch);

		HashNode* result = searchByMSSV(mssvToSearch);

		if (result != NULL)
		{
			printf("Thong tin sinh vien co MSSV %s:\n", mssvToSearch);
			printf("Ho va ten: %s\n", result->key.HoTen);
			printf("Nam sinh: %d\n", result->key.namSinh);
			printf("Diem: %d\n", result->key.Diem);
		}
		else
		{
			printf("Khong tim thay sinh vien co MSSV %s.\n", mssvToSearch);
		}

	}break;
	case 7: {
		docFile(file);
		XuatFile();
		addStudent();
		XuatFile();
	}break;
	case 8: {
		docFile(file);
		XuatFile();
		int bucketToRemoveFrom;
		printf("Nhap vi tri can xoa: ", MAXSIZE - 1);
		scanf("%d", &bucketToRemoveFrom);
		removeFirstStudentInBucket(bucketToRemoveFrom);
		XuatFile();
	} break;
	case 9: {
		docFile(file);
		XuatFile();
		int bucketToRemove;
		printf("Enter the bucket index (0 to %d) to remove: ", MAXSIZE - 1);
		scanf("%d", &bucketToRemove);

		ClearBucket(bucketToRemove);
		XuatFile();
	}break;
	case 10: {
		docFile(file);
		XuatFile();
		ClearAll();
		XuatFile();
	}break;
	default:
		break;
	}


	getch();
}

