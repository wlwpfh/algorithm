#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int rest = 0, three_num = 0, tmp, new_count = 0, new_three = 0, count = 0, answer = 0;

    while (1) {
        if (n < 3) {
            three_num = pow(10, count) * n + three_num;
            count++;
            break;
        }
        else {
            rest = n % 3;
            n = n / 3;
            three_num = pow(10, count) * rest + three_num;
            count++;

        }
    }
    printf("%d %d", three_num, count);

    while (1) {
        if (new_count == count) {
            printf("%d", new_three);
            break;
        }
        else {
            tmp = three_num % 10;
            three_num = three_num / 10;
            new_three = pow(10, count - new_count) * tmp + new_three;
            new_count++;
        }
    }

    return answer;
}