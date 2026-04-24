#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void vector_print(const std::vector<T>& v) {
    for (const auto& item : v) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void heapify(std::vector<T>& vec, const size_t index, size_t size) {
    size_t largest = index;
    if (vec[largest] < vec[2 * index + 1] && (2 * index + 1) < size) {
        largest = 2 * index + 1;
    }
    if (vec[largest] < vec[2 * index + 2] && (2 * index + 2) < size) {
        largest = 2 * index + 2;
    }

    if (largest != index) {
        std::swap(vec[largest], vec[index]);
        heapify(vec, largest, size);
    }
}

template <typename T>
void heapsort(std::vector<T>& vec) {
    for (size_t i = vec.size() / 2 - 1; i != -1; i--) {
        heapify(vec, i, vec.size());
    }

    for (size_t i = 0; i < vec.size(); i++) {
        std::swap(vec[0], vec[vec.size() - i]);
        heapify(vec, 0, vec.size() - i);
    }
}

int main() {
    std::vector<int> vector = {1, 11, 15, 7, 22, -2, 4};

    heapsort(vector);
    vector_print(vector);
}