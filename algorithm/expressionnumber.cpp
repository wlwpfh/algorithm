#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;
    n--;
    while (n > 0) {
        a++;
        n = n - a;

        if (n % a == 0)
            answer++;
    }

    return answer + 1;
}