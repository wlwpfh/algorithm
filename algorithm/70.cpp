#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> map[20];
queue<int> q;
int front = -1, back = 1, check[20];
int dis[20];
int main() {
	int n, m, i, a, b, x, count;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}

	q.push(1);
	check[1] = 1;

	while (!q.empty()) { //자료가 있는 경우 
		x = q.front(); //제일 앞의 값을 참조해서 x에 넣은 것
		q.pop();
		for (i = 0; i < map[x].size(); i++) { //연결된 노드들 찾기 
			if (check[map[x][i]] == 0) {
				check[map[x][i]] = 1;
				q.push(map[x][i]);
				dis[map[x][i]] = dis[x] + 1; //x를 통해서 map[x][i]정점을 가는 것이니까

			}
		}

	}

	for (i = 2; i <= n; i++) {
		printf("%d : %d \n", i, dis[i]);
	}
	return 0;

}