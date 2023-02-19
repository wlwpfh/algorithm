#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string, vector<string>> m;
map<pair<string, string>, bool> visited;
priority_queue<string, vector<string>, greater<string>> q;
vector<string> answer;

bool compare(string a, string b) {
    return a < b;
}

void BFS(string start) {
    q.push(start);
    while (!q.empty()) { //다른 항공편 있는지 확인하기 
        string city = q.top();
        answer.push_back(city);
   
        q.pop();
        for (int i = 0; i < m[city].size(); i++) {
            if (!visited[make_pair(city, m[city][i])]) {
                q.push(m[city][i]);

                visited[make_pair(city, m[city][i])] = true;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i = 0; i < tickets.size(); i++)
        m[tickets[i][0]].push_back(tickets[i][1]);

    BFS("ICN");
    return answer;
}