#include<stdio.h>
#include<stack>

using namespace std;

int main() {

	int K, num, answer = 0;
	scanf("%d", &K);

	stack<int>s;

	for (int i = 0; i < K; i++) {
		scanf("%d", &num);

		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	while (s.size() != 0) {
		answer += s.top();
		s.pop();
	}

	printf("%d", answer);

	return 0;
}