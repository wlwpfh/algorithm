#include <queue>
#include <vector>

using namespace std;

queue<int> waiting;
queue<int> going;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;

    vector<int> location(truck_weights.size(), 0);

    for (int i = 0; i < truck_weights.size(); i++)
        waiting.push(truck_weights[i]);

    int curr_weight = 0, start = 0, end = 0;

    while (1) {
        answer++;
        if (!waiting.empty() && curr_weight + waiting.front() <= weight) {
            int in = waiting.front();
            curr_weight += in;
            waiting.pop();
            going.push(in);
            end++;
        }

        for (int i = start; i < end; i++)
            location[i]++;

        if (location[start] == bridge_length && !going.empty()) {
            curr_weight -= going.front();
            going.pop();
            start++;
        }

        if (waiting.empty() && going.empty())
            break;
    }

    return answer;
}