#include<stdio.h>
int main() {

	int num, i, j, sum = 0, final_sum = 0, count = 0; //몇 개가 있는 지 나중에 세기 위해서 
	scanf("%d", &num);

	//printf("%d",num/2);
	int now = 0, past = 0; bool check = true; //false가 되면 바로 다음 계산으로 넘어가기 

	for (i = num / 2 + 1; i > 0; i--) {
		if (past == 0) //처음 들어온 경우 
		{
			past = i;
			sum = sum + past;
			printf("처음 들어온 수는 %d입니다. \n", i);
		}
		else { //처음들어온 게 아닌 경우 
			if (!(sum >= num) && i - past == 1 && check == true) //하나만 차이가 나는 경우 
			{
				past = i;
				sum = sum + past;
				printf("다음으로 들어온 수는 %d입니다. \n", i);
			}
			else {
				check = false;
			}

		}
		if (check == true && sum == num)
		{
			count++;
			printf("하나의 %d가 만들어졌습니다. \n", sum);
			sum = 0;
		}
	}

	printf("\n %d", count);

	return 0;
}