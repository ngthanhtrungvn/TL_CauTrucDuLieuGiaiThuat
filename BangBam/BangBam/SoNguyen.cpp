//#include<conio.h>
//#include<stdio.h>
//
//struct HashNode
//{
//	int key;
//	HashNode* next;
//};
//
//typedef HashNode* NodePtr;
//int MAXSIZE = 7;
//NodePtr* bang;
//int countNode = 0;
//double threshold = 0.6;
//int countMax = MAXSIZE * threshold;
//
//int HashFunction(int key) {
//	return key % MAXSIZE;
//}
//
//HashNode* createHashNode(int x) {
//	HashNode* p = new HashNode;
//	if (p == NULL)
//	{
//		return NULL;
//	}
//	p->key = x;
//	p->next = NULL;
//	return p;
//}
//
//void resize()
//{
//	int cu = MAXSIZE;
//	MAXSIZE = MAXSIZE * 2;
//	countMax = MAXSIZE * threshold;
//	NodePtr* bangMoi = new NodePtr[MAXSIZE];
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		bangMoi[i] = NULL;
//	}
//
//	for (int i = 0; i < cu; i++)
//	{
//		if (bang[i] != NULL)
//		{
//			while (bang[i] != NULL) {
//				//lay phan tu dau cua bang[i]
//				int key = bang[i]->key;
//				//them phan tu vua lay vao bang moi theo dung cach
//				int vt = HashFunction(key);
//				HashNode* p = createHashNode(key);
//				p->next = bangMoi[vt];
//				bangMoi[vt] = p;
//				// xoa phan tu dau o bang[i]
//				p = bang[i];
//				bang[i] = bang[i]->next;
//				delete p;
//			}
//		}
//	}
//	delete bang;
//	bang = bangMoi;
//}
//
//void insert(int key)
//{
//	if (countNode > countMax)
//	{
//		printf("\nDa vuot so luong!\n");
//		resize();
//	}
//	int vt = HashFunction(key);
//	HashNode* p = createHashNode(key);
//	if (p == NULL)
//	{
//		return;
//	}
//	if (bang[vt] == NULL)
//	{
//		bang[vt] = p;
//	}
//	else
//	{
//		p->next = bang[vt];
//		bang[vt] = p;
//	}
//	countNode++;
//}
//
//void initBucket()
//{
//	bang = new NodePtr[MAXSIZE];
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		bang[i] = NULL;
//	}
//}
//
//void docFile(char file[]) {
//	initBucket();
//	FILE* f = fopen(file, "r+");
//	int n;
//	fscanf(f, "%d", &n);
//	char c;
//	fscanf(f, "%c", &c);
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		fscanf(f, "%d\n", &x);
//		HashNode* p = createHashNode(x);
//		insert(x);
//	}
//
//	fclose(f);
//}
//
//void XuatFile()
//{
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		if (bang[i] == NULL)
//		{
//			printf("bucket[%d]:\n", i);
//		}
//		else
//		{
//			printf("bucket[%d]: ", i);
//			for (HashNode* p = bang[i]; p != NULL; p = p->next)
//			{
//				printf("%d ", p->key);
//			}
//			printf("\n");
//		}
//	}
//}
//
//NodePtr search(int k)
//{
//	int b = HashFunction(k);
//	NodePtr p = bang[b];
//	while (p != NULL && p->key != k) {
//		p = p->next;
//	}
//	return p;
//}
//
//
//int IsEmptyBucket(int b) {
//	return(bang[b] == NULL ? 1 : 0);
//}
//
//int IsEmpty()
//{
//	for (int b = 0; b < MAXSIZE; b++)
//		if (bang[b] != NULL) return 0;
//	return 1;
//}
//
//int Pop(int b) {
//	if (bang[b] == NULL) {
//		return 0;
//	}
//	HashNode* p = bang[b];
//	bang[b] = p->next;
//	delete p;
//	countNode--;
//}
//
//int DeleteAfter(NodePtr p) {
//	NodePtr q;
//	int k;
//	if (p == NULL || p->next == NULL) {
//		printf("\n Khong xoa Node duoc!");
//		return 0;
//	}
//	q = p->next; 
//	k = q->key;
//	p->next = q->next; 
//	delete q;
//	return k;
//	countNode--;
//}
//
//int Remove(int k) {
//	NodePtr q, p;
//	int b = HashFunction(k); 
//	p = bang[b];
//	while (p != NULL && p->key != k) {
//		q = p; 
//		p = p->next;
//	}
//	if (p == NULL)
//		printf("\n khong co nut co khoa %d", k);
//	else {
//		countNode--;
//		if (p == bang[b])
//			return Pop(b);
//		else
//			return DeleteAfter(q); //xoa nut
//	}
//}
//
////xóa bucket trong bảng băm
//void ClearBucket(int b) {
//	NodePtr p, q; //q la nut truoc,p la nut sau
//	q = NULL; 
//	p = bang[b];
//	while (p != NULL) {
//		q = p; 
//		p = p->next; 
//		delete q;
//	}
//	bang[b] = NULL; //khoi dong lai bucket b
//}
//
////Phép toán xóa tất cả các phần tử trong bảng băm.
//void ClearAll() {
//	for (int b = 0; b < MAXSIZE; b++) 
//		ClearBucket(b);
//}
//
//void main() {
//	char file[] = "data1.txt";
//	int chon;
//	printf("------------------------MENU------------------------");
//	printf("\n 1. Doc file");
//	printf("\n 2. Them 1 phan tu co khoa k");
//	printf("\n 3. Tim node chua khoa k trong bang bam");
//	printf("\n 4. Xoa 1 nut o dau bucket");
//	printf("\n 5. Xoa 1 nut ngay sau nut p");
//	printf("\n 6. Xoa khoa k trong bang bam");
//	printf("\n 7. Xoa 1 bucket trong bang bam");
//	printf("\n 8. Xoa tat ca phan tu trong bang bam");
//	printf("\n Moi ban chon bai: ");
//	scanf("%d", &chon);
//	switch (chon)
//	{
//	case 1: {
//		docFile(file);
//		XuatFile();
//	}break;
//	case 2: {
//		docFile(file);
//		XuatFile();
//		int x;
//		printf("Moi ban nhap x: ");
//		scanf("%d", &x);
//		insert(x);
//		XuatFile();
//	}break;
//	case 3: {
//		docFile(file);
//		XuatFile();
//		int x;
//		printf("Nhap x can tim: ");
//		scanf("%d", &x);
//		HashNode* node = search(x);
//		if (node != NULL) {
//			printf("Tim thay %d trong bucket\n", x);
//		}
//		else {
//			printf("Khong tim thay %d trong bucket\n", x);
//		}
//	}break;
//	case 4: {
//		docFile(file);
//		XuatFile();
//		int x;
//		printf("Nhap bucket can xoa: ");
//		scanf("%d", &x);
//		Pop(x);
//		XuatFile();
//	}break;
//	case 5: {
//		docFile(file);
//		XuatFile();
//		int x;
//		printf("Nhap nut p: ");
//		scanf("%d", &x);
//		HashNode* p = search(x);
//		if (p != NULL) {
//			DeleteAfter(p);
//			printf("Da xoa nut sau node p!\n");
//			XuatFile();
//		}
//		else {
//			printf("Khong tim thay khoa trong node %d\n", x);
//		}
//	}break;
//	case 6: {
//		docFile(file);
//		XuatFile();
//		int x;
//		printf("Nhap khoa k: ");
//		scanf("%d", &x);
//		Remove(x);
//		XuatFile();
//	}break;
//	case 7: {
//		docFile(file);
//		XuatFile();
//		int x;
//		printf("Nhap bucket muon xoa: ");
//		scanf("%d", &x);
//		ClearBucket(x);
//		XuatFile();
//	}break;
//	case 8: {
//		docFile(file);
//		XuatFile();
//		printf("\nBucket sau khi da xoa\n");
//		ClearAll();
//		XuatFile();
//	}break;
//	default:
//		break;
//	}
//	getch();
//}