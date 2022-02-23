#include<stdio.h>

using namespace std;

int arr[8];
int checked[8];
int Send() {
	return arr[6] * 1000 + arr[1] * 100 + arr[3] * 10 + arr[0];
}

int More() {
	return arr[2] * 1000 + arr[4] * 100 + arr[5] * 10 + arr[1];
}

int Money() {
	return arr[2] * 10000 + arr[4] * 1000 + arr[3] * 100 + arr[1] * 10 + arr[7];
}

void DFS(int level) {
	if (level == 8) {
		//숫자가 다 찬 경우  
		if (Send() + More() == Money()) {
			printf("  %d %d %d %d \n", arr[6], arr[1], arr[3], arr[0]);
			printf("+ %d %d %d %d \n", arr[2], arr[4], arr[5], arr[1]);
			printf("-----\n");
			printf("%d %d %d %d %d\n\n", arr[2], arr[4], arr[3], arr[1], arr[7]);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (checked[i] == 0) {
				arr[level] = i;
				checked[i] = 1;
				DFS(level + 1);
				checked[i] = 0;
			}
		}
	}

}

int main() {

	DFS(0);

	return 0;
}