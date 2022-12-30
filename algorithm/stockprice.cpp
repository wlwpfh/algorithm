#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> s;
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); i++) {
        if (i != 0) {
            while (!s.empty() && prices[s.top()] > prices[i]) {
                answer[s.top()] = i - s.top();
                s.pop();
            }
        }
        s.push(i);
    }

    while (!s.empty()) {
        answer[s.top()] = prices.size() - s.top() - 1;;
        s.pop();
    }

    return answer;
}