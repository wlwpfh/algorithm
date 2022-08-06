#include<stdio.h>
#include<queue>

using namespace std;

int K, N;

struct Num {
	int number;
	int order;

	Num(int a, int b) {
		number = a;
		order = b;
	}

	bool operator<(const Num n)const {
		return number < n.number;
	}
};
priority_queue<Num> q;
//해당 숫자, 입력될 때의 index 

int main() {

	int i = 0, div, tmp;

	scanf("%d %d", &N, &K);

	printf("잘입력됨");

	tmp = N;

	while (tmp >= 10) {

		int div = tmp % 10;
		tmp /= 10;
		q.push(Num(div, i));

		i++;
	}
	q.push(Num(tmp, i));

	while (!q.empty()) {
		//pair<int,int>p=q.top();
		Num p = q.top();
		printf("숫자:%d, 순서: %d\n", p.number, p.order);
		q.pop();
	}

	return 0;
}