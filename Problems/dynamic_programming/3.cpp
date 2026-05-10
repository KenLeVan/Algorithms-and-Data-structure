#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int eating = 0;
    int resting = 0;

    for (int i = 0; i < num; i++) {
        int lunch;
        std::cin >> lunch;

        int prev_meal = eating;

        eating = resting + lunch;
        resting = std::max(resting, prev_meal);
    }

    std::cout << std::max(eating, resting) << '\n';
}