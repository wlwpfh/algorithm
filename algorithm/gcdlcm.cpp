#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> tmp_div;
    int i, min, max = 1, div = 1;
    for (i = 1; i <= n; i++) {
        if (n % i == 0)
            tmp_div.push_back(i);
    }
    for (i = 0; i < tmp_div.size(); i++) {
        if (m % tmp_div[i] == 0)
        {
            printf("최대 공약수는 %d \n", tmp_div[i]);
            min = tmp_div[i];
        }
    }

    answer.push_back(min);
    answer.push_back((n * m) / min);
    return answer;
}