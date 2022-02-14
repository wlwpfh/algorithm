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
int dis[501];
int main() {
	int N, M;
	int i, j, a, b, c;
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
			a = line[j].start;
			b = line[j].end;
			c = line[j].value;

			if (dis[a] != INF && dis[a] + c < dis[b]) {
				dis[b] = dis[a] + c;
			}
		}
	}

	for (i = 0; i < line.size(); i++) {
		a = line[i].start;
		b = line[i].end;
		c = line[i].value;

		if (dis[a] != INF && dis[a] + c < dis[b]) {
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