#include <vector>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, index, i, sum = 0, max = 0;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &index);
		sum = 0; max = 0;
		vector<int> price(index);
		for (i = 0; i < price.size(); i++)
			scanf("%d", &price[i]);

		max = price[price.size() - 1];
		printf("max: %d \n", max);

		for (i = price.size() - 1; i >= 0; i--) {
			if (price[i] < max) {
				sum += max - price[i];
				//max=price[i];

			}
			else {
				max = price[i];
			}
		}
		printf("#%d %d \n", test_case, sum);

	}
	return 0;
}