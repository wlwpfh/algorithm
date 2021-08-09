#include<stdio.h>
#include<vector>

using namespace std;
int queue[10], front = -1, back = -1, check[10];
vector<int> map[10];

int main() {
	int i, a, b, x;

	for (i = 1; i <= 6; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b); //a���� b�� �� �� �ִ�.
		//map[b].push_back(a); //b���� a�� �� �� �ִ�. 
	}



	queue[++back] = 1; //1�� ��Ʈ��� �ֱ� 
	check[1] = 1;

	while (front < back) {
		x = queue[++front];
		printf("%d ", x);

		for (i = 0; i < map[x].size(); i++) {//x�ϰ� ����� ��� ã�� 
			if (check[map[x][i]] == 0) {
				check[map[x][i]] = 1;
				queue[++back] = map[x][i]; //����� ��� ť�� �ֱ� 
			}
		}

	}
	return 0;
}