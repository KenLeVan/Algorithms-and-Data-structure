#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

void boyer_moore(const std::string &text, const std::string &word) {
    int m = word.length();
    if (m == 0 || text.size() < word.size()) return;

    std::vector<int> suffices(m);
    std::vector<int> gs(m, m);

    suffices[m - 1] = m;
    for (int i = m - 2; i >= 0; i--) {
        int k = i;
        while (k >= 0 && word[k] == word[m - 1 - (i - k)])
            k--;
        suffices[i] = i - k;
    }

    int last_prefix_index = m;
    for (int i = m - 1; i >= 0; i--) {
        if (suffices[i] == i + 1) {
            last_prefix_index = m - 1 - i;
        }
        gs[i] = last_prefix_index;
    }

    for (int i = 0; i < m - 1; i++) {
        if (suffices[i] > 0) {
            gs[m - 1 - suffices[i]] = m - 1 - i;
        }
    }

    std::map<char, int> table;
    for (size_t i = 0; i < word.length(); i++) {
        table[word[i]] = i;
    }

    size_t i = 0;

    while (i <= text.length() - word.length()) {
        int k = word.length() - 1;
        while (k >= 0 && word[k] == text[i + k]) {
            k--;
        }

        if (k < 0) {
            std::cout << i << ' ';
            i++;
        }
        else {
            int good_suff = gs[k];
            int bad_char = k - (table.count(text[i + k]) ? table[text[i + k]] : -1);
            i += std::max(good_suff, std::max(1, bad_char));
        }
    }

    std::cout << "DONE" << std::endl;
}

int main()
{
    std::string text = "abacabdbabaacabb";
    std::string word = "cab";

    boyer_moore(text, word);
}