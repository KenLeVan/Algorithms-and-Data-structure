#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void selection_sort(std::vector<T>& vec) {
    if (vec.empty()) return;

    for (size_t i = 0; i < vec.size() - 1; i++) {
        size_t min_index = i;

        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }

        std::swap(vec[min_index], vec[i]);
    }
}

template <typename T>
void vector_print(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vector = {0, 10, 20, 7, 13};

    selection_sort(vector);
    vector_print(vector);
}