#include <stdio.h>

int g_nData;

void SetData(int data) { g_nData; };
int GetData() { return g_nData; };
void PrintData() { printf("Data : %d\n", g_nData); };

extern int g_nStaticData;
extern void PrintStaticData();

void TestStaticGlobalMain() {
	//static 전역변수/함수는 다른 파일에서는 사용할 수 없다.
	g_nStaticData = 999;
	PrintStaticData();
}