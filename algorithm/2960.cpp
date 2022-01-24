#include<stdio.h>
#include<cmath>

using namespace std;

int main() {
	int n, k, answer;
	scanf("%d %d", &n, &k);
	int count = 0;
	int arr[n + 1];

	int i, j;
	for (i = 2; i <= n; i++)
		arr[i] = i;

	for (i = 2; i <= n; i++) {
		if (arr[i] == 0)
			continue;

		arr[i] = 0;
		count++;
		//printf("지워진 수는 %d이다 \n",i);
		if (count == k) {
			answer = i;
			break;
		}

		for (j = i * i; j <= n; j += i) {
			if (arr[j] == 0)
				continue;
			else {
				arr[j] = 0;
				//printf("지워진 수는 %d이다 \n",j);
				count++;
			}

			if (count == k) {
				answer = j;
				break;
			}
		}


		if (answer != 0)
			break;


	}

	printf("%d", answer);

	return 0;
}