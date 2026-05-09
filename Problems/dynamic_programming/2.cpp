#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int price;
    std::cin >> price;

    int hold = -price;
    int rest = 0;
    int sold = -4e18;

    for (int i = 1; i < num; i++) {
        std::cin >> price;

        int sold_yesterday = sold;

        sold = hold + price;
        hold = std::max(hold, rest - price);
        rest = std::max(rest, sold_yesterday);
    }

    std::cout << std::max(sold, std::max(hold, rest)) << '\n';
}