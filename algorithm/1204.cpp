#include<iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int i, index, test_case, tmp;
    vector<int>count(101);
    int T;

    scanf("%d", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &index);

        for (i = 1; i <= 100; i++) {
            cin >> tmp;

            count[tmp]++;
       
        }


        index = 0; int max = 0;
        for (i = 1; i < 101; i++) {
            if (count[i] >= count[max]) {
        
                max = i;
            }
        }

        printf("#%d %d \n", test_case, max);
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}