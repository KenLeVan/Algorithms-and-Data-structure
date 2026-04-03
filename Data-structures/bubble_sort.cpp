#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void bubble_sort(std::vector<T>& vec) {
    if (vec.empty()) return;
    
    bool swaped;
    for (size_t i = 1; i < vec.size(); i++) {
        swaped = false;
        for (size_t j = 0; j < vec.size() - i; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j+ 1]);
                swaped = true;
            }
        }
        if (!swaped) break;
    }
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {0, 5, 20, 3, 10};

    bubble_sort(v);
    print_vector(v);
}