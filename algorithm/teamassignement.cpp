#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	int n;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &n);

		printf("#%d %d \n", test_case, n > 2 ? n / 3 : 0);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}