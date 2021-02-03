#include<stdio.h>
#include<vector>
int main39_() {
	int i, j, num1, num2, num3;



	scanf("%d", &num1);
	std::vector <int> arr1(num1);

	for (i = 0; i < num1; i++)
		scanf("%d", &arr1[i]);

	scanf("%d", &num2);
	std::vector <int> arr2(num2);

	for (j = 0; j < num2; j++)
		scanf("%d", &arr2[j]);

	num3 = num1 + num2;

	std::vector <int> arr3(num3);
	i = 0, j = 0;
	int count = 0;

	while (1) {
		if (i == num1 && j == num2) { //둘 다 다 넣은 경 
			break;
		}
		else if (i == num1) { //arr1만 끝난 경우 
			arr3[count] = arr2[j];
			j++;
		}
		else if (j == num2) { //arr2만 끝난 경우 
			arr3[count] = arr1[i];
			i++;
		}
		else {

			if (arr1[i] > arr2[j]) {
				arr3[count] = arr2[j];
				j++;

			}
			else { //같거나 arr2의 것이 더 큰 경우 
				arr3[count] = arr1[i];
				i++;
			}
		}
		count++;
	}

	for (i = 0; i < num3; i++)
		printf("%d ", arr3[i]);

	return 0;
}