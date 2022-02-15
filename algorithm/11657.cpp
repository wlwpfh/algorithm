#include<stdio.h>
#include<vector>
#define INF 987654321 

using namespace std;

struct Line {
	int start;
	int end;
	int value;

	Line(int a, int b, int c) {
		start = a;
		end = b;
		value = c;
	}
};
vector<Line> line;
long long dis[501];
int main() {
	int N, M;
	int i, j, a, b, c;
	int start, end, cost;
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		line.push_back(Line(a, b, c));
	}


	for (i = 1; i <= N; i++)
		dis[i] = INF;

	dis[1] = 0;

	for (i = 1; i < N; i++) {
		for (j = 0; j < line.size(); j++) {
			start = line[j].start;
			end = line[j].end;
			cost = line[j].value;

			if (dis[start] != INF && dis[start] + cost < dis[end]) {
				dis[end] = dis[start] + cost;
			}
		}
	}

	for (i = 0; i < line.size(); i++) {
		start = line[i].start;
		end = line[i].end;
		cost = line[i].value;

		if (dis[start] != INF && dis[start] + cost < dis[end]) {
			//더 갱신 된다는 것은 음의 사이클이 있다는 뜻이니까  
			printf("-1");
			return 0;
		}
	}

	for (i = 2; i <= N; i++) {
		if (dis[i] != INF)
			printf("%d \n", dis[i]);
		else
			printf("-1 \n");
	}


	return 0;
}
