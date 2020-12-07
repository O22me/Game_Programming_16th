#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StringMain() {
	//char strName[] = "ksh";
	//char strName[100] = "ksh";
	//����ó�� �ʱ�ȭ�ϸ� ������ ���� 0���� �ʱ�ȭ��.
	char strName[100]; // = { 'k', 'h', 'g' }; 
	//������ ���� �Է��ϸ� ������ �����̿ܿ� ������ ���� �������Ƿ�, �̻��� ���ڰ� ��µ� �� �ִ�.
	//�ι��� : ����(�ƽ�Ű�ڵ�) 0 or ���� '\0'
	strName[0] = 'k'; strName[1] = 'h'; strName[2] = 'g'; strName[3] = 0; //'\0';
	int nSize = sizeof(strName); //4
	
	for (int i = 0; i < nSize; i++) {
		printf("%c", strName[i]);
	}
	printf("\n");

	int i = 0;
	while (strName[i] != '\0') {
		printf("[%d]%c", i, strName[i]);
		i++;
	}
	printf("\n");

	printf("%s", strName);
	//int getch(void) Ȯ���� ��.
	//���� ó�� ���̺귯�� �Լ� is~(c) ������ �Լ���
}
//���� �̸��� �Է¹޾Ƽ� �ѱ����̸��̳� �̱��� �̸����� ��ȯ�Ͽ� ����ϴ� ���α׷�.
//������ : ��, �̸�, Ǯ���� (���ڿ�)
//�˰��� : �ѱ���, �� + �̸�, �̱��� ; �̸� + ��
void StringLibraryMain() {
	char strLastName[100] = "k";
	char strFirstName[100] = "sh";
	char strFullName[200];
	//Print last name and firstname.
	printf("LastName : %s", strLastName);
	printf("\tFirstName : %s\n", strFirstName);
	//Print Korea naming
	strcpy(strFullName, strLastName);
	strcat(strFullName, strFirstName);
	printf("Korea naming : %s\n", strFullName);
	//Print American naming
	strcpy(strFullName, strFirstName);
	strcat(strFullName, strLastName);
	printf("American naming : %s\n", strFullName);
}
//����
//������ ���� ��µǴ� �ܾ� ���߱� ���Ӹ����
//Q: _ _ _ _
//A: Z
//Z�� ���� �����Դϴ�.
//Q: _ _ _ _
//A: G
//Q: G _ _ _
//A: A
//......
//Q: G A M _
//A: E
//Q: G A M E
//�����Դϴ�!
//��ȭ: ���� ���� ������ �ε��������̿ܿ� ���ڿ� �Լ��� �̿��Ͽ� �����ϱ�
void hangManGame() {
	char word[5] = "GAME";
	char screen[5] = "____";
	//������ ����(����X)
	//������ : ���䳻�� ���� ���� �����ִ��� Ȯ��
	//�Ѱ��� ���� �Է� �ޱ� , ���ڿ�����
	//������ -> �����մϴ�. ��� + ��ũ�� ������Ʈ
	//������ -> �������� �ʽ��ϴ�. ���
	//������ �������� : ����� ��ũ�� ��ġ��
	//�����Դϴ�. ���
	while (strcmp(word, screen) != 0) {
		char input;
		int i;
		scanf("%c", &input);
		for (i = 0; i < strlen(word); i++) {
			if (word[i] == input) {
				printf("�����մϴ�.\n");
				screen[i] = input;
				break;
			}
		}
		if (i = strlen(word)) {
			printf("�������� �ʽ��ϴ�.\n");
		}
	}
	printf("�����Դϴ�.\n");
}
void checker(char word[]) {
	char input[10];
	scanf("%s", input);
	while (strcmp(word, input) != 0) {
		printScreen();
		break;
	}
}
void printScreen() {
	printf("check\n");
}
int main(void) {
	//StringMain();
	//StringLibraryMain();
	char word[10] = "MYSTERY";
	hangManGame();
	return 0;
}