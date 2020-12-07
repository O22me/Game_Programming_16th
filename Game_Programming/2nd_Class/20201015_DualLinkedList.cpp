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
Node *FindNodeData(NodeManager *manager, element data) { //head부터 data와 일치하는 노드가 있으면 반환, 없으면 NULL반환
	for (Node *curr = manager->head; curr != NULL; curr = curr->next) {
		if (curr->data == data) {
			return curr;
		}
	}
	return NULL;
}
void InsertNodeEnd(NodeManager *manager, element data) { //맨 마지막 노드에 새로운 노드(data)를 추가하는 함수
	if (IsEmptyList(manager)) { //노드가 없는 경우
		Node *newnode = AllocNewNode(data);
		manager->head = newnode;
		manager->tail = newnode;
	}
	else { //기존 노드 존재 : 멘 마지막 노드에 추가 
		Node *newnode = AllocNewNode(data);
		manager->tail->next = newnode;
		newnode->prev = manager->tail;
		manager->tail = newnode;
	}
}
void InsertNodeData(NodeManager *manager, element data, element insert) { //노드(data)뒤에 새로운 노드(insert)를 추가하는 함수
	Node *foundDataNode = FindNodeData(manager, data);
	if (foundDataNode == NULL) { //data와 일치하는 node가 없는 경우
		printf("No matching data node.\n");
		return;
	}
	else {
		if (foundDataNode->next == NULL) { //찾은 노드가 마지막 노드인 경우
			InsertNodeEnd(manager, insert);
		}
		else { //노드가 존재하고 마지막 노드가 아닌 모든 경우( == 2개이상의 노드)
			Node *newnode = AllocNewNode(insert);
			newnode->prev = foundDataNode;
			newnode->next = foundDataNode->next;
			foundDataNode->next->prev = newnode;
			foundDataNode->next = newnode;
		}
	}
}
void DeleteNodeEnd(NodeManager *manager) { //맨 마지막 노드(tail) 삭제
	if (manager->head == NULL && manager->tail == NULL) { //삭제할 노드가 없는 경우
		printf("List is empty.\n");
		return;
	}
	else {
		if (manager->head->next == NULL) { //마지막 노드의 삭제
			Node *remover = manager->tail;
			manager->head = NULL;
			manager->tail = NULL;
			free(remover);
		}
		else { //2개 이상의 노드
			Node *remover = manager->tail;
			manager->tail = manager->tail->prev;
			manager->tail->next = NULL;
			free(remover);
		}
	}
}
void DeleteNodeData(NodeManager *manager, element data) { //데이터가 일치하는 노드 삭제(data)
	if (IsEmptyList(manager)) { //노드가 존재하지 않다면 함수 종료
		printf("List is empty.\n");
		return;
	}
	else { //노드가 존재함. (1개이상의 노드)
		Node *remover = FindNodeData(manager, data); //삭제할 노드(data) 탐색
		if (remover == NULL) { //data와 일치하는 노드 없음
			printf("No matching data node.\n");
		}
		//이 함수의 핵심 코드 시작
		else { //삭제할 data와 일치하는 노드 존재
			if (remover->next == NULL) { //삭제할 노드가 마지막 노드
				DeleteNodeEnd(manager);
				return;
			}
			//삭제할 노드가 존재하고 대상 노드가 마지막 노드가 아닌 2개 이상의 노드
			else { 
				if (remover->prev == NULL) { //삭제할 노드가 head
					manager->head = manager->head->next;
					manager->head->prev = NULL;
					free(remover);
				}
				else { //중간노드의 삭제
					remover->next->prev = remover->prev;
					remover->prev->next = remover->next;
					free(remover);
				}
			}
		}
	}
}
void DeleteList(NodeManager *manager) { //List 삭제
	if (IsEmptyList(manager)) { //삭제할 노드가 없는 경우
		printf("List is empty.\n");
		return;
	}
	else { //List의 길이를 계산하여 삭제연산
		int ListLength = 0;
		for (Node *count = manager->head; count != NULL; count = count->next) {
			ListLength++;
		}
		for (int i = 0; i < ListLength; i++) {
			DeleteNodeEnd(manager);
		}
	}
}
//Stack 관련 코드 제작
//head 가 bottom, tail로 pop/push
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

//Queue 관련 코드 제작
//tail로 enqueue, head로 dequeue
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
//Tree 관련 코드 제작...예정



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