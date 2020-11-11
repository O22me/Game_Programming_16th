#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

typedef int element;
typedef struct {
	int vn;
	int **matrix;
}Graph;

Graph *NewGraph(int max_vertex) {
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vn = max_vertex;
	graph->matrix = (int **)malloc(sizeof(int *)*max_vertex);
	for (int i = 0; i < max_vertex; i++) {
		graph->matrix[i] = (int *)malloc(sizeof(int)*max_vertex);
		memset(graph->matrix[i], 0, max_vertex);
	}
	return graph;
}
int main(void) {

	return 0;
}