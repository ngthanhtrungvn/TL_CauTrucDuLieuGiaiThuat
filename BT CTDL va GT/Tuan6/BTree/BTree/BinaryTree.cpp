#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;

typedef int itemType;

struct TNode
{
	itemType info;
	TNode* left;
	TNode* right;
};


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
		if(p->info == root->info)
			return 0;
		else if(p->info < root->info)
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
		int x;
		in >> x;
		TNode* p= createTNode(x);
		insert(root, p);
	}
	in.close();
}

void duyetLNR(TNode* root)
{
	if(root == NULL)
		return;
	duyetLNR(root->left);
	printf("%5d", root->info);
	duyetLNR(root->right);
}

int demNode(TNode* root)
{
	if(root == NULL)
		return 0;
	else
		return 1 + demNode(root->left) + demNode(root->right);
}


void main()
{
	TNode* root;
	taoCayTuFile(root, "data.txt");
	duyetLNR(root);
	printf("\nTong so node cua cay= %d", demNode(root));
	getch();
}