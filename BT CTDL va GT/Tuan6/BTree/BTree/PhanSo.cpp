#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;
struct PS
{
	int tu;
	int mau;
};

typedef PS itemType;
struct TNode
{
	itemType info;
	TNode* left;
	TNode* right;
};

int soSanh(PS ps1, PS ps2)
{
	if(ps1.tu*ps2.mau == ps1.mau*ps2.tu)
		return 0;
	else if((ps1.tu / (float)ps1.mau) < (ps2.tu / (float)ps2.mau))
		return -1;
	else
		return 1;
}

TNode* createTNode(itemType x)
{
	TNode* p= new TNode;
	if(p == NULL)
		return NULL;
	p->info= x;
	p->left= NULL;
	p->right= NULL;
	return p;
}

int timUCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if(a == 0)
		return b;
	while(a != b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

void toiGian(PS &ps)
{
	int uc=timUCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / uc;
	ps.mau = ps.mau / uc;
}
int insert(TNode* &root, TNode* p)
{
	if(p == NULL)
		return 0;
	if(root == NULL)
	{
		root = p;
		return 1;
	}
	else
	{
		/*if(p->info == root->info)
			return 0;
		else if(p->info < root->info)
			return insert(root->left, p);
		else
			return insert(root->right, p);*/
		if(soSanh(p->info, root->info) == 0)
			return 0;
		else if(soSanh(p->info, root->info) < 0)
			return insert(root->left, p);
		else
			return insert(root->right, p);
	}
}

void taoCayTuFile(TNode* &root, char tenFile[])
{
	root = NULL;
	ifstream in;
	in.open(tenFile);
	int n;
	in >> n;
	for(int i=0; i<n; i++)
	{
		/*int x;
		in >> x;*/
		PS x;
		in >> x.tu >> x.mau;
		TNode* p= createTNode(x);
		insert(root, p);
	}
	in.close();
}

void duyetLNR(TNode* root)
{
	if(root == NULL)
		return;
	toiGian(root->info);
	duyetLNR(root->left);
	printf(" %d/%d", root->info.tu, root->info.mau);
	duyetLNR(root->right);
	/*duyetLNR(root->left);
	printf("%5d", root->info);
	duyetLNR(root->right);*/
}
int demNode(TNode* root)
{
	if(root == NULL)
		return 0;
	else
		return 1 + demNode(root->left) + demNode(root->right);
}
int demNodeLonHon1(TNode* root)
{
	PS x;
	x.tu = 1;
	x.mau = 1;
	if(root == NULL)
		return 0;
	else if(soSanh(root->info, x) >= 0)
		return 1 + demNode(root->left) + demNode(root->right);
	else
		demNode(root->left) + demNode(root->right); //khong dem goc(root)
}
void main()
{
	TNode* root;
	taoCayTuFile(root, "data1.txt");
	duyetLNR(root);
	printf("\nPhan So lon hon 1: %d", demNodeLonHon1(root));
	getch();
}