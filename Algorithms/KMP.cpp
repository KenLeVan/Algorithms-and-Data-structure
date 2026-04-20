#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
void vector_print(const std::vector<T>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

void KMP(const std::string& text, const std::string& word) {
    std::string str = word + '#' + text;

    std::vector<int> pi_function;
    pi_function.reserve(str.size());
    pi_function.push_back(0);

    size_t j = 0;
    for (size_t i = 1; i < str.length(); i++) {
        while (str[j] != str[i] && j > 0) {
            j = pi_function[j - 1];
        }
        if (str[j] == str[i]) {
            j++;
        }
        pi_function.push_back(j);
    }

    for (size_t i = 0; i < pi_function.size(); i++) {
        if (pi_function[i] == word.length()) {
            std::cout << i << ' ';
        }
    }
}

int main() {
    std::string text = "abacabababaacabb";
    std::string word = "cab";
    KMP(text, word);
}