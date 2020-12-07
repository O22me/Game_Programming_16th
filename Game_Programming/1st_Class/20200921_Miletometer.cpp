#include <stdio.h>


//마일을 미터로 변환하는 프로그램(0~2마일까지 변환한다.)
//데이터 : 마일, 미터
//알고리즘 : 마일*1609 = 미터
//1. 반복하는 구문을 찾음
//2. 반복하는 조건을 찾는다. -> 마일이 0~2
//3. 끝나는 조건을 찾는다. -> 마일 == 2
//4. 조건을 만족하게 변수를 연산한다. -> 마일++
//5. 만약 조건에 맞다면 break를 한다.
//6. 반복되는 조건을 찾는다 -> 마일 != 2, 마일 < 2

int main(void) {
	int nMeter;
	int nMile = 0;

	while (nMile <= 5) {
		nMeter = nMile * 1609;
		printf("%d Mail to Meter %d\n", nMile, nMeter);
		nMile++;
	}
	
	return 0;
}
/*
	nMile = 0;
	nMeter = nMile * 1609;
	printf("%d마일은 %d미터입니다.\n", nMile, nMeter);

	nMile = 1;
	nMeter = nMile * 1609;
	printf("%d마일은 %d미터입니다.\n", nMile, nMeter);

	nMile = 2;
	nMeter = nMile * 1609;
	printf("%d마일은 %d미터입니다.", nMile, nMeter);
*/