#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

void assert_test(
    const std::vector<float>& conveyer,
    const std::vector<float>& sorted_conveyer
) {
    int current_item = 0;
    std::stack<float> warehouse;

    bool possible = true;

    for (int i = 0; i < conveyer.size() && possible; i++) {
        if (conveyer[i] == sorted_conveyer[current_item]) {
            current_item++;

            while (!warehouse.empty()) {
                if (warehouse.top() == sorted_conveyer[current_item]) {
                    warehouse.pop();
                    current_item++;
                } else break;
            }

        } else {
            if (warehouse.empty() || warehouse.top() >= conveyer[i]) {
                warehouse.push(conveyer[i]);
            } else {
                possible = false;
            }
        }
    }

    if (possible) { std::cout << "1\n"; }
    else { std::cout << "0\n"; }
}

int main() {
    int num_of_tests; std::cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        int size; std::cin >> size;

        std::vector<float> conveyer(size);
        std::vector<float> sorted_conveyer(size);

        for (int j = 0; j < size; j++) { 
            float num; std:: cin >> num;
            conveyer[j] = num; sorted_conveyer[j] = num; 
        }

        std::sort(sorted_conveyer.begin(), sorted_conveyer.end());
        assert_test(conveyer, sorted_conveyer);
    }
}