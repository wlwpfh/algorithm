#include<stdio.h>
#include<cstring> 
using namespace std;

int N, M, C;
int map[51][51];
int dp[51][51][51][51];
// 	  x  y    l   k
// (x,y)에서 (n,m)까지 갈 때 l번 오락실 경우, 오락실을 k번 지나가는 경우  

int dfs(int x, int y, int prev, int count) {
	//현재 위치  , 마지막으로 들린 오락실 -prev, 총 들린 오락실 count

	if (x<0 || y<0 || x>N || y>M)
		return 0;

	int now = dp[x][y][count][prev];

	if (now != -1) //이미 왔다 간 경우  
		return now;



}

int main() {
	// N * M의 도시, 집은 1,1 학원은 N,M에 있고 오락실은 C개 
	//이동 시 현재 위치에서 밑으로 가거나 오른족으로 가는 경우
	// 오락실 번호가 증가하는 순대로 가야 함. 0-> 0 , 0->1, 0->1, 0->1->2
	//오락실을 k번 방문해서 학원에 도착하는 경우의 수 
	//오락실 0개 방문 ~ C 개 방문의 경우의 수  
	scanf("%d %d %d", &N, &M, &C);

	int i, tmp_x, tmp_y;

	for (i = 1; i <= C; i++) {
		scanf("%d %d", &tmp_x, &tmp_y);
		map[tmp_x][tmp_y] = i;
	} //여기는 숫자로 설정함.  

	memset(dp, -1, sizeof(dp));
	//dp배열 초기화


	for (i = 0; i <= C; i++)
		printf("%d ", dfs(1, 1, 0, i));
	//0번 가는 경우도 있ㅇ니까  

	return 0;
}