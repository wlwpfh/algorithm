#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool solution(int x) {
    bool answer = true;
    int div, sum = 0, num = x, count = 1;

    while (num > 0) {

        div = num % 10;
        printf("%d���� �������� %d \n", x, div);

        sum += div;
        num = num / 10;

    }
    printf("sum�� %d, x�� %d \n", sum, x);
    if (x % sum == 0) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}