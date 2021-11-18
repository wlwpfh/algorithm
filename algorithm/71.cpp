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
				//��� ������ 1�� �����߱� ������ �� ������ Ƚ���� �ؾ� �� 
				exit(0);
				//���α׷� ��ü�� ���� 
			}
			else {
				if (check[pos] == 0)
				{
					check[pos] = check[x] + 1;
					//üũ �迭�� ���ÿ� ���� �迭
					Q.push(pos);
				}
			}
		}
	}


	return 0;
}