#include <stdio.h>
#include <stdlib.h>
//동적할당으로 점수를 저장하는 배열을 100개 만든다.
//점수의 갯수를 입력받아 배열에 저장하는 프로그램 만들기

void MallocMain() {
	int nSize = 100;
	//메모리의 동적할당 : 프로그램 실행중에 메모리를 할당함.
	//배열의 크기를 입력받아 결정된다.
	int *pArrScore = (int *)malloc(sizeof(int));
	for (int i = 0; i < nSize; i++) {
		pArrScore[i] = i;
		printf("%d", pArrScore[i]);
	}
	printf("\n");
	//동적할당된 메모리는 사용이 끝났다면 반드시 제거해야한다.(메모리누수 방지)
	free(pArrScore);
}
//동적할당 : 동적 : 프로그램 실행중, 할당 : 메모리를 만드는 것. ->
//프로그램 실행중에 메모리의 크기를 변경할 수 있다.
//-> 변수의 메모리 주소를 저장할려면? 포인터
//정적할당 : 정적 : 컴파일 이전엔 
//-> 코딩을 할때 메모리 할당이 결정되는 것.
//-> 변수에 이름을 부여할 수 있고, 이름을 통해 메모리에 접근가능하다.

void reallocMain() {
	//동적할당된 배열의 크기를 변경할 수 있으나
	//공간이 부족하면 모두제거하고 다시 만든다.
	int *pArr = (int *)malloc(sizeof(int) * 3);
	pArr[0] = 0; pArr[1] = 1; pArr[2] = 2;

	pArr = (int *)realloc(pArr, sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", pArr[i]);
	free(pArr);
}
//c++에서 동적할당과 해제
//new, new[] : 새로운 동적할당 메모리/배열을 늘림.
void NewDeleteMain() {
	int *pArrScore = new int[100];
	int *pScore = new int;

	delete pScore;			//변수를 지울때
	delete[] pArrScore;	//배열을 지울때
}

int main(void) {
	
	return 0;
}