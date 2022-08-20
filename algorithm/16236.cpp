#include<stdio.h>
#include<queue>

using namespace std;

struct Feed {
	int x, y, dis;

	Feed(int a, int b, int c) {
		x = a, y = b; dis = c;
	}

	bool operator<(const Feed& feed)const {
		if (dis == feed.dis) {
			if (y == feed.y)
				return x > feed.x;
			return y > feed.y;
		}
		return dis > feed.dis;
	}
};

queue<Feed> shark;
int N, map[20][20], shark_size = 2, min_distance;
//bool visited[20][20];
//0:빈칸,  123456:물고기 크기, 9:아기상어 위치  

void BFS() {
	while (1) {
		priority_queue<Feed> fish;
		vector<vector<bool>> visited(N, vector<bool>(N));
		int eat = 0;
		//초기화 

		while (!shark.empty()) {
			Feed now = shark.front();

			shark.pop();

			int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };

			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
					continue;
				if (map[nx][ny] > shark_size)
					continue;

				if (map[nx][ny] < shark_size && map[nx][ny] != 0) {
					fish.push(Feed(nx, ny, now.dis + 1));
				}//0이 아니고 먹을 수 있는 경우   

				visited[nx][ny] = true;
				shark.push(Feed(nx, ny, now.dis + 1));
				//상어 이동 거리  
			}
		}

		if (fish.empty())
			break;
		//먹을 먹이가 없다면 	

		Feed feed = fish.top();

		if (++eat == shark_size) {
			eat = 0;
			shark_size++;
		}

		map[feed.x][feed.y] = 0; //먹었으니까 이동하고 커짐  
		shark.push(Feed(feed.x, feed.y, 0));
		min_distance += feed.dis;
		printf("min:%d \n", min_distance);
	}
}

int main() {
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9) {
				shark.push(Feed(i, j, 0));
				map[i][j] = 0;
			}
		}

	BFS();

	printf("%d", min_distance);

	return 0;
}