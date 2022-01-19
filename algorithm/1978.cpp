#include <stdio.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    else if (n == 2)
        return true;
    else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

int main(void) {
    int i, N, count = 0;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < N; i++)
    {
        if (isPrime(arr[i]))
            count++;
    }
    printf("%d", count);
    return 0;
}