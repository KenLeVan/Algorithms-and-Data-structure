#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>

template <typename T>
struct Edge {
    T from;
    T to;
    int weight;
};

template <typename T>
void bellman_ford(
    const std::vector<T>& nodes,
    const std::vector<Edge<T>>& edges, 
    const T& starting_node,
    const T& target_node
) {
    if (starting_node == target_node) {
        std::cout << starting_node << std::endl;
        return;
    }

    std::map<T, T> parent_table;
    std::map<T, int> min_distances;

    for (const T& node : nodes) {
        min_distances[node] = INT_MAX;
    }

    min_distances[starting_node] = 0;

    for (size_t i = 0; i < nodes.size() - 1; i++) {
        for (const auto& e : edges) {
            if (min_distances[e.from] != INT_MAX && min_distances[e.to] > min_distances[e.from] + e.weight) {
                min_distances[e.to] = min_distances[e.from] + e.weight;
                parent_table[e.to] = e.from;
            }
        }
    }

    bool change = false;
    for (const auto& e : edges) {
        if (min_distances[e.to] > min_distances[e.from] + e.weight) {
            change = true;
            break;
        }
    }

    if (min_distances[target_node] == INT_MAX) {
        std::cout << "the path to the target node does not exist" << std::endl;
        return;
    }

    if (change) {
        std::cout << "negative cycle exists, path does not exist" << std::endl;
        return;
    }
    else {
        std::stack<T> path;
        T current_node = target_node;
        while (current_node != starting_node) {
            path.push(current_node);
            current_node = parent_table[current_node];
        }
        path.push(current_node);

        std::cout << "shortest path is: " << min_distances[target_node] << std::endl;
        std::cout << "the path is: ";
        
        while (!path.empty()) {
            std::cout << path.top() << ' ';
            path.pop();
        }
        
        std::cout << std::endl;
    }
}

int main() {
    std::vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F'};

    std::vector<Edge<char>> edges = {
        {'A', 'B', 4},
        {'A', 'C', 2},
        {'B', 'D', -1},
        {'B', 'E', 3},
        {'C', 'F', 10},
        {'E', 'F', 2}
    };

    bellman_ford(nodes, edges, nodes[0], nodes[5]);
}