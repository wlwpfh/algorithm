#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> orders;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int skill_index = 0;
    bool flag = false;

    for (auto a : skill)
        orders[a]++;

    for (string s : skill_trees) {
        flag = true;
        skill_index = 0;
        for (int i = 0; i < s.length(); i++) {

            if (orders[s[i]] == 0)
                continue;
            if (orders[s[i]] == 1 && skill[skill_index] == s[i]) {
                skill_index++;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    }
    return answer == 0 ? -1 : answer;
}