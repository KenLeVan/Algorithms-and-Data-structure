#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int p_red = 0, p_blue = 0, p_green = 0;

    for (int i = 0; i < num; i++) {
        int red, blue, green;
        std::cin >> red >> blue >> green;

        int prev_p_red = p_red;
        int prev_p_blue = p_blue;
        int prev_p_green = p_green;

        p_red = red + std::min(prev_p_blue, prev_p_green);
        p_blue = blue + std::min(prev_p_red, prev_p_green);
        p_green = green + std::min(prev_p_red, prev_p_blue);
    }

    std::cout << std::min(p_red, std::min(p_blue, p_green)) << '\n';
}