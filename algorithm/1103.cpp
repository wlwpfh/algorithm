#include<stdio.h>

using namespace std;

int n, m;
int dp[55][55] = { 0, }; //��� �ߺ��� ���� ���ؼ�  
char map[55][55] = { 0, }; //������ �����ϱ� ���ؼ�  
bool visited[55][55]; // ������ �Ȱ����� üũ�ϱ� ���ؼ�  
int max_level = -1;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void go(int x, int y, int level) {

	visited[x][y] = true;

	dp[x][y] = level;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i] * (map[x][y] - '0'); //�̷��� �ϸ� int�� �ȴ� 
		int next_y = y + dy[i] * (map[x][y] - '0');

		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || map[next_x][next_y] == 'H') {
			if (max_level < level)
				max_level = level;
			return;
		}
		//������ ����� ���  
		if (visited[next_x][next_y]) {
			max_level = -1;
			return;
		} //�̹� �Դ� ���  


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
