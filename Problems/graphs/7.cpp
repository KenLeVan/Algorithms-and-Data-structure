#include <iostream>
#include <vector>
#include <queue>

void BFS(const std::vector<std::vector<int>> connections) {
    std::vector<int> colours(connections.size(), -1);
    std::vector<bool> global_visited(connections.size(), false);

    int count = 0;
    int start = 0;

    while (count < connections.size()) {
        if (global_visited[start]) {
            start++;
            continue;
        }

        std::queue<int> q;
        q.push(start);

        colours[start] = 0;
        global_visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;

            for (int student : connections[current]) {
                if (colours[current] == colours[student]) {
                    std::cout << "NO\n";
                    return;
                }

                if (global_visited[student]) continue;

                global_visited[student] = true;
                q.push(student);
                colours[student] = (colours[current] + 1) % 2;
            }
        }
    }
    
    std::cout << "YES\n";
}

int main() {
    int student_num, trades_num;
    std::cin >> student_num >> trades_num;

    std::vector<std::vector<int>> connections(student_num);

    for (int i = 0; i < trades_num; i++) {
        int first, second;
        std::cin >> first >> second;

        connections[first - 1].push_back(second - 1);
        connections[second - 1].push_back(first - 1);
    }

    BFS(connections);
}