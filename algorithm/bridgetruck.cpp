#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //대기하는 트럭 큐
    queue<int> waiting;
    //건너는 중인 트럭 큐
    queue<int> going;
    // 건너는 트럭의 현재 위치...?  -> 인덱스로 접근해야 함.. 
    vector<int> location(truck_weights.size(), 0);

    for (int i = 0; i < truck_weights.size(); i++)
        waiting.push(truck_weights[i]);
    int end_bridge = 0;
    int curr_weight = 0, start = 0, end = 0;
    //현재 있는 그것!    // start는 다리를 건너는 트럭의 첫과 끝 index, 
    while (end_bridge != truck_weights.size()) {

        if (!waiting.empty() && curr_weight + waiting.front() <= weight) {
            curr_weight += waiting.front();
            going.push(waiting.front());//건너는거에 추가하기;
            waiting.pop();
            end++;
        }

        for (int i = start; i <= end; i++)
            location[i]++; //이동중 
        if (location[start] == bridge_length + 1) {
            start++;
            going.pop();
            end_bridge++;
        }
        answer++;
    }

    return answer;
}