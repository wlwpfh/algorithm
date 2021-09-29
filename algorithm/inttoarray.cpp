#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    long long a = n;

    while (a > 0) {

        answer.push_back(a % 10);
        printf("%d°¡ µé¾î°¬´Ù \n", a % 10);
        a = a / 10;
    }

    return answer;
}