#include<stdio.h>
#include<vector>
using namespace std;

int N, R, count;
int arr[15];
int checked[15];
int print[15];
void DFS(int number) {
	if (number == R) {
		for (int i = 0; i < R; i++)
			printf("%d ", print[i]);
		printf("\n");
		count++;

		return;
	}

	for (int i = 0; i < N; i++) {
		if (checked[i] == false) {
			checked[i] = true;
			print[number] = arr[i];
			DFS(number + 1);
			checked[i] = false;

		}




	}

}

int main() {

	scanf("%d %d", &N, &R);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	DFS(0);
	printf("%d", count);
}