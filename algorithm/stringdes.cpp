#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(char c1, char c2) {
    return c1 > c2;
}
string solution(string s) {
    string answer = "";
    int i;
    vector<char> tmp_s(s.length());
    for (i = 0; i < s.length(); i++) {
        tmp_s[i] = s[i];
    }
    sort(tmp_s.begin(), tmp_s.end(), comp);
    for (i = 0; i < tmp_s.size(); i++)
        answer += tmp_s[i];
    return answer;
}