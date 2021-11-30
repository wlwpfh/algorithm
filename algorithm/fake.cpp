#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int i, j, answer = 0;
    unordered_map<string, string> com(clothes.size()); //�ϳ��� �� �� ����.
    vector<string> kind;


    for (i = 0; i < clothes.size(); i++) {
        com[clothes[i][1]] = clothes[i][0];
        kind.push_back(clothes[i][1]);
    }
    sort(kind.begin(), kind.end());
    auto last = unique(kind.begin(), kind.end());
    kind.erase(last, kind.end());


    return answer;
}