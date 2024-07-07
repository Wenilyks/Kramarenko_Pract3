#include <stdio.h>

int main() {
    int p;
    printf("Введіть кількість розрядів p: ");
    scanf("%d", &p);
    long long dp[p+1][4];
    dp[1][0] = 1;
    dp[1][1] = 1; 
    dp[1][2] = 0; 
    dp[1][3] = 0; 
    for (int i = 2; i <= p; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][3];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][1];
    }
    long long result = dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
    printf("Кількість чисел з %d розрядів: %lld\n", p, result);
    return 0;
}
