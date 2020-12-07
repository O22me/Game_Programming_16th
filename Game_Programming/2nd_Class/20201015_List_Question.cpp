/*##################################
단일연결리스트(수업용)
파일명: LinkedList_empty.cpp
작성자: 김홍규 (downkhg@gmail.com)
마지막수정날짜: 2019.04.12
버전: 1.10
###################################*/

#include <stdio.h>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더
//#include  "linkedlistClass.h"

struct SNode {
	int nData;
	SNode* pNext;
};

SNode* CreateNode(SNode* pNode, int data); //노드를 하나 받고 이어서 해당 데이터를 가진 노드를 추가한다.
SNode* FindNodeData(SNode* pStart, int data); //해당 데이터를 가진 노드를 찾는다.
SNode* InsertNodeData(SNode* pStart, int data, int insert); //해당 데이터를 가진 노드 뒤에 노드를 추가한다.
void DeleteNodeData(SNode* pStart, int del); //해당데이터를 가진 노드를 삭제한다.
void PrintLinkedList(SNode* pStart); //노드를 순회하며 끝날때까지 출력한다.
void DeleteLinkedList(SNode* pStart); //노드를 순회하며 모든데이터를 삭제한다.
void ReverseLinkedList(SNode** pStart);

									   //연결리스트 동적으로 입력받기.(동적할당 설명용)
void InputAdd();

//정상작동 테스트를 위해서, 다음과 같이 기본적인 절차로 오류를 확인한다.
//이 소스에 몇가지 버그가 존재한다.
//이 코드가 정상작동 된 후 발견해볼것!
//main()함수 내 코드는 추가는 가능하지만 삭제는 하지말것!
int main()
{
	_CrtSetBreakAlloc(71); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 

	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	//노드 추가 테스트
	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd; //마지막 노드를 알아야 검색이 가능하므로 저장해둔다.

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);

	PrintLinkedList(pBegin);

	SNode* pFind = FindNodeData(pBegin, 40);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	pEnd = InsertNodeData(pBegin, 30, 60);//노드 삽입

	PrintLinkedList(pBegin);

	DeleteNodeData(pBegin, 60);//노드 삭제

	PrintLinkedList(pBegin);

	printf("Reverse Start\n");

	ReverseLinkedList(&pBegin);

	PrintLinkedList(pBegin);

	DeleteLinkedList(pBegin); //모든노드삭제 - 이 함수를 호출하지않을시 메모리가 누수됨.

	return 0;
}

SNode *AllocNewNode(int data) {
	SNode *newnode = (SNode *)malloc(sizeof(SNode));
	newnode->nData = data;
	newnode->pNext = NULL;
	return newnode;
}
//여기서 부터 기능을 구현한다.
//기존코드는 손대지말고, 추가만 하여 현 프로그램 정상 작동하도록할것.
SNode* CreateNode(SNode* pNode,  int data) //end와 data
{
	if (pNode == NULL) { //첫노드 생성인경우
		pNode = AllocNewNode(data);
		return pNode;
	}
	else { //pNode != NULL, 노드가 최소 1개이상
		SNode* pTemp = AllocNewNode(data);
		pTemp->pNext = pNode->pNext; //end가 왔다면 NULL을 자동대입
		pNode->pNext = pTemp;
		pNode = pTemp; //생성한 노드의 포인터를 반환
		return pNode;
	}
}

SNode* FindNodeData(SNode* pStart, int data)
{
	if (pStart == NULL) return NULL;
	for (SNode* pNode = pStart; pNode != NULL; pNode = pNode->pNext) {
		if (pNode->nData == data) return pNode;
	}
	return NULL; //data와 일치하는 노드 존재하지 않음
}

SNode* InsertNodeData(SNode* pStart, int data, int insert) //pBegin, data->insert... 순.
{
	SNode *pNode_data = FindNodeData(pStart, data); //data와 일치하는 노드탐색
	SNode *pNode_insert = AllocNewNode(insert); //insert 값을 가지는 노드생성
	if (pNode_data->pNext == NULL) { //찾은 노드(data일치노드)의 다음이 NULL인 경우 == 마지막 노드에 추가하는 경우
		pNode_data->pNext = pNode_insert; 
		return pNode_insert; //마지막 노드반환
	}
	else { //찾은 노드(data일치노드)의 다음이 NULL이 아닌 경우 == 중간 노드에 추가하는 겨우
		pNode_insert->pNext = pNode_data->pNext;
		pNode_data->pNext = pNode_insert; //삽입완료
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
	if (pDelete == NULL) return; //삭제대상 노드 찾지 못하였음.
	else if (pDelete == pStart) { //첫 노드가 삭제대상
		if (pDelete->pNext == NULL) { //노드가 하나뿐인 경우
			pStart = NULL;
			free(pDelete);
		}
		else {
			pStart = pStart->pNext;
			free(pDelete);
		}
	}
	else if (pDelete != pStart) { //첫 노드가 삭제대상이 아니고, 두개이상의 노드가 존재할 경우
		SNode *pChaser = pStart;
		while (pChaser->pNext != pDelete) { //pChaser의 다음 노드가 pDelete 노드가 되게끔 설정.
			pChaser = pChaser->pNext;
		}
		pChaser->pNext = pDelete->pNext; //삭제한 노드의 다음 노드를 이어줌
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
	if (pStart == NULL) return; //노드 존재 X
	else if (pStart->pNext == NULL) { //노드가 하나만 있는경우
		free(pStart);
	}
	else { //두개이상의 노드가 존재하는 경우
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
	if (*pStart == NULL || (*pStart)->pNext == NULL) return; //노드가 0개 혹은 1개일 경우 함수종료
	else { //두개이상의 노드
		SNode *prev = *pStart;
		SNode *Changer = (*pStart)->pNext;
		SNode *next = Changer->pNext;
		while (next != NULL) { //3개 이상의 노드의 경우에 실행
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

	//동적할당을 하면 프로그램이 사용자에 의해서 사용되는 메모리가 결정된다.
	//쉽게말해서, 컴파일단계에서 100개를 만들고 쓴다면, 
	//사용하지않더라도 100개의 메모리를 사용할수밖에없다.
	//그리고, 100개 이상의 메모리도 사용할수없다.
	//그러나, 동적할당을 하면 사용자가 추가한 메모리만큼만 메모리가 사용되고 
	//메모리용량이 허용하는 한 추가가 된다.
	while (nData != -1)
	{
		scanf("%d", &nData);
		pNode = CreateNode(pNode, nData);

		if (pNode == NULL)
		{
			printf("더 이상 사용할수 있는 메모리가 없습니다!");
		}

		if (pStart == NULL)
			pStart = pNode;

		PrintLinkedList(pStart);
	}
	DeleteLinkedList(pStart); //모든노드삭제 - 이 함수를 호출하지않을시 메모리가 누수됨.
}