#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;

    for (int i = 0; i < 26; i++) {
        string s = "";
        s.push_back('A' + i);
        dict[s] = i + 1;
    }
    int counts = 27, index = 0;
    string now = "";
    string tmp = "";
    for (int i = 0; i < msg.length(); i++) {
        now = msg[i];
        int j = i;
        index = 0;
        while (dict.find(now) != dict.end()) {
            index++;
            j++;
            now += msg[j];
        }
        i += index - 1;
        dict[now] = counts++;
        now.pop_back();
        answer.push_back(dict[now]);
    }
    return answer;
}