#include<stdio.h>
#include<vector>

using namespace std;

int N, B, C;

int main() {
	vector<int> members;
	long long answer = 0;
	int tmp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		members.push_back(tmp);
	}
	scanf("%d %d", &B, &C);

	for (int i = 0; i < members.size(); i++) {
		members[i] -= B;
		answer++;

		if (members[i] <= 0)
			continue;
		int div = members[i] / C;

		if (members[i] % C == 0) {
			answer += div;
		}
		else {
			answer += (div + 1);
		}

	}
	printf("%lld", answer);

	return 0;
}