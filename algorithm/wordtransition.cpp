#include <string>
#include <vector>
#define INF 987654321 

using namespace std;

bool visited[50];
int answer = INF;


bool check(string a, string b) {
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            count++;
    }
    if (count == 1)
        return true;
    return false;
}

void dfs(string begin, string target, vector<string> words, int count) {
    if (answer <= count)
        return;
    if (begin == target) {
        answer = answer > count ? count : answer;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && check(begin, words[i])) {
            visited[i] = true;
            dfs(words[i], target, words, count + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int count = 0;
    dfs(begin, target, words, 0);

    if (answer == INF)
        answer = 0;
    return answer;
}