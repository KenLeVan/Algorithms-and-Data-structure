#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string text;
    int K;
    std::cin >> text >> K;

    std::vector<int> current_characters(128, 0);
    int num_chars = 0;
    int begin = 0;
    int length = 0;
    int current_length = 0;

    for (int end = 0; end < text.size(); end++) {
        unsigned char c_end = text[end];
        bool added = false;

        current_characters[c_end]++;
        current_length++;

        if (current_characters[c_end] == 1) {
            num_chars++;
        }

        while (num_chars > K && begin < text.size()) {
            unsigned char c_begin = text[begin];

            current_characters[c_begin]--;
            if (current_characters[c_begin] == 0) {
                num_chars--;
            }

            begin++;
            current_length--;
        }

        length = std::max(length, current_length);
    }

    std::cout << length << '\n';
}