#include <stdio.h>

//Debug : 문제점을 찾기위한 모드. 실행중 문제가 생기면 알려줌.
//Release : 문제점을 찾는 기능을 끄고 최종적으로 배포될 실행파일을 만듦.
int main(void) {
	int a, b;
	char op;
	printf("수식을 입력하세요 : ");
	scanf("%d%c%d", &a, &op, &b); //수식입력구간
	switch (op) //연산자에 따른 구분 스위치
	{
	case '+': printf("%d %c %d = %d", a, op, b, a + b); break; //더하기에 관한 연산 및 출력
	case '-': printf("%d %c %d = %d", a, op, b, a - b); break; //뺄셈에 관한 연산 및 출력
	case '*': printf("%d %c %d = %d", a, op, b, a * b); break; //곱하기에 관한 연산 및 출력
	case '/': printf("%d %c %d = %d", a, op, b, a / b); break; //나누기에 관한 연산 및 출력
	default: printf("Error\n"); //사칙연산자를 제외한 입력의 경우 Error 처리
	}
	return 0;
}