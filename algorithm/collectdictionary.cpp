#include <string>
#include <vector>
#include <map>

using namespace std;
int count = 1;
vector<string> alpha = { "A","E","I","O","U" };
map<string, int> answer;
void DFS(string tmp) {
    if (tmp.length() > 5)
        return;
    answer[tmp] = count++;

    for (string s : alpha)
        DFS(tmp + s);
}

int solution(string word) {

    for (string s : alpha)
        DFS(s);

    return answer[word];
}