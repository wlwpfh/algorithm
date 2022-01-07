#include <bits/stdc++.h>

#define MAXN 10

using namespace std;

int N, M;
int Top;
int D[MAXN];

void printD()
{
    for (int i = 0; i < M; i++) printf("%d ", D[i]);
    printf("\n");
}

void backtracking(int start)
{
    if (Top == M)
    {
        printD();
        return;
    }

    for (int i = start; i <= N; i++)
    {
        if (N - i + 1 < M - Top) break; 
        //가지치기

        D[Top++] = i; //값을 넣었음
        backtracking(i + 1);
        Top--; //다음 수가 들어가도록 비우는 것 
    }
}

int main()
{
    printf("combination\n");
    N = 5;
    M = 3;
    Top = 0;
    backtracking(1);

    return 0;
}