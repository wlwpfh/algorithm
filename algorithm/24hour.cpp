#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, n, m;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &n, &m);

		printf("#%d %d \n", test_case, (n + m) % 24);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}