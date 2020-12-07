/*##################################
���Ͽ��Ḯ��Ʈ(������)
���ϸ�: LinkedList_empty.cpp
�ۼ���: ��ȫ�� (downkhg@gmail.com)
������������¥: 2019.04.12
����: 1.10
###################################*/

#include <stdio.h>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���
//#include  "linkedlistClass.h"

struct SNode {
	int nData;
	SNode* pNext;
};

SNode* CreateNode(SNode* pNode, int data); //��带 �ϳ� �ް� �̾ �ش� �����͸� ���� ��带 �߰��Ѵ�.
SNode* FindNodeData(SNode* pStart, int data); //�ش� �����͸� ���� ��带 ã�´�.
SNode* InsertNodeData(SNode* pStart, int data, int insert); //�ش� �����͸� ���� ��� �ڿ� ��带 �߰��Ѵ�.
void DeleteNodeData(SNode* pStart, int del); //�ش絥���͸� ���� ��带 �����Ѵ�.
void PrintLinkedList(SNode* pStart); //��带 ��ȸ�ϸ� ���������� ����Ѵ�.
void DeleteLinkedList(SNode* pStart); //��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
void ReverseLinkedList(SNode** pStart);

									   //���Ḯ��Ʈ �������� �Է¹ޱ�.(�����Ҵ� �����)
void InputAdd();

//�����۵� �׽�Ʈ�� ���ؼ�, ������ ���� �⺻���� ������ ������ Ȯ���Ѵ�.
//�� �ҽ��� ��� ���װ� �����Ѵ�.
//�� �ڵ尡 �����۵� �� �� �߰��غ���!
//main()�Լ� �� �ڵ�� �߰��� ���������� ������ ��������!
int main()
{
	_CrtSetBreakAlloc(71); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	//��� �߰� �׽�Ʈ
	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd; //������ ��带 �˾ƾ� �˻��� �����ϹǷ� �����صд�.

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);

	PrintLinkedList(pBegin);

	SNode* pFind = FindNodeData(pBegin, 40);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	pEnd = InsertNodeData(pBegin, 30, 60);//��� ����

	PrintLinkedList(pBegin);

	DeleteNodeData(pBegin, 60);//��� ����

	PrintLinkedList(pBegin);

	printf("Reverse Start\n");

	ReverseLinkedList(&pBegin);

	PrintLinkedList(pBegin);

	DeleteLinkedList(pBegin); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.

	return 0;
}

SNode *AllocNewNode(int data) {
	SNode *newnode = (SNode *)malloc(sizeof(SNode));
	newnode->nData = data;
	newnode->pNext = NULL;
	return newnode;
}
//���⼭ ���� ����� �����Ѵ�.
//�����ڵ�� �մ�������, �߰��� �Ͽ� �� ���α׷� ���� �۵��ϵ����Ұ�.
SNode* CreateNode(SNode* pNode,  int data) //end�� data
{
	if (pNode == NULL) { //ù��� �����ΰ��
		pNode = AllocNewNode(data);
		return pNode;
	}
	else { //pNode != NULL, ��尡 �ּ� 1���̻�
		SNode* pTemp = AllocNewNode(data);
		pTemp->pNext = pNode->pNext; //end�� �Դٸ� NULL�� �ڵ�����
		pNode->pNext = pTemp;
		pNode = pTemp; //������ ����� �����͸� ��ȯ
		return pNode;
	}
}

SNode* FindNodeData(SNode* pStart, int data)
{
	if (pStart == NULL) return NULL;
	for (SNode* pNode = pStart; pNode != NULL; pNode = pNode->pNext) {
		if (pNode->nData == data) return pNode;
	}
	return NULL; //data�� ��ġ�ϴ� ��� �������� ����
}

SNode* InsertNodeData(SNode* pStart, int data, int insert) //pBegin, data->insert... ��.
{
	SNode *pNode_data = FindNodeData(pStart, data); //data�� ��ġ�ϴ� ���Ž��
	SNode *pNode_insert = AllocNewNode(insert); //insert ���� ������ ������
	if (pNode_data->pNext == NULL) { //ã�� ���(data��ġ���)�� ������ NULL�� ��� == ������ ��忡 �߰��ϴ� ���
		pNode_data->pNext = pNode_insert; 
		return pNode_insert; //������ ����ȯ
	}
	else { //ã�� ���(data��ġ���)�� ������ NULL�� �ƴ� ��� == �߰� ��忡 �߰��ϴ� �ܿ�
		pNode_insert->pNext = pNode_data->pNext;
		pNode_data->pNext = pNode_insert; //���ԿϷ�
		SNode *pEnd_return = pStart;
		while (pEnd_return->pNext != NULL) {
			pEnd_return = pEnd_return->pNext;
		}
		return pEnd_return;
	}
}

void DeleteNodeData(SNode* pStart, int del)
{
	SNode *pDelete = FindNodeData(pStart, del);
	if (pDelete == NULL) return; //������� ��� ã�� ���Ͽ���.
	else if (pDelete == pStart) { //ù ��尡 �������
		if (pDelete->pNext == NULL) { //��尡 �ϳ����� ���
			pStart = NULL;
			free(pDelete);
		}
		else {
			pStart = pStart->pNext;
			free(pDelete);
		}
	}
	else if (pDelete != pStart) { //ù ��尡 ��������� �ƴϰ�, �ΰ��̻��� ��尡 ������ ���
		SNode *pChaser = pStart;
		while (pChaser->pNext != pDelete) { //pChaser�� ���� ��尡 pDelete ��尡 �ǰԲ� ����.
			pChaser = pChaser->pNext;
		}
		pChaser->pNext = pDelete->pNext; //������ ����� ���� ��带 �̾���
		free(pDelete);
	}
}

void PrintLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	printf("data:");
	while (pNode != NULL)
	{
		printf("%d", pNode->nData);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(",");
	}
	printf("\n");
}

void DeleteLinkedList(SNode* pStart)
{
	if (pStart == NULL) return; //��� ���� X
	else if (pStart->pNext == NULL) { //��尡 �ϳ��� �ִ°��
		free(pStart);
	}
	else { //�ΰ��̻��� ��尡 �����ϴ� ���
		SNode *pChased = pStart->pNext;
		SNode *pDelete = pStart;
		while (pChased->pNext != NULL) {
			free(pDelete);
			pDelete = pChased;
			pChased = pChased->pNext;
		}
		free(pDelete);
		free(pChased);
	}
	pStart = NULL;
}
void ReverseLinkedList(SNode** pStart) {
	if (*pStart == NULL || (*pStart)->pNext == NULL) return; //��尡 0�� Ȥ�� 1���� ��� �Լ�����
	else { //�ΰ��̻��� ���
		SNode *prev = *pStart;
		SNode *Changer = (*pStart)->pNext;
		SNode *next = Changer->pNext;
		while (next != NULL) { //3�� �̻��� ����� ��쿡 ����
			Changer->pNext = prev;
			prev = Changer;
			Changer = next;
			next = next->pNext;
		}
		Changer->pNext = prev;
		(*pStart)->pNext = NULL;  //*(pStart).pNext = NULL;
		*pStart = Changer;
	}
}

void InputAdd()
{
	SNode* pStart = NULL;
	SNode* pNode = NULL;
	int nData = 0;

	//�����Ҵ��� �ϸ� ���α׷��� ����ڿ� ���ؼ� ���Ǵ� �޸𸮰� �����ȴ�.
	//���Ը��ؼ�, �����ϴܰ迡�� 100���� ����� ���ٸ�, 
	//��������ʴ��� 100���� �޸𸮸� ����Ҽ��ۿ�����.
	//�׸���, 100�� �̻��� �޸𸮵� ����Ҽ�����.
	//�׷���, �����Ҵ��� �ϸ� ����ڰ� �߰��� �޸𸮸�ŭ�� �޸𸮰� ���ǰ� 
	//�޸𸮿뷮�� ����ϴ� �� �߰��� �ȴ�.
	while (nData != -1)
	{
		scanf("%d", &nData);
		pNode = CreateNode(pNode, nData);

		if (pNode == NULL)
		{
			printf("�� �̻� ����Ҽ� �ִ� �޸𸮰� �����ϴ�!");
		}

		if (pStart == NULL)
			pStart = pNode;

		PrintLinkedList(pStart);
	}
	DeleteLinkedList(pStart); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}