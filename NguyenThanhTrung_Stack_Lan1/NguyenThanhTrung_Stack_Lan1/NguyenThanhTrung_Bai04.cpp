//#include<stdio.h>
//#include<conio.h>
//#include<string.h>
//typedef char ItemType;
//struct StackNode
//{
//	ItemType info;
//	StackNode* next;
//};
//
//struct Stack
//{
//	StackNode* top;
//};
//
//StackNode* createStackNode(ItemType x) {
//	StackNode* p = new StackNode();
//	if (p == NULL)
//	{
//		return NULL;
//	}
//	p->info = x;
//	p->next = NULL;
//	return p;
//}
//
//void initStack(Stack &s) {
//	s.top = NULL;
//}
//
//void push(Stack &s, StackNode *p) {
//
//	//StackNode *p = createStackNode(x);
//	if (s.top == NULL)
//	{
//		s.top = p;
//	}
//	else
//	{
//		p->next = s.top;
//		s.top = p;
//	}
//}
//
//int pop(Stack &s, ItemType &x) {
//
//	if (s.top == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		StackNode* p = s.top;
//		s.top = s.top->next;
//		x = p->info;
//		p->next = NULL;
//		delete p;
//		return 1;
//	}
//}
//
//int top(Stack s, ItemType &x) {
//	if (s.top == NULL)
//	{
//		return 0;
//	}
//	x = s.top->info;
//	return 1;
//}
//
//int isEmpty(Stack s) {
//	return s.top == NULL;
//}
//
//void printStack(Stack s) {
//	for (StackNode* i = s.top; i != NULL; i = i->next)
//	{
//		printf("%5d", i->info);
//	}
//	printf("\n");
//}
//
//int ktra(char *chuoi)
//{
//	Stack s;
//	initStack(s);
//	for (int i = 0; i<strlen(chuoi); i++)
//	{
//		char c = chuoi[i];
//
//		if (c == '(' || c == '{' || c == '[')
//			push(s, createStackNode(c));
//		else
//		{
//			if (s.top == NULL)
//				return 0;
//			char x;
//			pop(s, x);
//			if (!(x == '(' && c == ')' || x == '[' && c == ']' || x == '{' && c == '}'))
//				return 1;
//		}
//	}
//	if (s.top != NULL)
//		return 0;
//	return 1;
//}
//
////kiem tra dau ngoac
//int kTraNgoac(char *bthuc)
//{
//	Stack s;
//	s.top = NULL;
//	for (int i = 0; i < strlen(bthuc); i++)
//	{
//		char c = bthuc[i];
//		if (c == '(' || c == '[' || c == '{')
//			push(s, createStackNode(c));
//		if (c == ')' || c == ']' || c == '}')
//		{
//			if (isEmpty(s))
//				return 0;
//			char cc;
//			pop(s, cc);
//			if ((cc != '(' && c == ')') || (cc != '[' && cc == ']') || (cc != '{' && cc == '}'))
//				return 0;
//		}
//	}
//	if (isEmpty(s) == 1)
//		return 1;
//	return 0;
//}
//
//
//
//void main()
//{
//	char bthuc[100];
//	printf("nhap bieu thuc can kiem tra: ");
//	flushall();
//	gets(bthuc);
//	int kq = kTraNgoac(bthuc);
//	if (kq == 1)
//	{
//		printf("Bieu thuc dung");
//	}
//	else
//	{
//		printf("Trung Lap() duoc tim thay trong bieu thuc\n");
//	}
//	getch();
//}
//
//
