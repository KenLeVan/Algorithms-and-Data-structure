#include <iostream>
#include <vector>
#include <queue>

void BFS(const std::vector<std::vector<int>>& adj) {
    std::vector<bool> is_visited(adj.size(), false);
    is_visited[0] = true;

    std::queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int edge : adj[current]) {
            if (is_visited[edge]) continue;

            is_visited[edge] = true;
            q.push(edge);
        }
    }

    for (int i = 0; i < is_visited.size(); i++) {
        if (is_visited[i]) {
            std::cout << i + 1 << ' ';
        }
    }
}

int main() {
    int node_num, edge_num;
    std::cin >> node_num >> edge_num;

    std::vector<std::vector<int>> adj(node_num);
    for (int i = 0; i < edge_num; i++) {
        int from, to;
        std::cin >> from >> to;

        if (from == to) continue;

        adj[to - 1].push_back(from - 1);
    }

    BFS(adj);
}