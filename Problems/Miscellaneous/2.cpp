#include <iostream>

int main() {
    int number;
    std::cin >> number;

    int constant = number;
    bool c = true;

    int ascending = number;
    bool a = true;

    int weakly_ascending = number;
    bool wa = true;

    int descending = number;
    bool d = true;

    int weakly_descending = number;
    bool wd = true;

    std::cin >> number;

    while (number != -2000000000) {

        if (c) {
            if (constant != number) c = false;
        }

        if (a) {
            if (ascending < number) ascending = number;
            else a = false;
        }

        if (wa) {
            if (weakly_ascending <= number) weakly_ascending = number;
            else wa = false;
        }

        if (d) {
            if (descending > number) descending = number;
            else d = false;
        }

        if (wd) {
            if (weakly_descending >= number) weakly_descending = number;
            else wd = false;
        }

        std::cin >> number;
    }

    if (c) std::cout << "CONSTANT\n";
    else if (a) std::cout << "ASCENDING\n";
    else if (wa) std::cout << "WEAKLY ASCENDING\n";
    else if (d) std::cout << "DESCENDING\n";
    else if (wd) std::cout << "WEAKLY DESCENDING\n";
    else std::cout << "RANDOM\n";
}