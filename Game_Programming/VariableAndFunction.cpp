#include <stdio.h>

//[�������] �[��]������ ���Ѹ��� �� �ִ�.
//[��������]�� �[�Լ�]������ ��밡���ϴ�.
//[����]�� [�츮��]������ ���� �� �ִ�.
//[��������]�� [�Լ��� ���]������ ��밡���ϴ�.

int g_nData; //�������� : ��� �Լ����� ������ �� �ִ� ����, ���α׷��� ����� �� �������.

int Add(int a, int b) { //�Ű������� ������ ����������.
	//������������ : �Լ��� ���͵� ���� ��������ʰ� �����ȴ�.
	//�Լ��� ȣ��Ƚ���� �����ϴµ� �����ϴ�.
	static int nCallCount = 0;
	nCallCount++;
	printf("Add[%d](%d, %d)\n", nCallCount, a, b);
	g_nData = 1;
	//��������
	int result = a + b;
	return result;
}
//�������� : ��ϳ������� �����ϴ� ����. ����� ������ �������.
void LocalValueMain() {
	//int i = ��������
	g_nData = 2;
	for (int i = 0; i < 3; i++) {
		printf("%d:test\n", i);
	}
	{
		int test; //��������
	}
}

//���������� �ݺ������� for�� 10�� ���� ����ϴ� �Լ��� �����.
//�� �Լ��� 5�� ���������� �ݺ����� ������.
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