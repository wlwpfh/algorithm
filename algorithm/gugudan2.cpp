#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	int n, m;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &n, &m);

		printf("#%d ", test_case);

		if (n >= 10 || m >= 10)
			printf("-1 \n");
		else
			printf("%d \n", n * m);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}