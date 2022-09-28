#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }

    for (int i = 0; i < m.size(); i++) {
        if (answer == (nums.size() + 1) / 2)
            break;
        answer++;
    }

    return answer;
}