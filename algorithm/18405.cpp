#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, S, X, Y;
int map[201][201];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct Virus {
	int x; int y; int number; int second;
	Virus(int a, int b, int c, int d) {
		x = a;
		y = b;
		number = c;
		second = d;
	}
	bool operator<(const Virus v)const {
		return number < v.number;
	}
};
queue<Virus> q;
vector<Virus> vec;
void Infection() {
	while (!q.empty()) {

		Virus v = q.front();
		int x = v.x;
		int y = v.y;
		int virus = v.number;
		int second = v.second;
		q.pop();

		if (S == second)
			break;

		//printf("virus :%d\n",virus);

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<1 || nx>N || ny<1 || ny>N) //범위를 벗어난 경우 
				continue;
			if (map[nx][ny] == 0) {

				map[nx][ny] = virus;
				q.push(Virus(nx, ny, virus, second + 1));
			}


		}
	}

}

int main() {
	int i, j;
	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] != 0) {
				//q.push(Virus(i,j,map[i][j],0));
				vec.push_back(Virus(i, j, map[i][j], 0));
			}
		}
	}
	scanf("%d %d %d", &S, &X, &Y);


	sort(vec.begin(), vec.end());

	for (i = 0; i < vec.size(); i++) {
		q.push(vec[i]);
		//printf("(%d, %d), Virus:%d \n",vec[i].x, vec[i].y,vec[i].number);
	}

	//	while(!q.empty()){
	//		Virus v=q.top();
	//		printf("(%d, %d), Virus:%d \n",v.x, v.y,v.number);
	//		q.pop();
	//	}

	Infection();

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}

	printf("%d", map[X][Y]);
	return 0;
}