#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_LENGTH 100000

void Bubble_Sort(int *arr) {
	for (int i = 0; i < LIST_LENGTH - 1; i++) {
		for (int j = 0; j < LIST_LENGTH - 1 - i; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}
void Quick_Sort(int *arr) {

}
void InitListRandom(int *arr) {
	for (int i = 0; i < LIST_LENGTH; i++) {
		*(arr + i) = rand() % 100;
	}
}
void print(int *arr) {
	for (int i = 0; i < LIST_LENGTH; i++) {
		printf("%d\t", *(arr + i));
	}
	printf("\n");
}
int main(void) {
	int *Not_sorted_arr = (int *)malloc(sizeof(int) * LIST_LENGTH);
	//int *Sorted_arr = (int *)malloc(sizeof(int) * LIST_LENGTH);

	InitListRandom(Not_sorted_arr);

	print(Not_sorted_arr);

	Bubble_Sort(Not_sorted_arr);

	print(Not_sorted_arr);

	free(Not_sorted_arr);
	//free(Sorted_arr);
	return 0;
}