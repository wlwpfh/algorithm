#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int location_index = 0; //위치가 변하니까 
    int tmp_max = 0;
    queue<int> q;
    int tmp_front;
    // queue<string> index;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(priorities[i]);

        if (q.back() > tmp_max)
            tmp_max = q.back();
    }

    printf("tmp_max: %d ", tmp_max);
    while (1) {
        if (q.size() == 0) //해당 값이 pop되면
            break;
        else {
            //앞에 있는 게 제일 뽑히고 그게 제일 뒤로 다시 넣기

            // 큐 안에서 늘 제일 큰 수가 뭔 지 확인해야 함



            if (q.front() == tmp_max)//앞의 값이 제일 큰 수인지
                q.pop();
            else {
                tmp_front = q.front();
                q.pop();
                q.push(tmp_front);
            }
        }
    }

    return answer;
}