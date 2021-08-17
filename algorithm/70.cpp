#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> map[20];
queue<int> q;
int front = -1, back = 1, check[20];
int dis[20];
int main() {
	int n, m, i, a, b, x, count;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}

	q.push(1);
	check[1] = 1;

	while (!q.empty()) { //�ڷᰡ �ִ� ��� 
		x = q.front(); //���� ���� ���� �����ؼ� x�� ���� ��
		q.pop();
		for (i = 0; i < map[x].size(); i++) { //����� ���� ã�� 
			if (check[map[x][i]] == 0) {
				check[map[x][i]] = 1;
				q.push(map[x][i]);
				dis[map[x][i]] = dis[x] + 1; //x�� ���ؼ� map[x][i]������ ���� ���̴ϱ�

			}
		}

	}

	for (i = 2; i <= n; i++) {
		printf("%d : %d \n", i, dis[i]);
	}
	return 0;

}