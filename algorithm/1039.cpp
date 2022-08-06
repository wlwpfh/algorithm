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
//�ش� ����, �Էµ� ���� index 

int main() {

	int i = 0, div, tmp;

	scanf("%d %d", &N, &K);

	printf("���Էµ�");

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
		printf("����:%d, ����: %d\n", p.number, p.order);
		q.pop();
	}

	return 0;
}