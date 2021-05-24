#include<stdio.h>
#include<vector>

using namespace std;
int q[100], front = -1, back = -1, check[10];
vector<int> tree[8];

int main() {
	int i, a, b, x;


	for (i = 1; i <= 6; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	q[++back] = 1; //1번 루트 노드 넣기
	check[1] = 1; //갔다고 가정함.

	while (front < back) { //같아지는 순간 큐가 비어있어 끝남. 
		x = q[++front];
		printf("%d ", x);

		for (i = 0; i < tree[x].size(); i++)//x와 연결된 node찾기 
		{
			if (check[tree[x][i]] == 0) {
				check[tree[x][i]] = 1;
				q[++back] = tree[x][i];
			}
		}
	}

	return 0;
}