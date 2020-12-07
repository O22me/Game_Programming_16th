#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
struct Node{
	element data;
	Node *prev;
	Node *next;
};

typedef struct {
	Node *head;
	Node *tail;
}NodeManager;
void InitManager(NodeManager *manager) {
	manager->head = NULL;
	manager->tail = NULL;
}
Node *AllocNewNode(element data) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
bool IsEmptyList(NodeManager *manager) {
	if (manager->head == NULL && manager->tail == NULL) {
		return true;
	}
	else return false;
}

void PrintList(NodeManager *manager) {
	if (IsEmptyList(manager)) {
		printf("List is empty.\n");
		return;
	}
	else {
		for (Node *curr = manager->head; curr != NULL; curr = curr->next) {
			printf("%d <-> ", curr->data);
		}
	}
	printf("\b\b\b\b\b     \n");
}
Node *FindNodeData(NodeManager *manager, element data) { //head���� data�� ��ġ�ϴ� ��尡 ������ ��ȯ, ������ NULL��ȯ
	for (Node *curr = manager->head; curr != NULL; curr = curr->next) {
		if (curr->data == data) {
			return curr;
		}
	}
	return NULL;
}
void InsertNodeEnd(NodeManager *manager, element data) { //�� ������ ��忡 ���ο� ���(data)�� �߰��ϴ� �Լ�
	if (IsEmptyList(manager)) { //��尡 ���� ���
		Node *newnode = AllocNewNode(data);
		manager->head = newnode;
		manager->tail = newnode;
	}
	else { //���� ��� ���� : �� ������ ��忡 �߰� 
		Node *newnode = AllocNewNode(data);
		manager->tail->next = newnode;
		newnode->prev = manager->tail;
		manager->tail = newnode;
	}
}
void InsertNodeData(NodeManager *manager, element data, element insert) { //���(data)�ڿ� ���ο� ���(insert)�� �߰��ϴ� �Լ�
	Node *foundDataNode = FindNodeData(manager, data);
	if (foundDataNode == NULL) { //data�� ��ġ�ϴ� node�� ���� ���
		printf("No matching data node.\n");
		return;
	}
	else {
		if (foundDataNode->next == NULL) { //ã�� ��尡 ������ ����� ���
			InsertNodeEnd(manager, insert);
		}
		else { //��尡 �����ϰ� ������ ��尡 �ƴ� ��� ���( == 2���̻��� ���)
			Node *newnode = AllocNewNode(insert);
			newnode->prev = foundDataNode;
			newnode->next = foundDataNode->next;
			foundDataNode->next->prev = newnode;
			foundDataNode->next = newnode;
		}
	}
}
void DeleteNodeEnd(NodeManager *manager) { //�� ������ ���(tail) ����
	if (manager->head == NULL && manager->tail == NULL) { //������ ��尡 ���� ���
		printf("List is empty.\n");
		return;
	}
	else {
		if (manager->head->next == NULL) { //������ ����� ����
			Node *remover = manager->tail;
			manager->head = NULL;
			manager->tail = NULL;
			free(remover);
		}
		else { //2�� �̻��� ���
			Node *remover = manager->tail;
			manager->tail = manager->tail->prev;
			manager->tail->next = NULL;
			free(remover);
		}
	}
}
void DeleteNodeData(NodeManager *manager, element data) { //�����Ͱ� ��ġ�ϴ� ��� ����(data)
	if (IsEmptyList(manager)) { //��尡 �������� �ʴٸ� �Լ� ����
		printf("List is empty.\n");
		return;
	}
	else { //��尡 ������. (1���̻��� ���)
		Node *remover = FindNodeData(manager, data); //������ ���(data) Ž��
		if (remover == NULL) { //data�� ��ġ�ϴ� ��� ����
			printf("No matching data node.\n");
		}
		//�� �Լ��� �ٽ� �ڵ� ����
		else { //������ data�� ��ġ�ϴ� ��� ����
			if (remover->next == NULL) { //������ ��尡 ������ ���
				DeleteNodeEnd(manager);
				return;
			}
			//������ ��尡 �����ϰ� ��� ��尡 ������ ��尡 �ƴ� 2�� �̻��� ���
			else { 
				if (remover->prev == NULL) { //������ ��尡 head
					manager->head = manager->head->next;
					manager->head->prev = NULL;
					free(remover);
				}
				else { //�߰������ ����
					remover->next->prev = remover->prev;
					remover->prev->next = remover->next;
					free(remover);
				}
			}
		}
	}
}
void DeleteList(NodeManager *manager) { //List ����
	if (IsEmptyList(manager)) { //������ ��尡 ���� ���
		printf("List is empty.\n");
		return;
	}
	else { //List�� ���̸� ����Ͽ� ��������
		int ListLength = 0;
		for (Node *count = manager->head; count != NULL; count = count->next) {
			ListLength++;
		}
		for (int i = 0; i < ListLength; i++) {
			DeleteNodeEnd(manager);
		}
	}
}
//Stack ���� �ڵ� ����
//head �� bottom, tail�� pop/push
element pop(NodeManager *manager) {
	if (IsEmptyList(manager)) {
		printf("Stack is Empty.\n");
		return;
	}
	else {
		element data_return = manager->tail->data;
		DeleteNodeEnd(manager);
		return data_return;
	}
}
void push(NodeManager *manager, element data) {
	InsertNodeEnd(manager, data);
}
element peek(NodeManager *manager) {
	return manager->tail->data;
}

//Queue ���� �ڵ� ����
//tail�� enqueue, head�� dequeue
void Enqueue(NodeManager *manager, element data) {
	InsertNodeEnd(manager, data);
}
element Dequeue(NodeManager *manager) {
	element data_return = manager->head->data;
	DeleteNodeData(manager, data_return);
	return data_return;
}
element Peek_queue(NodeManager *manager) {
	return manager->head->data;
}
//Tree ���� �ڵ� ����...����



int main(void) {
	NodeManager *manager_stack = (NodeManager *)malloc(sizeof(NodeManager));
	NodeManager *manager_queue = (NodeManager *)malloc(sizeof(NodeManager));
	NodeManager *manager_list = (NodeManager *)malloc(sizeof(NodeManager));

	InitManager(manager_stack);
	InitManager(manager_queue);
	InitManager(manager_list);


	PrintList(manager_list);

	InsertNodeEnd(manager_list, 10);
	InsertNodeEnd(manager_list, 20);
	InsertNodeEnd(manager_list, 30);
	PrintList(manager_list);
	/*
	DeleteNodeEnd(manager);
	DeleteNodeEnd(manager);
	DeleteNodeEnd(manager);
	*/
	DeleteNodeData(manager_list, 20);

	PrintList(manager_list);

	DeleteList(manager_list);
	PrintList(manager_list);

	free(manager_stack);
	free(manager_queue);
	free(manager_list);
	
	return 0;
}