#include<stdio.h>
#include<conio.h>
typedef int ItemType;

struct Node
{
	ItemType info;
	Node* next;

};

struct SList
{
	Node* head;
	Node* tail;
};

Node* createNode(ItemType x) {
	Node* p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void initSList(SList& l) {
	l.head = l.tail = NULL;
}

void addHeadList(SList& l, Node* p) {
	if (p == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTailList(SList& l, Node* p) {
	if (p == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void createSList(SList& l) {
	initSList(l);
	int n;
	printf("Vui long nhap so phan tu muon them vao danh sach: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		printf("Vui long nhap gia tri muon them thu %d: ", i);
		scanf("%d", &x);
		Node* moi = createNode(x);
		addTailList(l, moi);
	}
}

void printList(SList l) {
	Node* p = new Node;
	/*while (i!=NULL)
	{
		printf("%5d", i->info);
		i = i->next;
	}*/
	for (p = l.head; p != NULL; p = p->next) {
		//hien thi du lieu cua tung node
		printf("%5d", p->info);
	}

}

void addHeadNodeSList(SList& l, Node* x) {
	int a;
	printf("Nhap gia tri node y: ");
	scanf("%d", &a);
	Node* y = createNode(a); //khoi tao 1 node q


	if (x == NULL || y == NULL)
	{
		return;
	}
	if (y == l.head)
	{
		addHeadList(l, x);
	}
	else
	{
		Node* g = new Node; //node g la node giu lien ket vs cai node nam truoc node q
		//duyet danh sach tu dau den cuoi de tim node q
		for (Node *k = l.head; l.head!=NULL; k = k->next)
		{
			//phat hien co ton tai trong danh sach
			if (y->info == k->info)
			{
				x->next = k; // cho node x tro den node y
				g->next = x;
			}
			else
			{
				g = k; //giu lien ket node nam truoc node q
			}
			
		}
	}
}

void deleteHeadSList(SList& l) {
	if (l.head==NULL)
	{
		return;
	}
	else
	{
		Node* p = l.head;
		l.head = p->next;
		p->next = NULL;
		delete p;
	}
}

void deleteTailSList(SList &l) {
	if (l.head == NULL)
	{
		return;
	}
	else {
		Node* p = l.tail;
		Node* q = l.head;
		while (q->next != l.tail)
		{
			q = q->next;
		}
		l.tail = q;
		l.tail->next = NULL;
		delete p;
	}

}

void deletebigx(SList& l) {
	
}


void main() {
	int bai;
	printf("b1: them phan tu moi vao cuoi danh sach\nb2: chen them phan tu co gia tri x vao truoc phan tu co gia tri y\nb3: viet ham xoa cac phan tu lon hon x trong dslk\nb4: viet ham xoa cac phan tu chan trong dslk\nb5: sap xep dslk tang dan, giam dan\nb6: cho biet trong dslk co bao nhieu so nguyen to\nb7: tinh tong cac so chinh phuong trong dslk\nb8: tim phan tu nho nhat, lon nhat trong dslk\nb9: cho biet trong dslk co bao nhieu phan tu lon hon gap doi phan tu phia sau no\nb10: tu sl tao 2 ds moi: sl1 chua cac so chan, sl2 chua cac so le\n");
	printf("Nhap bai ban muon chon: ");
	scanf("%d", &bai);
	SList ds;
	createSList(ds);
	switch (bai)
	{
	case 1: {
		int x;
		printf("Nhap phan tu muon them: ");
		scanf("%d", &x);
		Node *p = new Node;
		p = createNode(x);
		addTailList(ds, p);
		printList(ds);
		
	}	
		  break;
	case 2: {
		int x;
		printf("Nhap gia tri node x: ");
		scanf("%d", &x);
		Node* p = createNode(x);
		addHeadNodeSList(ds, p);
		printList(ds);
	}
		  break;
	case 3: {
		deleteTailSList(ds);
		printList(ds);
	}
		  break;
	default: printf("Loi");
		break;
		
	}
	getch();
}