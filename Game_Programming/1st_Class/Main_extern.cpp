#include <stdio.h>

//�� �Լ��� �ִ� ������ �Լ��� �ƴѰͿ� extern�� ���δ�.
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