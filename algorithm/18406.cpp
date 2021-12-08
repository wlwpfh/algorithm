#include<stdio.h>
#include<string>
using namespace std;

int main() {
	int n;
	string tmp;
	string s1, s2;
	int sum1 = 0, sum2 = 0;
	scanf("%d", &n);

	tmp = to_string(n);

	s1 = tmp.substr(0, tmp.length() / 2);
	s2 = tmp.substr(tmp.length() / 2, tmp.length() / 2);

	for (int i = 0; i < s1.size(); i++) {
		sum1 += s1[i] - 48;
		sum2 += s2[i] - 48;
	}

	if (sum1 == sum2)
		printf("LUCKY \n");
	else
		printf("READY \n");

	return 0;
}