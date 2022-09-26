#include <string>
#include <vector>

using namespace std;

int toBinary(int n) {
    int count = 0; //1�� ������ ���� ����

    while (n > 0) {
        if (n % 2 == 1)
            count++;
        n /= 2;
    }
    return count;
}

int toBigger(int n, int count) {
    while (1) {
        int tmp_one = toBinary(++n);
  
        if (tmp_one == count)
            break;
    }
    return n;
}

int solution(int n) {
    int answer = 0;

    int one_count = toBinary(n); //���� n�� 1�� ����

    return toBigger(n, one_count);
}