#include<stdio.h>

using namespace std;

int N, M, r, c, d, result;
int home[50][50]; // �׵θ��� �� 1�� ���̴�
bool visited[50][50];
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

int main() {
	int a, b, c;

	scanf("%d %d", &N, &M);

	scanf("%d %d %d", &r, &c, &d);
	//q.push(Cleaner(a,b,c));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &home[i][j]);

	//printf("�ߵ���");

	while (1) {
		if (!visited[r][c]) {
			result++;
		} //û���ϱ�  
		visited[r][c] = true;
		bool cleaned = false;

		//�̵��ϱ� 
		for (int i = 1; i <= 4; i++) {
			int nd = (d + 4 - i) % 4;
			int nr = r + dx[nd];
			int nc = c + dy[nd];

			if (home[nr][nc] == 1 || visited[nr][nc] == true)
				continue;

			//���� �ƴϰ� ������ ���� ���̶�� �̵�  
			cleaned = true;
			r = nr, c = nc, d = nd;
			break;
		}//1

		if (!cleaned) { //û�Ҹ� ���� ���� ���
			int nd = (d + 2) % 4;
			int nr = r + dx[nd];
			int nc = c + dy[nd];



			if (home[nr][nc] == 1)
				break;
			else {
				r = nr;
				c = nc;
				//d=nd;
			}
		}
	}

	printf("%d", result);

	return 0;
}