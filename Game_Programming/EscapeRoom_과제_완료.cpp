#include <stdio.h>

typedef enum {
	KEY_PART1 = 0,
	KEY_PART2 = 1,
	KEY_PART3 = 2,
	KEY_PART4 = 3
}KEY;

void printWay() {
	printf("방에 갇혔다.\n");
	printf("나는 무엇을 해야하는가?\n");
	printf("(책상 : 1, 침대 : 2, 책장 : 3, 옷장 : 4, 문 : 5)\n");
}
int main(void) {
	int key[4] = { 0, }; //배열의 요소가 모두 1이 되면 완성된 키.
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
				printf("열쇠는 완성되었다. 이제는..?\n");
				break;
			}
			if (key[KEY_PART1] && key[KEY_PART2] && key[KEY_PART3] && key[KEY_PART4]) {
				printf("도구상자에서 열쇠를 조립하는데 성공했다!\n");
				assemble_key = true;
				break;
			}
			else if (key[KEY_PART1] == 0) {
				printf("열쇠조각 1을 발견했다!\n");
				key[KEY_PART1] = 1; break;
			}
			else printf("아무것도 없다!\n");
			break;
		case 2:
			if (key[KEY_PART2] == 0) {
				printf("열쇠조각 2를 발견했다!\n");
				key[KEY_PART2] = 1; break;
			}
			else printf("아무것도 없다!\n");
			break;
		case 3:
			if (key[KEY_PART3] == 0) {
				printf("열쇠조각 3를 발견했다!\n");
				key[KEY_PART3] = 1; break;
			}
			else printf("아무것도 없다!\n");
			break;
		case 4:
			if (key[KEY_PART4] == 0) {
				printf("열쇠조각 4를 발견했다!\n");
				key[KEY_PART4] = 1; break;
			}
			else printf("아무것도 없다!\n");
			break;
		case 5:
			if (assemble_key) {
				printf("탈출성공!\n");
				escape = true; //while문 break;
				break;
			}
			else printf("열쇠가 없다!\n");
			break;
		default:
			printf("잘못된 선택 : 1에서 5사이의 값을 입력하세요.\n");
			break;
		}
	}
	return 0;
}