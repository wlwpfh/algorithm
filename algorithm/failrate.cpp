#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int count = 0, s_size = stages.size();
    vector<pair<int, double>> fail;
    //index,  실패율 
    for (int i = 1; i <= N; i++) { //스테이지별 사람들
        count = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i) {
                count++;
                stages[j] = 502; //stage의 최대 크기                
            }
        }
        if (count != 0)
            fail.push_back(make_pair(i, count / (float)s_size));
        else
            fail.push_back(make_pair(i, 0.0));
        s_size -= count;
    }

    sort(fail.begin(), fail.end(), compare);

    for (int i = 0; i < fail.size(); i++)
        answer.push_back(fail[i].first);

    return answer;
}