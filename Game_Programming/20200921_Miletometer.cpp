#include <stdio.h>


//������ ���ͷ� ��ȯ�ϴ� ���α׷�(0~2���ϱ��� ��ȯ�Ѵ�.)
//������ : ����, ����
//�˰��� : ����*1609 = ����
//1. �ݺ��ϴ� ������ ã��
//2. �ݺ��ϴ� ������ ã�´�. -> ������ 0~2
//3. ������ ������ ã�´�. -> ���� == 2
//4. ������ �����ϰ� ������ �����Ѵ�. -> ����++
//5. ���� ���ǿ� �´ٸ� break�� �Ѵ�.
//6. �ݺ��Ǵ� ������ ã�´� -> ���� != 2, ���� < 2

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
	printf("%d������ %d�����Դϴ�.\n", nMile, nMeter);

	nMile = 1;
	nMeter = nMile * 1609;
	printf("%d������ %d�����Դϴ�.\n", nMile, nMeter);

	nMile = 2;
	nMeter = nMile * 1609;
	printf("%d������ %d�����Դϴ�.", nMile, nMeter);
*/