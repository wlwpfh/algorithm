#include <string>

using namespace std;

bool visited[11][11][11][11];
pair<int, int> now = make_pair(0, 0); //현재 위치 저장4
pair<int, int> adv = make_pair(0, 0);
int solution(string dirs) {
    int answer = 0;

    for (int i = 0; i < dirs.length(); i++) {
        adv = now;
        if (dirs[i] == 'L')
            adv.first--;
        else if (dirs[i] == 'R')
            adv.first++;
        else if (dirs[i] == 'U')
            adv.second++;
        else
            adv.second--;

        if (adv.first < -5 || adv.first>5 || adv.second < -5 || adv.second>5)
            continue;

        if (!visited[now.first + 5][now.second + 5][adv.first + 5][adv.second + 5]) {
            answer++;
            visited[now.first + 5][now.second + 5][adv.first + 5][adv.second + 5] = 1;
            visited[adv.first + 5][adv.second + 5][now.first + 5][now.second + 5] = 1;
        }
        now = adv;
    }

    return answer;
}