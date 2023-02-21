#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int index;
map<string, vector<string>> m;
map<pair<string, string>, int> visited;
vector<string> answer;
vector<string> tmp;

bool compare(string a, string b) {
    return a < b;
}

void DFS(string city, int counts) { 

    if (counts == index) {
        if (tmp[0] == "ICN" && answer.empty()) {
            answer = tmp;
        }
        return;
    }

    for (int i = 0; i < m[city].size(); i++) {
        if (visited[make_pair(city, m[city][i])] > 0) {
            tmp.push_back(m[city][i]);
            visited[make_pair(city, m[city][i])]--;
            DFS(m[city][i], counts + 1);
            tmp.pop_back();
            visited[make_pair(city, m[city][i])]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back(tickets[i][1]);
        visited[make_pair(tickets[i][0], tickets[i][1])]++;
    }
    index = tickets.size() + 1;

    for (pair<string, vector<string>> p : m) {
        sort(m[p.first].begin(), m[p.first].end(), compare);
    }

    tmp.push_back("ICN");
    DFS("ICN", 1);

    return answer;
}