#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

template <typename T>
void vector_print(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void radix_sort(std::vector<int>& vec) {
    if (vec.empty()) return;

    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    int exp = 1;

    for (auto& element : vec) {
        element -= min;
    }

    while((max - min) / exp > 0) {
        std::map<int, std::vector<int>> count_sort;
        for (const auto& element : vec) {
            int digit = (element / exp) % 10;
            count_sort[digit].push_back(element);
        }

        int idx = 0;
        for (size_t j = 0; j < 10; j++) {
            for (const int& num : count_sort[j]) {
                vec[idx++] = num;
            }
        }

        exp *= 10;
    }

    for (auto& element : vec) {
        element += min;
    }
}

int main() {
    std::vector<int> vector = {501, 122, 450, 67, 1077, 306, -201};

    radix_sort(vector);
    vector_print(vector);
}