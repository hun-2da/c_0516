#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다. element data;
	element data;
	struct ListNode* link;
} ListNode;
int size=0;	// list의 사이즈
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p =
		(ListNode*)malloc(sizeof(ListNode));//(1)
	p->data = value;
	// (2)
	p->link = head; //(3)
	head = p; //(4)
	return head;
}
// 노드 pre 뒤에 새로운 노드 삽입
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
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
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
		printf("메뉴\n 1)삽입\n 2)삭제\n 3)모두 출력\n 0)프로그램 종료\n입력해 주십시오: ");
		int integer_number = 0; // 삽입 숫자
		int location = 0; // 위치
		scanf_s("%d", &integer_number);
		switch (integer_number) {
		case 1:
			printf("추가할 숫자와 위치를 입력해 주십시오 : ");
			scanf_s("%d %d", &integer_number, &location);
			if (size >= location)	size++;
			else { printf("잘못된 입력값입니다. \n"); continue; }

			if (location == 0)
				head = insert_first(head, integer_number);
			else {
				move = 1;
				ListNode* p = head;
				for (int i = 0; i < location - 1; i++) { move++; p = p->link; }
				head = insert(head, p, integer_number);
			}
			printf("\n움직인 횟수는 %d\n\n", move);
			break;
		case 2:
			printf("리스트에서 삭제할 위치는 ?! :");
			scanf_s("%d", &location);
			if (size >= location)	size--;
			else { printf("잘못된 입력값입니다. \n"); continue; }

			if (location == 0) 
				head = delete_first(head);
			else {
				move = 1;
				ListNode* p = head;
				for (int i = 0; i < location - 1; i++) { move++; p = p->link; }
				if (p != NULL)
					head = delete(head, p);
			}
			printf("\n움직인 횟수는 %d\n\n", move);
			break;
		case 3: print_list(head); break;
		case 0: printf("프로그램이 종료됩니다. "); return 0;
		default:
			printf("잘못된 입력값입니다.\n");
		}
	}
}
