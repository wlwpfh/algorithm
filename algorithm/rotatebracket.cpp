#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<char> st;
char small[] = { '(',')' };
char middle[] = { '[',']' };
char large[] = { '{','}' };

bool checkBracket(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == small[0] || s[i] == middle[0] || s[i] == large[0])
            st.push(s[i]);
        else if (st.empty()) //위에가 아닌데 빈 경우 
            return false;
        else {
            if (st.top() == small[0] && s[i] == small[1])
                st.pop();
            else if (st.top() == middle[0] && s[i] == middle[1])
                st.pop();
            else if (st.top() == large[0] && s[i] == large[1])
                st.pop();
        } //내 짝이 위에 있을 때 pop
    }
    if (st.empty())
        return true;
    return false;
}

int solution(string s) {
    int answer = 0;

    string first = s;

    string tmp = "";

    for (int i = 0; i < s.length(); i++) {
        tmp = first.substr(i + 1, s.length() - 1) + first.substr(0, i + 1);
        //printf("tmp: %s \n", tmp.c_str());
        if (checkBracket(tmp))
            answer++;

    }

    return answer;
}