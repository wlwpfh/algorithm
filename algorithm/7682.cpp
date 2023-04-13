#include<iostream>

using namespace std;

string game;
char map[3][3];

bool xWin() {
	for (int i = 0; i < 3; i++) {
		if (map[i][0] == 'X' && map[i][1] == map[i][0] && map[i][1] == map[i][2]) // 가로에 있는 지 
			return true;
		if (map[0][i] == 'X' && map[0][i] == map[1][i] && map[1][i] == map[2][i]) // 세로에 있는 지  
			return true;
	}
	if (map[0][0] == 'X' && map[1][1] == map[0][0] && map[1][1] == map[2][2])
		return true;
	if (map[2][0] == 'X' && map[1][1] == map[2][0] && map[1][1] == map[0][2])
		return true;

	return false;
}

bool oWin() {
	for (int i = 0; i < 3; i++) {
		if (map[i][0] == 'O' && map[i][1] == map[i][0] && map[i][1] == map[i][2]) // 가로에 있는 지 
			return true;
		if (map[0][i] == 'O' && map[0][i] == map[1][i] && map[1][i] == map[2][i]) // 세로에 있는 지  
			return true;
	}
	if (map[0][0] == 'O' && map[1][1] == map[0][0] && map[1][1] == map[2][2])
		return true;
	if (map[2][0] == 'O' && map[1][1] == map[2][0] && map[1][1] == map[0][2])
		return true;

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int xcount = 0, ocount = 0;
	while (1) {
		xcount = 0, ocount = 0;
		cin >> game;

		if (game == "end")
			break;

		for (int i = 0; i < 9; i++) {

			map[i / 3][i % 3] = game[i];
			if (game[i] == 'X')
				xcount++;
			if (game[i] == 'O')
				ocount++;
		}
		bool xflag = xWin();
		bool oflag = oWin();

		if (xflag && !oflag && xcount - ocount == 1)
			cout << "valid" << endl;
		else if (!xflag && oflag && ocount == xcount)
			cout << "valid" << endl;
		else if (!xflag && !oflag && xcount == 5 && ocount == 4)
			cout << "valid" << endl;
		else
			cout << "invalid" << endl;

	}

	return 0;
}