#include <stdio.h>

//Debug : �������� ã������ ���. ������ ������ ����� �˷���.
//Release : �������� ã�� ����� ���� ���������� ������ ���������� ����.
int main(void) {
	int a, b;
	char op;
	printf("������ �Է��ϼ��� : ");
	scanf("%d%c%d", &a, &op, &b); //�����Է±���
	switch (op) //�����ڿ� ���� ���� ����ġ
	{
	case '+': printf("%d %c %d = %d", a, op, b, a + b); break; //���ϱ⿡ ���� ���� �� ���
	case '-': printf("%d %c %d = %d", a, op, b, a - b); break; //������ ���� ���� �� ���
	case '*': printf("%d %c %d = %d", a, op, b, a * b); break; //���ϱ⿡ ���� ���� �� ���
	case '/': printf("%d %c %d = %d", a, op, b, a / b); break; //�����⿡ ���� ���� �� ���
	default: printf("Error\n"); //��Ģ�����ڸ� ������ �Է��� ��� Error ó��
	}
	return 0;
}