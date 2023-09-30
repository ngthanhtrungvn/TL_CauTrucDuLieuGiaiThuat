#include<conio.h>
#include<stdio.h>
#include"asciinode.h"
#include"BST.h"
void main() {
	BTree bt;
	char file[] = "data.txt";
	int chon;
	printf("Doc file");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
		createBSTree_FromFile(bt, file);
		print_ascii_tree(bt.Root);
	}break;
	default:
		break;
	}
	getch();
}