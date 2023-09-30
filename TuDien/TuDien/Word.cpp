#include<conio.h>
#include<stdio.h>
#include"asciinode.h"
#include"BST.h"
void main() {
	BSTree cay;
	char file[] = "data.txt";
	int chon;
	printf("1. Tao cay NPTK tu 1 file text luu tu dien Anh-Viet.\n2.Duyet cay NPTK de xem noi dung theo phep duyet cay traverseLNR.\n3.Them mot tu bat ky vao cay, duyet lai cay de xem ket qua.\n4.Xoa mot tu bat ky khoi cay, duyet lai cay de xem ket qua.\n5.Tra cuu nghaa cua 1 tu bat ky.\n6.Bo sung hay chinh sua nghia cua 1 tu bat ky.\n7.Xoa toan bo cay.\n");
	printf("Chon bai ban muon: ");
	scanf("%d", &chon);
	char c;
	scanf("%c", &c);
	switch (chon)
	{
	case 1: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		
	}break;
	case 2: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		traveLNR(cay.root);
		
	}break;
	case 3: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x;
		nhapTD(x);
		insertTNode(cay.root, createTNode(x));
		print_ascii_tree(cay.root);
	}break;
	case 4: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x;
		printf("Nhap tu de xoa");
		nhapTD(x);
		deleteTNode(cay.root, x);
		print_ascii_tree(cay.root);
		
	}break;
	case 5: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Nhap vao tieng anh de tra nghia:");
		char en[101];
		scanf("%s", &en);
		traNghia(cay.root, en);
		
	}break;
	case 6: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x;
		printf("Nhap vao tu can chinh sua nghia:");
		nhapTD(x);
		chinhSuaNghia(cay.root, x);
		traveLNR(cay.root);
	}break;
	case 7: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		xoaALL(cay.root);
	}break;
	default:
		break;
	}
	getch();
}