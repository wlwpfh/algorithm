#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int song_num, dvd_num, i, mid, high, low, sum;
	scanf("%d %d", &song_num, &dvd_num);

	vector<int> songs(song_num);

	for (i = 0; i < song_num; i++)
		scanf("%d", &songs[i]);

	low = 0;
	int tmp = 0;
	sum = 0;
	high = song_num - 1;
	while (high > low) {
		mid = (low + high) / 2;

		while (mid >= low) {
			tmp = tmp + low;
			low++;
		}
		low = mid + 1;
		if (tmp >= sum) {
			sum = tmp;
		}

	}

	printf("%d", sum);

	return 0;
}