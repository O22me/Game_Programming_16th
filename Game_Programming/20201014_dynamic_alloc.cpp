#include <stdio.h>
#include <stdlib.h>
//�����Ҵ����� ������ �����ϴ� �迭�� 100�� �����.
//������ ������ �Է¹޾� �迭�� �����ϴ� ���α׷� �����

void MallocMain() {
	int nSize = 100;
	//�޸��� �����Ҵ� : ���α׷� �����߿� �޸𸮸� �Ҵ���.
	//�迭�� ũ�⸦ �Է¹޾� �����ȴ�.
	int *pArrScore = (int *)malloc(sizeof(int));
	for (int i = 0; i < nSize; i++) {
		pArrScore[i] = i;
		printf("%d", pArrScore[i]);
	}
	printf("\n");
	//�����Ҵ�� �޸𸮴� ����� �����ٸ� �ݵ�� �����ؾ��Ѵ�.(�޸𸮴��� ����)
	free(pArrScore);
}
//�����Ҵ� : ���� : ���α׷� ������, �Ҵ� : �޸𸮸� ����� ��. ->
//���α׷� �����߿� �޸��� ũ�⸦ ������ �� �ִ�.
//-> ������ �޸� �ּҸ� �����ҷ���? ������
//�����Ҵ� : ���� : ������ ������ 
//-> �ڵ��� �Ҷ� �޸� �Ҵ��� �����Ǵ� ��.
//-> ������ �̸��� �ο��� �� �ְ�, �̸��� ���� �޸𸮿� ���ٰ����ϴ�.

void reallocMain() {
	//�����Ҵ�� �迭�� ũ�⸦ ������ �� ������
	//������ �����ϸ� ��������ϰ� �ٽ� �����.
	int *pArr = (int *)malloc(sizeof(int) * 3);
	pArr[0] = 0; pArr[1] = 1; pArr[2] = 2;

	pArr = (int *)realloc(pArr, sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", pArr[i]);
	free(pArr);
}
//c++���� �����Ҵ�� ����
//new, new[] : ���ο� �����Ҵ� �޸�/�迭�� �ø�.
void NewDeleteMain() {
	int *pArrScore = new int[100];
	int *pScore = new int;

	delete pScore;			//������ ���ﶧ
	delete[] pArrScore;	//�迭�� ���ﶧ
}

int main(void) {
	
	return 0;
}