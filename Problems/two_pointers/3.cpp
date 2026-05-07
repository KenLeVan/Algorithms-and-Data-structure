#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num;
    std::cin >> num;

    std::vector<int> water(num);

    for (int i = 0; i < num; i++) {
        std::cin >> water[i];
    }

    int max_volume = 0;
    int current_volume = 0;

    int begin = 0;
    int end = num - 1;

    while (begin != end) {
        current_volume = std::min(water[begin], water[end]) * (end - begin);
        max_volume = std::max(max_volume, current_volume);
        
        if (water[begin] > water[end]) {
            int current = water[end];
            while (current >= water[end] && begin != end) {
                end--;
            }
        }
        else {
            int current = water[begin];
            while (current >= water[begin] && begin != end) {
                begin++;
            }
        }
    }

    std::cout << max_volume << '\n';
}