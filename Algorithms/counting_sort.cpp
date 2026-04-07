#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

template <typename T>
void vector_print(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void counting_sort(std::vector<int>& vec) {
    if (vec.empty()) return;

    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());

    std::vector<int> counts(max - min + 1, 0);
    for (const int& element : vec) {
        counts[element - min] += 1;
    }

    std::vector<int> ans;
    ans.reserve(vec.size());

    for (size_t i = 0; i < counts.size(); i++) {
        for (size_t j = 0; j < counts[i]; j++) {
            ans.push_back(i + min);
        }
    }

    vec = ans;
}

int main() {
    std::vector<int> vector = {0, 5, 20, 3, 10, 11, -5, 5};
    
    counting_sort(vector);
    vector_print(vector);
}