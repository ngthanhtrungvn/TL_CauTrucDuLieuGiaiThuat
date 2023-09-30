//#include<stdio.h>
//#include<conio.h>
//#include<random>
//#include<time.h>
//typedef int ItemType;
//struct TNode
//{
//	ItemType Info;
//	TNode* Left;
//	TNode* Right;
//};
//struct BTree
//{
//	TNode* Root;
//};
//void initBTree(BTree& bt)
//{
//	bt.Root = NULL;
//}
//TNode* createTNode(ItemType x)
//{
//	TNode* p = new TNode;
//	if (!p) return NULL;
//	p->Info = x;
//	p->Left = NULL;
//	p->Right = NULL;
//	return p;
//}
//int insertTNode(TNode*& root, TNode* p)
//{
//	if (p == NULL)
//		return 0; //Thực hiện không thành công
//	if (root == NULL)
//	{ //Cây rỗng, nên thêm vào gốc
//		root = p;
//		return 1; //Thực hiện thành công
//	}
//	if (root->Info == p->Info)
//		return 0; //Bị trùng nút
//	if (p->Info < root->Info)
//		insertTNode(root->Left, p); //Them trai
//	else
//		insertTNode(root->Right, p); //Them phai
//	return 1; //Thực hiện thành công
//}
////Tạo cây NP bằng 3 cách (Cách 1: Cho trước 1 mảng a có n phần
////tử, hãy tạo một cây NP có n nút, mỗi nút lưu 1 phần tử của mảng.
////Cách 2: Nhập liệu từ bàn phím.Cách 3 : Tạo ngẫu nhiên tự
////động).
//void nhapMang(int a[], int n)
//{
//
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 100;
//	}
//
//}
//void caua_1(TNode*& root, int a[], int n)
//{
//	nhapMang(a, n);
//	for (int i = 0; i < n; i++)
//	{
//		insertTNode(root, createTNode(a[i]));
//	}
//}
//void caua_2(TNode*& root, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ItemType x;
//		printf("Nhap node %d:", i + 1);
//		scanf("%d", &x);
//		insertTNode(root, createTNode(x));
//	}
//}
//void caua_3(TNode*& root, int n)
//{
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		insertTNode(root, createTNode(rand() % 100));
//	}
//}
////Duyệt cây NP bằng 6 cách: traverseNLR, traverseLNR,
////traverseLRN, traverseNRL, traverseRNL, traverseRLN.
//void traverseNLR(TNode* root)
//{
//	if (!root) return;
//	printf("%5d", root->Info);
//	traverseNLR(root->Left);
//	traverseNLR(root->Right);
//}
//void traverseNRL(TNode* root)
//{
//	if (!root) return;
//	printf("%5d", root->Info);
//	traverseNRL(root->Right);
//	traverseNRL(root->Left);
//}
//void traverseRLN(TNode* root)
//{
//	if (!root) return;
//	traverseRLN(root->Right);
//	traverseRLN(root->Left);
//	printf("%5d", root->Info);
//}
//void traverseLRN(TNode* root)
//{
//	if (!root) return;
//	traverseLRN(root->Left);
//	traverseLRN(root->Right);
//	printf("%5d", root->Info);
//}
//void traverseLNR(TNode* root)
//{
//	if (!root) return;
//	traverseLNR(root->Left);
//	printf("%5d", root->Info);
//	traverseLNR(root->Right);
//}
//void traverseRNL(TNode* root)
//{
//	if (!root) return;
//	traverseRNL(root->Right);
//	printf("%5d", root->Info);
//	traverseRNL(root->Left);
//}
////Đếm số nút trên cây.
//int countTNode(TNode* root)
//{
//	if (!root)return 0;
//	return 1 + countTNode(root->Left) + countTNode(root->Right);
//}
////Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?
//TNode* findTNode(TNode* root, ItemType x)
//{
//	if (!root)return NULL;
//	if (root->Info == x)
//		return root;
//	if (root->Info > x)
//		return findTNode(root->Left, x);
//	return findTNode(root->Right, x);
//}
////Liệt kê các nút có giá trị có lớn hơn x.
//void caug(TNode* root, ItemType x)
//{
//	if (!root) return;
//	if (root->Info > x)
//		printf("%4d", root->Info);
//	caug(root->Left, x);
//	caug(root->Right, x);
//
//}
////Thực hiện một số thao tác xử lý tính toán trên cây như : Đếm số
////nút trên cây / số nút lá / số nút có 1 con / số nút có 2 con / ..., Tính
////tổng các nút trên cây / tổng nút lá / tổng nút có 1 con / tổng nút có
////2 con / ..., tính chiều cao, ...
//int countTNodeLeaf(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = countTNodeLeaf(root->Left);
//	int nr = countTNodeLeaf(root->Right);
//	if (!root->Left && !root->Right)
//		return 1 + nl + nr;
//	return nl + nr;
//}
//int soNut1Con(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = soNut1Con(root->Left);
//	int nr = soNut1Con(root->Right);
//	if ((!root->Left && root->Right) || (root->Left && !root->Right))
//		return 1 + nl + nr;
//	return nl + nr;
//
//}
//int soNut2Con(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = soNut2Con(root->Left);
//	int nr = soNut2Con(root->Right);
//	if (root->Left && root->Right)
//		return 1 + nl + nr;
//	return nl + nr;
//
//}
//int sumTNode(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = sumTNode(root->Left);
//	int nr = sumTNode(root->Right);
//	return root->Info + nl + nr;
//
//}
//int sumTNodeLeaf(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = sumTNodeLeaf(root->Left);
//	int nr = sumTNodeLeaf(root->Right);
//	if (!root->Left && !root->Right)
//		return root->Info + nl + nr;
//	return nl + nr;
//}
//int tongNut1Con(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = tongNut1Con(root->Left);
//	int nr = tongNut1Con(root->Right);
//	if ((!root->Left && root->Right) || (root->Left && !root->Right))
//		return root->Info + nl + nr;
//	return nl + nr;
//
//}
//int tongNut2Con(TNode* root)
//{
//	if (!root)
//		return 0;
//	int nl = tongNut2Con(root->Left);
//	int nr = tongNut2Con(root->Right);
//	if (root->Left && root->Right)
//		return root->Info + nl + nr;
//	return nl + nr;
//}
//int tinhChieuCao(TNode* root)
//{
//	if (!root)
//		return 0;
//	int hl = tinhChieuCao(root->Left);
//	int hr = tinhChieuCao(root->Right);
//	if (hl > hr)
//		return hl + 1;
//	return hr + 1;
//}
//void main()
//{
//	BTree bt;
//	initBTree(bt);
//	int n, a[100];
//	printf("Nhap so node :");
//	scanf("%d", &n);
//	caua_2(bt.Root, n);
//	traverseNLR(bt.Root);
//	printf("\nNut la:%d", maxTNode(bt.Root));
//	getch();
//}
//
