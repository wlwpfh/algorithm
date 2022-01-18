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
		if (start == a.start)
			return end > a.end;

		return start > a.start;
	}
	//end가 항상 start보다 같거나 크니까  
};

vector<Time> v;

int main() {

	int i, N, a, b, count, rest = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(Time(a, b));
	}

	sort(v.begin(), v.end());

	count = 1;
	rest = v[0].start;

	for (i = 1; i < N; i++) {
		if (rest >= v[i].end) {
			rest = v[i].start;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}