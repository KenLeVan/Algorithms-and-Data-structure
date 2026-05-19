#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

int shift_by_one(int num, int dict) {
    std::string str = std::to_string(num);
    std::string ans = "";

    if (dict == 1) {
        ans += str[str.size() - 1];
        for (int i = 0; i < str.size() - 1; i++) {
            ans += str[i];
        }
    } else {
        for (int i = 1; i < str.size(); i++) {
            ans += str[i];
        }
        ans += str[0];
    }

    return std::stoi(ans);
}

void BFS(int start, int finish) {
    if (start == finish) {
        std::cout << start << '\n' << finish << '\n';
        return;
    }
    std::vector<int> parent_table(10000, -1);

    std::vector<bool> is_visited(10000, false);
    is_visited[start] = true;

    std::queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == finish) break;

        std::vector<int> options = {shift_by_one(current, 1), shift_by_one(current, -1)};
        if (current < 9000) {
            options.push_back(current + 1000);
        }
        if (current % 10 > 1) {
            options.push_back(current - 1);
        }

        for (int element : options) {
            if (is_visited[element]) continue;

            is_visited[element] = true;
            parent_table[element] = current;
            q.push(element);
        }
    }

    std::stack<int> answer;
    int current = finish;
    while (current != start) {
        answer.push(current);
        current = parent_table[current];
    }

    answer.push(start);
    while (!answer.empty()) {
        std::cout << answer.top() << '\n';
        answer.pop();
    }
}

int main() {
    int start, finish;
    std::cin >> start >> finish;

    BFS(start, finish);
}