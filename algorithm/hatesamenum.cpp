#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    bool put = false;
    int i;
    int prev;
    answer.push_back(arr[0]);
    for (i = 1; i < arr.size(); i++) {
        prev = arr[i - 1];
        if (prev == arr[i]) {
            ;
        }
        else {
            answer.push_back(arr[i]);


        }
    }

    return answer;
}
//erase�� unique�Լ��� ����Ͽ� �� �����ϰ� Ǯ �� ����.