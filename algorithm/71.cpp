#include<stdio.h>
#include<queue>
#include<stdlib.h>

using namespace std;
int check[10001], cal[3] = { 1,-1, 5 };
int main() {
	int i, start, end, x, pos;
	queue<int>Q;

	scanf("%d %d", &start, &end);

	check[start] = 1;
	Q.push(start);
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();

		for (i = 0; i < 3; i++) {
			pos = x + cal[i];

			if (pos <= 0 || pos > 10000)
				continue;

			if (pos == end)
			{
				printf("%d \n", check[x]);
				//출발 지점이 1로 시작했기 때문에 전 지점의 횟수로 해야 함 
				exit(0);
				//프로그램 자체가 종료 
			}
			else {
				if (check[pos] == 0)
				{
					check[pos] = check[x] + 1;
					//체크 배열과 동시에 레벨 배열
					Q.push(pos);
				}
			}
		}
	}


	return 0;
}