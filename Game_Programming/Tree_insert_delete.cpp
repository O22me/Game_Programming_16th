#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

bool removeflag = false;

typedef int element;
 struct TreeNode{
	element data;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

void printTreePreorder(TreeNode *root) {
	if (root != NULL) {
		printf("%d ", root->data);
		printTreePreorder(root->leftChild);
		printTreePreorder(root->rightChild);
	}
}
void printTreeInorder(TreeNode *root) {
	if (root != NULL) {
		printTreeInorder(root->leftChild);
		printf("%d ", root->data);
		printTreeInorder(root->rightChild);
	}
}
void printTreePostorder(TreeNode *root) {
	if (root != NULL) {
		printTreePostorder(root->leftChild);
		printTreePostorder(root->rightChild);
		printf("%d ", root->data);
	}
}
void printTreeLevelorder(TreeNode *root) {
	queue<TreeNode *> q_levelTraversal;
	q_levelTraversal.push(root);
	while (!q_levelTraversal.empty()) {
		TreeNode *popNode = q_levelTraversal.front();
		if (popNode->leftChild != NULL) {
			q_levelTraversal.push(popNode->leftChild);
		}
		if (popNode->rightChild != NULL) {
			q_levelTraversal.push(popNode->rightChild);
		}
		printf("%d ", popNode->data);
		q_levelTraversal.pop();
	}
}
void printAllOrder(TreeNode* root) {
	printf("\nPreorder : \t");
	printTreePreorder(root);
	printf("\nInorder : \t");
	printTreeInorder(root);
	printf("\nPostorder : \t");
	printTreePostorder(root);
	printf("\nLevelorder : \t");
	printTreeLevelorder(root);
}
TreeNode *CreateNode(element data) { //data를 입력받아 동적할당하여 포인터 반환
	TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
	if (newnode == NULL) return NULL;
	newnode->data = data;
	newnode->leftChild = NULL;
	newnode->rightChild = NULL;
	return newnode;
}
void insertData(TreeNode **root, element data) { 
	if (*root == NULL) {
		*root = CreateNode(data);
	}
	else { //root != NULL
		if (data >= (*root)->data) { //입력되는 데이터가 root->data 이상
			insertData(&((*root)->rightChild), data);
		}
		else if (data < (*root)->data) { //입력되는 데이터가 root->data 미만
			insertData(&((*root)->leftChild), data);
		}
	}
}
int TreeSize(TreeNode* root) {
	int size = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *popNode = q.front();
		if (popNode->leftChild != NULL) q.push(popNode->leftChild);
		if (popNode->rightChild != NULL) q.push(popNode->rightChild);
		q.pop();
		size++;
	}
	return size;
}
void deleteData(TreeNode *root, element data) { //data 검색 후 삭제
	removeflag = false; //NULL처리를 위한 flag이용
	if (root->data == data) { //삭제대상 노드 발견
		if (root->leftChild == NULL && root->rightChild == NULL) { //단말 노드인 경우
			free(root);
			removeflag = true;
			return;
		}
		else if (root->leftChild != NULL && root->rightChild != NULL) { //자식노드가 둘다 있는 경우
			if (TreeSize(root->leftChild) >= TreeSize(root->rightChild)) { // 왼서브트리가 더 큰 경우
				root->data = root->leftChild->data;
				deleteData(root->leftChild, root->data); //반드시 일치하게 됨.
				if (removeflag) {
					root->leftChild = NULL;
					removeflag = false;
				}
			}
			else { //TreeSize(root->leftChild) < TreeSize(root->rightChild) //오른 서브트리가 더 큰 경우
				root->data = root->rightChild->data;
				deleteData(root->rightChild, root->data); //반드시 일치하게 됨.
				if (removeflag) {
					root->rightChild = NULL;
					removeflag = false;
				}
			}
		}
		else if (root->leftChild != NULL && root->rightChild == NULL) { //왼 자식트리만 있는 경우
			root->data = root->leftChild->data;
			deleteData(root->leftChild, root->data);
			if (removeflag) {
				root->leftChild = NULL;
				removeflag = false;
			}
		}
		else if (root->rightChild != NULL && root->leftChild == NULL) { //오른 자식트리만 있는 경우
			root->data = root->rightChild->data;
			deleteData(root->rightChild, root->data);
			if (removeflag) {
				root->rightChild = NULL;
				removeflag = false;
			}
		}
	}
	else { //재귀함수를 통한 delete 실현.
		if (root->data <= data) {
			deleteData(root->rightChild, data); //삭제할 노드(data)가 같거나 더 큰 경우
			if (removeflag) {
				root->rightChild = NULL;
				removeflag = false;
			}
		}
		else {
			deleteData(root->leftChild, data); //삭제할 노드(data)가 작은 경우
			if (removeflag) {
				root->leftChild = NULL;
				removeflag = false;
			}
		}
	}
}

int main(void) {
	TreeNode *root = NULL;
	insertData(&root, 4);
	insertData(&root, 6);
	insertData(&root, 2);
	insertData(&root, 1);
	insertData(&root, 3);
	insertData(&root, 5);
	insertData(&root, 7);

	printf("TreeSize : %d\n", TreeSize(root));
	printAllOrder(root);
	deleteData(root, 4);
	
	printAllOrder(root);
	return 0;
}