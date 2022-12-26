#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //����ϴ� Ʈ�� ť
    queue<int> waiting;
    //�ǳʴ� ���� Ʈ�� ť
    queue<int> going;
    // �ǳʴ� Ʈ���� ���� ��ġ...?  -> �ε����� �����ؾ� ��.. 
    vector<int> location(truck_weights.size(), 0);

    for (int i = 0; i < truck_weights.size(); i++)
        waiting.push(truck_weights[i]);
    int end_bridge = 0;
    int curr_weight = 0, start = 0, end = 0;
    //���� �ִ� �װ�!    // start�� �ٸ��� �ǳʴ� Ʈ���� ù�� �� index, 
    while (end_bridge != truck_weights.size()) {

        if (!waiting.empty() && curr_weight + waiting.front() <= weight) {
            curr_weight += waiting.front();
            going.push(waiting.front());//�ǳʴ°ſ� �߰��ϱ�;
            waiting.pop();
            end++;
        }

        for (int i = start; i <= end; i++)
            location[i]++; //�̵��� 
        if (location[start] == bridge_length + 1) {
            start++;
            going.pop();
            end_bridge++;
        }
        answer++;
    }

    return answer;
}