#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

struct Tv {
	int x, y, num;

	Tv(int a, int b, int c) {
		x = a, y = b, num = c;
	}
};

int N, M, res = INF, cctv_sum;
int rotation[] = { 0,4,2,4,4,1 };
int map[8][8];
vector<Tv> cctv;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

void countEmpty() {
	int zero_count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				zero_count++;
		}
	}
	res = min(res, zero_count);
}

void setCctv(Tv tv, int dir) { // cctv몇번인지, 현재 방향..?  
	int x = tv.x, y = tv.y, num = tv.num;
	int d = dir % 4;

	if (d == 0) { //동  
		for (int i = x + 1; i < N; i++) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (d == 1) { //남
		for (int j = y + 1; j < M; j++) {
			if (map[x][j] == 6)
				break;
			else if (map[x][j] == 0)
				map[x][j] = -1;
		}

	}
	else if (d == 2) { //서  
		for (int i = x - 1; i >= 0; i--) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else { //북  
		for (int j = y - 1; j >= 0; j--) {
			if (map[x][j] == 6)
				break;
			else if (map[x][j] == 0)
				map[x][j] = -1;
		}
	}

}

void watch(int index) {
	if (index == cctv.size()) {
		//	print();
		countEmpty();
		return;
	}
	int tmp[8][8];

	int x = cctv[index].x, y = cctv[index].y, num = cctv[index].num;

	for (int i = 1; i <= rotation[num]; i++) {
		copy(&map[0][0], &map[0][0] + 64, &tmp[0][0]);

		if (num == 1) {
			setCctv(cctv[index], i); //동 	
		}
		else if (num == 2) {
			setCctv(cctv[index], i); //동  
			setCctv(cctv[index], i + 2);// 서  
		}
		else if (num == 3) {
			setCctv(cctv[index], i); //동  
			setCctv(cctv[index], i + 1); //남  
		}
		else if (num == 4) {
			setCctv(cctv[index], i); //동  
			setCctv(cctv[index], i + 1); //남  
			setCctv(cctv[index], i + 2); //서  
		}
		else {
			setCctv(cctv[index], i); //동  
			setCctv(cctv[index], i + 1); //남  
			setCctv(cctv[index], i + 2); //서  
			setCctv(cctv[index], i + 3); // 북  
		}
		watch(index + 1);
		copy(&tmp[0][0], &tmp[0][0] + 64, &map[0][0]);
	}

}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6)
				cctv.push_back(Tv(i, j, map[i][j]));
		}
	cctv_sum = cctv.size();

	//0은 빈칸. 1-5는 cctv, 6은 벽 
	//1,3,4는 4가지 방법, 2는 2가지 방법, 5는 한가지 방법  
	//각 번호대로 볼 수 있는 방법이 정해져 있음 

	watch(0);

	printf("%d", res);

	return 0;
}