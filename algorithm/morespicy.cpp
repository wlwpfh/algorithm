#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, tmp = 0, count = 0, i = 0;
    make_heap(scoville.begin(), scoville.end());
    sort_heap(scoville.begin(), scoville.end());
    for (i = 0; i < scoville.size(); i++)
        printf("%d ", scoville[i]);
    printf("\n ");
    while (1) {
        if (answer == 2) {
            //heap���� ��� ���� K���� ���� ��� break�� ����������
            break;
        }
        else {
            tmp = scoville[i] + scoville[i + 1] * 2;
            pop_heap(scoville[i], scoville[i + 1], comp);
            scoville.push_back(tmp); answer++;
            printf("���� �� ��:%d+ (%d*2)= %d \n", scoville[i], scoville[i + 1] + 1, tmp);
            i += 2;



        }
        sort_heap(scoville.begin(), scoville.end());
        printf("���� ���ĵ� heap: ");
        for (i = 0; i < scoville.size(); i++)
            printf("%d ", scoville[i]);
        printf("\n");
    }

    return answer;
}

https://leeminju531.tistory.com/20