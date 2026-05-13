#include <iostream>
#include <vector>

void print_vector(const std::vector<std::pair<int, int>>& vec) {
    for (auto& el : vec) {
        std::cout << el.first << ' ' << el.second << '\n';
    }
}

int main() {
    int items, capacity;
    std::cin >> items >> capacity;

    std::vector<std::vector<int>> dp(items + 1, std::vector<int>(capacity + 1, 0));
    std::vector<std::pair<int, int>> item_list(items);

    for (int i = 0; i < items; i++) {
        int weight, value;
        std::cin >> weight >> value;

        item_list[i] = {weight, value};
    }

    for (int i = 1; i <= items; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j - item_list[i - 1].first >= 0) {
                dp[i][j] = std::max(dp[i - 1][j - item_list[i - 1].first] + item_list[i - 1].second, dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::vector<std::pair<int, int>> il;
    int i = items;
    int j = capacity;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            il.push_back(item_list[i - 1]);
            j -= item_list[i - 1].first;
        }
        i--;
    }

    print_vector(il);
}