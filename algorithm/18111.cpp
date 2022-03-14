#include<stdio.h>
#include<cmath>
using namespace std;
int N, M;
long long B;
int ground[500][500];
int depth[257];
bool lackB = false;
int main() {

	int i, j, a, b;

	scanf("%d %d %lld", &N, &M, &B);
	//B���� �κ��丮�� ����Ǿ�����. 

	int min_time = 987654321, ans_depth = 0, tmp_time, tmp_b;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			scanf("%d", &ground[i][j]);
			depth[ground[i][j]]++;
		}

	//���� ���̸� �����ϰ�

	//�� ���� -1: 2�� , �κ��丮�� �ֱ� B++; 
	//�� ���� +1: 1�� , �κ��丮���� ���� B--; 

	//�� ����� �ð�, ���� ����



	for (i = 0; i <= 256; i++) {
		//depth�� ��������

		tmp_time = 0;
		tmp_b = B;
		printf("depth:%d ������� \n", i);
		for (a = 0; a < N; a++) {
			for (b = 0; b < M; b++) {

				int diff = abs(ground[a][b] - i);
				//printf("ground[%d][%d]�� %d�� %d ���̳� \n",a,b,i,diff);
				if (diff == 0) {
					printf("����� ���� ������ ������ ~ \n");
					continue;
				}

				for (j = 1; j <= diff; j++) {
					if (j > tmp_b && j < 0) {
						//printf("B�������� \n");
						lackB = true;
						break;
					}
					if (j > 0) {
						//�� ���� �ִ� ��� -> �κ��� �߰�  
						tmp_b++;
						tmp_time += 2;
					}
					else {
						//�� ���� ��� -> �κ����� �� �� 
						tmp_b--;
						tmp_time += 1;
					}
				}



				printf("(%d, %d): tmp_b:%d, tmp_time:%d \n", a, b, tmp_b, tmp_time);
			}
		}

		if (min_time >= tmp_time && lackB == false) {
			min_time = tmp_time;
			ans_depth = i;
			printf("min_time:%d ans_depth:%d �� ���� \n", min_time, ans_depth);
		}

	}


	printf("%d %d", min_time, ans_depth);


	return 0;
}