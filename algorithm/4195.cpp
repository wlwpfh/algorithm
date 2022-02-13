#include<stdio.h>
#include<unordered_map>
#include<string>
#define MAX 200000
using namespace std;
char fr1[21], fr2[21];
char tmp[42];
int ans[41];
int F;
unordered_map<string, int>info;
int friends[MAX + 1];
int Find(int r) {
	if (r == friends[r])
		return r;
	return friends[r] = Find(friends[r]);
}
int Union(int a, int b) {
	int n = Find(a);
	int m = Find(b);

	if (n != m) {
		friends[m] = n;

		ans[m] += ans[n];
		ans[n] = ans[m];
		//printf("%d와 %d가 친구가 되어서 %d %d\n",a,b,ans[n],ans[m]);
	}
	else {
		if (ans[m] > ans[n])
			ans[n] = ans[m];
		else
			ans[m] = ans[n];

		//printf("%d와 %d는 원래 친구 => %d %d \n",a,b,ans[n],ans[m]);
	}

	return ans[n];
}


int main() {
	int i, n, j, count = 1, k, num1, num2;
	scanf("%d", &F);

	for (i = 0; i < F; i++) {
		scanf("%d", &n);



		for (j = 1; j <= n; j++) {
			int number;
			scanf("%s %s", fr1, fr2);


			if (info[fr1] == 0) {
				friends[count] = count;
				ans[count] = 1;
				info[fr1] = count++;

			}

			if (info[fr2] == 0) {
				friends[count] = count;
				ans[count] = 1;
				info[fr2] = count++;
			}


			num1 = info[fr1];
			num2 = info[fr2];
			//num1과 num2는 각 이름의 인덱스를 저장하는 변수다 . 


		   //int num=num1<num2? num2:num1;

   //printf("num1:%d, num2:%d num:%d \n",num1, num2, num);

			printf("%d\n", Union(num1, num2));
			//printf("Union한 후, friends[info[fr1]==%d]:%d, friends[info[fr2]==%d]:%d \n"
			//,info[fr1],friends[info[fr1]],info[fr2],friends[info[fr2]]);
			// number=friends[info[fr1]];


			 //printf("num1:%d, num2:%d",num1, num2);


		//printf("ans[info[fr1]==%d]:%d, ans[info[fr2]==%d]:%d \n",info[fr1],ans[info[fr1]],info[fr2],ans[info[fr2]]); 


		}

		//memset(friends, 0, sizeof(friends));
		count = 1;
		info.clear();
	}


	return 0;
}