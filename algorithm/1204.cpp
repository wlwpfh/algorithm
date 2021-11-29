
#include<iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int i, index = 0, test_case, tmp;
    vector<int>count(1001);
    int T;

    scanf("%d", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &index);

        for (i = 1; i <= 1000; i++) {
            scanf("%d", &tmp);

            count[tmp]++;

        }

        int max = 1;
        for (i = 1; i < 1001; i++) {
            if (count[i] >= count[max]) {
                max = i;
            }
        }

        printf("#%d %d \n", test_case, max);

        for (i = 0; i < 1001; i++)
            count[i] = 0;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}