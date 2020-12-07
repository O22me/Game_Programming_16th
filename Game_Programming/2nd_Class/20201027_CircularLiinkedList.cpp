#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
struct Node {
	element data;
	Node *next;
};
Node *AllocNewNode(element data) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void PrintList(Node *head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	else { //한 개 이상의 노드 존재
		printf("*%d -> ", head->data); //for문 구동을 위한 head 처리
		for (Node *curr = head->next; curr != head; curr = curr->next) {
			printf("%d -> ", curr->data);
		}
		printf("head(*%d)\n", head->data);
	}
}
Node *FindNodeData(Node *head, element data) {
	if (head->data == data) return head; //for문 구동을 위해서 head처리
	else {
		for (Node *curr = head->next; curr != head; curr = curr->next) {
			if (curr->data == data) return curr;
		}
		return NULL;
	}
}
void InsertNodeHead(Node *head, element data) { //head앞에 노드(data) 생성 후 head 재지정
	if (head == NULL) { //첫 노드 생성
		Node *newnode = AllocNewNode(data);
		head = newnode;
		head->next = newnode;
	}
	else {
		Node *newnode = AllocNewNode(data);
		Node *forwardHead = head->next;
		while (forwardHead->next != head) {
			forwardHead = forwardHead->next;
		}
		newnode->next = head;
		forwardHead->next = newnode;
		head = newnode;
	}
}
void InsertNodeData(Node *head, element data, element insert) { //노드(data)뒤에 새로운 노드(insert)
	Node *foundDataNode = FindNodeData(head, data); //해당 노드(data) 반환
	if (foundDataNode == NULL) {
		printf("No matching data node.\n");
		return;
	}
	else {
		Node *newnode = AllocNewNode(insert);
		newnode->next = foundDataNode->next;
		foundDataNode->next = newnode;
	}
}
void DeleteNodeHead(Node *head) { //head가 가리키는 노드 삭제
	if (head == NULL) {
		printf("List is empty.\n");
	}
	if (head == head->next) { //노드가 한 개
		free(head);
		head = NULL;
	}
	else { //노드가 2개 이상
		Node *remover = head;
		Node *forwardHead = head->next;
		while (forwardHead->next != head) {
			forwardHead = forwardHead->next;
		}
		head = head->next;
		forwardHead->next = head;
	}
}
void DeleteNodeData(Node *head, element data) {
	Node *foundDataNode = FindNodeData(head, data);
	if (foundDataNode == NULL) { //노드가 없거나 일치하는 노드가 없는 경우
		printf("No matching data node.\n");
		return;
	}
	else { //삭제할 노드(data) 존재
		DeleteNodeHead(foundDataNode);
	}
}
void DeleteList(Node *head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	else { //노드 최소 한개 이상
		int ListLength = 1;
		for (Node *count = head->next; count != head; count = count->next) {
			ListLength++;
		}
		for (int i = 0; i < ListLength; i++) {
			DeleteNodeHead(head);
		}
	}
}
int main(void) {
	Node *head = NULL;

	PrintList(head);

	InsertNodeHead(head, 10);
	InsertNodeHead(head, 20);
	InsertNodeHead(head, 30);

	PrintList(head);

	DeleteNodeHead(head);
	DeleteNodeHead(head);
	DeleteNodeHead(head);

	PrintList(head);

	InsertNodeHead(head, 10);
	InsertNodeData(head, 10, 20);
	InsertNodeData(head, 20, 30);

	PrintList(head);

	DeleteList(head);

	PrintList(head);
	return 0;
}