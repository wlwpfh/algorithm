#include<stdio.h>
#include<cmath>
using namespace std;

long long x, y;
//100을 곱해야하니까 int의 범위가 넘음.

bool findMin(int num) {
	if (y * 100 / x < (y + num) * 100 / (x + num))
		return true;
	else
		return false;
}

int main() {

	scanf("%lld %lld", &x, &y);


	int ub = 100000000, lb = 0;

	if (y * 100 / x >= 99) {

		printf("-1");
		return 0;
	}
	else {

		while (lb + 1 < ub) {
			int m = lb + (ub - lb) / 2;
			if (findMin(m)) ub = m;
			else lb = m;
		}
		printf("%d", ub);

		return 0;
	}


}