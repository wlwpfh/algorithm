#include <map>
#include <vector>

using namespace std;
map<int, int> take;
map<int, int> left;
int solution(vector<int> topping) {
    int answer = 0;

    for (int i = 0; i < topping.size(); i++)
        left[topping[i]]++;

    for (int i = 0; i < topping.size(); i++) {
        take[topping[i]]++;

        left[topping[i]]--;
        if (left[topping[i]] == 0)
            left.erase(topping[i]);

        if (take.size() == left.size())
            answer++;
    }
    return answer;
}