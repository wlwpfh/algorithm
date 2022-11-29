#include <vector>
#define DIV 1234567
using namespace std;
vector<int> count;
long long solution(int n) {

    count.push_back(1); //1
    count.push_back(2); //2
    count.push_back(3); //3

    for (int i = 3; i <= n; i++) {
        long long tmp = (count[i - 2] + count[i - 1]) % DIV;
        count.push_back(tmp);
    }
    return count[n - 1];
}