#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double tmp, fraction;
    int num;
    tmp = sqrt(n);
    num = (int)tmp;
    fraction = tmp - num;

    printf("num¿∫ %d \n", num);
    if (fraction != 0) {
        answer = -1;
    }
    else {
        answer = pow(num + 1, 2);
    }
    return answer;
}