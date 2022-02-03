#include<stdio.h>
#include<queue>
#include<vector>
#define INF 987654321
#define MAX_N 10

using namespace std;

struct Node {
	int next, weight;

	Node(int n, int w) {
		next = n;
		weight = w;
	}
	bool operator<(const Node n)const {
		return weight > n.weight;
	}
};

bool visited[MAX_N + 1] = { false, };
vector<Node> v[MAX_N + 1];
int dis[MAX_N + 1];
priority_queue<Node> pq;

int main() {

	int N, M, i, s, e, value;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &value);
		v[s].push_back(Node(e, value));
	}

	for (i = 1; i <= N; i++)
		dis[i] = INF;


	dis[1] = 0; //1번 정점에서 시작하니까 
	pq.push(Node(1, 0)); //1번 정점으로 가고 비용은 0 

	while (!pq.empty()) {
		int now = pq.top().next;
		int cost = pq.top().weight;
		pq.pop();

		if (cost > dis[now])
			continue;
		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i].next;
			int dist = v[now][i].weight + cost;

			if (dis[next] > dist)
				pq.push(Node(next, dist));

		}
	}

	for (i = 1; i <= N; i++) {
		if (dis[i] == INF)
			printf("%d : Impossible \n", i);
		else
			printf("%d : %d \n", i, dis[i]);
	}

	return 0;
}