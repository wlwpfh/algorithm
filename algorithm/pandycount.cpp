#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int i, p_count = 0, y_count = 0;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            p_count++;
        else if (s[i] == 'y' || s[i] == 'Y')
            y_count++;
        else
            ;
    }
    if (p_count == y_count)
        answer = true;
    else
        answer = false;
    return answer;
}