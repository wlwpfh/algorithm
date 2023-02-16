#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, endTime;
    sort(jobs.begin(), jobs.end(), compare);
    endTime = jobs[0][0];
    for (int i = 0; i < jobs.size(); i++) {
        answer += (jobs[i][1] + endTime);
        // printf("%d번째가 요청부터 종료까지 %d 시간 소요 \n", i,jobs[i][1]+endTime);
        endTime = jobs[i][1];
    }

    return answer / jobs.size();
}