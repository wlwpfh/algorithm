#include<stdio.h>
#include<vector>

using namespace std;
int queue[10], front = -1, back = -1, check[10];
vector<int> map[10];

int main() {
	int i, a, b, x;

	for (i = 1; i <= 6; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b); //a에서 b로 갈 수 있다.
		//map[b].push_back(a); //b에서 a로 갈 수 있다. 
	}



	queue[++back] = 1; //1번 루트노드 넣기 
	check[1] = 1;

	while (front < back) {
		x = queue[++front];
		printf("%d ", x);

		for (i = 0; i < map[x].size(); i++) {//x하고 연결된 노드 찾기 
			if (check[map[x][i]] == 0) {
				check[map[x][i]] = 1;
				queue[++back] = map[x][i]; //연결된 노드 큐에 넣기 
			}
		}

	}
	return 0;
}