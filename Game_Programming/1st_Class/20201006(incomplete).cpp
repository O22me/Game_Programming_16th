#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StringMain() {
	//char strName[] = "ksh";
	//char strName[100] = "ksh";
	//벼열처럼 초기화하면 나머지 값은 0으로 초기화됨.
	char strName[100]; // = { 'k', 'h', 'g' }; 
	//다음과 같이 입력하면 마지막 문자이외에 쓰레기 값이 들어가있으므로, 이상한 문자가 출력될 수 있다.
	//널문자 : 숫자(아스키코드) 0 or 문자 '\0'
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
	//int getch(void) 확인할 것.
	//문자 처리 라이브러리 함수 is~(c) 형태의 함수들
}
//성과 이름을 입력받아서 한국형이름이나 미국형 이름으로 변환하여 출력하는 프로그램.
//데이터 : 성, 이름, 풀네임 (문자열)
//알고리즘 : 한국형, 성 + 이름, 미국형 ; 이름 + 성
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
//숙제
//다음과 같이 출력되는 단어 맞추기 게임만들기
//Q: _ _ _ _
//A: Z
//Z는 없는 문자입니다.
//Q: _ _ _ _
//A: G
//Q: G _ _ _
//A: A
//......
//Q: G A M _
//A: E
//Q: G A M E
//정답입니다!
//심화: 위와 같은 문제를 인덱스접근이외에 문자열 함수만 이용하여 구현하기
void hangManGame() {
	char word[5] = "GAME";
	char screen[5] = "____";
	//고정된 정답(랜덤X)
	//루프문 : 정답내에 전달 받은 문자있는지 확인
	//한개의 문자 입력 받기 , 문자열내에
	//있으면 -> 존재합니다. 출력 + 스크린 업데이트
	//없으면 -> 존재하지 않습니다. 출력
	//루프문 종료조건 : 정답과 스크린 일치시
	//정답입니다. 출력
	while (strcmp(word, screen) != 0) {
		char input;
		int i;
		scanf("%c", &input);
		for (i = 0; i < strlen(word); i++) {
			if (word[i] == input) {
				printf("존재합니다.\n");
				screen[i] = input;
				break;
			}
		}
		if (i = strlen(word)) {
			printf("존재하지 않습니다.\n");
		}
	}
	printf("정답입니다.\n");
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