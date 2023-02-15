
#include <vector>
#include <stack>

using namespace std;

stack<int> s;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());

    for (int i = 0; i < numbers.size(); i++) {
        answer[i] = -1;
        while (!s.empty() && numbers[i] > numbers[s.top()]) {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
    return answer;
}