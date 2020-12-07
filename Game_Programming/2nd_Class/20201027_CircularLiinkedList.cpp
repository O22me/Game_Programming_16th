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
	else { //�� �� �̻��� ��� ����
		printf("*%d -> ", head->data); //for�� ������ ���� head ó��
		for (Node *curr = head->next; curr != head; curr = curr->next) {
			printf("%d -> ", curr->data);
		}
		printf("head(*%d)\n", head->data);
	}
}
Node *FindNodeData(Node *head, element data) {
	if (head->data == data) return head; //for�� ������ ���ؼ� headó��
	else {
		for (Node *curr = head->next; curr != head; curr = curr->next) {
			if (curr->data == data) return curr;
		}
		return NULL;
	}
}
void InsertNodeHead(Node *head, element data) { //head�տ� ���(data) ���� �� head ������
	if (head == NULL) { //ù ��� ����
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
void InsertNodeData(Node *head, element data, element insert) { //���(data)�ڿ� ���ο� ���(insert)
	Node *foundDataNode = FindNodeData(head, data); //�ش� ���(data) ��ȯ
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
void DeleteNodeHead(Node *head) { //head�� ����Ű�� ��� ����
	if (head == NULL) {
		printf("List is empty.\n");
	}
	if (head == head->next) { //��尡 �� ��
		free(head);
		head = NULL;
	}
	else { //��尡 2�� �̻�
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
	if (foundDataNode == NULL) { //��尡 ���ų� ��ġ�ϴ� ��尡 ���� ���
		printf("No matching data node.\n");
		return;
	}
	else { //������ ���(data) ����
		DeleteNodeHead(foundDataNode);
	}
}
void DeleteList(Node *head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	else { //��� �ּ� �Ѱ� �̻�
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