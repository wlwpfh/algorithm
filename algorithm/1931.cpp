#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Time {
	int start;
	int end;

	Time(int a, int b) {
		start = a;
		end = b;
	}
	bool operator<(const Time a) const {
		return end > a.end;
	}
};

vector<Time> v;

int main() {

	int i, N, a, b;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(Time(a, b));
	}
	// end가 커야하는지 start가 커야하는지 판단하기  

	sort(v.begin(), v.end());

	for (Time a : v) {
		printf("%d %d \n", a.start, a.end);
	}

	return 0;
}