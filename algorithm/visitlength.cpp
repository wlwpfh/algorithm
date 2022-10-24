#include <string>
#include <map>
using namespace std;

bool visited[10][10];
pair<int, int> now = make_pair(0, 0); //현재 위치 저장
int solution(string dirs) {
    int answer = 0;

    for (int i = 0; i < dirs.length(); i++) {
        if (dirs[i] == 'L')
            now.first--;
        else if (dirs[i] == 'R')
            now.first++;
        else if (dirs[i] == 'U')
            now.second++;
        else
            now.second--;

        if (now.first == -5 || now.second == -5 || now.first == 5 || now.second == 5)
            continue;

        if (visited[now.first + 5][now.second + 5] == 0) {
            printf("현재 (%d, %d) \n", now.first, now.second);
            answer++;
            visited[now.first + 5][now.second + 5] = 1;
        }

    }

    return answer;
}