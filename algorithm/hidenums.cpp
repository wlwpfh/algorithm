#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = ""; int i;
    printf("%d", phone_number.length());
    //���ڸ� 4�ڸ� �Ĥ���
    for (i = 0; i < phone_number.length() - 4; i++) {
        answer += '*';
    }
    for (i = phone_number.length() - 4; i < phone_number.length(); i++) {
        answer += phone_number[i];
    }
    return answer;

}