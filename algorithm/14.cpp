#include<iostream>
#include<math.h>
using namespace std;

int reverse(int x) {

	int tmp = 0;
	int rev = 0;

	while (x > 0) {
		tmp = x % 10;
		rev = rev * 10 + tmp;
		x = x / 10;
	}
	return  rev;
}

bool isPrime(int x) {
	bool checked = true;

	if (x == 1)
		return false;

	for (int i = 2; i <= (x / 2); i++) {
		if (x % i == 0)
			checked = false;
	}
	return checked;
}
int prime[100];
int main014() {
	int count;

	int num[100] = { 0, };

	int rev;

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> num[i];

	}

	for (int i = 0; i < count; i++) {
		int rev = reverse(num[i]);

		if (isPrime(rev)) {
			printf("%d ", rev);
		}
	}
	return 0;
}