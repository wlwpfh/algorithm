#include<stdio.h>
#include<vector>
#include<cmath>
#define INF 987654321 

using namespace std;

typedef pair<int, int> pii;
int map[50][50], N, M, tmp_sum, sum = INF;
bool visited[13];
vector<pii> house, chicken;

int calDistance(pair<int, int> x, pair<int, int>y) {
	int tmp = abs(x.first - y.first) + abs(x.second - y.second);

	return tmp;
}

void Visit() {
	tmp_sum = 0;
	int dis = 0, tmp = 0;
	for (int i = 0; i < house.size(); i++) {
		dis = INF;
		for (int j = 0; j < chicken.size(); j++) {
			if (visited[j]) {
				tmp = calDistance(house[i], chicken[j]);
				dis = dis > tmp ? tmp : dis;
			}

		}
		tmp_sum += dis;
	}
}

void Choose(int index, int count) {
	if (count == M) {
		Visit();
		sum = sum > tmp_sum ? tmp_sum : sum;
		//printf("sum: %d, tmp_sum:%d \n",sum, tmp_sum);
		return;
	}

	if (index >= chicken.size())
		return;

	visited[index] = true;
	Choose(index + 1, count + 1);
	visited[index] = false;
	Choose(index + 1, count);

}

int main() {
	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
			if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}

	Choose(0, 0);
	//치킨 집 순번, 치킨 집 간 숫자  

	printf("%d", sum);
	return 0;
}