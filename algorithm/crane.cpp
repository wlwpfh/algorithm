#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;

int solution(vector<vector<int>> board, vector<int> moves) {
    int i, answer = 0;

    for (int i = 0; i < moves.size(); i++) {
        int index = moves[i] - 1;
        int doll = board[index][board[index].size() - 1];
        board[index].erase(board[index].begin() + board[index].size() - 1); //»Ì±â
        if (doll == 0)
            continue;
        if (!q.empty() && q.front() == doll) {
            answer += 2;
            q.pop();
        }
        else {
            q.push(doll);
        }

    }

    return answer;
}