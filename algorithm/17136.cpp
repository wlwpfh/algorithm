#include<stdio.h>
#include<algorithm>
using namespace std;

int map[10][10];
int paper[6] = { 0,5,5,5,5,5 };
int res = 987654321;

bool canPutPaper(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (i < 0 || i >= 10 || j < 0 || j >= 10) //범위를 벗어나는 지 
				return false;
			if (map[i][j] != 1)

				return false;
		}
	}
	return true;
} //종이를 넣을 수 있는지 확인  

void putPaper(int x, int y, int size, int value) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			map[i][j] = value;
		}
	}
} //붙이거나 떼는 과정  - value값으로 수정해주기 

void DFS(int x, int y, int count) {

	if (x == 9 && y > 9) {
		res = min(res, count);
		return;
	}
	if (count >= res)
		return;
	if (y > 9) { //다시 0부터  
		DFS(x + 1, 0, count);
		return;
	}
	if (map[x][y] == 1) {
		for (int i = 5; i >= 1; i--) {
			if (paper[i] > 0 && canPutPaper(x, y, i)) {
				//종이가 남아있고 종이를 붙일 수 있다

				putPaper(x, y, i, 0); //붙이기 1 ->0
				paper[i]--;
				DFS(x, y, count + 1);
				putPaper(x, y, i, 1); //떼기 0-> 1
				paper[i]++;
			}
		}
	}
	else
		DFS(x, y + 1, count);

}


int main() {

	int i, j;

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
		}


	//모든 1을 덮는데 필요한 색종이의 최소 개수 
	//모든 덮는 게 불가능한 경우엔 -1 출력 
	//각 종류의 종이는 5개씩 가지고 있으며 1*1, 2*2, 3*3, 4*4, 5*5의 색종이를 사용해야 함,

	// 1 찾기 -> 붙이기 시도 -> 붙이기 -> 안되면 제거  

	//1. 붙일 수 있는지 확인 -> 2. 붙이기와 떼기 과정 반복  
	DFS(0, 0, 0);


	if (res == 987654321)
		printf("-1");
	else
		printf("%d", res);


	return 0;
}