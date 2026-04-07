#include <iostream>
#include <vector>
#include <algorithm>

/*

501: %10 = 1 / 1 = 1; 501 % 100 = 01 / 10 = 0
122: %10 = 2 / 1 = 1;

*/

template <typename T>
void vector_print(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int get_digit(const int& num, const int& n) {
    return (num / (int)pow(10, n)) % 10;
}

void radix_sort(std::vector<int>& vec) {
    bool swapped = true;
    size_t i = 0;
    while(swapped) {
        swapped = false;
        for (size_t j = 0; j < vec.size() - 1; j++) {
            if (get_digit(vec[j], i) > get_digit(vec[j + 1], i)) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        i++;
    }
}

int main() {
    std::vector<int> vector = {501, 122, 450, 67, 1077, 306};

    radix_sort(vector);
    vector_print(vector);
}