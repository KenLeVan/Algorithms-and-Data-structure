#include <iostream>
#include <vector>
#include <climits>

int main() {
    int number, sum;
    std::cin >> number >> sum;

    std::vector<int> coins(number);
    for (int i = 0; i < number; i++) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(sum + 1, INT_MAX);

    dp[0] = 0;

    for (int coin : coins) {
        for (int j = 1; j <= sum; j++) {
            if (j - coin >= 0) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = std::min(dp[j], dp[j - coin] + 1);
                }
            }
        }
    }

    std::cout << dp[sum] << '\n';
}