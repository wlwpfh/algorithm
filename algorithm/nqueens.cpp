#include <string>
#include <vector>

using namespace std;
int answer;
int col[15];

bool check(int row) {
    for (int i = 0; i < row; i++) {
        if (col[i] == col[row] || abs(col[row] - col[i]) == row - i)
            return false;
    }
    return true;
}

void DFS(int index, int n) {
    if (index == n) {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++) {
        col[index] = i;

        if (check(index))
            DFS(index + 1, n);
    }
}

int solution(int n) {

    DFS(0, n);

    return answer;
}