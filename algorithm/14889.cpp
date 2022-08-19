#include<stdio.h>
#include<cmath>
#define INF 987654321

using namespace std;

int N, arr[20][20], start, link, result = INF;
bool visited[20];
//내 팀인 경우, 아닌 경우
void makeTeam(int index, int count) {
	if (count == N / 2) {
		start = 0, link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visited[i] && visited[j]) {
					start += arr[i][j];
					start += arr[j][i];
				}
				if (!visited[i] && !visited[j]) {
					link += arr[i][j];
					link += arr[j][i];
				}

			}

		}
		int v = abs(start - link);
		result = result > v ? v : result;
		return;
	}

	for (int i = index; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			makeTeam(i + 1, count + 1);
			visited[i] = false;
		}
	}
}

int main() {

	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	makeTeam(0, 0);

	printf("%d", result);

	return 0;
}