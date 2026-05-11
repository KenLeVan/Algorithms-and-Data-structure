#include <iostream>

int main() {
    int num, fee;
    std::cin >> num >> fee;

    int hold, rest = 0;
    std::cin >> hold;
    hold = -hold;

    for (int i = 1; i < num; i++) {
        int price;
        std::cin >> price;

        int hold_prev = hold;

        hold = std::max(hold, rest - price);
        rest = std::max(rest, hold_prev + price - fee);
    }

    std::cout << std::max(hold, rest) << '\n';
}