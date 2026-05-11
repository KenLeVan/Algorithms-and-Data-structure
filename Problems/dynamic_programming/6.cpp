#include <iostream>
#include <vector>

int main() {
    int num, K;
    std::cin >> num >> K;

    std::vector<long long> hold(K + 1, -4e18);
    std::vector<long long> rest(K + 1, 0);

    int p;
    std::cin >> p;
    hold[0] = -p;
    
    for (int i = 1; i < num; i++) {
        int price;
        std::cin >> price;

        std::vector<long long> hold_prev = hold;

        for (int j = 1; j <= K; j++) {
            hold[j] = std::max(hold_prev[j], rest[j - 1] - price);
            rest[j] = std::max(rest[j], hold_prev[j] + price);
        }
    }

    std::cout << rest[K] << '\n';
}