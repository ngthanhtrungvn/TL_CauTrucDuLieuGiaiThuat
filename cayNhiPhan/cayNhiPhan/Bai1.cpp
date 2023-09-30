#include<conio.h>
#include<stdio.h>
#include"BST.h"
#include"asciinode.h"

void main() {
	BSTree cay;
	char file[] = "data.txt";
	int chon;
	printf("1.Tao cay tu ban phim\n2.Tao cay tu file\n3.Duyet cay NPTK bang 6 cach: traverseNLR, traverseLNR, traverseLRN, traverseNRL, traverseRNL, traverseRLN.\n4.Them 1 nut co gia tri x vao cay.\n5.Tim kiem 1 nut co gia tri x tren cay hay khong.\n6.Xoa nut co gia tri x tren cay.\n7.Xuat cac phan tu theo chieu giam dan.\n8.dem so gia tri lon hon x, nho hon x, co gia tri trong doan [x, y].\n9.Tim nut co gia tri lon nhat, nho nhat cua cay.\n10.Xuat ra noi dung cac nut o muc k/noi dung cac nut la o muc k/noi dung cac nut chi co 1 con o muc k\n11.dem so nut o muc k/so nut la o muc k/ so nut chi co 1 con o muc k\n12.Tinh tong gia tri cac nut duong/ gia tri cac nut am tren cay.\n13.Tim phan tu co khoang cach ve gia tri gan nhat voi phan tu x trong cay(neu cay rong tra ve - 1).\n14.Tim phan tu co khoang cach ve gia tri xa nhat voi phan tu x trong cay(neu cay rong tra ve - 1).\n15.Dem so nut cua cay\n16.Dem so nut la so nguyen to, la so chinh phuong, la so hoan thien,la so thinh vuong, la so yeu cua cay.\n17.tinh tong nut la so nguyen to, la so chinh phuong, la so hoan thien,la so thinh vuong, la so yeu cua cay.\n18.Dem so nut cua cay\n19.Xoa toan bo danh sach.\n20.Viet ham xuat cac so hoan thien trong cay.\n21.Dem so luong nut nam o tang thap hon tang thu k cua cay.\n22.Dem so luong nut nam o tang cao hon tang thu k cua cay.\n23.Dem so luong nut la ma thong tin tai nut do la gia tri chan.\n24.Dem so luong nut co dung 1 con ma thong tin tai nut do la so nguyen to.\n25.Dem so luong nut co dung 2 con ma thong tin tai nut do la so chinh phuong.\n26.Tinh tong cac nut le.\n27.Tinh tong cac nut la ma thong tin tai nut do la gia tri chan.\n28.Tinh tong cac nut co dung 1 con ma thong tin tai nut do la so nguyen to.\n29.Tinh tong cac nut co dung 2 con ma thong tin tai nut do la so chinh phuong.");
	printf("Chon bai ban muon: ");
	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
		createBSTree(cay);
		print_ascii_tree(cay.root);
	}break;
	case 2: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
	}break;
	case 3: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		traverseNLR(cay.root);
		printf("\n");
		traverseLNR(cay.root);
		printf("\n");

		traverseLRN(cay.root);
		printf("\n");

		traverseNRL(cay.root);
		printf("\n");

		traverseRNL(cay.root);
		printf("\n");

		traverseRLN(cay.root);

	}break;
	case 4: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x;
		printf("Nhap gia tri ban muon them: ");
		scanf("%d", &x);
		insertTNode(cay.root, createTNode(x));
		print_ascii_tree(cay.root);
	}break;
	case 5: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x;
		printf("Nhap gia tri ban muon tim: ");
		scanf("%d", &x);
		if (findNode(cay.root, x))
		{
			printf("Tim thay %d trong cay", x);
		}
		else
		{
			printf("Khong tim thay %d trong cay", x);
		}
	}break;
	case 6: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x;
		printf("Nhap gia tri ban muon xoa: ");
		scanf("%d", &x);
		deleteTNodeX(cay.root, x);
		print_ascii_tree(cay.root);
	}break;
	case 7: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		traverseRNL(cay.root);
	}break;
	case 8: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		ItemType x, y;
		printf("Nhap gia tri x: ");
		scanf("%d", &x);
		printf("Nhap gia tri y: ");
		scanf("%d", &y);
		if (demLonHonX(cay.root, x))
		{
			printf("Co %d gia tri lon hon %d", demLonHonX(cay.root, x), x);
		}
		printf("\n");
		if (demNhoHonX(cay.root, x))
		{
			printf("Co %d gia tri nho hon %d", demNhoHonX(cay.root, x), x);
		}
		printf("\n");
		if (demTrongDoanXY(cay.root, x, y))
		{
			printf("Co %d gia tri trong doan tu %d den %d", demTrongDoanXY(cay.root, x, y), x, y);
		}

		print_ascii_tree(cay.root);
	}break;
	case 9: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Gia tri lon nhat la: %d\n", maxTNode(cay.root));
		printf("Gia tri nho nhat la: %d", minTNode(cay.root));

	}break;
	case 10: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		int k;
		printf("Nhap so muc k: ");
		scanf("%d", &k);
		printf("Cac nut o muc %d: ", k);
		xuatNutOMucK(cay.root, k);
		printf("\nCac nut la o muc %d: ", k);
		xuatNutLaOMucK(cay.root, k);
		printf("\nCac nut chi co 1 con o muc %d: ", k);
		xuatNut1ConOMucK(cay.root, k);
	}break;
	case 11: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		int k;
		printf("Nhap so muc k: ");
		scanf("%d", &k);
		printf("So nut o muc %d: %d ", k, demNutOMucK(cay.root, k));
		printf("\nSo nut la o muc %d: %d ", k, demNutLaOMucK(cay.root, k));
		printf("\nSo nut co 1 con o muc %d: %d ", k, demNut1ConMucK(cay.root, k));
	}break;
	case 12: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong gia tri cac nut duong: %d\n", tinhTongDuong(cay.root));
		printf("Tong gia tri cac nut am: %d", tinhTongAm(cay.root));
	}break;
	case 13: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		int x;
		printf("Nhap phan tu x: ");
		scanf("%d", &x);
		printf("phan tu co khoang cach ve gia tri gan nhat voi phan tu %d trong cay la: %d", x, minDistance(cay.root, x));
	}break;
	case 14: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		int x;
		printf("Nhap phan tu x: ");
		scanf("%d", &x);
		printf("phan tu co khoang cach ve gia tri xa nhat voi phan tu %d trong cay la: %d", x, maxDistance(cay.root, x));
	}break;
	case 15: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("So nut cua cay la: %d", demNut(cay.root));
	}break;
	case 16: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Co %d so nguyen to", demSNT(cay.root));
		printf("\nCo %d so chinh phuong", demSCP(cay.root));
		printf("\nCo %d so hoan thien", demSHH(cay.root));
		printf("\nCo %d so thinh vuong", demSTV(cay.root));
		printf("\nCo %d so yeu", demSYeu(cay.root));
	}break;
	case 17: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong so nguyen to: %d", tongSNT(cay.root));
		printf("\nTong so chinh phuong: %d", tongSCP(cay.root));
		printf("\nTong so hoan thien: %d", tongSHH(cay.root));
		printf("\nTong so thinh vuong: %d", tongSTV(cay.root));
		printf("\nTong so yeu: %d", tongSYeu(cay.root));
	}break;
	case 18: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong so nut: %d", tinhTong(cay.root));
	}break;
	case 19: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		xoaALL(cay.root);
	}break;
	case 20: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		xuatSoHH(cay.root);
	}break;
	case 21: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		int k;
		printf("Nhap muc k: ");
		scanf("%d", &k);
		printf("So luong nut nam o tang thap hon thu %d: %d",k, demNodeTangThapHonK(cay.root, k));
	}break;
	case 22: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		int k;
		printf("Nhap muc k: ");
		scanf("%d", &k);
		printf("So luong nut nam o tang cao hon thu %d: %d", k, demNodeTangCaoHonK(cay.root, k));
	}break;
	case 23: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("so luong nut la gia tri chan: %d", demNodeLaChan(cay.root));
	}break;
	case 24: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("so luong nut co 1 con ma nut do la so nguyen to: %d", demNode1ConSNT(cay.root));
	}break;
	case 25: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("so luong nut co 2 con ma nut do la so chinh phuong: %d", demNode2ConSCP(cay.root));
	}break;
	case 26: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong cac nut le: %d", tinhTongLe(cay.root));
	}break;
	case 27: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong cac nut la chan: %d", tinhTongLaChan(cay.root));
	}break;
	case 28: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong cac nut 1 con la so nguyen to: %d", tongNode1ConSNT(cay.root));
	}break;
	case 29: {
		createBSTree_FromFile(cay, file);
		print_ascii_tree(cay.root);
		printf("Tong cac nut 2 con la so chinh phuong: %d", tinhTong2ConSCP(cay.root));
	}break;
	default:
		break;
	}
	getch();
}



