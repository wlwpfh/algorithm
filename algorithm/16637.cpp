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
	}//�������� 

	char oper = (index == 0) ? '+' : s[index - 1];

	//���� �� �ִ��� üũ -> ����  
	if (index + 2 < N) {
		int tie = cal(s[index] - '0', s[index + 2] - '0', s[index + 1]);
		DFS(index + 4, cal(sum, tie, oper));
		//��ø�� �� ���� �ƿ� ���� index�� �Ѿ���� 			
	}

	//����


	//�ȹ���  - ���� 1 ������ ���� 2
	DFS(index + 2, cal(sum, s[index] - '0', oper));
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> s;

	//���� 0-9 ������ ����
	//���⿡ ������ �������� �켱������ ������ + - *

	DFS(0, 0);

	cout << max_sum;

	return 0;
}