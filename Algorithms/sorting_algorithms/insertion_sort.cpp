#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void vector_print(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void insertion_sort(std::vector<T>& vec) {
    if (vec.empty()) return;

    for (size_t i = 0; i < vec.size() - 1; i++) {
        const T element = vec[i + 1];
        size_t j = i + 1;

        for (; j > 0 && vec[j - 1] > element; j--) {
            vec[j] = vec[j - 1];
        }
        
        vec[j] = element;
    }
}

int main() {
    std::vector<int> vector = {5, 11, 15, 6, 24, 14, 0, -2};

    insertion_sort(vector);
    vector_print(vector);
}