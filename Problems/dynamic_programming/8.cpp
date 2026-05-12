#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string text1, text2;
    std::cin >> text1 >> text2;

    std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    std::string LCS = "";

    int i = text1.size();
    int j = text2.size();
    while (i > 0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            LCS += text1[i-1];

            i--;
            j--;
        } else {
            if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    std::reverse(LCS.begin(), LCS.end());

    std::cout << LCS << '\n';
}