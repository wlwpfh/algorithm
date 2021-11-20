#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer;
    unordered_map< string, int> checked;

    for (string name : participant)
        checked[name]++;

    for (string name : completion)
        checked[name]--;
    for (pair<string, int> k : checked)
    {
        if (k.second == 1)
        {
            return k.first;
        }
    }

}