#include<vector>
#include<stdio.h>
#include<queue>

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

vector<Data> v[10];
int dis[10];
bool isVisited[10];

priority_queue<Data> pq;

int N, M;

int main() {
	scanf("%d %d", &N, &M);
	int a, b, c;

	for (int i = 0; i <= N; i++) {
		v[i].clear();
		dis[i] = INF;
		isVisited[i] = false;
	} //값들 초기화

	for (int i = 0; i < M; i++) {

		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Data(b, c));
		v[b].push_back(Data(a, c));
		//양방향이기 때문에  
	}


	//다익스트라 구현
	//시작하려는 노드를 정하기 - 일단 1번으로 하기 

	dis[1] = 0;
	pq.push(Data(1, 0));

	while (!pq.empty()) {
		Data now = pq.top(); //지금 방문한 노드  
		pq.pop();

		if (isVisited[now.node])
			continue;

		isVisited[now.node] = true;

		for (int i = 0; i < v[now.node].size(); i++) {
			//현재 방문한 노드에 연결된 노드의 간선의 개수
			Data next = v[now.node].at(i);

			if (dis[next.node] > dis[now.node] + next.weight)
				//아 ~ 이게 INF값일 수 있으니까 더 짧은 거리로 갱신  
				dis[next.node] = dis[now.node] + next.weight;
			pq.push(Data(next.node, dis[next.node]));
			//다음 노드와 갱신된 거리를 넣기  
		}

	}

	for (int i = 0; i <= N; i++) {
		printf("%d ", dis[i]);
	}



	return 0;
}