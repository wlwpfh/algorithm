#include<stdio.h>
#include<vector>

using namespace std;

int front = -1, back = -1;
vector<int> map[10000];
int checked[10000];
void dfs(int x) {
    checked[x] = 1;

    printf("%d ", x);

    for (int i = 0; i < map[x].size(); i++) {
        int y = map[x][i];
        if (checked[y] == 0)
            dfs(y);
    }
}

int main() {
    int x;
    int n, m, s;
    int i;
    int a = 0;
    int b;
    scanf("%d %d %d", &n, &m, &s);
    vector<int> map[m];

    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }

    dfs(s);




    return 0;
}