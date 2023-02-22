#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

vector<int> number;
string s;
vector<int> answer;
map<int, int> counts;
bool visited[8];

bool isPrime(int num)
{
    bool ret = true;
    if (num == 0 || num == 1) {
        ret = false;
        return ret;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            ret = false;
            break;
        }
    }
    return ret;
}

//DFS
void check(string numbers, int start, int end) {
    if (start == end) {
        int tmp = stoi(s);
        answer.push_back(tmp);
        return;
    }
    for (int i = 0; i < numbers.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            s.push_back(numbers[i]);
            check(numbers, start + 1, end);
            s.pop_back();
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    for (int i = 0; i < numbers.length(); i++)
        number.push_back(numbers[i] - '0');
    sort(number.begin(), number.end());

    for (int i = 1; i <= numbers.length(); i++)
        check(numbers, 0, i);

    for (int i = 0; i < answer.size(); i++) {
        if (isPrime(answer[i])) {
            counts[answer[i]]++;
        }
    }

    return counts.size();
}