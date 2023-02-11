#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;

stack<int> waiting;

int solution(vector<int> order) {
    int answer = 0;
    int number = 1;
    int i = 0;
    for (number = 1; number <= order.size(); number++) {
        if (order[i] == number) {
            answer++; i++;
        }
        else {
            waiting.push(number);
            continue;
        }

        while (!waiting.empty() && order[i] == waiting.top()) {
            waiting.pop();
            answer++; i++;
        }
    }
    return answer;
}