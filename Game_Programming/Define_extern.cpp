#include <stdio.h>

int g_nData;

void SetData(int data) { g_nData; };
int GetData() { return g_nData; };
void PrintData() { printf("Data : %d\n", g_nData); };

extern int g_nStaticData;
extern void PrintStaticData();

void TestStaticGlobalMain() {
	//static ��������/�Լ��� �ٸ� ���Ͽ����� ����� �� ����.
	g_nStaticData = 999;
	PrintStaticData();
}