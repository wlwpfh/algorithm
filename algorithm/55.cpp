#include<stdio.h>
#include<stack>

using namespace std;

int main() {
	int num, i, arr[30], count = 0, max = 0;


	//1�� ������ �ٷ� pop�ϱ� 

	stack <int> s;

	scanf("%d", &num);
	max = num;

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	int array_max = arr[0];
	//count�� ���� ���� ���� �ָ� ����Ű�� 

	i = 0;

	while (1) {

		if (array_max >= arr[i]) {
			s.push(arr[i]);
			printf("P");
		}
		//		else if(arr[i]>array_max &&arr[i]==max){
		//			s.push(arr[i]);
		//			printf("P");
		//			s.pop();
		//			printf("O");
		//		}
		else {
			while (!s.empty()) {
				s.pop();
				printf("O");
			}


		}
		i++;

		if (i == num)
			break;

	}

	re