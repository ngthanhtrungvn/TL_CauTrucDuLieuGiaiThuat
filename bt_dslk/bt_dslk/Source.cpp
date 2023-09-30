#include<stdio.h>
#include<conio.h>
typedef int ItemType;
struct Node
{
	ItemType Info;
	Node* Next;
};
struct SList
{
	Node* Head;
	Node* Tail;
};

Node* createNode(int x) {
	Node* p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

void initSList(SList& l) {
	l.Head = l.Tail = NULL;
}
// Thêm node vào dslk(thêm ở đầu / giữa / cuối)

void insertTail(SList& l, Node* p) {
	if (p == NULL)
	{
		return;
	}
	if (l.Head == NULL)
	{
		l.Head = l.Tail = p;
	}
	else
	{
		l.Tail->Next = p;
		l.Tail = p;
	}
}
void insertHead(SList& l, Node* p) {
	if (p == NULL)
	{
		return;
	}
	if (l.Head == NULL)
	{
		l.Head = l.Tail = p;
	}
	else
	{
		p->Next = l.Head;
		l.Head = p;
	}

}

void themGiuaSau(SList& l, Node* q, Node* p) {
	if (p == NULL || q == NULL)
	{
		return;
	}
	else
	{
		if (q == l.Tail)
		{
			insertTail(l, p);
		}
		else
		{
			p->Next = q->Next;
			q->Next = p;
		}
	}
}

void themGiuaTruoc(SList& l, Node* q, Node* p) {
	Node* g = new Node;
	if (p == NULL || q == NULL)
	{
		return;
	}
	else
	{
		if (q == l.Head)
		{
			insertHead(l, p);
		}
		else
		{
			p->Next = q;
			g->Next = p;
		}
		g = q;
	}
}

void createSListFromFile(SList& l, const char* file) {
	initSList(l);
	int n;
	FILE* f = fopen(file, "r+");
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		fscanf(f, "%d", &x);
		Node* moi = createNode(x);
		insertTail(l, moi);
	}
	fclose(f);
}

void createSList(SList& l) {
	initSList(l);
	int n;
	printf("Vui long nhap so phan tu ban muon them vao danh sach: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		printf("Vui long nhap gia tri muon them thu %d: ", i);
		scanf("%d", &x);
		Node* moi = createNode(x);
		insertTail(l, moi);
	}
}

void printList(SList l) {
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		printf("%5d", i->Info);
	}
	printf("\n");
}



Node* findNode(SList l, ItemType x)
{
	for (Node* p = l.Head; p != NULL; p = p->Next)
		if (p->Info == x)
			return p; //Tra ve con tro co gia tri bang voi x
	return NULL; //Khong co nut nao co gia tri bang voi x
}
// 3. Xóa node trong dslk (xóa ở đầu/cuối/giữa)
void deleteHead(SList& l) {
	if (l.Head == NULL)
	{
		return;
	}
	else
	{
		Node* p = l.Head;
		l.Head = l.Head->Next;
		p->Next = NULL;
		if (l.Head == NULL)
		{
			l.Tail = NULL;
		}
		delete p;
	}
}

void deleteTail(SList& l) {
	if (l.Head == NULL)
		return;
	else
	{
		Node* p = l.Tail;
		//tim node nam ngay truoc Tail
		Node* q = l.Head;
		while (q->Next != l.Tail)
			q = q->Next;
		//cắt node Tail rồi l và xóa
		l.Tail = q;
		l.Tail->Next = NULL;
		delete p;
	}
}
int isEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;
	else
		return 0;
}
int deleteAfter(SList& sl, Node* q, int& x)
{
	if (!q || !q->Next)
		return 0;
	Node* p = q->Next;
	q->Next = p->Next;
	if (sl.Tail == p)
		sl.Tail = q;
	x = p->Info;
	delete p;
	return 1;
}
int deleteSNodeX(SList& sl, ItemType x) {
	if (isEmpty(sl) == 1) return 0; //Không thực hiện được
	Node* p = sl.Head;
	Node* q = NULL; //sẽ trỏ đến nút kế trước p
	while ((p != NULL) && (p->Info != x))
	{//vòng lặp tìm nút p chứa x, q là nút kế trước p
		q = p; p = p->Next;
	}
	if (p == NULL) return 0; //không tìm thấy phần tử có khóa x
	if (p == sl.Head) //p có khóa bằng x là nút đầu danh sách
		deleteHead(sl);
	else //xóa nút p có khóa x nằm kế sau nút q
		deleteAfter(sl, q, x);
	return 1; //Thực hiện thành công
}
void xoaGiuaSau(SList& l, Node* q) {
	if (l.Head == NULL || q == NULL || q == l.Tail)
	{
		return;
	}
	else
	{
		if (q->Next == l.Tail)
		{
			deleteTail(l);
		}
		else
		{
			Node* p = new Node;
			q->Next = p->Next;
			p->Next = NULL;
			delete p;
		}
	}
}

// 4. Sắp xếp dslk tăng/giảm
void sortListAscending(SList& l) {
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		for (Node* j = i->Next; j != NULL; j = j->Next)
		{
			if (i->Info > j->Info)
			{
				int t = i->Info;
				i->Info = j->Info;
				j->Info = t;
			}
		}
	}
}

void sortListDescending(SList& l) {
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		for (Node* j = i->Next; j != NULL; j = j->Next)
		{
			if (i->Info < j->Info)
			{
				int t = i->Info;
				i->Info = j->Info;
				j->Info = t;
			}
		}
	}
}

// 7. Xuất các phần tử chẵn/lẻ
void xuatChan(SList l) {
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		if (i->Info % 2 == 0)
		{
			printf("%d ", i->Info);
		}
	}
}

void xuatLe(SList l) {
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		if (i->Info % 2 != 0)
		{
			printf("%d ", i->Info);
		}
	}
}
// 20. Kiểm tra dslk có tăng dần/giảm dần không?
int kTraTangDan(SList l) {
	for (Node* i = l.Head; i->Next != NULL; i = i->Next)
	{
		if (i->Info >= i->Next->Info)
		{
			return 0;
		}
	}
	return 1;
}

int kTraGiamDan(SList l) {
	for (Node* i = l.Head; i->Next != NULL; i = i->Next)
	{
		if (i->Info <= i->Next->Info)
		{
			return 1;
		}
	}
	return 0;
}


//5. Đếm số phần tử của dslk.
void demSoPhanTu(SList l) {
	int dem = 0;
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		dem++;
	}
	printf("So phan tu la: %d", dem);
}

void tinhTong(SList l) {
	int sum = 0;
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		sum += i->Info;
	}
	printf("tong la: %d", sum);
}

//8. Xuất các phần tử ở vị trí chẵn/lẻ

void xuatViTriChan(SList l) {
	int position = 0;
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		if (position % 2 == 0)
		{
			printf("%d ", i->Info);
		}
		position++;
	}
}

void xuatViTriLe(SList l) {
	int position = 0;
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		if (position % 2 != 0)
		{
			printf("%d ", i->Info);
		}
		position++;
	}
}
//9. Tìm kiếm x trên dslk 
int timX(SList l, int x) {
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		if (i->Info == x)
		{
			return 1;
		}
	}
	return 0;
}

//10. Đếm trên dslk l có bao nhiêu x.
void demX(SList l, int x) {
	int dem = 0;
	for (Node* i = l.Head; i != NULL; i = i->Next)
	{
		if (i->Info == x)
		{
			dem++;
		}
	}
	printf("Co %d gia tri", dem);
}

// 12. TÌm phần tử max/min trên dslk.
int timMax(SList l) {
	int max = l.Head->Info;
	for (Node* i = l.Head->Next; i != NULL; i = i->Next)
	{
		if (max < i->Info)
		{
			max = i->Info;
		}
	}
	return max;
}

int timMin(SList l) {
	int min = l.Head->Info;
	for (Node* i = l.Head->Next; i != NULL; i = i->Next)
	{
		if (i->Info < min)
		{
			min = i->Info;
		}
	}
	return min;
}

// 13. Tìm số chẵn nhỏ nhất trên dslk

int timChanNhoNhat(SList l) {
	Node* min = l.Head;

	for (Node* i = l.Head; i != NULL; i = i->Next)
	{

		if (i->Info % 2 == 0)
		{
			if (i->Info < min->Info)
			{
				min->Info = i->Info;
			}
		}
	}
	return min->Info;
}

// 14. Tìm số lẻ lớn nhất trên dslk.
int timLeLonNhat(SList l) {
	Node* max = l.Head;

	for (Node* i = l.Head; i != NULL; i = i->Next)
	{

		if (i->Info % 2 != 0)
		{
			if (max->Info < i->Info)
			{
				max->Info = i->Info;
			}
		}
	}
	return max->Info;
}


void addXBeforeY(SList& l, ItemType x, ItemType y) {
	if (l.Head == NULL)
	{
		return;
	}
	Node* p = createNode(x);
	if (l.Head->Info == y)
	{
		insertHead(l, p);
	}
	else
	{
		Node* i = l.Head;
		while (i->Next != NULL)
		{
			if (i->Next->Info == y)
			{
				themGiuaSau(l, i, p);
				return;
			}
			i = i->Next;
		}
	}
}
//15. Tìm số chẵn lớn nhất trong dslk, nếu dslk không có số chẵn thì trả về -1.
Node* timChanLeDau(SList sl, int check = 0)
{
	//check:0 chan,1:le
	for (Node* p = sl.Head; p != NULL; p = p->Next)
	{
		if (check == 0)
		{
			if (p->Info % 2 == 0)
				return p;
		}
		else
			if (p->Info % 2 != 0)
				return p;
	}
	return NULL;
}
int timChanLonNhat(SList sl)
{
	Node* temp = timChanLeDau(sl);
	if (temp == NULL)
		return -1;
	//check:0 chan,1:le
	for (Node* p = temp->Next; p != NULL; p = p->Next)
	{
		if (p->Info % 2 == 0 && temp->Info < p->Info)
			temp = p;
	}
	return temp->Info;
}

//16. Tìm số lẻ nhỏ nhất trong dslk, nếu dslk không có số lẻ thì trả về 0.
int timLeNhoNhat(SList sl)
{
	Node* temp = timChanLeDau(sl, 1);
	if (temp == NULL)
		return 0;
	//check:0 chan,1:le
	for (Node* p = temp->Next; p != NULL; p = p->Next)
	{
		if (p->Info % 2 != 0 && temp->Info > p->Info)
			temp = p;
	}
	return temp->Info;
}
//17. Xóa phần tử max/min của dslk
void xoaMax(SList& sl)
{
	int max = timMax(sl);
	Node* p = sl.Head;
	while (p != NULL)
	{
		Node* temp = p->Next;
		if (p->Info == max)
			deleteSNodeX(sl, max);
		p = temp;
	}
}
void xoaMin(SList& sl)
{
	int min = timMin(sl);
	Node* p = sl.Head;
	while (p != NULL)
	{
		Node* temp = p->Next;
		if (p->Info == min)
			deleteSNodeX(sl, min);
		p = temp;
	}
}
//3Xóa node trong dslk(xóa ở đầu / cuối / giữa)
int countList(SList sl)
{

	int count = 0;
	Node* p = sl.Head;
	while (p != NULL)
	{
		count++;
		p = p->Next;
	}
	return count;

}
Node* timNodeGiua(SList sl)
{
	int length = countList(sl);
	if (length == 0)
		return NULL;
	int location = length / 2;
	int count = 0;
	for (Node* p = sl.Head; p != NULL; p = p->Next)
	{
		if (count == location)
			return p;
		count++;
	}
}
void xoaNodeGiua(SList& sl)
{
	Node* p = timNodeGiua(sl);
	if (p == NULL)
		return;
	deleteSNodeX(sl, p->Info);
}
//tìm node trước phaanf tuw x
Node* timNodeTruocQ(SList sl, int x)
{
	Node* p = sl.Head;
	Node* q = NULL; //sẽ trỏ đến nút kế trước p
	while ((p != NULL) && (p->Info != x))
	{//vòng lặp tìm nút p chứa x, q là nút kế trước p
		q = p; p = p->Next;
	}
	if (p == NULL || p == sl.Head) return NULL; //không tìm thấy phần tử có khóa x
	return q;
}
void xoaTruocQ(SList& sl, Node* q)
{
	Node* temp = timNodeTruocQ(sl, q->Info);
	if (temp == NULL)
		return;
	deleteSNodeX(sl, temp->Info);
}
void main() {
	int bai;
	SList ds;
	printf("b1: Xuat thong tin cac phan tu\nb2: Them node vao dslk(dau/giua/cuoi)\nb3: Xoa node trong dslk(dau/giua/cuoi)\nb4: Sap xep dslk tang/giam\nb5: dem so phan tu cua dslk.\b6: Tinh tong cac phan tu cua dslk\nb7: Xuat cac phan tu chan/le\nb8: Xuat cac phan tu o vi tri chan/le\nb9: Tim kiem x tren dslk\nb10: dem tren dslk l co bao nhieu x.\nb11: Tim phan tu max/min tren dslk.\nb12: Tim so chan nho nhat tren dslk\nb13: Tim so le lon nhat tren dslk.\nb14: Tim so chan lon nhat trong dslk, neu dslk khong co so chan thi tra ve -1.\nb15: Tim so le nho nhat trong dslk, neu dslk khong co so le thi tra ve 0.\nb16: Xoa phan tu max/min cua dslk\nb17: Them x vao dslk sao cho x la phan tu cuc dai (lon hon cac phan tu ke no)\nb18: Tim day con dai nhat cua dslk\nb19: Kiem tra dslk co tang dan/giam dan khong?\n");
	printf("Vui long chon bai: ");
	scanf("%d", &bai);
	switch (bai)
	{
	case 1: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
	}break;
	case 2: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
		int x, y;
		printf("\nNhap gia tri muon them: ");
		scanf("%d", &x);
		insertHead(ds, createNode(x));
		printList(ds);

		createSListFromFile(ds, "input.txt");
		insertTail(ds, createNode(x));
		printList(ds);

		createSListFromFile(ds, "input.txt");
		printf("Nhap mot gia tri nut ke sau: ");
		scanf("%d", &y);
		themGiuaSau(ds, findNode(ds, y), createNode(x));
		printList(ds);


		createSListFromFile(ds, "input.txt");
		printf("\nNhap mot gia tri nut ke truoc: ");
		scanf("%d", &y);
		addXBeforeY(ds, 100, y);
		printList(ds);
	}
		  break;
	case 3: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
		int x = 1;
		Node* q = findNode(ds, x);
		if (q)
		{
			xoaTruocQ(ds, q);
			printList(ds);
		}

		/*	deleteHead(ds);
			printList(ds);

			createSListFromFile(ds, "input.txt");
			deleteTail(ds);
			printList(ds);*/

			//int y;
			//createSList(ds);
			//printf("Nhap mot gia tri nut ke sau: ");
			//scanf("%d", &y);
			//Node* o = findNode(ds, y); //tim nut Q chua gia tri Y
			//xoaGiuaSau(ds, o);
			//printList(ds);
	}
		  break;
	case 4: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
		sortListAscending(ds);
		printList(ds);

		createSListFromFile(ds, "input.txt");
		sortListDescending(ds);
		printList(ds);

	}break;
	case 5: {
		createSListFromFile(ds, "input.txt");
		demSoPhanTu(ds);
	}break;
	case 6: {
		createSListFromFile(ds, "input.txt");
		tinhTong(ds);
	}break;
	case 7: {
		createSListFromFile(ds, "input.txt");
		xuatChan(ds);
		printf("\n");
		createSListFromFile(ds, "input.txt");
		xuatLe(ds);
	}break;
	case 8: {
		createSListFromFile(ds, "input.txt");
		xuatViTriChan(ds);
		printf("\n");
		createSListFromFile(ds, "input.txt");
		xuatViTriLe(ds);
	}break;
	case 9: {
		createSListFromFile(ds, "input.txt");
		int x;
		printf("Nhap gia tri can tim: ");
		scanf("%d", &x);
		int kq = timX(ds, x);
		if (kq == 1)
		{
			printf("Co");
		}
		else
		{
			printf("Khong");
		}
	}break;
	case 10: {
		createSListFromFile(ds, "input.txt");
		int x;
		printf("Nhap gia tri ban muon tim: ");
		scanf("%d", &x);
		demX(ds, x);
	}break;
	case 11: {
		createSListFromFile(ds, "input.txt");
		int kq = timMax(ds);
		printf("Gia tri lon nhat la: %d\n", kq);
		createSListFromFile(ds, "input.txt");
		int kq1 = timMin(ds);
		printf("Gia tri nho nhat la: %d", kq1);
	}break;
	case 12: {
		createSListFromFile(ds, "input.txt");
		printf("So chan nho nhat: %d", timChanNhoNhat(ds));
	}break;
	case 13: {
		createSListFromFile(ds, "input.txt");
		printf("So le lon nhat: %d", timLeLonNhat(ds));
	}break;
	case 14: {
		createSListFromFile(ds, "input.txt");
		printf("%d", timChanLonNhat(ds));

	}break;
	case 15: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
		int result = timChanLonNhat(ds);
		if (result == -1)
			printf("khong co so chan");
		else
			printf("So chan max:%d", result);
	}break;
	case 16: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
		xoaMax(ds);
		printf("\n");
		printList(ds);

	}break;
	case 17: {

	}break;
	case 18: {

	}break;
	case 19: {

	}break;
	case 20: {
		createSListFromFile(ds, "input.txt");
		printList(ds);
		sortListAscending(ds);
		printList(ds);
		int kq = kTraTangDan(ds);
		if (kq == 1)
		{
			printf("Danh sach tang dan");
		}
		else
		{
			printf("Danh sach giam dan");
		}

		createSListFromFile(ds, "input.txt");
		sortListDescending(ds);
		printList(ds);
		int kq1 = kTraGiamDan(ds);
		if (kq1 == 0)
		{
			printf("Danh sach giam dan");
		}
		else
		{
			printf("Danh sach tang dan");
		}

	}break;
	default: printf("Vui long chon bai khac!");
		break;
	}
	getch();
}



