#include <stdio.h>
#include <malloc.h>

void InitFullRect() {
	const int Width = 5;
	const int Height = 5;
	char arrBackGround[Height][Width];

	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			arrBackGround[y][x] = '*';
		}
	}
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			printf("%c", arrBackGround[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}
void InitStair(char **arr2D, int width, int height) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			*(*(arr2D + x) + y) = '*';
		}
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			
		}
		printf("\n");
	}
	printf("\n");
}
void InitWindow(char **arr2D, int width, int height) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			*(*(arr2D + x) + y) = '*';
		}
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (x % 2 == 1 && y % 2 == 1) {
				printf(" ");
			}
			else printf("%c", *(*(arr2D + x) + y));
		}
		printf("\n");
	}
	printf("\n");
}
void InitEmptyRect(char **arr2D, int width, int height) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			*(*(arr2D + x) + y) = '*';
		}
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
				printf("%c", *(*(arr2D + x) + y));
			}
			else printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	char **arr = NULL;
	//이중포인터 동적할당 : 5는 임의의 값
	arr = (char **)malloc(sizeof(char) * 5);
	for (int i = 0; i < 5; i++) {
		*(arr + i) = (char *)malloc(sizeof(char) * 5);
	}
	
	InitFullRect();
	InitStair(arr, 5, 5);
	InitWindow(arr, 5, 5);
	InitEmptyRect(arr, 5, 5);
	/* 메모리 해제 -오류
	for (int i = 0; i < 5; i++) {
		free(*(arr + i));
	}
	free(arr);
	*/
	return 0;
}