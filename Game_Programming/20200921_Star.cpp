#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//1.�����Ϳ� �˰����� �и��Ѵ�.
//2.�����ʹ� ���� �˰����� ����,�ݺ�,���� ���� ���յȴ�.
//3.�ݺ��Ǵ� ���� ���� �ݺ��ϰ� ������ ����Ѵ�.
/*
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	nBateria = nBateria * 2;//20
	nTime = 1;

	nBateria = nBateria * 2;//40
	nTime = 2;

	nBateria = nBateria * 2;//80
	nTime = 3;

	nBateria = nBateria * 2;//160
	nTime = 4;

	printf("Time:%d\n", nTime);
}
*/
//4.�ݺ��Ǵ� ��Ģ���� ã�Ƽ� ���ѹݺ��� ������ �ݺ��� ������ ��� Ȯ���Ѵ�.
//(���α׷��Ӱ� �ƴ϶�� ���⼭ ���ĵ� ������. �׷��� ��ġ��(������� �þ�����)�� ������� �ɼ�����)
/*
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while (true)
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		if (nBateria > 100) break;
	}
}
*/
//5.break���� ������ �ݴ�� if���� �ִ´�.(�ʰ�,�̸�:������  �̻�,����:����)
//������ 10������ ����ϰ� ���ռ��� 100���� �̻��� �Ǵ� �ð���?
//������ 1�ð����� 2�辿 �����Ѵ�.
//������: ���ռ�,�ð�
//�˰���: ���ռ�*2, 1�ð�����, 100���� �̻��̵ɶ�����
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while (nBateria <= 100)
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria > 100) break;
	}
}

//���̸� ������ (����)�� (1/2�� �پ�)�鶧,
//(���̸����� 1/10����)�� �پ�����, (�����)�ƾ��ϴ°�?
void PaperAreaMain()
{
	double paperSize = 1.0;
	int count = 0;
	while (paperSize > 0.1) {
		paperSize /= 2;
		count++;
	}
	printf("PaperAreaMain() : \t%d\n", count);
}

//(����:����) 10������ ����Ͽ� (10�ð���:����)�� ���ռ��� ���Ͽ���.
//�̶�, ������ (1�ð� ���� 4��)�� �����Ѵ� 
//���ռ�:10 //�ð�:0  //���ռ�*=4
void BateriaForMain()
{
	int hour = 0, Bateria = 10;
	while (hour < 10) {
		Bateria *= 4;
		hour++;
	}
	printf("BateriaForMain() : \t%d\n", Bateria);
}

//���̸� 10 �������� ������ ���̵Ǵ°�?
//�̶�, ������ ���� 100�̶������.
//(���̸����� �������پ���)
void PaperForMain()
{
	double paperSize = 100;
	int count = 0;
	while (count < 10) {
		paperSize /= 2;
		count++;
	}
	printf("PaperForMain() : \t%lf\n", paperSize);
}



//�ݰ���: ���ɹ����Ǿ��� 1/2�� �Ǵ� �ð�
//���� ������ ���� 2000���� ������ ������ ����?
//�ݰ���:400��
//���ɹ����Ǿ�: 100
void HalfLifeForMain()
{
	double radiation = 100;
	int halfLife = 400, year = 2000;
	while (year > 0) {
		radiation /= 2;
		year -= halfLife;
	}
	printf("HalfLifeForMain() : \t%lf\n", radiation);
}

//�ݰ���: �����Ǿ��� ������ �پ��� �ð�
//(���ɹ����� ��)�� (1/10���Ϸ��� �Ǵµ�) (���)�� �ɸ��°�?
//������ �ݰ���: 400�� 
//������: 100 
void HalfLifeMain()
{
	double radiation = 100;
	int year = 0, halfLife = 400;
	while (radiation > 10) {
		radiation /= 2;
		year += halfLife;
	}
	printf("HalfLifeMain() : \t%d\n", year);
}



//���ٿ����: 
//���ڸ� �����ϸ� �� ���ڰ� �������� ���� ������, down ũ�� up ���߸� ��.
//1.(���� Q) �� �������ִ�.
//2.���亸�� (ū��)��  (A �Է�)������ up�̶�� ���
//3.���亸�� (������)�� (A �Է�)������ down�̶�� ���
//4.������ �ƴ϶�� �ٽ� �Է¹���.
//5.�����̶�� ������ ������.
//������ �������� �����ϵ��� �����
void UpDownGameMain()
{
	srand(time(NULL));
	int random_number = rand() % 10;
	int input;
	printf("UP/DOWN GAME : ");
	scanf("%d", &input);
	while (random_number != input) {
		if (random_number > input) {
			printf("UP\n");
		}
		else if (random_number < input) {
			printf("DOWN\n");
		}
		printf("UP/DOWN GAME : ");
		scanf("%d", &input);
	}
	printf("CORRECT\n");
}
/* ��������� ����϶�.
�ش����� �̸��� �Լ��ȿ� ���Ǹ� �����Ͽ� �ش����� ��µǵ��ϸ����
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.��Ģ�� ã�´�.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> Ȧ��
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.��Ģ��� ������ ��� �ش�.
//
//3.��Ģ���� ���ϸ��� �κ��� ������ ã�´�.
//(���ǹ����̰���) -> y�� �����Ҷ����� x�� ���� �����Ѵ�.
void RectMain()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
}
void WindowMain()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((i % 2 == 1) && (j % 2 == 1)) {
				printf(" ");
			}
			else printf("#");
		}
		printf("\n");
	}
	printf("\n");
}
void StiarMain()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("#");
		}
		printf("\n");
	}
}

void main()
{
	PaperAreaMain();
	BateriaForMain();
	PaperForMain();
	HalfLifeForMain();
	HalfLifeMain();
	UpDownGameMain();
	RectMain();
	WindowMain();
	StiarMain();
}