#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int i, count = 0, answer = 0;
    long tmp = num;
    while (tmp != 1) {
        if (count == 500) {
            break;
        }
        if (tmp % 2 == 0) { //¦
            tmp = tmp / 2;
        }
        else { //Ȧ
            tmp = tmp * 3 + 1;
        }
        count++;
    }
    if (count == 500)
        answer = -1;
    else
        answer = count;
    return answer;
}