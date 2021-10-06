#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int i, j, count, answer = 0;
    for (i = left; i <= right; i++) {
        count = 0;
        for (j = 1; j <= i / 2; j++) {
            if (i % j == 0)
                count++;
        }

        if (count % 2 == 0)
            answer = answer - i;
        else
            answer = answer + i;
    }
    return answer;
}