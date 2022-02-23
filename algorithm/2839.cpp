#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int sugar[5001] = { 0,0,0,1,0,1,0 };

int bongji(int number) {

	if (sugar[number] > 0) {
		return sugar[number];
	}

	if (number >= 3)
		return sugar[number] += bongji(number - 3);
	else if (number >= 5)
		return sugar[number] += bongji(number - 5);

}


int main() {

	scanf("%d", &N);
	sugar[N] = -1;
	if (sugar[N] == 0)
		printf("-1");
	else
		printf("%d", sugar[N]);

	return 0;
}