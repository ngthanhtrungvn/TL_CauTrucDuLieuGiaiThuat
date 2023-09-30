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
////kiem tra dau ngoac
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
//
//void main()
//{
//	char chuoi[50];
//	printf("Nhap vao chuoi:");
//	scanf("%s", &chuoi);
//	if (ktra(chuoi) == 1)
//		printf("Chuoi hop le");
//	else
//		printf("Chuoi khong hop le");
//	getch();
//}
