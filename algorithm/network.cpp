#include <string>
#include <vector>
using namespace std;

int N, parents[200], same = 0, answer;

void Union(int x, int y) {
    if (x < y)
        parents[y] = x;
    else
        parents[x] = y;
}

int Find(int x) {
    if (x == parents[x])
        return x;
    return parents[x] = Find(parents[x]);
}

void printAns() {
    for (int i = 0; i < N; i++) {
        Find(i);
        if (parents[i] == i)
            answer++;
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    for (int i = 0; i < n; i++)
        parents[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && i != j) {
                int find_i = Find(i);
                int find_j = Find(j);
                if (find_i != find_j)
                    Union(find_i, find_j);
                else
                    continue;
            }
        }
    }

    printAns();

    return answer;
}