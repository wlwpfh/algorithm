#include <string>
#include <vector>
#include <queue>
using namespace std;
int cal[2] = { 1,-1 }; //곱하면 된다.
int solution(vector<int> numbers, int target) {
    int i, j, curr, sum, answer = 0;

    queue<int>Q;
    Q.push(numbers[0]);
    vector<int> check(numbers.size()); //numbers다 넣었는지 확인
    check[0] = 1;
    while (!Q.empty()) {
        curr = Q.front();
        Q.pop();

        for (i = 1; i < numbers.size(); i++) {
            for (j = 0; j < 2; j++) {
                sum = curr + (numbers[i]) * cal[j];

                if (sum == target) {
                    break;
                }
                else {
                    answer++;
                    check[i] = 1;
                    Q.push(sum);

                }
            }
        }


    }

    return answer;
}