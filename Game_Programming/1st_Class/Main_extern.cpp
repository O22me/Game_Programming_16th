#include <stdio.h>

//이 함수에 있는 변수나 함수가 아닌것에 extern을 붙인다.
extern int g_nData;
extern void SetData(int);
extern int GetData();
extern void PrintData();

static int g_nStaticData;

void PrintStaticData() { printf("StaticDat : %d\n", g_nData); }

extern void TestStaticGlobalMain();

void main(void) {
	g_nData = 10;
	SetData(20);
	int nData = GetData();
	printf("LocalData : %d\n", nData);
	PrintData();
	g_nStaticData = 20;
	TestStaticGlobalMain();
}