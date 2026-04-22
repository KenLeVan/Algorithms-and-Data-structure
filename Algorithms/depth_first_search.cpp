#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

template <typename T>
void vector_print(const std::vector<T>& v) {
    for (const auto& item : v) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
bool DFS_recursive(
        const std::map<T, std::vector<T>>& adj,
        const T& current_node,
        const T& target_node,
        std::vector<T>& path,
        std::unordered_set<T>& is_visited
        ) {

    is_visited.insert(current_node);
    if (current_node == target_node) {
        vector_print(path);
        return true;
    }
    else {
        for (const T& node : adj.at(current_node)) {
            if (is_visited.count(node) > 0) {
                continue;
            }

            path.push_back(node);
            if(DFS_recursive(adj, node, target_node, path, is_visited)) {
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}

template <typename T>
void DFS(
        std::map<T, std::vector<T>>& adj,
        const T& starting_node,
        const T& target_node
        ) {

    std::vector<T> path;
    path.push_back(starting_node);

    std::unordered_set<T> is_visited;
    DFS_recursive(adj, starting_node, target_node, path, is_visited);

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

    DFS(adj, nodes[0], nodes[5]);
}