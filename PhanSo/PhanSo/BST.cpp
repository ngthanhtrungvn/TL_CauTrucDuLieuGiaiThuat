#include<stdio.h>
#include<string.h>
#include<math.h>
#include"BST.h"
#include"asciinode.h"

void initBTree(BTree& bt)
{
	bt.Root = NULL;
}

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
void toiGian(ItemType& x)
{
	int ucln = UCLN(x.tu, x.mau);
	x.tu = x.tu / ucln;
	x.mau = x.mau / ucln;
}
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

TNode* createTNode(ItemType x) {
	TNode* p = new TNode;
	if (p == NULL)
	{
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
void createBSTree_FromFile(BTree& cay, char filename[]) {
	FILE* f = fopen(filename, "r+");
	initBTree(cay);
	int n;
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		fscanf(f, "%d", &x.tu);
		fscanf(f, "%d", &x.mau);
		toiGian(x);
		TNode* p = createTNode(x);
		insertTNode(cay.Root, p);
	}
	fclose(f);
}
void xuatPS(ItemType x)
{
	printf("%5d/%5d\t", x.tu, x.mau);
}
void LNR(TNode* root)
{
	if (!root)
		return;
	LNR(root->Left);
	xuatPS(root->Info);
	LNR(root->Right);
}


TNode* findTNodeReplace(TNode*& p)
{ //Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
	TNode* f = p;
	TNode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q; //Lưu nút cha của q
		q = q->Left; //q qua bên trái
	}
	p->Info = q->Info;
	//Tìm được phần tử thế mạng cho p là q
	if (f == p) //Nếu cha của q là p
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
	//trả về nút q là nút thế mạng cho p
}
//Xóa một phân số x trên cây.
//===========================================
int deleteTNodeX(TNode*& root, ItemType x)
{ //Hàm xóa nút có giá trị là x
	if (root == NULL) //Khi cây rỗng
		return 0; //Xóa không thành công
	if (soSanh(root->Info, x) > 0)
		return deleteTNodeX(root->Left, x);
	if (soSanh(root->Info, x) < 0)
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
//Xóa những phân số > 2 (xét theo giá trị).
void xoaPSLon2(TNode*& root)
{
	ItemType x;
	if (!root)
		return;
	xoaPSLon2(root->Right);
	xoaPSLon2(root->Left);
	if ((float)root->Info.tu / root->Info.mau > 2)
		deleteTNodeX(root, x);
}

//Xóa những phân số có mẫu số là số nguyên tố.
void xoaPSMauSNT(TNode*& root)
{
	ItemType x;
	if (!root)
		return;
	xoaPSLon2(root->Right);
	xoaPSLon2(root->Left);
	if (ktraSNT(root->Info.mau))
		deleteTNodeX(root, x);
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

void PSTuMauSNT(TNode* root)
{
	if (!root)return;
	if (ktraSNT(root->Info.tu) && ktraSNT(root->Info.mau))
		xuatPS(root->Info);
	PSTuMauSNT(root->Left);
	PSTuMauSNT(root->Right);
}
//m.Liệt kê các phân số có tử số và mẫu số đồng thời là các số
//nguyên tố.
void lkTuMauSNT(TNode* root)
{
	if (!root)
		return;
	lkTuMauSNT(root->Left);
	lkTuMauSNT(root->Right);
	if (ktraSNT(root->Info.tu) && ktraSNT(root->Info.mau))
		xuatPS(root->Info);
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
//q.Đếm có bao nhiêu phân số có cả tử số và mẫu số đều là các số
//nguyên tố.
int demPSTuMauSNT(TNode* root)
{
	if (!root)
		return 0;
	int l = demPSTuMauSNT(root->Left);
	int r = demPSTuMauSNT(root->Right);
	if (ktraSNT(root->Info.tu) && ktraSNT(root->Info.mau))
		return 1 + l + r;
	return l + r;
}
void xoaAll(TNode*& root)
{
	if (!root)
		return;
	xoaAll(root->Left);
	xoaAll(root->Right);
	delete root;
}