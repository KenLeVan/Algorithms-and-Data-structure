#include <iostream>
#include <vector>

int main() {
    int width, height;
    std::cin >> width >> height;

    std::vector<std::vector<int>> dp(width, std::vector<int>(height, 0));

    dp[0][0] = 1;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i + 1 < width && j + 2 < height) {
                dp[i + 1][j + 2] += dp[i][j];
            }
            if (i + 2 < width && j + 1 < height) {
                dp[i + 2][j + 1] += dp[i][j];
            }
        }
    }

    std::cout << dp[width - 1][height - 1] << '\n';
}