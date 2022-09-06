#include<iostream>
#include<climits>
using namespace std;
int max_sum = INT_MIN;
int N;
string s;

int cal(int a, int b, char oper) {
	int result = a;
	if (oper == '+')
		result += b;
	else if (oper == '-')
		result -= b;
	else
		result *= b;

	return result;
}

void DFS(int index, int sum) {
	if (index > N - 1) {
		max_sum = sum > max_sum ? sum : max_sum;
		return;
	}//종료조건 

	char oper = (index == 0) ? '+' : s[index - 1];

	//묶을 수 있는지 체크 -> 묶기  
	if (index + 2 < N) {
		int tie = cal(s[index] - '0', s[index + 2] - '0', s[index + 1]);
		DFS(index + 4, cal(sum, tie, oper));
		//중첩할 수 없게 아예 다음 index로 넘어가버림 			
	}

	//묶기


	//안묶기  - 숫자 1 연산자 숫자 2
	DFS(index + 2, cal(sum, s[index] - '0', oper));
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> s;

	//수는 0-9 사이의 숫자
	//여기에 나오는 연산자의 우선순위는 동일함 + - *

	DFS(0, 0);

	cout << max_sum;

	return 0;
}