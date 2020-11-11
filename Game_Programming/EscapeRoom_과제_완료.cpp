#include <stdio.h>

typedef enum {
	KEY_PART1 = 0,
	KEY_PART2 = 1,
	KEY_PART3 = 2,
	KEY_PART4 = 3
}KEY;

void printWay() {
	printf("�濡 ������.\n");
	printf("���� ������ �ؾ��ϴ°�?\n");
	printf("(å�� : 1, ħ�� : 2, å�� : 3, ���� : 4, �� : 5)\n");
}
int main(void) {
	int key[4] = { 0, }; //�迭�� ��Ұ� ��� 1�� �Ǹ� �ϼ��� Ű.
	int player_select;
	bool assemble_key = false;
	bool escape = false;
	while (!escape) {
		printWay();
		scanf("%d", &player_select);
		switch (player_select)
		{
		case 1: 
			if (assemble_key) {
				printf("����� �ϼ��Ǿ���. ������..?\n");
				break;
			}
			if (key[KEY_PART1] && key[KEY_PART2] && key[KEY_PART3] && key[KEY_PART4]) {
				printf("�������ڿ��� ���踦 �����ϴµ� �����ߴ�!\n");
				assemble_key = true;
				break;
			}
			else if (key[KEY_PART1] == 0) {
				printf("�������� 1�� �߰��ߴ�!\n");
				key[KEY_PART1] = 1; break;
			}
			else printf("�ƹ��͵� ����!\n");
			break;
		case 2:
			if (key[KEY_PART2] == 0) {
				printf("�������� 2�� �߰��ߴ�!\n");
				key[KEY_PART2] = 1; break;
			}
			else printf("�ƹ��͵� ����!\n");
			break;
		case 3:
			if (key[KEY_PART3] == 0) {
				printf("�������� 3�� �߰��ߴ�!\n");
				key[KEY_PART3] = 1; break;
			}
			else printf("�ƹ��͵� ����!\n");
			break;
		case 4:
			if (key[KEY_PART4] == 0) {
				printf("�������� 4�� �߰��ߴ�!\n");
				key[KEY_PART4] = 1; break;
			}
			else printf("�ƹ��͵� ����!\n");
			break;
		case 5:
			if (assemble_key) {
				printf("Ż�⼺��!\n");
				escape = true; //while�� break;
				break;
			}
			else printf("���谡 ����!\n");
			break;
		default:
			printf("�߸��� ���� : 1���� 5������ ���� �Է��ϼ���.\n");
			break;
		}
	}
	return 0;
}