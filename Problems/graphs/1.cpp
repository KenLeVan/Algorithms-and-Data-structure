#include <iostream>
#include <vector>
#include <queue>

void BFS(
    const std::vector<std::vector<int>>& adj,
    int start,
    int finish
) {
    if (start == finish) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<bool> is_visited(adj.size(), false);
    std::vector<int> parent_table(adj.size());
    std::queue<int> q;

    q.push(start);
    is_visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int edge : adj[current]) {
            if (is_visited[edge]) continue;

            is_visited[edge] = true;
            parent_table[edge] = current;
            q.push(edge);
        }
    }

    if (is_visited[finish] == false) {
        std::cout << -1 << '\n';
        return;
    } else {
        int counter = 0;
        int current = finish;

        while (current != start) {
            counter++;
            current = parent_table[current];
        }

        std::cout << counter << '\n';
    }

}

int main() {
    int num;
    std::cin >> num;

    std::vector<std::vector<int>> adj(num, std::vector<int>(0));

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            int edge;
            std::cin >> edge;

            if (edge == 1) {
                adj[i].push_back(j);
            }
        }
    }

    int start, finish;
    std::cin >> start >> finish;

    BFS(adj, start - 1, finish - 1);
}