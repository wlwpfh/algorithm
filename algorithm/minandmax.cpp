#include <string>
#include <vector>

using namespace std;
//이게 s[0]이 마이너스인 경우가 있음... 그래서 그래
string solution(string s) {
    string answer = "";
    int i;
    int min = 10000000000, max = -100000000;
    //printf("%d ",s[0]);
    bool min_plus = true, max_plus = true;
    for (i = 1; i < s.length(); i++) {
        //printf("%d ",s[i]);
        if (s[i] == 32)
            continue;
        if (s[i - 1] == 45) {
            printf("%d는 마이너스로 시작한다. \n", i - 1);
            if (min > (s[i] - 48))
            {
                min = s[i] - 48;
                min_plus = false;
                printf("min은 -%d \n", min);
            }

            if (max < (s[i] - 48))
            {
                max = s[i] - 48;
                max_plus = false;
                printf("max은 -%d \n", min);
            }
        }
        else {
            if (min > (s[i] - 48))
                min = s[i] - 48;
            if (max < (s[i] - 48))
                max = s[i] - 48;
        }

    }
    printf(" \n min: %d %d, max: %d %d", min_plus, min, max_plus, max);

    return answer;
}