#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

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
		TreeNode *pop = q_levelTraversal.front();
		if (pop->leftChild != NULL) {
			q_levelTraversal.push(pop->leftChild);
		}
		if (pop->rightChild != NULL) {
			q_levelTraversal.push(pop->rightChild);
		}
		printf("%d ", pop->data);
		q_levelTraversal.pop();
	}
}
TreeNode *CreateNode(element data) { //data�� �Է¹޾� �����Ҵ��Ͽ� ������ ��ȯ
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
		if (data >= (*root)->data) { //�ԷµǴ� �����Ͱ� root->data �̻�
			insertData(&((*root)->rightChild), data);
		}
		else if (data < (*root)->data) { //�ԷµǴ� �����Ͱ� root->data �̸�
			insertData(&((*root)->leftChild), data);
		}
	}
}
void deleteData(TreeNode *root, element data) { //data �˻� �� ����

}

int main(void) {
	TreeNode *root = NULL;
	insertData(&root, 4);
	insertData(&root, 5);
	insertData(&root, 6);
	printf("%d ", root->data);
	
	printTreeLevelorder(root);
	/*
	root = insertData(root, 1);
	root = insertData(root, 3);
	root = insertData(root, 6);
	root = insertData(root, 5);
	root = insertData(root, 7);
	*/

	return 0;
}