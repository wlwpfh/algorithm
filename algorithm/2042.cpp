#include<stdio.h>
#define MAX_SIZE 1000000
using namespace std;

long long n, m, k, b;
long long lla[MAX_SIZE];
// 출력 자체는 long을 넘지 않는다.  

void init() {
	// 트리 안에 값 집어넣기 
	for (int i = b - 1; i > 0; i--) {
		lla[i] = (lla[i << 1] + lla[(i << 1) + 1]);
	}
}

void update() {
	//자기 위에 배열들 업데이트시키기 
}

int main() {
	int tmp;
	long long answer;
	scanf("%d %d %d", &n, &m, &k);

	for (b = 1; b < n; b <<= 1);
	//b의 값이 8이 되어서 해당 값이 된다. 

	for (int i = b; i < n + b; i++) {
		scanf("%lld", &lla[i]);
	}

	init();



	printf("%lld", answer);
	return 0;
}