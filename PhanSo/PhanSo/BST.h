#ifndef hihi
#define hihi

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
void createBSTree_FromFile(BTree& cay, char filename[]);
void LNR(TNode* root);
#endif // !hihi

