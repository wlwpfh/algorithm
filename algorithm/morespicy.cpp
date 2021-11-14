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
            //heap안의 모든 수가 K보다 높은 경우 break로 빠져나오기
            break;
        }
        else {
            tmp = scoville[i] + scoville[i + 1] * 2;
            pop_heap(scoville[i], scoville[i + 1], comp);
            scoville.push_back(tmp); answer++;
            printf("새로 들어간 값:%d+ (%d*2)= %d \n", scoville[i], scoville[i + 1] + 1, tmp);
            i += 2;



        }
        sort_heap(scoville.begin(), scoville.end());
        printf("새로 정렬된 heap: ");
        for (i = 0; i < scoville.size(); i++)
            printf("%d ", scoville[i]);
        printf("\n");
    }

    return answer;
}

https://leeminju531.tistory.com/20