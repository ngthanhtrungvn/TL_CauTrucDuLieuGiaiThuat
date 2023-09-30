#include<stdio.h>
#include<conio.h>
#ifndef hihi
#define hihi
struct Word {
	char word[101];
	char mean[101];
	int soluong;
	float thoiLuong;
};
typedef Word ItemType;
struct TNode
{
	ItemType Info;
	TNode* Left;
	TNode* Right;
};

struct BSTree
{
	TNode* root;
};
TNode* createTNode(ItemType x);
void createBSTree_FromFile(BSTree& cay, char* filename);
int insertTNode(TNode*& root, TNode* p);
void initBSTree(BSTree& cay);
int deleteTNode(TNode*& root, ItemType x);
void traveLNR(TNode* root);
void nhapTD(Word& W);
void traNghia(TNode* root, char* en);
void xoaALL(TNode*& root);
void chinhSuaNghia(TNode*& root, Word w);

#endif // !hihi
