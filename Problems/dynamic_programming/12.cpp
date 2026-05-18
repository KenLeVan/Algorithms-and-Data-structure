#include <iostream>
#include <vector>
#include <stack>

int main() {
    int num;
    std::cin >> num;

    std::vector<int> seq(num);
    for (int i = 0; i < num; i++) std::cin >> seq[i];

    std::vector<int> dp(num, 1);
    std::vector<int> prev(num, -1);

    int max_idx = 0;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                int p = dp[i];
                dp[i] = std::max(dp[i], dp[j] + 1);

                if (dp[i] > dp[max_idx]) max_idx = i;
                if (p != dp[i]) prev[i] = j;
            }
        }
    }

    std::stack<int> path;

    int cur = max_idx;
    while (cur != -1) {
        path.push(seq[cur]);
        cur = prev[cur];
    }

    while (!path.empty()) {
        std::cout << path.top() << ' ';
        path.pop();
    }
}