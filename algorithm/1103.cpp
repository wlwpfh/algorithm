#include<stdio.h>

using namespace std;

int n, m;
int dp[55][55] = { 0, }; //계산 중복을 막기 위해서  
char map[55][55] = { 0, }; //지도를 저장하기 위해서  
bool visited[55][55]; // 갔는지 안갔는지 체크하기 위해서  
int max_level = -1;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void go(int x, int y, int level) {

	visited[x][y] = true;

	dp[x][y] = level;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i] * (map[x][y] - '0'); //이렇게 하면 int가 된다 
		int next_y = y + dy[i] * (map[x][y] - '0');

		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || map[next_x][next_y] == 'H') {
			if (max_level < level)
				max_level = level;
			return;
		}
		//범위에 벗어나는 경우  
		if (visited[next_x][next_y]) {
			max_level = -1;
			return;
		} //이미 왔던 경우  


		go(next_x, next_y, level + 1);

	}

}


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", &map[i]);

	}

	go(0, 0, 1);

	printf("%d", max_level);
	return 0;
}
