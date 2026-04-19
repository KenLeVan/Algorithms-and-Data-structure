#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void vector_print(const std::vector<T> v) {
    for (const auto& item : v) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> quicksort(const std::vector<T> vector) {
    if (vector.size() <= 1) { return vector; }

    std::vector<T> left;
    left.reserve(vector.size() / 2);

    std::vector<T> right;
    right.reserve(vector.size() / 2);

    const T dilimer = vector[0];

    for (size_t i = 1; i < vector.size(); i++) {
        if (vector[i] <= dilimer) {
            left.push_back(vector[i]);
        }
        else {
            right.push_back(vector[i]);
        }
    }

    left = quicksort(left);
    right = quicksort(right);

    std::vector<T> answer;
    answer.reserve(vector.size());

    answer.insert(answer.end(), left.begin(), left.end());
    answer.push_back(dilimer);
    answer.insert(answer.end(), right.begin(), right.end());

    return answer;
}

int main() {
    std::vector<int> vector = {1, 11, 15, 7, 22, -2, 4};

    std::vector<int> answer = quicksort(vector);
    vector_print(answer);
}