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
    printf("\n");
    return;
}

vector<string> moveDown(vector<string> board) {
    int N = board.size();
    int M = board[0].length();
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < N; j++) {
            for (int k = j; k > 0; k--) {
                if (board[k][i] == '0') {
                    //밑에가 비어있다면
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = '0';
                }
            }
        }
    } //맨 아래에서 위로 
    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0, reduce = 0;

    while (1) {
        initRemoved(m, n);
        reduce = 0;
        //4블록 없애기
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i][j + 1]) && (board[i + 1][j] == board[i + 1][j + 1]) && board[i][j] != '0') {
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
        } //줄어든 거 확인하기 

        if (reduce == 0) //줄어든 게 없을 때까지
            break;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (removed[i][j])
                    board[i][j] = '0';
            }
        }

        board = moveDown(board);
        ///printBoard(board);
        answer += reduce;
    }
    return answer;
}