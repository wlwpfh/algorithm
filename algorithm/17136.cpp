#include<stdio.h>
#include<algorithm>
using namespace std;

int map[10][10];
int paper[6] = { 0,5,5,5,5,5 };
int res = 987654321;

bool canPutPaper(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (i < 0 || i >= 10 || j < 0 || j >= 10) //������ ����� �� 
				return false;
			if (map[i][j] != 1)

				return false;
		}
	}
	return true;
} //���̸� ���� �� �ִ��� Ȯ��  

void putPaper(int x, int y, int size, int value) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			map[i][j] = value;
		}
	}
} //���̰ų� ���� ����  - value������ �������ֱ� 

void DFS(int x, int y, int count) {

	if (x == 9 && y > 9) {
		res = min(res, count);
		return;
	}
	if (count >= res)
		return;
	if (y > 9) { //�ٽ� 0����  
		DFS(x + 1, 0, count);
		return;
	}
	if (map[x][y] == 1) {
		for (int i = 5; i >= 1; i--) {
			if (paper[i] > 0 && canPutPaper(x, y, i)) {
				//���̰� �����ְ� ���̸� ���� �� �ִ�

				putPaper(x, y, i, 0); //���̱� 1 ->0
				paper[i]--;
				DFS(x, y, count + 1);
				putPaper(x, y, i, 1); //���� 0-> 1
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


	//��� 1�� ���µ� �ʿ��� �������� �ּ� ���� 
	//��� ���� �� �Ұ����� ��쿣 -1 ��� 
	//�� ������ ���̴� 5���� ������ ������ 1*1, 2*2, 3*3, 4*4, 5*5�� �����̸� ����ؾ� ��,

	// 1 ã�� -> ���̱� �õ� -> ���̱� -> �ȵǸ� ����  

	//1. ���� �� �ִ��� Ȯ�� -> 2. ���̱�� ���� ���� �ݺ�  
	DFS(0, 0, 0);


	if (res == 987654321)
		printf("-1");
	else
		printf("%d", res);


	return 0;
}