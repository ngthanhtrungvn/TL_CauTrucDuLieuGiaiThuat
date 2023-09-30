#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;

struct WEBSITE
{
	char ma[10];
	char ten[40];
	int nam;
	int view;
	int truyCap;
	char nD[200];
};

typedef WEBSITE itemType;
struct TNode
{
	itemType info;
	TNode* left;
	TNode* right;
};

//bien thanh node

TNode* createTNode(itemType x)
{
	TNode* p= new TNode;
	if(p==NULL)
		return NULL;
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

//chen 1 node
int insert(TNode* &root, TNode* p)
{
	if(p==NULL)
		return 0;
	if(root==NULL)
	{
		root = p;
		return 1;
	}
	else
	{
		if(strcmp(p->info.ma, root->info.ma)==0)
			return 0;
		else if(strcmp(p->info.ma, root->info.ma)<0)
			return insert(root->left, p);
		else
			return insert(root->right, p);
	}
}

//doc file
void taoCayTuFile(TNode* &root, char tenFile[])
{
	root = NULL;
	fstream in;
	in.open(tenFile);
	int n;
	in >> n;
	for(int i=0; i<n; i++)
	{
		WEBSITE w;
		in >> w.ma >> w.ten >> w.nam >> w.view >> w.truyCap;
		in.getline(w.nD, 10);
		in.getline(w.nD, 100);
		TNode* p= createTNode(w);
		insert(root, p);
	}
	in.close();
}

//duyet cay LNR
void xuatCayLNR(TNode* root)
{
	if(root == NULL)
		return;
	WEBSITE w = root->info;
	xuatCayLNR(root->left);
	printf("Ma: %5s Ten: %10s Nam: %d View: %d SLTC: %d NoiDung: %10s \n",w.ma, w.ten, w.nam, w.view, w.truyCap, w.nD);
	xuatCayLNR(root->right);
}

//xuat website co ten la React Native
void xuatCayLNRreactnative(TNode* root)
{
	if(root == NULL)
		return;
	WEBSITE w = root->info;
	xuatCayLNR(root->left);
	if(strcmp(w.nD,"reactnative")!=NULL)
	printf("Ma: %5s Ten: %10s Nam: %d View: %d SLTC: %d \nNoiDung: %10s \n",w.ma, w.ten, w.nam, w.view, w.truyCap, w.nD);
	xuatCayLNR(root->right);
}

//cho biet wibsite nao co so luong truy cap nhieu nhat
TNode* truyCapNN(TNode* root)
{
	//neu cay rong
	if(root == NULL)
		return NULL;
	TNode* maxTC= root;
	TNode* maxL= truyCapNN(root->left);
	TNode* maxR= truyCapNN(root->right);
	if(maxL==NULL && maxR==NULL)
		return maxTC;

	if(maxL != NULL)
	if(maxTC->info.truyCap < maxL->info.truyCap)
			maxTC=maxL;
	if(maxR != NULL)
	if(maxTC->info.truyCap < maxR->info.truyCap)
			maxTC=maxR;
	return maxTC;
}

//xuat 1 website
void xuatWB(TNode* root)
{
	WEBSITE w = root->info;
	printf("Ma: %5s Ten: %10s Nam: %d View: %d SLTC: %d NoiDung: %10s \n",w.ma, w.ten, w.nam, w.view, w.truyCap, w.nD);
}

//dem website nam 2018 va co so luong truy cap tren 10000
int demWB2018Tren100000(TNode* root)
{
	if(root == NULL)
		return 0;
	if(root->info.nam == 2018 && root->info.truyCap > 100000)
		return 1 + demWB2018Tren100000(root->left) + demWB2018Tren100000(root->right);
	else
		return demWB2018Tren100000(root->left) + demWB2018Tren100000(root->right);
}

//them 1 website
int themWB(TNode* &root, WEBSITE w)
{
	TNode* p= createTNode(w);
	return insert(root, p);
}

//thuc thi chuong trinh
void main()
{
	TNode* root;
	taoCayTuFile(root, "wb.txt");
	xuatCayLNR(root);

	TNode* lonNhat = truyCapNN(root);
	if(lonNhat == NULL)
		printf("Lam gi co nut nao ???\n");
	else
	{
		printf("Website co luong truy cap nhieu nhat: \n");
		xuatWB(lonNhat);
	}

	int kq= demWB2018Tren100000(root);
	printf("so website 2018 co luong truy cap tren 100000: %d", kq);

	getch();
}