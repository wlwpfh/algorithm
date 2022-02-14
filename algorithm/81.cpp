#include<stdio.h>
#include<vector>
#define INF 987654321

using namespace std;

int N, M;

struct Edge {
	int s;
	int e;
	int value;

	Edge(int a, int b, int c) {
		s = a;
		e = b;
		value = c;
	}
};
vector<Edge> E;
int dis[101];
int main() {
	scanf("%d %d", &N, &M);

	int i, a, b, c, ans, j;
	int start, end;
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		E.push_back(Edge(a, b, c));

	}

	for (i = 0; i <= N; i++)
		dis[i] = INF;

	scanf("%d %d", &start, &end);

	dis[start] = 0; //출발점이니까 

	for (i = 1; i < N; i++) {
		//간선이 N-1개를 했을 때 최적   
		for (j = 0; j < E.size(); j++) {
			a = E[j].s;
			b = E[j].e;
			c = E[j].value;

			if (dis[a] != INF && dis[a] + c < dis[b]) {
				dis[b] = dis[a] + c;
			}
		}
	}

	for (i = 0; i < E.size(); i++) {
		a = E[i].s;
		b = E[i].e;
		c = E[i].value;

		if (dis[a] != INF && dis[a] + c < dis[b]) {
			printf("-1\n");
			return 0;
		}
	}

	printf("%d", dis[end]);

	return 0;
}