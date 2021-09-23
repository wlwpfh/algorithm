#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int i, answer = 0;
    vector<int> check(10);

    for (i = 0; i < numbers.size(); i++) {
        check[numbers[i]]++;
    }

    for (i = 0; i < check.size(); i++) {
        if (check[i] == 0) {
            answer += i;
        }
    }

    return answer;
}