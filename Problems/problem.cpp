#include <iostream>
#include <map>
#include <string>
#include <fstream>

int main() {
    std::map<std::string, int> frequencies;

    std::ifstream file("test.txt");
    std::string word;

    while (file >> word) {
        if (frequencies.find(word) == frequencies.end()) {
            frequencies[word] = 0;
        } else {
            frequencies[word]++;
        }
        std::cout << frequencies[word] << ' ';
    }

    file.close();
}