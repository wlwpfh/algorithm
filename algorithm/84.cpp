#include<vector>
#include<iostream>

using namespace std;

int n, res = 0;
int t[20], p[20];

void DFS(int L, int sum) { //날짜와 그에 따른 수익  
	if (L == n + 1) {
		if (sum > res)
			res = sum; //수익이 기존의 수익보다 큰 경우
	}
	else {
		if (L + t[L] <= n + 1) { //현재에 상담 기간을 넣어줌  
			DFS(L + t[L], sum + p[L]); //한다 
		}
		DFS(L + 1, sum); //안한다.  
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	int i;
	int a, b;
	scanf("%d", &n);


	for (i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}

	DFS(1, 0);

	printf("%d", res);

	return 0;
}