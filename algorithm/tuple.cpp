#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> m;
string tmp;
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

void split(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
            if (tmp != "") {
                int val = stoi(tmp);
                m[val]++;
                tmp = "";
            }
            continue;
        }
        tmp += s[i];
    }
    return;
}

vector<int> solution(string s) {
    vector<int> answer;

    split(s);

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), compare);

    for (auto a : v)
        answer.push_back(a.first);

    return answer;
}