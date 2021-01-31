#include<stdio.h>
#include<vector> //동적 할당을 위해서 
using namespace std;
int main22_() {
	int days, distance, i, j, sum = 0, max;
	scanf("%d %d", &days, &distance);

	vector<int>temp(days); //days크기만큼 temp라는 백터 배열이 생긴 것 

	for (i = 0; i < days; i++) {
		scanf("%d", &temp[i]);
	} //배열 초기화 

	for (i = 0; i < distance; i++) {
		sum += temp[i]; //처음에 합을 구해서 넣기 
	}
	max = sum;

	for (i = distance; i < days; i++) {
		sum = sum + (temp[i] - temp[i - distance]);

		if (sum > max)
			max = sum;
	}


	printf("%d \n", max);

	return 0;
}