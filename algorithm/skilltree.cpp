#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> orders;

bool isRightOrder(string s) {
    int index = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - '0' != index) 
            return false;
        index++;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    vector<string> skills;
    int answer = 0;
    for (auto a : skill)
        orders[a]++;

    for (string s : skill_trees) {
        string tmp = "";
        for (int i = 0; i < s.length(); i++) {
            if (orders[s[i]] == 0)
                continue;
            tmp += s[i];
        }
        skills.push_back(tmp);
    }

    for (int i = 0; i < skills.size(); i++) {
        string tmp = "";
        for (int j = 0; j < skills[i].length(); j++) {
            for (int k = 0; k < skill.size(); k++) {
                if (skills[i][j] == skill[k])
                    tmp += to_string(k);
            }
        }
        skills[i] = tmp;
    }

    for (auto a : skills) {
        if (isRightOrder(a))
            answer++;
    }
    return answer;
}