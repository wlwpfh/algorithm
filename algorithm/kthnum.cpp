#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp(array.size());
    int i, j, count;

    for (i = 0; i < commands.size(); i++) {

        vector<int> tmp(commands[i][1] - commands[i][0] + 1);
        count = 0;
        for (j = commands[i][0] - 1; j <= commands[i][1] - 1; j++)
        {
            tmp[count] = array[j];
            count++;
        }
        for (j = 0; j < tmp.size(); j++)
            sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    return answer;
}