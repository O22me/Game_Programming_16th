#include <stdio.h>

int main(void) {
	char ch;
	printf("input your letter : ");
	scanf_s("%c", &ch);

	if (ch >= 'A' && ch <= 'Z') {
		printf("%c is capital letter.\n");
	}
	else if (ch >= 'a' && ch <= 'z') {
		printf("%c is small letter.\n");
	}
	else if (ch >= '0' && ch <= '9') {
		printf("%c is number.\n");
	}
	else printf("%c is undefined letter.\n");
	return 0;
}