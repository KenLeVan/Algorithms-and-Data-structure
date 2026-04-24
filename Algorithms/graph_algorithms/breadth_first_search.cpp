#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
#include <stack>

template <typename T>
void vector_print(const std::vector<T>& v) {
    for (const auto& item : v) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void BFS(
    const std::map<T, std::vector<T>>& adj,
    const T& starting_node,
    const T& target_node
) {;
    std::queue<T> next_nodes;
    std::map<T, T> parent_table;
    std::unordered_set<T> is_visited;

    next_nodes.push(starting_node);
    is_visited.insert(starting_node);

    bool found = false;
    while (!next_nodes.empty() && found == false) {
        T current_node = next_nodes.front();
        next_nodes.pop();

        if (current_node == target_node) {
            found = true;
        }

        for (const T& node : adj.at(current_node)) {
            if (is_visited.find(node) != is_visited.end()) {
                continue;
            }

            is_visited.insert(node);
            parent_table[node] = current_node;
            next_nodes.push(node);
        }
    }

    if (found) {
        std::stack<T> path;
        T current_node = target_node;
        while (current_node != starting_node) {
            path.push(current_node);
            current_node = parent_table[current_node];
        }
        path.push(current_node);

        while (!path.empty()) {
            std::cout << path.top() << ' ';
            path.pop();
        }
    }
}

int main() {
    std::vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F'};

    std::map<char, std::vector<char>> adj = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };

    BFS(adj, nodes[0], nodes[5]);
}