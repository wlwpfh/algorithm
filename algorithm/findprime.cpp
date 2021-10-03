#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<int> prime(n + 1);
    int answer = 0;
    int i, j;
    for (i = 2; i <= n; i++) {
        prime[i] = i;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (prime[i] == 0)
            continue;

        for (j = i * i; j <= n; j += i) {
            prime[j] = 0;

        }

    }
    for (i = 2; i <= n; i++) {
        if (prime[i] != 0)
            answer++;
    }
    return answer;
}