#include<stdio.h>
#include<vector>

using namespace std;

int main49_() {
	int n, i, j, count = 0;

	scanf("%d", &n);

	vector<vector<int> > input(2, vector<int>(n));

	for (i = 0; i <= 1; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &input[i][j]);
		}
	}


	for (i = 0; i < n; i++) { //�� ���� �� üũ�ϱ� 
		input[0][i]; //���� 
		input[1][j]; //���� 

		for (j = 0; j < n; j++) {
			if (input[0][i] > input[1][j]) {
				count = count + input[1][j];
			}
			else {
				count = count + input[0][i];
			}
		}

	}

	printf("%d", count);


	return 0;
}