#include<stdio.h>
#include<unordered_map>
#include<memory.h>
#include<string>
#define MAX 200000
using namespace std;
char fr1[20], fr2[20];
char tmp[40];
int F;
unordered_map<string, int>info;
int friends[MAX + 1];
int Find(int r) {
	if (r == friends[r])
		return r;
	return friends[r] = Find(friends[r]);
}
void Union(int a, int b) {
	int n = Find(a);
	int m = Find(b);

	if (n < m) {
		friends[m] = n;
	}
	else {
		friends[n] = m;
	}
}

int main() {
	int i, n, j, count = 1, sum = 0, k, num1, num2;
	scanf("%d", &F);

	for (i = 0; i < F; i++) {
		scanf("%d", &n);

		for (j = 1; j <= n; j++) {
			int number;
			scanf("%s %s", fr1, fr2);


			if (info[fr1] == 0) {
				friends[count] = count;
				info[fr1] = count++;
			}

			if (info[fr2] == 0) {
				friends[count] = count;
				info[fr2] = count++;
			}


			num1 = info[fr1];
			num2 = info[fr2];
			int num = num1 < num2 ? num2 : num1;

			Union(info[fr1], info[fr2]);

			number = friends[info[fr1]];


			for (k = 1; k <= info.size(); k++) {
				if (friends[k] == num)
					friends[k] = number;
			}

			for (k = 1; k <= info.size(); k++) {
				if (number == friends[k])
					sum++;
			}
			printf("%d \n", sum);
			sum = 0;
		}

		memset(friends, 0, sizeof(friends));
		count = 1;
		info.clear();
	}


	return 0;
}