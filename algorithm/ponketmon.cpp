#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{   //nums: 포켓몬 종류 번호가 담긴 배열
    //앞의 수와 다르면 ++, 근데 answer>nums.size()/2면 반띵한 사이즈로
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