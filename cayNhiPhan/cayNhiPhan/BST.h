#include<stdio.h>
#include<conio.h>
typedef int ItemType;
#ifndef hihi
#define hihi

struct TNode
{
	ItemType info;
	TNode* Left;
	TNode* Right;
};

struct BSTree
{
	TNode* root;
};

TNode* createTNode(ItemType x);
int insertTNode(TNode*& root, TNode* p);
void initBSTree(BSTree& cay);
void createBSTree(BSTree& cay);
void traverseNLR(TNode* root);
void traverseNRL(TNode* root);
void traverseLNR(TNode* root);
void traverseRNL(TNode* root);
void traverseLRN(TNode* root);
void traverseRLN(TNode* root);
void createBSTree_FromFile(BSTree& cay, char file[]);
TNode* findNode(TNode* root, ItemType x);
TNode* findTNodeReplace(TNode*& p);
int deleteTNodeX(TNode*& root, ItemType x);
int maxTNode(TNode* root);
int minTNode(TNode* root);
void xuatNutOMucK(TNode* root, int k);
void xuatNutLaOMucK(TNode* root, int k);
void xuatNut1ConOMucK(TNode* root, int k);
int demNutOMucK(TNode* root, int k);
int demNutLaOMucK(TNode* root, int k);
int demNhoHonX(TNode* root, ItemType x);
int demLonHonX(TNode* root, ItemType x);
int demTrongDoanXY(TNode* root, int x, int y);
int demNut1ConMucK(TNode* root, int k);
int tinhTongDuong(TNode* root);
int tinhTongAm(TNode* root);
int minDistance(TNode* root, ItemType x);
int maxDistance(TNode* root, ItemType x);
int demNut(TNode* root);
bool ktraSNT(int n);
int demSNT(TNode* root);
int tongSNT(TNode* root);
bool ktraSCP(int n);
int tongSCP(TNode* root);
int demSCP(TNode* root);
bool ktraSHH(int n);
int tongSHH(TNode* root);
int demSHH(TNode* root);
bool ktraSTV(int n);
int tongSTV(TNode* root);
int demSTV(TNode* root);
bool ktraSYeu(int n);
int tongSYeu(TNode* root);
int demSYeu(TNode* root);
int tinhTong(TNode* root);
void xoaALL(TNode*& root);
void xuatSoHH(TNode* root);
int demNodeLaChan(TNode* root);
int demNode1ConSNT(TNode* root);
int demNode2ConSCP(TNode* root);
int tinhTongLe(TNode* root);
int tinhTongLaChan(TNode* root);
int tongNode1ConSNT(TNode* root);
int tinhTong2ConSCP(TNode* root);
int tinhChieCao(TNode* root);
int demNodeTangThapHonK(TNode* root, int k);
int demNodeTangCaoHonK(TNode* root, int k);

#endif
