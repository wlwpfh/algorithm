#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> fib(n + 1);
    int i = 1, answer = 0;

    fib[0] = 0;
    if (n > 0) {
        fib[1] = 1;
        for (i = 2; i < n + 1; i++) {
            fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
        }
    }

    return fib[n];
}