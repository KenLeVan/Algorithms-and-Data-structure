#include <iostream>
#include <vector>

int main() {
    std::string first, second;
    std::cin >> first >> second;

    std::vector<std::vector<int>> dp(first.size() + 1, std::vector<int>(second.size() + 1, 0));

    for (int i = 1; i <= first.size(); i++) dp[i][0] = i;
    for (int i = 1; i <= second.size(); i++) dp[0][i] = i;

    for (int i = 1; i <= first.size(); i++) {
        for (int j = 1; j <= second.size(); j++) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    std::cout << dp[first.size()][second.size()] << '\n';
}