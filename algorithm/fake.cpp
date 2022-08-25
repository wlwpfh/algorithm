#include <string>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int i, j, answer = 1;
    unordered_map<string, int> com(clothes.size());

    for (i = 0; i < clothes.size(); i++) {
        com[clothes[i][1]]++;
    }

    for (pair<string, int> p : com) {
        answer *= (p.second + 1);
    }
    return answer - 1;
}