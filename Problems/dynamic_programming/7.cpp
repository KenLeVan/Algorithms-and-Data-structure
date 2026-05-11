#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int width, height;
    std::cin >> width >> height;

    std::vector<std::vector<long long>> profit_table(width, std::vector<long long>(height, 0));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            std::cin >> profit_table[i][j];
        }
    }
    
    std::vector<std::vector<long long>> fee(width, std::vector<long long>(height, 0));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            std::cin >> fee[i][j];
        }
    }

    std::vector<long long> max_profit(height);
    for (int i = 0; i < height; i++) {
        max_profit[i] = profit_table[0][i];
    }

    for (int i = 1; i < width; i++) {
        std::vector<long long> next_day(height, -4e18);

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < height; k++) {
                if (j != k) {
                    long long curr_run = max_profit[k] + profit_table[i][j] - fee[k][j];
                    max_profit[j] = std::max(max_profit[j], curr_run);
                }
            }
        }

        max_profit = next_day;
    }

    std::cout << *std::max_element(max_profit.begin(), max_profit.end());
}