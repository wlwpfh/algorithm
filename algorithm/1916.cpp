#include<stdio.h>
#include<queue>
#include<vector>

#define INF 987654321
#define MAX_SIZE 1000

using namespace std;

struct Data {
	int node;
	int weight;

	Data(int a, int b) {
		node = a;
		weight = b;
	}

	bool operator<(const Data d) const {
		return weight > d.weight;
	}
};

vector<Data> v[MAX_SIZE + 1];
int dis[MAX_SIZE + 1];
bool visited[MAX_SIZE + 1] = { false, };
priority_queue<Data> pq;
int N, M, S, E;

int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	int a, b, c;

	for (int i = 1; i <= N; i++)
		dis[i] = INF;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Data(b, c));
	}
	scanf("%d %d", &S, &E);

	dis[S] = 0;
	pq.push(Data(S, 0));

	while (!pq.empty()) {
		Data now = pq.top();
		pq.pop();

		if (visited[now.node] == true)
			continue;

		visited[now.node] = true;

		for (int i = 0; i < v[now.node].size(); i++) {
			Data next = v[now.node].at(i);

			if (dis[next.node] > dis[now.node] + dis[next.weight]) {
				dis[next.node] = dis[now.node] + dis[next.weight];
				pq.push(Data(next.node, dis[next.node]));
			}

		}
	}

	printf("%d ", dis[E]);

	return 0;
}

