#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int t, i, j, tmp, k;
	scanf("%d", &t);
	int a, b;
	bool p1, p2;
	vector<int> sum(t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		sum[i] = a + b;
	}
	//�� �� �Ҽ��� �Ǵ� ��츦 ã�ƾ���.. �̰Ŵ� vector pair�� �ؼ� <j�� ��, �Ҽ�����> �̷��� �� ��? 
	for (i = 0; i < sum.size(); i++) {
		p1 = true; p2 = true;
		for (j = 2; j < sum[i] / 2; j++) {
			//tmp=sum[i]-j;

			//j�� �Ҽ����� Ȯ�� . tmp�� �Ҽ����� Ȯ��
			for (k = 2; k < j / 2; k++) {
				if (j % k == 0) {
					//check.push_back(make_pair(j,true));
					p1 = false;
				}
			}
			if (p1 == true) {

				tmp = sum[i] - j;
				printf("j: %d, tmp:%d \n", j, tmp);
				for (k = 2; k < tmp / 2; k++) {
					if (tmp % k == 0) {
						//check.push_back(make_pair(j,true));
						p2 = false;
						printf("tmp(%d) % k(%d) = %d \n", tmp, k, tmp % k);
					}
				}
				if (p2 == true) {
					printf("YES \n");
				}
				else {
					printf("NO2 \n");
				}
			}
			else {
				printf("NO1 \n");
			}

		}

	}

	return 0;
}