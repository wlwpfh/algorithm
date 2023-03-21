#include <string>
#include <vector>

using namespace std;
bool removed[30][30];

void initRemoved(int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            removed[i][j] = false;
    return;
}

void printBoard(vector<string> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return;
}

vector<string> moveDown(vector<string> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
            for (int k = j; k < board[i].length() - 1; k++) {
                if (removed[i][k + 1]) {
                    //밑에가 비어있다면
                    board[i][k + 1] = board[i][k];
                    board[i][k] = 0;
                }
            }
        }
    }

    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0, reduce = 0;

    while (1) {
        reduce = 0;
        //4블록 없애기
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i][j + 1]) && (board[i + 1][j] == board[i + 1][j + 1])) {
                    if (removed[i][j] == false)
                        reduce++;
                    if (removed[i + 1][j] == false)
                        reduce++;
                    if (removed[i][j + 1] == false)
                        reduce++;
                    if (removed[i + 1][j + 1] == false)
                        reduce++;
                    removed[i][j] = true;
                    removed[i][j + 1] = true;
                    removed[i + 1][j] = true;
                    removed[i + 1][j + 1] = true;


                }
                else
                    continue;
            }
        }

        if (reduce == 0) //줄어든 게 없을 때까지
            break;

        board = moveDown(board);
        printBoard(board);
        answer += reduce;
        //initRemoved(m,n);
    }
    return answer;
}