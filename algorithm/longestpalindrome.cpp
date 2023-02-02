#include <string>
#include <algorithm>

using namespace std;

int count_1 = 1, count_2 = 0;
bool even = false, odd = false;

int solution(string s)
{
    int answer = 1;
    s += "0";
    for (int i = 1; i < s.length(); i++) {
        int left = i - 1;
        int right = i + 1;
        odd = true; even = true;
        count_1 = 1; count_2 = 0;
        while (left >= 0 && right < s.length()) {
            if (s[left] == s[right - 1])
                count_2 += 2;
            else
                even = false;

            if (s[left--] == s[right++])
                count_1 += 2;
            else
                odd = false;
            //printf("answer:%d, count_1:%d, count_2:%d \n",answer, count_1, count_2);
            answer = max(answer, max(count_1, count_2));

            if (!odd && !even)
                break;

        }
    }
    return answer;
}