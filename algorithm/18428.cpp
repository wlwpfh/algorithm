#include<vector>
#include<iostream>
using namespace std;

char map[6][6];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
int N;
vector<pair<int, int> > teacher, e;

bool checkWall(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;

		while (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (map[nx][ny] == 'O')
				break;
			if (map[nx][ny] == 'S')
				return false;

			nx += dx[i];
			ny += dy[i];
		}
	}
	return true;
}

void makeWall(int count, int index) {
	if (count == 3) {
		//printMap();
		for (pair<int, int> p : teacher) {
			if (!checkWall(p.first, p.second)) {
				return;
			}
		}
		cout << "YES";
		exit(0);
	}
	for (int i = index; i < e.size(); i++) {
		map[e[i].first][e[i].second] = 'O';
		makeWall(count + 1, i + 1);
		map[e[i].first][e[i].second] = 'X';

	}

}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'T')
				teacher.push_back(make_pair(i, j));
			else if (map[i][j] == 'X')
				e.push_back(make_pair(i, j));
		} //넣기 성공 

		//상하좌우를 감시할 수 있음. 총 3개의 벽을 만들어야 함.	
	makeWall(0, 0);
	//현재 벽을 세운 개수

	cout << "NO";

	return 0;
}