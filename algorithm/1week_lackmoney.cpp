using namespace std;

long long solution(int price, int money, int count)
{
    int i;
    long long sum = 0;
    for (i = 1; i <= count; i++) {
        sum = sum + price * i;
    }
    return sum > money ? sum - money : 0;
}