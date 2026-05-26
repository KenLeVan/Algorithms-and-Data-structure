#include <iostream>
#include <vector>

void DFS(const std::vector<std::vector<int>>& adj, int current, std::vector<bool>& global_visited, int& count) {
    for (int edge : adj[current]) {
        if (global_visited[edge]) continue;

        global_visited[edge] = true;
        count++;
        DFS(adj, edge, global_visited, count);
    }
}

void find_connected_component(
    const std::vector<std::vector<int>>& adj,
    int start
) {
    std::vector<bool> global_visited(adj.size(), false);
    global_visited[start] = true;
    int count = 1;

    for (int edge : adj[start]) {
        DFS(adj, edge, global_visited, count);
    }

    std::cout << count << '\n';

    for (int i = 0; i < global_visited.size(); i++) {
        if (global_visited[i]) {
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

        adj[from - 1].push_back(to - 1);
        adj[to - 1].push_back(from - 1);
    }

    find_connected_component(adj, 0);
}