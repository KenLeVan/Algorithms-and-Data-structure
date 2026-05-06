#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main() {
    int num;
    std::cin >> num;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;

    for (size_t i = 0; i < num; i++) {
        int profit, deadline;
        std::cin >> profit >> deadline;

        queue.push({deadline, profit});
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> profit_queue;
    int sum_profit = 0;

    while (!queue.empty()) {
        std::pair<int, int> current_task = queue.top();

        if (profit_queue.size() < current_task.first) {
            profit_queue.push(current_task.second);
        } else {
            int worst_task = profit_queue.top();

            if (worst_task < current_task.second) {
                profit_queue.pop();
                profit_queue.push(current_task.second);
            }
        }

        queue.pop();
    }

    while (!profit_queue.empty()) {
        sum_profit += profit_queue.top();
        profit_queue.pop();
    }

    std::cout << sum_profit << '\n';
}