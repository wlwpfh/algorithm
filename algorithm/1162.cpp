#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 98765432100
using namespace std;

int N, M, K;
long long time = INF;
//N개의 도시, M개의 도로 수, K개의 포장할 도로 수
//M개의 줄에 대해 도로가 연결하는데 연결하는 시간이 주어짐 
//도로를 통과하는 시간이 최소 시간이 걸리도록
//K개 이하의 도로를 포장하기  
struct Path {
	int end;
	long long time;
	Path(int b, long long c) {
		end = b; time = c;
	}
};
vector<Path> p[10001];
priority_queue<pair<long long, pair<int, int> > > pq;
long long costs[10001][21];

void dijkstra() {
	int i, j, next, node_num, k;
	long long next_cost, tmp_cost;

	for (i = 1; i <= N; i++)
		for (j = 0; j <= K; j++)
			costs[i][j] = INF;

	pq.push({ 0,{1,0} });

	costs[1][0] = 0;

	while (!pq.empty()) {
		pair<long long, pair<int, int>> tmp_p = pq.top();
		pq.pop();

		node_num = tmp_p.second.first;
		k = tmp_p.second.second;

		tmp_cost = tmp_p.first;

		if (costs[node_num][k] < tmp_cost)
			continue;

		for (i = 0; i < p[node_num].size(); i++) {
			next = p[node_num][i].end;
			next_cost = p[node_num][i].time + tmp_cost;


			if (next_cost < costs[next][k]) {
				costs[next][k] = next_cost;
				pq.push({ next_cost, {next,k} });
			} //포장하지 않는 경우 - k

			if (tmp_cost < costs[next][k + 1] && k <= K) {
				costs[next][k + 1] = tmp_cost;
				pq.push({ tmp_cost, {next,k + 1} });
			} // 포장하는 경우 - k+1로  
		}
	}

}

int main() {

	int i, a, b, c;

	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		p[a].push_back(Path(b, c));
		p[b].push_back(Path(a, c));
	}

	dijkstra();

	for (i = 0; i <= K; i++) {
		time = min(time, costs[N][i]);
	}
	printf("%lld", time);

	return 0;
}