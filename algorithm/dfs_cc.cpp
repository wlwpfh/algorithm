#include <bits/stdc++.h>
#include<vector>
#include<stdio.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

enum { UNVISITED = -1, VISITED = -2 };                     // basic flags

// these variables have to be global to be easily accessible by our recursion (other ways exist)
vector<vii> AL;
vi dfs_num;

void dfs(int u) {                                // normal usage
    printf(" %d", u);                              // this vertex is visited
    dfs_num[u] = VISITED;                          // mark u as visited
    for (auto& [v, w] : AL[u])                     // C++17 style, w ignored
        //인접리스트에 대해서 탐색
        if (dfs_num[v] == UNVISITED)                 // to avoid cycle
            dfs(v);                                    // recursively visits v
}//해당 번호를 출력 

int main() {
    /*
    // Undirected Graph in Figure 4.1
    9
    1 1 0
    3 0 0 2 0 3 0
    2 1 0 3 0
    3 1 0 2 0 4 0
    1 3 0
    0
    2 7 0 8 0
    1 6 0
    1 6 0
    */

    freopen("dfs_cc_in.txt", "r", stdin);

    int V; scanf("%d", &V);
    AL.assign(V, vii());
    for (int u = 0; u < V; ++u) {
        int k; scanf("%d", &k);
        while (k--) {
            int v, w; scanf("%d %d", &v, &w);
            AL[u].emplace_back(v, w);
            //인접 리스트에 정보 넣기  
        }
    }

    printf("Standard DFS Demo (the input graph must be UNDIRECTED)\n");
    dfs_num.assign(V, UNVISITED);
    //벡터 한번에 unvisited상태로 만들기. 
    int numCC = 0;
    //지금 몇 묶음이 있는 지 
    for (int u = 0; u < V; ++u)                    // for each u in [0..V-1]
        if (dfs_num[u] == UNVISITED)                 // if that u is unvisited
            printf("CC %d:", ++numCC), dfs(u), printf("\n"); // 3 lines here!
        //새로움 단위를 찍고 수행함. 
    printf("There are %d connected components\n", numCC);

    

    return 0;
}