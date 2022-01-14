#include<stdio.h>
#include<algorithm>
#define MAX_SIZE 1000000
using namespace std;

long long n, m, k, b, sum;
long long lla[MAX_SIZE];
// 출력 자체는 long을 넘지 않는다.  

void init() {
	// 트리 안에 값 집어넣기 
	for (int i = b - 1; i > 0; i--) {
		lla[i] = (lla[i << 1] + lla[(i << 1) + 1]);
	}
}
void print(int start, int end) {
	//-Start 일 경우
	//Index 가 홀수 일 경우 : Max값 갱신 후 부모노드로 이동
	//Index가 짝수일 경우 : 갱신 없이 부모 노드로 이동
	//
	//- End 일 경우
	//Index 가 홀수 일 경우 : 갱신 없이 부모 노드로 이동
	//Index가 짝수일 경우 : Max값 갱신 후 부모노드로 이동

	while (start <= end) {
		if (start % 2 == 1)
			sum = max(lla[start], sum);
		if (end % 2 == 0)
			sum = max(lla[end], sum);

		start = (start + 1) / 2;
		end = (end - 1) / 2;

	}

}
void update(int i1, int i2) {
	long long tmp = lla[i1];
	lla[i1] = lla[i2];
	lla[i2] = tmp;
	//자기 위에 배열들 업데이트시키기 
	for (int i = b - 1; i > 0; i--) {
		lla[i] = (lla[i << 1] + lla[(i << 1) + 1]);
	}
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
	int a1, b1, c1;
	for (int i = 0; i < m + k; i++) {
		scanf("%d %d %d", &a1, &b1, &c1);
		if (a1 == 1) {
			update(b1, c1);

		}
		else { //a==2인 경우  
			print(b1, c1);
			printf("%d \n", sum);
		}
	}


	return 0;
}