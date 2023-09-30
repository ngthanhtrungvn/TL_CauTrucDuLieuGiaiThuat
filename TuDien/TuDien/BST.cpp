#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"BST.h"
#include"asciinode.h"

int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	else
	{
		if (strcmp(p->Info.word, root->Info.word) == 0)
			return 0;
		if (strcmp(p->Info.word, root->Info.word) < 0)
			return insertTNode(root->Left, p);
		return insertTNode(root->Right, p);
	}
}

TNode* createTNode(ItemType x)
{
	TNode* p = new TNode;
	if (p == NULL)
		return NULL;
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}

TNode* findTNodeReplace(TNode*& p)
{//Ham tim nut rp nho nhat trword cay con phai de the mang cho nut p
	TNode* f = p, * rp = p->Right;
	while (rp->Left != NULL) {
		f = rp; //Luu cha cua rp
		rp = rp->Left; //rp qua bword trai
	}
	p->Info = rp->Info; //tim duoc phan tu the mang cho p la rp
	if (f == p) //neu cha cua rp la p
		f->Right = rp->Right;
	else
		f->Left = rp->Right;
	return rp; //Tra ve nut rp la nut the mang cho p
}


//Xóa một từ bất kỳ khỏi cây, duyệt lại cây để xem kết quả.
int deleteTNode(TNode*& root, ItemType x)
{
	if (!root) return 0;
	if (strcmp(root->Info.word, x.word) > 0) //tìm bên trái
		return deleteTNode(root->Left, x);
	if (strcmp(root->Info.word, x.word) < 0) //tìm bên phải
		return deleteTNode(root->Right, x);
	TNode* p = root;
	if (!root->Left)//khi cay con khong co nhanh trai
		root = root->Right;
	else if (!root->Right)//khi cay con khong co nhanh phai
		root = root->Left;
	else
	{//khi cay con co ca 2 nhanh, chon min cua nhanh phai de the mang
		TNode* p = root;
		TNode* rp = findTNodeReplace(p);
		deleteTNode(rp, x);
	}
}

void initBSTree(BSTree& cay) {
	cay.root = NULL;
}

//Tạo cây NPTK từ 1 file text lưu từ điển Anh-Việt.
void createBSTree_FromFile(BSTree& cay, char* filename) {
	FILE* f = fopen(filename, "r+");
	initBSTree(cay);
	int n;
	fscanf(f, "%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		fscanf(f, "%[^#]# %[^#]# %d # %f\n", x.word, x.mean, &x.soluong, &x.thoiLuong);
		TNode* p = createTNode(x);
		insertTNode(cay.root, p);
	}
	fclose(f);
}

void printWord(ItemType x)
{
	printf("%s:%s:%d:%f\t", x.word, x.mean, x.soluong, x.thoiLuong);
}

//Duyệt cây NPTK để xem nội dung theo phép duyệt cây traverseLNR.
void traveLNR(TNode* root)
{
	if (!root) return;
	traveLNR(root->Left);
	printWord(root->Info);
	traveLNR(root->Right);
}

//Thêm một từ bất kỳ vào cây, duyệt lại cây để xem kết quả.
void nhapTD(Word& w)
{
	printf("\nNhap tieng anh:");
	gets_s(w.word);
	printf("Nhap tieng viet:");
	gets_s(w.mean);
}

TNode* findNode(TNode* root, ItemType x)
{
	if (!root)return NULL;
	if (strcmp(root->Info.word, x.word) == 0)
		return root;
	if (strcmp(root->Info.word, x.word) > 0)
		return findNode(root->Left, x);
	return findNode(root->Right, x);
}

//Tra cứu nghĩa của 1 từ bất kỳ.
void traNghia(TNode* root, char* word)
{
	if (!root)
		return;
	if (strcmp(root->Info.word, word) == 0)
		printf("Nghia la:%s", root->Info.mean);
	traNghia(root->Left, word);
	traNghia(root->Right, word);
}

//Xóa toàn bộ cây.
void xoaALL(TNode*& root)
{
	if (!root)return;
	xoaALL(root->Left);
	xoaALL(root->Right);
	delete root;
}

//Bổ sung hay chỉnh sủa nghĩa của 1 từ bất kỳ.
void chinhSuaNghia(TNode*& root, Word w) {
	if (!root)return;
	if (strcmp(root->Info.word, w.word) == 0)
		root->Info = w;
	if (strcmp(root->Info.word, w.word) > 0)
		chinhSuaNghia(root->Left, w);
	chinhSuaNghia(root->Right, w);
}