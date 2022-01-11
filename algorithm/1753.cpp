#include<stdio.h>
#include<queue>
#include<vector>

#define MAX_SIZE 20000
#define INF 987654321

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

using namespace std;

bool isVisited[MAX_SIZE + 1] = { false, };
vector<Data> vec[MAX_SIZE + 1];
int dis[MAX_SIZE + 1] = { 0, };
priority_queue<Data> pq;

int V, E, K;

int main() {

	scanf("%d %d", &V, &E);

	scanf("%d", &K); //출발 지점

	int u, v, w;

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);

		vec[u].push_back(Data(v, w));
		//방향 그래프이니까 일방향으로 설정하기  
	}

	for (int i = 1; i <= V; i++) {
		dis[i] = INF;
	}

	dis[K] = 0;
	pq.push(Data(K, 0));

	while (!pq.empty()) {
		Data now = pq.top();
		pq.pop();

		if (isVisited[now.node] == true)
			continue;

		isVisited[now.node] = true;

		for (int i = 0; i < vec[now.node].size(); i++) {
			Data next = vec[now.node].at(i);

			if (dis[next.node] > dis[now.node] + next.weight) {
				dis[next.node] = dis[now.node] + next.weight;

				pq.push(Data(next.node, dis[next.node]));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF)
			printf("INF \n");
		else
			printf("%d \n", dis[i]);
	}

	return 0;
}