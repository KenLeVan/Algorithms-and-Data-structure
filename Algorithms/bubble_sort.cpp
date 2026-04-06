#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubble_sort(std::vector<T>& vec) {
    if (vec.empty()) return;
    
    bool swapped;
    for (size_t i = 1; i < vec.size(); i++) {
        swapped = false;
        for (size_t j = 0; j < vec.size() - i; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j+ 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    std::vector<int> vector = {0, 5, 20, 3, 10};

    bubble_sort(vector);
    print_vector(vector);
}