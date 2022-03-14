#include<stdio.h>
#include<algorithm>
using namespace std;

int X, Y, W, H;

int main() {


	scanf("%d %d %d %d", &X, &Y, &W, &H);
	int distance = min(min(X - 0, Y - 0), min(W - X, H - Y));

	printf("%d", distance);
	return 0;
}