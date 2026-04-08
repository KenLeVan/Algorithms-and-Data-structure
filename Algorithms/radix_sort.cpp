#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

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
    if (vec.empty()) return;

    int min = *std::min_element(vec.begin(), vec.end());

    for (auto& element : vec) {
        element -= min;
    }

    bool swapped = true;
    size_t i = 0;
    
    while(swapped) {
        swapped = false;

        std::vector<std::pair<int, int>> counts;
        for (const auto& element : vec) {
            counts.push_back({get_digit(element, i), element});
            if (get_digit(element, i) != 0) {
                swapped = true;
            }
        }

        std::map<int, std::vector<int>> count_sort;
        for (const auto& pair : counts) {
            count_sort[pair.first].push_back(pair.second);
        }

        std::vector<int> sorted;
        sorted.reserve(vec.size());

        for (size_t j = 0; j < 10; j++) {
            for (const int& num : count_sort[j]) {
                sorted.push_back(num);
            }
        }

        vec = sorted;
        i++;
    }

    for (auto& element : vec) {
        element += min;
    }
}

int main() {
    std::vector<int> vector = {501, 122, 450, 67, 1077, 306};

    radix_sort(vector);
    vector_print(vector);
}