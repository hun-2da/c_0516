#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�. element data;
	element data;
	struct ListNode* link;
} ListNode;
int size=0;	// list�� ������
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p =
		(ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;
	// (2)
	p->link = head; //(3)
	head = p; //(4)
}
// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	//(1)
	p->data = value; //(2)
	p -> link = pre->link; //(3)
	pre->link = p; //(4)
	return head; //(5)
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
void print_list(ListNode* head)
{
	printf("List : ");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);

	printf("\n");
}
int main(void)
{
	ListNode* head = NULL;
	while (1) {
		int move=0;
		printf("�޴�\n 1)����\n 2)����\n 3)��� ���\n 0)���α׷� ����\n�Է��� �ֽʽÿ�: ");
		int integer_number = 0; // ���� ����
		int location = 0; // ��ġ
		scanf_s("%d", &integer_number);
		switch (integer_number) {
		case 1:
			printf("�߰��� ���ڿ� ��ġ�� �Է��� �ֽʽÿ� : ");
			scanf_s("%d %d", &integer_number, &location);
			if (size >= location)	size++;
			else { printf("�߸��� �Է°��Դϴ�. \n"); continue; }

			if (location == 0)
				head = insert_first(head, integer_number);
			else {
				move = 1;
				ListNode* p = head;
				for (int i = 0; i < location - 1; i++) { move++; p = p->link; }
				head = insert(head, p, integer_number);
			}
			printf("\n������ Ƚ���� %d\n\n", move);
			break;
		case 2:
			printf("����Ʈ���� ������ ��ġ�� ?! :");
			scanf_s("%d", &location);
			if (size >= location)	size--;
			else { printf("�߸��� �Է°��Դϴ�. \n"); continue; }

			if (location == 0) 
				head = delete_first(head);
			else {
				move = 1;
				ListNode* p = head;
				for (int i = 0; i < location - 1; i++) { move++; p = p->link; }
				if (p != NULL)
					head = delete(head, p);
			}
			printf("\n������ Ƚ���� %d\n\n", move);
			break;
		case 3: print_list(head); break;
		case 0: printf("���α׷��� ����˴ϴ�. "); return 0;
		default:
			printf("�߸��� �Է°��Դϴ�.\n");
		}
	}
}