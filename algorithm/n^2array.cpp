#include <string>
#include <vector>

using namespace std;

struct Index {
    long long x; long long y;
    Index(long long a, long long b) {
        x = a; y = b;
    }
};

vector<int> solution(int n, long long l, long long r) {
    vector<int> answer;
    Index left = Index(l / n, l % n);
    Index right = Index(r / n, r % n);

    int x = left.x, y = left.y;
    for (int i = 0; i <= r - l; i++) {
        if (y == n) {
            y = 0;
            x++;
        }
        if (x > y)
            answer.push_back(x + 1);
        else
            answer.push_back(y + 1);

        y++;
    }
    return answer;
}