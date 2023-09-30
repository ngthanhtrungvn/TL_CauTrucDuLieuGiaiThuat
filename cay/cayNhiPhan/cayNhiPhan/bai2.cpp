#include<stdio.h>
#include<conio.h>
#include<random>
#include<time.h>
#include<math.h>
struct PhanSo
{
	int tu;
	int mau;
};
typedef PhanSo ItemType;

struct TNode
{
	ItemType Info;
	TNode* Left;
	TNode* Right;
};
struct BTree
{
	TNode* Root;
};
void initBTree(BTree& bt)
{
	bt.Root = NULL;
}
TNode* createTNode(ItemType x)
{
	TNode* p = new TNode;
	if (!p) return NULL;
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
/// <summary>
/// 0: bang nhau
/// 1: ps1>ps2
/// -1:ps1<ps2
/// </summary>
/// <param name="x">Phan so 1</param>
/// <param name="y">Phan so 2</param>
/// <returns>int</returns>
int soSanh(ItemType x, ItemType y)
{
	float ps1 = (float)x.tu / x.mau;
	float ps2 = (float)y.tu / y.mau;
	if (ps1 > ps2)
		return 1;
	if (ps1 < ps2)
		return -1;
	return 0;
}
int soSanh(ItemType x)
{
	float ps1 = (float)x.tu / x.mau;
	float ps2 = 1;
	if (ps1 > ps2)
		return 1;
	if (ps1 < ps2)
		return -1;
	return 0;
}
ItemType tong2PS(ItemType x, ItemType y)
{
	ItemType result;
	result.tu = x.tu * y.mau + x.mau * y.tu;
	result.mau = x.mau * y.mau;
	toiGian(result);
	return result;
}

int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0; //Thực hiện không thành công
	if (root == NULL)
	{ //Cây rỗng, nên thêm vào gốc
		root = p;
		return 1; //Thực hiện thành công
	}
	if (soSanh(root->Info, p->Info) == 0)
		return 0; //Bị trùng nút
	//root>p
	if (soSanh(root->Info, p->Info) > 0)
		insertTNode(root->Left, p); //Them trai
	else
		insertTNode(root->Right, p); //Them phai
	return 1; //Thực hiện thành công
}
//Tạo cây NP bằng 3 cách (Cách 1: Cho trước 1 mảng a có n phần
//tử, hãy tạo một cây NP có n nút, mỗi nút lưu 1 phần tử của mảng.
//Cách 2: Nhập liệu từ bàn phím.Cách 3 : Tạo ngẫu nhiên tự
//động).
int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
void toiGian(ItemType& x)
{
	int ucln = UCLN(x.tu, x.mau);
	x.tu = x.tu / ucln;
	x.mau = x.mau / ucln;
}
void nhapPS(ItemType& x)
{
	printf("Nhap tu so:");
	scanf("%d", &x.tu);
	printf("Nhap mau so:");
	scanf("%d", &x.mau);
	toiGian(x);
}
void nhapPSAuto(ItemType& x)
{
	srand(time(NULL));
	x.tu = rand() % 100;
	x.mau = rand() % 100;
	toiGian(x);
}
void nhapMang(ItemType a[], int n)
{

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		nhapPS(x);
		a[i] = x;
	}

}
void caua_1(TNode*& root, ItemType a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		insertTNode(root, createTNode(a[i]));
	}
}
void caua_2(TNode*& root, int n)
{
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		printf("Nhap node %d:", i + 1);
		nhapPS(x);
		insertTNode(root, createTNode(x));
	}
}
void caua_3(TNode*& root, int n)
{
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		nhapPSAuto(x);
		insertTNode(root, createTNode(x));
	}
}
//Duyệt cây NP bằng 6 cách: traverseNLR, traverseLNR,
//traverseLRN, traverseNRL, traverseRNL, traverseRLN.
void xuatPS(ItemType x)
{
	printf("%5d/%5d\t", x.tu, x.mau);
}
void traverseNLR(TNode* root)
{
	if (!root) return;
	xuatPS(root->Info);
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
void traverseNRL(TNode* root)
{
	if (!root) return;
	xuatPS(root->Info);

	traverseNRL(root->Right);
	traverseNRL(root->Left);
}
void traverseRLN(TNode* root)
{
	if (!root) return;
	traverseRLN(root->Right);
	traverseRLN(root->Left);
	xuatPS(root->Info);

}
void traverseLRN(TNode* root)
{
	if (!root) return;
	traverseLRN(root->Left);
	traverseLRN(root->Right);
	xuatPS(root->Info);

}
void traverseLNR(TNode* root)
{
	if (!root) return;
	traverseLNR(root->Left);
	xuatPS(root->Info);

	traverseLNR(root->Right);
}
void traverseRNL(TNode* root)
{
	if (!root) return;
	traverseRNL(root->Right);
	xuatPS(root->Info);

	traverseRNL(root->Left);
}
//Thêm 1 nút là phân số p làm con trái/ phải của nút T.
int cauc_left(TNode* T, ItemType x)
{
	if (T == NULL)
		return 0; //Không tồn tại nút T
	if (T->Left != NULL)
		return 0; //Đã tồn tại nút con trái
	TNode* p = createTNode(x);
	T->Left = p;
	return 1;
}
int cauc_right(TNode* T, ItemType x)
{
	if (T == NULL)
		return 0; //Không tồn tại nút T
	if (T->Right != NULL)
		return 0; //Đã tồn tại nút con phair
	TNode* p = createTNode(x);
	T->Right = p;
	return 1;
}
//Đếm số lượng những phân số lớn hơn 1.
int soNodeLonHon1(TNode* root)
{
	if (!root)
		return 0;
	int nl = soNodeLonHon1(root->Left);
	int nr = soNodeLonHon1(root->Right);

	if (soSanh(root->Info) > 0)
		return 1 + nl + nr;
	return nl + nr;
}
//Tìm kiếm trên cây có nút nào có giá trị bằng với phân số x hay không ?
TNode* findTNode(TNode* root, ItemType x)
{
	if (!root)return NULL;
	if (soSanh(root->Info, x) == 0)
		return root;
	if (soSanh(root->Info, x) > 0)
		return findTNode(root->Left, x);
	return findTNode(root->Right, x);
}
//Tính tổng các phân số.
ItemType tongPS(TNode* root)
{
	if (!root)
	{
		ItemType x;
		x.tu = 0;
		x.mau = 1;
		return x;
	}
	ItemType nl = tongPS(root->Left);
	ItemType nr = tongPS(root->Right);
	return tong2PS(root->Info, tong2PS(nl, nr));
}
//Tìm phân số nhỏ nhất/ lớn nhất.(NPTK)
ItemType PSMax(TNode* root)
{
	if (root->Right == NULL)
		return root->Info;
	return PSMax(root->Right);
}
ItemType PSMin(TNode* root)
{
	if (root->Left == NULL)
		return root->Info;
	return PSMin(root->Left);
}
//Liệt kê các phân số có tử số lớn hơn mẫu số / nhỏ hơn mẫu số.
void PSTuLonMau(TNode* root)
{
	if (!root)
		return;
	if (root->Info.tu > root->Info.mau)
		xuatPS(root->Info);
	PSTuLonMau(root->Right);
	PSTuLonMau(root->Left);
}
void PSTuNhoMau(TNode* root)
{
	if (!root)
		return;
	if (root->Info.tu < root->Info.mau)
		xuatPS(root->Info);
	PSTuNhoMau(root->Right);
	PSTuNhoMau(root->Left);
}
//d.Liệt kê các phân số có tử số và mẫu số đồng thời là số nguyên tố.
bool ktraSNT(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
void PSTuMauSNT(TNode* root)
{
	if (!root)return;
	if (ktraSNT(root->Info.tu) && ktraSNT(root->Info.mau))
		xuatPS(root->Info);
	PSTuMauSNT(root->Left);
	PSTuMauSNT(root->Right);
}
//Liệt kê các phân số ở mức k (k được nhập từ bàn phím).
void PSMucK(TNode* root, int k)
{
	if (!root)
		return;
	if (k == 0)
		xuatPS(root->Info);
	k--;
	PSMucK(root->Left, k);
	PSMucK(root->Right, k);
}
//Đếm số lượng phân số ở mức k (k được nhập từ bàn phím).
int demPSMucK(TNode* root, int k)
{
	if (!root)
		return 0;
	if (k == 0)
		return 1;
	k--;
	return demPSMucK(root->Left, k) + demPSMucK(root->Right, k);
}
//Tong số lượng phân số ở mức k (k được nhập từ bàn phím).
ItemType tongPSMucK(TNode* root, int k)
{
	if (!root)
	{
		ItemType x;
		x.tu = 0;
		x.mau = 1;
		return x;
	}
	if (k == 0)
		return root->Info;
	k--;
	return tong2PS(tongPSMucK(root->Left, k), tongPSMucK(root->Right, k));
}
//Liệt kê các nút có giá trị có lớn hơn x.
void caug(TNode* root, ItemType x)
{
	if (!root) return;
	if (root->Info > x)
		printf("%4d", root->Info);
	caug(root->Left, x);
	caug(root->Right, x);

}
//Thực hiện một số thao tác xử lý tính toán trên cây như : Đếm số
//nút trên cây / số nút lá / số nút có 1 con / số nút có 2 con / ..., Tính
//tổng các nút trên cây / tổng nút lá / tổng nút có 1 con / tổng nút có
//2 con / ..., tính chiều cao, ...
int countTNodeLeaf(TNode* root)
{
	if (!root)
		return 0;
	int nl = countTNodeLeaf(root->Left);
	int nr = countTNodeLeaf(root->Right);
	if (!root->Left && !root->Right)
		return 1 + nl + nr;
	return nl + nr;
}
int soNut1Con(TNode* root)
{
	if (!root)
		return 0;
	int nl = soNut1Con(root->Left);
	int nr = soNut1Con(root->Right);
	if ((!root->Left && root->Right) || (root->Left && !root->Right))
		return 1 + nl + nr;
	return nl + nr;

}
int soNut2Con(TNode* root)
{
	if (!root)
		return 0;
	int nl = soNut2Con(root->Left);
	int nr = soNut2Con(root->Right);
	if (root->Left && root->Right)
		return 1 + nl + nr;
	return nl + nr;

}
int sumTNode(TNode* root)
{
	if (!root)
		return 0;
	int nl = sumTNode(root->Left);
	int nr = sumTNode(root->Right);
	return root->Info + nl + nr;

}
int sumTNodeLeaf(TNode* root)
{
	if (!root)
		return 0;
	int nl = sumTNodeLeaf(root->Left);
	int nr = sumTNodeLeaf(root->Right);
	if (!root->Left && !root->Right)
		return root->Info + nl + nr;
	return nl + nr;
}
int tongNut1Con(TNode* root)
{
	if (!root)
		return 0;
	int nl = tongNut1Con(root->Left);
	int nr = tongNut1Con(root->Right);
	if ((!root->Left && root->Right) || (root->Left && !root->Right))
		return root->Info + nl + nr;
	return nl + nr;

}
int tongNut2Con(TNode* root)
{
	if (!root)
		return 0;
	int nl = tongNut2Con(root->Left);
	int nr = tongNut2Con(root->Right);
	if (root->Left && root->Right)
		return root->Info + nl + nr;
	return nl + nr;
}
int tinhChieuCao(TNode* root)
{
	if (!root)
		return 0;
	int hl = tinhChieuCao(root->Left);
	int hr = tinhChieuCao(root->Right);
	if (hl > hr)
		return hl + 1;
	return hr + 1;
}
void main()
{
	BTree bt;
	initBTree(bt);
	int n, a[100];
	printf("Nhap so node :");
	scanf("%d", &n);
	caua_2(bt.Root, n);
	traverseNLR(bt.Root);
	printf("\nNut la:%d", maxTNode(bt.Root));
	getch();
}

