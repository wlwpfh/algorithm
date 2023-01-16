#include <string>
#include <vector>

using namespace std;

bool visited[20];

vector<int> answer(20);
vector<int> tmp(20);

void getLine(int number, int count, long long k, int n, long long counts) {
    if (count == n) {
        visited[tmp[n - 1]] = false;
        for (int i = 0; i < count; i++)
            printf("%d ", tmp[i]);
        if (k == counts)
            answer = tmp;

        return;
    }
    for (int i = number; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            tmp[count] = i;
            getLine(i + 1, count + 1, k, n, counts + 1);
            visited[i] = false;
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

    getLine(1, 0, k, n, 0);

    return answer;
}