#include<stdio.h>

using namespace std;

int arr[65][65];

void recursive(int x, int y, int number) {
	//���� ��
	int point = arr[x][y];
	for (int i = x; i < x + number; i++) {
		for (int j = y; j < y + number; j++) {
			if (point != arr[i][j]) {
				point = -1;
				break;
			}//�������� �ٸ� ���� ����  
		}
		if (point == -1)
			break;
	}

	if (point == -1) {
		//�ٸ� ���� �ִ� �Ŵϱ� 
		printf("(");
		recursive(x, y, number / 2); //���� ��  
		recursive(x, y + number / 2, number / 2); //������ ��  
		recursive(x + number / 2, y, number / 2); //����  �Ʒ�  
		recursive(x + number / 2, y + number / 2, number / 2); // ������ �Ʒ�  
		printf(")");
	}
	else if (point == 1) {
		printf("1"); //�� 1�� �Ŵϱ�  
	}
	else if (point == 0)
		printf("0");

}

int main() {

	int N, i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%1d", &arr[i][j]);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	recursive(1, 1, N);

	return 0;
}