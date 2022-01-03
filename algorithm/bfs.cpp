#include <bits/stdc++.h>
#include<stdio.h>
#include<vector>
using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

vi p;                                            // addition:parent vector

void printPath(int u) {                          // extract info from vi p
    if (p[u] == -1) { printf("%d", u); return; }
    printPath(p[u]);                               // output format: s -> ... -> t
    //자신의 부모를 타고 가면 경로가 나온다.
    printf(" %d", u);
}

int main() {
    /*
    // Graph in Figure 4.3, format: list of unweighted edges
    // This example shows another form of reading graph input
    13 16
    0 1    1 2    2  3   0  4   1  5   2  6    3  7   5  6
    4 8    8 9    5 10   6 11   7 12   9 10   10 11  11 12
    */

    freopen("bfs_in.txt", "r", stdin);

    int V, E; scanf("%d %d", &V, &E);
    vector<vii> AL(V, vii());
    for (int i = 0; i < E; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        AL[a].emplace_back(b, 0);
        AL[b].emplace_back(a, 0);
    }

    // as an example, we start from this source, see Figure 4.3
    int s = 5;
    //출발지점 

    // BFS routine inside int main() -- we do not use recursion
    vi dist(V, INF); dist[s] = 0;                  // INF = 1e9 here
    //모든 거리를 무한대로 지정 

    queue<int> q; q.push(s);
    p.assign(V, -1);                               // p is global

    int layer = -1;                                // for output printing
    //거리를 위해서 사용함

    bool isBipartite = true;                       // additional feature

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] != layer) printf("\nLayer %d: ", dist[u]);
        layer = dist[u];
        printf("visit %d, ", u);
        for (auto& [v, w] : AL[u]) {                 // C++17 style, w ignored
            if (dist[v] == INF) { //방문을 안한 경우 
                dist[v] = dist[u] + 1;                     // dist[v] != INF now
                p[v] = u;                                // parent of v is u
                // u -> v로 방문했으니까 v의 부모는 u다.
                q.push(v);                               // for next iteration
            }
            else if ((dist[v] % 2) == (dist[u] % 2))       // same parity
                //이분 그래프인지 확인
                // 2개의 색으로 인접 그래프 색칠하기 
                isBipartite = false;
        }
    }

    printf("\nShortest path: ");
    printPath(7), printf("\n");
    printf("isBipartite? %d\n", isBipartite);

    return 0;
}