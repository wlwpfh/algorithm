
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int sum, n, i;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		sum = 0;
		scanf("%d", &n);

		for (i = 1; i <= n; i++) {
			if (i % 2 == 0) sum -= i;
			else sum += i;
		}

		printf("#%d %d \n", test_case, sum);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}