#include<string>
#include<iostream>
#include<stack>

using namespace std;

stack<char> c;

bool solution(string s) {
    bool answer = true;


    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            c.push(s[i]);
        else if (s[i] == ')') {
            if (!c.empty() && c.top() == '(')
                c.pop();
            else {
                answer = false;
                break;
            }

        }
    }

    if (!c.empty())
        answer = false;

    return answer;
}