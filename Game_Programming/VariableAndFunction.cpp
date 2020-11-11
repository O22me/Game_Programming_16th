#include <stdio.h>

//[배달음식] 어떤[집]에서든 시켜먹을 수 있다.
//[전역변수]는 어떤[함수]에서든 사용가능하다.
//[집밥]은 [우리집]에서만 먹을 수 있다.
//[지역변수]는 [함수나 블록]에서만 사용가능하다.

int g_nData; //전역변수 : 모든 함수에서 접근할 수 있는 변수, 프로그램이 종료될 때 사라진다.

int Add(int a, int b) { //매개변수도 일종의 지역변수다.
	//정적지역변수 : 함수에 들어와도 값이 사라지지않고 유지된다.
	//함수의 호출횟수를 저장하는데 용이하다.
	static int nCallCount = 0;
	nCallCount++;
	printf("Add[%d](%d, %d)\n", nCallCount, a, b);
	g_nData = 1;
	//지역변수
	int result = a + b;
	return result;
}
//지역변수 : 블록내에서만 존재하는 변수. 블록이 끝날때 사라진다.
void LocalValueMain() {
	//int i = 지역변수
	g_nData = 2;
	for (int i = 0; i < 3; i++) {
		printf("%d:test\n", i);
	}
	{
		int test; //지역변수
	}
}

//전역변수를 반복변수로 for을 10번 돌려 출력하는 함수를 만든다.
//위 함수를 5번 전역변수로 반복문을 돌린다.
int g_nidx;

void GIdxFor10PrintShape() {
	for (g_nidx = 0; g_nidx < 10; g_nidx++) {
		printf("#");
	}
	printf("\nFor10_g_nidx : %d\n", g_nidx);
}
void GIdxFor10PrintShapeX5_Main() {
	for (g_nidx = 0; g_nidx < 5; g_nidx++) {
		GIdxFor10PrintShape();
	}
	printf("X5_g_nidx : %d\n", g_nidx);
}
int main(void) {
	g_nData = 3;
	printf("Add() : %d\n", Add(10, 20));
	LocalValueMain();
	GIdxFor10PrintShapeX5_Main();
	return 0;
}






