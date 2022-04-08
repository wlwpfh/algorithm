#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>

#define MAX_N 1000005

using namespace std;

int A[MAX_N];
vector<int> v;
int track[MAX_N]; //위치 찾기용 
stack<int> s; //출력용  
int main() {

	int i, N, count = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	v.push_back(A[1]);

	for (i = 2; i <= N; i++) {
		if (v[count] < A[i]) {
			//들어있는 맨 뒤의 값 < A의 원소들
			v.push_back(A[i]);
			track[i] = ++count;
		}
		else {
			int index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
			//이분탐색할 때 사용하기!  
			//lower_bound: 찾으려는 key값보다 같거나 큰 숫자가 배열의 언제에서 처음 등장하는 지 찾기 - 인덱스 번호가 나옴   
			v[index] = A[i];
			track[i] = index;
			//맨 뒤보다는 아니지만큰 경우 v에 새로운 자리에 A[i]의 값을 넣어주고 
			//track의 i번째에 해당 index값을 넣어준다.  

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