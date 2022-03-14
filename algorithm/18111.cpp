#include<stdio.h>
#include<cmath>
using namespace std;
int N, M;
long long B;
int ground[500][500];
int depth[257];
bool lackB = false;
int main() {

	int i, j, a, b;

	scanf("%d %d %lld", &N, &M, &B);
	//B개의 인벤토리에 저장되어있음. 

	int min_time = 987654321, ans_depth = 0, tmp_time, tmp_b;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			scanf("%d", &ground[i][j]);
			depth[ground[i][j]]++;
		}

	//땅의 높이를 일정하게

	//땅 높이 -1: 2초 , 인벤토리에 넣기 B++; 
	//땅 높이 +1: 1초 , 인벤토리에서 빼기 B--; 

	//땅 만드는 시간, 땅의 높이



	for (i = 0; i <= 256; i++) {
		//depth를 기준으로

		tmp_time = 0;
		tmp_b = B;
		printf("depth:%d 조사시작 \n", i);
		for (a = 0; a < N; a++) {
			for (b = 0; b < M; b++) {

				int diff = abs(ground[a][b] - i);
				//printf("ground[%d][%d]와 %d와 %d 차이남 \n",a,b,i,diff);
				if (diff == 0) {
					printf("지면과 같기 때문에 지나감 ~ \n");
					continue;
				}

				for (j = 1; j <= diff; j++) {
					if (j > tmp_b && j < 0) {
						//printf("B부족사태 \n");
						lackB = true;
						break;
					}
					if (j > 0) {
						//더 높이 있는 경우 -> 인벤에 추가  
						tmp_b++;
						tmp_time += 2;
					}
					else {
						//더 낮은 경우 -> 인벤에서 빼 기 
						tmp_b--;
						tmp_time += 1;
					}
				}



				printf("(%d, %d): tmp_b:%d, tmp_time:%d \n", a, b, tmp_b, tmp_time);
			}
		}

		if (min_time >= tmp_time && lackB == false) {
			min_time = tmp_time;
			ans_depth = i;
			printf("min_time:%d ans_depth:%d 로 갱신 \n", min_time, ans_depth);
		}

	}


	printf("%d %d", min_time, ans_depth);


	return 0;
}