#include<stdio.h>
#include<conio.h>
#include"BST.h"
#include"asciinode.h"
#include<math.h>
typedef int ItemType;

// tao Node 
TNode* createTNode(ItemType x) {
	TNode* p = new TNode;
	if (p == NULL)
	{
		return NULL;
	}
	p->info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}

// Them Node
int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (root->info == p->info)
		return 0;
	if (p->info < root->info)
		insertTNode(root->Left, p);
	else
		insertTNode(root->Right, p);
	return 1;
}

// Tao cay rong
void initBSTree(BSTree& cay) {
	cay.root = NULL;
}

// Nhap tu ban phim
void createBSTree(BSTree& cay) {
	initBSTree(cay);
	int n;
	printf("Nhap vao so luong n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		printf("Nhap gia tri muon them thu %d: ", i);
		scanf("%d", &x);
		TNode* p = createTNode(x);
		insertTNode(cay.root, p);
	}
}

// Nhap tu file
void createBSTree_FromFile(BSTree& cay, char file[]) {
	FILE* f = fopen(file, "r+");
	initBSTree(cay);
	int n;
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		fscanf(f, "%d", &x);
		TNode* p = createTNode(x);
		insertTNode(cay.root, p);
	}
	fclose(f);
}

// Xuat Node
void showTNode(TNode* root) {
	printf("%d ", root->info);
}

// Duyet cay
void traverseNLR(TNode* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		showTNode(root);
		traverseNLR(root->Left);
		traverseNLR(root->Right);
	}
}

void traverseLNR(TNode* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		traverseLNR(root->Left);
		showTNode(root);
		traverseLNR(root->Right);
	}
}

void traverseLRN(TNode* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		traverseLRN(root->Left);
		traverseLRN(root->Right);
		showTNode(root);

	}
}

void traverseNRL(TNode* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		showTNode(root);
		traverseNRL(root->Right);
		traverseNRL(root->Left);
	}
}

void traverseRNL(TNode* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		traverseRNL(root->Right);
		showTNode(root);
		traverseRNL(root->Left);

	}
}

void traverseRLN(TNode* root) {
	if (root == NULL)
	{
		return;
	}
	else
	{
		traverseRLN(root->Right);
		traverseRLN(root->Left);
		showTNode(root);
	}
}

// Tim Node
TNode* findNode(TNode* root, ItemType x) {
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		if (root->info == x)
		{
			return root;
		}
		TNode* left = findNode(root->Left, x);
		TNode* right = findNode(root->Right, x);
		if (left != NULL)
		{
			return findNode(root->Left, x);
		}
		else
		{
			return findNode(root->Right, x);
		}
	}
}

//Ham tim nut thay the
TNode* findTNodeReplace(TNode*& p)
{ //Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
	TNode* f = p;
	TNode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q; //Lưu nút cha của q
		q = q->Left; //q qua bên trái
	}
	p->info = q->info;
	//Tìm được phần tử thế mạng cho p là q
	if (f == p) //Nếu cha của q là p
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
	//trả về nút q là nút thế mạng cho p
}

// Ham xoa
int deleteTNodeX(TNode*& root, ItemType x)
{ //Hàm xóa nút có giá trị là x
	if (root == NULL) //Khi cây rỗng
		return 0; //Xóa không thành công
	if (root->info > x)
		return deleteTNodeX(root->Left, x);
	else if (root->info < x)
		return deleteTNodeX(root->Right, x);
	else
	{
		//rootInfo = x, tìm nút thế mạng cho root
		TNode* p = root;
		if (root->Left == NULL)
		{ //khi cây con không có nhánh trái
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)
		{ //khi cây con không có nhánh phải
			root = root->Left;
			delete p;
		}
		else
		{
			/* khi cây con có cả 2 nhánh, chọn min

			của nhánh phải để thế mạng */

			TNode* q = findTNodeReplace(p);
			//Xóa nút q là nút thế mạng cho p
			delete q;
		}
		return 1; //Xóa thành công
	}
}

// Đếm số giá trị lớn hơn x, nhỏ hơn x, có giá trị trong đoạn [x, y].
int demNhoHonX(TNode* root, ItemType x) {
	if (root == NULL)
		return 0;
	int l = demNhoHonX(root->Left, x);
	int r = demNhoHonX(root->Right, x);
	if (root->info < x)
		return 1 + l + r;
	return l + r;
}

int demLonHonX(TNode* root, ItemType x) {
	if (root == NULL)
		return 0;
	int l = demLonHonX(root->Left, x);
	int r = demLonHonX(root->Right, x);
	if (root->info > x)
		return 1 + l + r;
	return l + r;
}

int demTrongDoanXY(TNode* root, int x, int y) {
	if (root == NULL)
		return 0;
	int l = demTrongDoanXY(root->Left, x, y);
	int r = demTrongDoanXY(root->Right, x, y);
	if (root->info >= x && root->info <= y)
		return  1 + l + r;
	return l + r;
}

//Tìm nút có giá trị lớn nhất, nhỏ nhất của cây.
int maxTNode(TNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int max = root->info;
	if (root->Right != NULL)
	{
		int r = maxTNode(root->Right);
		if (r > max)
		{
			max = r;
		}
	}
	return max;
}

int minTNode(TNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int min = root->info;
	if (root->Left != NULL)
	{
		int l = minTNode(root->Left);
		if (l < min)
		{
			min = l;
		}
	}
	return min;
}

//Xuất ra nội dung các nút ở mức k/nội dung các nút lá ở mức k/nội dung các nút chỉ có 1 con ở mức k /....
void xuatNutOMucK(TNode* root, int k) {
	if (root == NULL)
	{
		return;
	}
	if (k == 0)
	{
		printf("%5d", root->info);
	}
	k--;
	xuatNutOMucK(root->Left, k);
	xuatNutOMucK(root->Right, k);
}

void xuatNutLaOMucK(TNode* root, int k) {
	if (root == NULL)
	{
		return;
	}
	if (k == 0 && root->Left == NULL && root->Right == NULL)
	{
		printf("%5d", root->info);
	}
	k--;
	xuatNutLaOMucK(root->Left, k);
	xuatNutLaOMucK(root->Right, k);
}

void xuatNut1ConOMucK(TNode* root, int k) {
	if (root == NULL)
	{
		return;
	}
	if (k == 0 && ((root->Left == NULL && root->Right != NULL) || (root->Left != NULL && root->Right == NULL)))
	{
		printf("%5d", root->info);
	}
	k--;
	xuatNut1ConOMucK(root->Left, k);
	xuatNut1ConOMucK(root->Right, k);
	
}

// Đếm số nút ở mức k/số nút lá ở mức k/ số nút chỉ có 1 con ở mức k
int demNutOMucK(TNode* root, int k) {
	if (root == NULL)
	{
		return 0;
	}
	if (k == 0)
	{
		return 1;
	}
	k--;
	return demNutOMucK(root->Left, k) + demNutOMucK(root->Right, k);
}

int demNutLaOMucK(TNode* root, int k) {
	if (root == NULL)
	{
		return 0;
	}
	if (k == 0 && root->Left == NULL && root->Right == NULL)
	{
		return 1;
	}
	k--;
	return demNutLaOMucK(root->Left, k) + demNutLaOMucK(root->Right, k);
}

int demNut1ConMucK(TNode* root, int k) {
	if (root == NULL)
	{
		return 0;
	}
	if (k == 0 && ((root->Left != NULL && root->Right == NULL) || (root->Left == NULL && root->Right != NULL)))
		return 1;
	k--;
	return 	demNut1ConMucK(root->Left, k) + demNut1ConMucK(root->Right, k);

}
//Tính tổng giá trị các nút dương / giá trị các nút âm trên cây.
int tinhTongDuong(TNode* root)
{
	if (root == NULL)
		return 0;
	if (root->info > 0)
		return root->info + tinhTongDuong(root->Left) + tinhTongDuong(root->Right);
	return tinhTongDuong(root->Left) + tinhTongDuong(root->Right);
}
int tinhTongAm(TNode* root)
{
	if (!root)
		return 0;
	int l = tinhTongAm(root->Left);
	int r = tinhTongAm(root->Right);
	if (root->info < 0)
		return root->info + l + r;
	return l + r;
}
//Tìm phần tử có khoảng cách về giá trị gần nhất với phần tử x trong cây(nếu cây rỗng trả về - 1).
int minDistance(TNode* root, ItemType x)
{
	if (root == NULL) {
		return -1;
	}
	int min = root->info;
	int mindis = abs(x - min);
	while (root != NULL)
	{
		if (root->info == x)
		{
			return x;
		}
		if (mindis > abs(x - root->info))
		{
			min = root->info;
			mindis = abs(x - min);
		}
		if (x > root->info)
		{
			root = root->Right;
		}
		else 
		{
			root = root->Left;
		}
	}
	return min;
}
//Tìm phần tử có khoảng cách về giá trị xa nhất với phần tử x trong cây(nếu cây rỗng trả về - 1).
int maxDistance(TNode* root, ItemType x)
{
	if (root == NULL)
	{
		return -1;
	}
	TNode* minLeft = root;
	//Tìm nút trái nhất
	while (minLeft->Left != NULL)
	{
		minLeft = minLeft->Left;
	}
	TNode* maxRight = root;
	//Tìm nút phải nhất
	while (maxRight->Right != NULL)
	{
		maxRight = maxRight->Right;
	}
	int dis1 = abs(x - minLeft->info);
	int dis2 = abs(x - maxRight->info);
	if (dis1 > dis2)
	{
		return minLeft->info;
	}
	else
	{
		return maxRight->info;
	}
}

//Đếm số nút của cây
int demNut(TNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + demNut(root->Left) + demNut(root->Right);
	}
}

//Đếm số nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây.
bool ktraSNT(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
int demSNT(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSNT(root->info))
		return 1 + demSNT(root->Left) + demSNT(root->Right);
	return demSNT(root->Left) + demSNT(root->Right);

}

bool ktraSCP(int n)
{
	int a = (int)sqrt(n);
	return a * a == n;
}

int demSCP(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSCP(root->info))
		return 1 + demSCP(root->Left) + demSCP(root->Right);
	return demSCP(root->Left) + demSCP(root->Right);

}
bool ktraSHH(int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
		if (n % i == 0)
			sum += i;
	return sum == n;
}

int demSHH(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSHH(root->info))
		return 1 + demSHH(root->Left) + demSHH(root->Right);
	return demSHH(root->Left) + demSHH(root->Right);

}
bool ktraSTV(int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
		if (n % i == 0)
			sum += i;
	return sum > n;
}

int demSTV(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSTV(root->info))
		return 1 + demSTV(root->Left) + demSTV(root->Right);
	return demSTV(root->Left) + demSTV(root->Right);
}
bool ktraSYeu(int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
		if (n % i == 0)
			sum += i;
	return sum < n;
}

int demSYeu(TNode* root)
{
	if (!root)
		return 0;
	if (ktraSYeu(root->info))
		return 1 + demSYeu(root->Left) + demSYeu(root->Right);
	return demSYeu(root->Left) + demSYeu(root->Right);
}

//tinh tong số nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây.
int tongSNT(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSNT(root->info))
		return root->info + tongSNT(root->Left) + tongSNT(root->Right);
	return tongSNT(root->Left) + tongSNT(root->Right);

}

int tongSCP(TNode* root)
{
	if (root == NULL)
		return 0;

	if (ktraSCP(root->info))
		return root->info + tongSCP(root->Left) + tongSCP(root->Right);
	return tongSCP(root->Left) + tongSCP(root->Right);

}

int tongSHH(TNode* root)
{
	if (!root)
		return 0;
	if (ktraSHH(root->info))
		return root->info + tongSHH(root->Left) + tongSHH(root->Right);
	return tongSHH(root->Left) + tongSHH(root->Right);

}

int tongSTV(TNode* root)
{
	if (!root)
		return 0;
	if (ktraSTV(root->info))
		return root->info + tongSTV(root->Left) + tongSTV(root->Right);
	return tongSTV(root->Left) + tongSTV(root->Right);

}

int tongSYeu(TNode* root)
{
	if (!root)
		return 0;
	if (ktraSYeu(root->info))
		return root->info + tongSYeu(root->Left) + tongSYeu(root->Right);
	return tongSYeu(root->Left) + tongSYeu(root->Right);

}

//Tính tổng giá trị các nút của cây
int tinhTong(TNode* root)
{
	if (!root)
		return 0;
	return root->info + tinhTong(root->Left) + tinhTong(root->Right);
}
void xoaALL(TNode*& root)
{
	if (!root)return;
	xoaALL(root->Left);
	xoaALL(root->Right);
	delete root;
}
//Viết hàm xuất các số hoàn thiện trong cây.
void xuatSoHH(TNode* root)
{
	if (!root)
		return;
	if (ktraSHH(root->info))
		printf("%d ", root->info);
	xuatSoHH(root->Left);
	xuatSoHH(root->Right);
}

int demNodeTangThapHonK(TNode* root, int k)
{
	int count = 0;
	for (int i = 0; i < k; i++)
		count += demNutOMucK(root, i);
	return count;
}
//Đếm số lượng nút nằm ở tầng cao hơn tầng thứ k của cây.
int demNodeTangCaoHonK(TNode* root, int k)
{
	int count = 0;
	int height = tinhChieCao(root);
	for (int i = k + 1; i < height; i++)
		count += demNutOMucK(root, i);
	return count;
}

//Đếm số lượng nút lá mà thông tin tại nút đó là giá trị chẵn.
int demNodeLaChan(TNode* root)
{
	if (root == NULL)
		return 0;
	if (root->info % 2 == 0 && root->Left == NULL && root->Right == NULL)
		return 1 + demNodeLaChan(root->Left) + demNodeLaChan(root->Right);
	return demNodeLaChan(root->Left) + demNodeLaChan(root->Right);
}

//Đếm số lượng nút có đúng 1 con mà thông tin tại nút đó là số nguyên tố.
int demNode1ConSNT(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSNT(root->info) && ((root->Left != NULL && root->Right == NULL) || (root->Left == NULL && root->Right != NULL)))
		return 1 + demNode1ConSNT(root->Left) + demNode1ConSNT(root->Right);
	return demNode1ConSNT(root->Left) + demNode1ConSNT(root->Right);
}

//Đếm số lượng nút có đúng 2 con mà thông tin tại nút đó là số chính phương.
int demNode2ConSCP(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSCP(root->info) && root->Left != NULL && root->Right != NULL)
		return 1 + demNode2ConSCP(root->Left) + demNode2ConSCP(root->Right);
	return demNode2ConSCP(root->Left) + demNode2ConSCP(root->Right);
}

//Tính tổng các nút lẻ.
int tinhTongLe(TNode* root)
{
	if (root == NULL)
		return 0;
	if (root->info % 2 != 0)
		return root->info + tinhTongLe(root->Left) + tinhTongLe(root->Right);
	return tinhTongLe(root->Left) + tinhTongLe(root->Right);
}

//Tính tổng các nút lá mà thông tin tại nút đó là giá trị chẵn.
int tinhTongLaChan(TNode* root)
{
	if (root == NULL)
		return 0;
	if (root->info % 2 == 0 && root->Left == NULL && root->Right == NULL)
		return root->info + tinhTongLaChan(root->Left) + tinhTongLaChan(root->Right);
	return tinhTongLaChan(root->Left) + tinhTongLaChan(root->Right);
}

//Tính tổng các nút có đúng 1 con mà thông tin tại nút đó là so nguyên tố.
int tongNode1ConSNT(TNode* root)
{
	if (root == NULL)
		return 0;
	if (ktraSNT(root->info) && ((root->Left != NULL && root->Right == NULL) || (root->Left == NULL && root->Right != NULL)))
		return root->info + tongNode1ConSNT(root->Left) + tongNode1ConSNT(root->Right);
	return tongNode1ConSNT(root->Left) + tongNode1ConSNT(root->Right);
}

//Tính tổng các nút có đúng 2 con mà thông tin tại nút đó là số chính phương.
int tinhTong2ConSCP(TNode* root)
{
	if (root == NULL)
		return 0;
	int l = tinhTong2ConSCP(root->Left);
	int r = tinhTong2ConSCP(root->Right);
	if (ktraSCP(root->info) && root->Left && root->Right)
		return root->info + l + r;
	return l + r;
}

int tinhChieCao(TNode* root)
{
	if (root == NULL)return 0;
	int hl = tinhChieCao(root->Left);
	int hr = tinhChieCao(root->Right);
	if (hl > hr)
		return hl + 1;
	return hr + 1;
}

