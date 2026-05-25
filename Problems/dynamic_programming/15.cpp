#include <iostream>
#include <vector>
#include <stack>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> first(N);
    for (int i = 0; i < N; i++) std::cin >> first[i];

    int M;
    std::cin >> M;

    std::vector<int> second(M);
    for (int i = 0; i < M; i++) std::cin >> second[i];

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int option = std::max(dp[i - 1][j - 1], std::max(dp[i - 1][j], dp[i][j - 1]));

            if (first[i - 1] == second[j - 1]) {
                option = std::max(option, dp[i - 1][j - 1] + 1);
            }

            dp[i][j] = option;
        }
    }

    std::stack<int> sequence;
    int i = N, j = M;
    while (i > 0 && j > 0) {
        if (first[i - 1] == second[j - 1]) {
            sequence.push(first[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                i--;
            } else {
                j--;
            }
        }
    }

    while (!sequence.empty()) {
        std::cout << sequence.top() << ' ';
        sequence.pop();
    }
}