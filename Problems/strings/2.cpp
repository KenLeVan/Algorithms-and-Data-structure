#include <iostream>
#include <map>

int main() {
    int num;
    std::cin >> num;

    std::map<std::string, std::string> dict;

    for (int i = 0; i < num; i++) {
        std::string key, value;
        std::cin >> key >> value;
        dict[key] = value;
        dict[value] = key;
    }

    std::string word;
    std::cin >> word;

    std::cout << dict[word] << '\n';
}
