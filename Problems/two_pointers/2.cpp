#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num, sum;
    std::cin >> num >> sum;

    std::vector<int> numbers(num);

    for (int i = 0; i < num; i++) {
        std::cin >> numbers[i];
    }

    int num_of_sums = 0;
    int cur_sum = 0;
    int begin = 0;

    for (int end = 0; end < numbers.size(); end++) {
        cur_sum += numbers[end];

        while (cur_sum > sum) {
            cur_sum -= numbers[begin];
            begin++;
        }

        if (cur_sum == sum) {
            num_of_sums++;
        }
    }

    std::cout << num_of_sums << '\n';
}