#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, tmp = 0, count = 0, i = 0, j;
    make_heap(scoville.begin(), scoville.end()); //front�� 12
    sort_heap(scoville.begin(), scoville.end()); //front�� 1
    //printf("%d ",scoville.back());
    while (1) {
        if (scoville.front() > K || answer == 2) {
            //heap���� ��� ���� K���� ���� ��� break�� ����������
            break;
        }
        else {
            tmp = scoville[i] + scoville[i + 1] * 2;
            printf("i: %d ,", scoville[i]);
            printf("i+1 : %d \n", scoville[i + 1]);
            printf("%d = %d + %d \n", tmp, scoville[i], scoville[i + 1] * 2);
            scoville.erase(scoville.begin());
            scoville.erase(scoville.begin());
            scoville.push_back(tmp); answer++;
            //printf("���� �� ��:%d+ (%d*2)= %d \n",scoville[i], scoville[i+1]+1,tmp);
            i += 2;

            sort_heap(scoville.begin(), scoville.end());

            for (j = 0; j < scoville.size(); j++)
                printf("%d ", scoville[j]);

        }
        sort_heap(scoville.begin(), scoville.end());
        //printf("���� ���ĵ� heap: ");
        for (i = 0; i < scoville.size(); i++)
            //  printf("%d ",scoville[i]);
            printf("\n");
    }

    return answer;
}