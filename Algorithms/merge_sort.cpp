#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void vector_print(const std::vector<T>& v) {
    for (const T& item : v) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> merge(const std::vector<T>& a, const std::vector<T>& b) {
    std::vector<T> merged;
    merged.reserve(a.size() + b.size());
    
    size_t i = 0;
    size_t j = 0;

    for (; i < a.size() && j < b.size();)  {
        if (b[j] < a[i]) {
            merged.push_back(b[j]);
            j++;
        }
        else {
            merged.push_back(a[i]);
            i++;
        }
    }

    merged.insert(merged.end(), a.begin() + i, a.end());
    merged.insert(merged.end(), b.begin() + j, b.end());

    return merged;
}

template <typename T>
std::vector<T> merge_sort(const std::vector<T>& vec) {
    if (vec.size() <= 1) { return vec; }

    auto dilimer = vec.begin() + vec.size()/2;

    std::vector<T> a(vec.begin(), dilimer);
    std::vector<T> b(dilimer, vec.end());

    return merge(merge_sort(a), merge_sort(b));
}

int main() {
    std::vector<int> vector = {5, 11, 15, 7, -2, 22, 1};

    std::vector<int> answer = merge_sort(vector);
    vector_print(answer);    
}