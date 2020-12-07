#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef enum _vertex{
	A, B, C, D, E, F, G, H, I
}vertex;

bool visited_dfs_recursive[9] = { false, }; //재귀함수를 활용하므로 전역선언

void bfsPrint(vector<vertex> graph[]) {
	bool visited_bfs[9] = { false, };
	queue<vertex> bfs;
	bfs.push(A);
	visited_bfs[A] = true;
	while (!bfs.empty()) {
		vertex pop_bfs = bfs.front();
		for (vector<vertex>::iterator it = graph[pop_bfs].begin(); it != graph[pop_bfs].end(); it++) {
			if (visited_bfs[*it] == false) {
				bfs.push(*it);
				visited_bfs[*it] = true;
			}
		}
		printf("%c ", pop_bfs + 65);
		//cout << pop_bfs << endl;
		bfs.pop();
	}
}
void dfsPrint(vector<vertex> graph[], vertex node) {
	printf("%c ", node + 65); //이거 cout 로 할 수 있는지..?
	visited_dfs_recursive[node] = true;
	for (vector<vertex>::iterator it = graph[node].begin(); it != graph[node].end(); it++) {
		if (visited_dfs_recursive[*it] == false) {
			dfsPrint(graph, *it);
		}
	}
}
void dfsPrintStack(vector<vertex> graph[]) {
	
}
int main(void) {
	vector<vertex> graph[9];
	//방향성 없는 그래프 생성
	//참고 : https://ehclub.co.kr/1561
	graph[A].push_back(B); graph[A].push_back(C);
	graph[B].push_back(A); graph[B].push_back(C); graph[B].push_back(D);
	graph[C].push_back(A); graph[C].push_back(B); graph[C].push_back(E);
	graph[D].push_back(B); graph[D].push_back(G);
	graph[E].push_back(C); graph[E].push_back(F); graph[E].push_back(G); graph[E].push_back(H);
	graph[F].push_back(E);
	graph[G].push_back(D); graph[G].push_back(E); graph[G].push_back(I);
	graph[H].push_back(E);
	graph[I].push_back(G);

	bfsPrint(graph);
	cout << endl;
	dfsPrint(graph, A);


	return 0;
}