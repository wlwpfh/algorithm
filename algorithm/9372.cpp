#include<stdio.h>
#include<queue>
#define MAX_CITY 1000
using namespace std;

//프림 알고리즘으로 풀어보기  
struct City {
	int start;
	int end;
	City(int a, int b) {
		start = a, end = b;
	}

};

queue<int> q;
//간 곳을 넣기  
vector<int> city[MAX_CITY + 1];
int visited[MAX_CITY + 1];
int main() {

	int T, i, N, M, a, b, count = 0, min = 0, tmp, j, k;
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		for (j = 0; j < M; j++) {
			scanf("%d %d", &a, &b);
			city[a].push_back(b);
			city[b].push_back(a);
			tmp = a;
		}


		q.push(tmp);
		visited[tmp] = 1;
		tmp = 1;
		while (!q.empty() && count != N - 1) {
			int next_city = q.front();
			q.pop();

			for (k = 0; k < city[next_city].size(); k++) {
				int tmp_city = city[next_city].at(k);
				if (visited[tmp_city] == 0)
					tmp++;
				count++;
			}
		}
		printf("%d\n", tmp);
	}
	return 0;
}