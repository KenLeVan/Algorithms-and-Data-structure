#include <iostream>
#include <vector>

int main() {
    int width, height;
    std::cin >> width >> height;

    std::vector<int> dp(height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int num;
            std::cin >> num;

            if (i == 0 && j == 0) {
                dp[0] = num;
            } else if (i == 0) {
                dp[j] = dp[j - 1] + num;
            } else if (j == 0) {
                dp[j] += num;
            } else {
                dp[j] = num + std::min(dp[j], dp[j - 1]);
            }
        }
    }

    std::cout << dp[height - 1] << '\n';
}