#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int L, C;
vector<char> arr;
char ans[15];
bool visited[15];

//1. 최소 하나의 모음 aeiou, 최소 두 개의 자음
//2. 오름 차순이어야 할 것

bool check() {
	int a = 0, b = 0;
	for (int i = 0; i < L; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
			a++;
		}
		else
			b++;
	}
	return a >= 1 && b >= 2 ? true : false;
}

void combi(int index, int count) {
	if (count == L && check()) {
		for (int i = 0; i < L; i++)
			printf("%c", ans[i]);
		printf("\n");

		return;
	}

	for (int i = index; i < C; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[count] = arr[i];

			if (count != L)
				combi(i, count + 1);
			else
				combi(i + 1, count + 1);

			visited[i] = false;
		}
	}
}

int main() {

	scanf("%d %d", &L, &C);

	char tmp;

	for (int i = 0; i < 2 * C; i++) {
		scanf("%c", &tmp);
		if (tmp == ' ' || tmp == '\n')
			continue;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	combi(0, 0);


	return 0;
}