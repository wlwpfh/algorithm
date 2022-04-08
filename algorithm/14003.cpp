#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>

#define MAX_N 1000005

using namespace std;

int A[MAX_N];
vector<int> v;
int track[MAX_N]; //��ġ ã��� 
stack<int> s; //��¿�  
int main() {

	int i, N, count = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	v.push_back(A[1]);

	for (i = 2; i <= N; i++) {
		if (v[count] < A[i]) {
			//����ִ� �� ���� �� < A�� ���ҵ�
			v.push_back(A[i]);
			track[i] = ++count;
		}
		else {
			int index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
			//�̺�Ž���� �� ����ϱ�!  
			//lower_bound: ã������ key������ ���ų� ū ���ڰ� �迭�� �������� ó�� �����ϴ� �� ã�� - �ε��� ��ȣ�� ����   
			v[index] = A[i];
			track[i] = index;
			//�� �ں��ٴ� �ƴ�����ū ��� v�� ���ο� �ڸ��� A[i]�� ���� �־��ְ� 
			//track�� i��°�� �ش� index���� �־��ش�.  

		}
	}


	printf("%d \n", count + 1);


	for (i = N; i >= 1; i--) {
		if (count == -1)
			break;

		if (track[i] == count) {
			s.push(A[i]);
			count--;
		}
	}

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}