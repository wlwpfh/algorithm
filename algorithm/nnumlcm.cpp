#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;

int solution(vector<int> arr) {
    int answer = 0, count = 2;

    for (int i = 0; i < arr.size(); i++) {
        int tmp = arr[i], count = 2;
        while (tmp > 1 && count <= tmp) {

            if (tmp % count == 0) {
                tmp /= count;
                m[count]++;
                continue;
            }
            count++;
        }

    }

    for (pair<int, int> p : m) {
        printf("%d -%d°³ \n", p.first, p.second);
    }


    return answer;
}