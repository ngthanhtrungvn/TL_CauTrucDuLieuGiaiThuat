#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;

struct TUDIEN
{
	char TAnh[30];
	char TViet[30];
};

typedef TUDIEN itemType;


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
		if(strcmp(p->info.TAnh, root->info.TAnh)==0)
			return 0;
		else if(strcmp(p->info.TAnh, root->info.TAnh)<0)
			return insert(root->left, p);
		else
			return insert(root->right, p);
	}
}


void taoCayTuFile(TNode* &root, char tenFile[])
{
	root = NULL;
	fstream in;
	in.open(tenFile);
	int n;
	in >> n;
	for(int i=0; i<n; i++)
	{
		TUDIEN t;
		in >> t.TAnh;
		in.getline(t.TViet, 10);
		in.getline(t.TViet, 100);
		TNode* p= createTNode(t);
		insert(root, p);
	}
	in.close();
}

void duyetCayLNR(TNode* root)
{
	if(root == NULL)
		return;
	duyetCayLNR(root->left);
	TUDIEN t = root->info;
	printf("%s\t: %s\n", t.TAnh, t.TViet);
	duyetCayLNR(root->right);
}


//them 1 TUDIEN bat ki
int themTD(TNode* &root, TUDIEN t)
{
	TNode* p= createTNode(t);
	return insert(root, p);
}

//xoa toan bo cay
void deleteTree(TNode* root)
{
	if(root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

//xoa bat ki 1 TUDIEN
TNode* findX(TNode* &p)
{
	TNode* f = p;
	TNode* q = p->right;
	while(q->left != NULL )
	{
		f = q;
		q = q -> left;
	}
	p -> info = q -> info;
	if(f == p)
		f -> right = q -> right;
	else
		f->left = q ->right;
	return q;
}	

int xoaTD(TNode* root, itemType x)
{
	if(root == NULL)
		return 0;
	TNode* p= createTNode(x);
	if(strcmp(root->info.TAnh, p->info.TAnh) < 0)
		xoaTD(root->left, p->info);
	else if (strcmp(root->info.TAnh, p->info.TAnh) > 0)
		xoaTD(root->right, p->info);
}


void menu()
{
	printf("1. Xuat file tudien.txt\n");
	printf("2. Them vao TUDIEN\n");
	printf("3. Xoa toan bo TUDIEN\n");
}
void main()
{
	TNode* root;
	int thoat = 0;
	int chon;
	menu();
	printf("Chon bai tap: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1:
		{
			printf("Bai tap 1\n");
			taoCayTuFile(root, "tudien.txt");
			duyetCayLNR(root);
			break;
		}
	case 2:
		{
			printf("Bai tap 2\n");
			taoCayTuFile(root, "tudien.txt");
			duyetCayLNR(root);

			TUDIEN t;
			printf("TA: ");
			scanf("%s", t.TAnh);
			printf("TV: ");
			scanf("%s", t.TViet);
			themTD(root, t);
			printf("TuDien bo sung\n");
			duyetCayLNR(root);
			break;
		}
	case 3:
		{
			printf("Bai tap 3\n");
			taoCayTuFile(root, "tudien.txt");
			duyetCayLNR(root);
			printf("Cay sau khi xoa: ");
			deleteTree(root);
			break;
		}
	case 0:
		{
			printf("Thoat chuong trinh\n");
			thoat = 1;
			break;
		}
	default: printf("Sai btap, nhap lai!");
		break;
	}while(thoat = 0);
	getch();
}

