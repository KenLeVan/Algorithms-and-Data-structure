#include <iostream>
#include <vector>
#include <algorithm>

bool DFS(
    const std::vector<std::vector<int>>& adj,
    std::vector<int>& colours,
    std::vector<int>& sorted_nodes,
    int current
) {
    colours[current] = 0;

    for (int edge : adj[current]) {
        if (colours[edge] == 0) return false;
        if (colours[edge] == 1) continue;

        if (!DFS(adj, colours, sorted_nodes, edge)) return false;
    }

    colours[current] = 1;
    sorted_nodes.push_back(current);
    return true;
}

void topological_sort(const std::vector<std::vector<int>>& adj) {
    std::vector<int> colours(adj.size(), -1);
    std::vector<int> sorted_nodes;

    for (int i = 0; i < adj.size(); i++) {
        if (colours[i] == -1) {
            if (!DFS(adj, colours, sorted_nodes, i)) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }
    
    std::reverse(sorted_nodes.begin(), sorted_nodes.end());

    for (int i = 0; i < sorted_nodes.size(); i++) {
        std::cout << sorted_nodes[i] + 1 << ' ';
    }
    std::cout << '\n';
}

int main() {
    int nodes, edges;
    std::cin >> nodes >> edges;

    std::vector<std::vector<int>> adj(nodes);

    for (int i = 0; i < edges; i++) {
        int from, to;
        std::cin >> from >> to;

        adj[from - 1].push_back(to - 1);
    }

    topological_sort(adj);
}