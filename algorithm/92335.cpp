#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> num;
int answer = 0;

string makeKNumber(int n, int k) {
    string re = "";
    while (n > 0) {
        re += to_string(n % k);
        n /= k;
    }
    reverse(re.begin(), re.end());
    return re;
}

bool isPrime(long long n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void hasZero(string s) {
    string tmp = "";
    s += "0";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0' && tmp != "") {
            long long n = stoll(tmp);
            if (isPrime(n))
                answer++;
            tmp = "";
        }
        else
            tmp += s[i];
    }
}

int solution(int n, int k) {
    string tmp = makeKNumber(n, k);

    hasZero(tmp);

    return answer;
}