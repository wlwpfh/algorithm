#include <string>
#include <vector>

using namespace std;

int num_size, answer = 0, goal;
vector<int> tmp;
void DFS(int index, int sum) {
    if (index == num_size) {
        if (sum == goal)
            answer++;
        return;
    }

    DFS(index + 1, sum + tmp[index]);
    DFS(index + 1, sum - tmp[index]);

}

int solution(vector<int> numbers, int target) {
    goal = target;
    num_size = numbers.size();

    tmp = numbers;
    //√ ±‚»≠ 

    DFS(0, 0);

    return answer;
}