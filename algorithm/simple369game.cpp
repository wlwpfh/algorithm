#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case, T, i, count;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		count = 0;
		string tmp = to_string(test_case);
		for (i = 0; i < tmp.length(); i++) {
			if (tmp[i] == '3' || tmp[i] == '6' || tmp[i] == '9')
				count++;
		}
		if (count == 0)
			printf("%s ", tmp.c_str());
		else if (count == 1)
			printf("- ");
		else {

			for (i = 0; i < count; i++)
				printf("-");
			printf(" ");
		}
	}
	return 0;
}