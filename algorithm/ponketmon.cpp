#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{   //nums: ���ϸ� ���� ��ȣ�� ��� �迭
    //���� ���� �ٸ��� ++, �ٵ� answer>nums.size()/2�� �ݶ��� �������
    vector<int> num(nums.size() + 1);
    int i, answer = 0;
    sort(nums.begin(), nums.end());

    for (i = 0; i < nums.size(); i++) {
        num[nums[i]]++;
    }

    for (i = 1; i < num.size(); i++) {
        printf("%d ", num[i]); 
    }

    if (answer > (nums.size() / 2))
        return nums.size() / 2;
    else
        return answer;
}