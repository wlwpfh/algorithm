#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer, queue;
    answer.push_back(0);
    answer.push_back(0);
    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];
        if (op[0] == 'I') {
            string num = op.substr(2);
            int tmp_num = stoi(num);
            queue.push_back(tmp_num);
        }
        else if (operations[i] == "D 1") { //최대값 삭제
            if (queue.empty())
                continue;
            queue.pop_back();
        }
        else { // 최소값 삭제 
            if (queue.empty())
                continue;
            queue.erase(queue.begin());
        }
        sort(queue.begin(), queue.end());
    }

    if (!queue.empty()) {
        answer[0] = queue[queue.size() - 1];
        answer[1] = queue[0];
    }

    return answer;
}