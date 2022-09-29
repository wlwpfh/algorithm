#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string tenary = "";

    while (n != 0) {
        tenary.insert(0, to_string(n % 3));
        n /= 3;
    }
    for (int i = tenary.length() - 1; i >= 0; i--) {
        answer += pow(3, i) * (tenary[i] - '0');
    }

    return answer;
}