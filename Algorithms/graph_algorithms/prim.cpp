#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>

template <typename T>
void prim(
    std::unordered_set<T> unvisited_nodes,
    const std::map<T, std::vector<std::pair<T, int>>>& adj
) {
    std::unordered_set<T> is_visited;

    while (!unvisited_nodes.empty()) {
        int tree_size = 0;
        std::unordered_set<T> current_tree;
        std::set<std::pair<int, T>> edge_candidates;

        T starting_node = *unvisited_nodes.begin();

        auto add_edges = [&](const T& u) {
            unvisited_nodes.erase(u);
            is_visited.insert(u);
            current_tree.insert(u);
            
            for (const auto& edge : adj.at(u)) {
                T v = edge.first;
                int weight = edge.second;
                if (is_visited.find(v) == is_visited.end()) {
                    edge_candidates.insert({weight, v});
                }
            }
        };

        add_edges(starting_node);

        while (!edge_candidates.empty()) {
            auto best_edge = edge_candidates.begin();
            int weight = best_edge->first;
            T vertex = best_edge->second;
            edge_candidates.erase(best_edge);

            if (is_visited.find(vertex) != is_visited.end()) { continue; }

            tree_size += weight;
            add_edges(vertex);
        }

        std::cout << "The minimal spanning tree is: ";
        for (const T& node : current_tree) {
            std::cout << node << " ";
        }

        std::cout << "The size of the tree is: " << tree_size << std::endl;
    }
}

int main() {
    std::unordered_set<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    std::map<char, std::vector<std::pair<char, int>>> adj = {
        // Компонент 1
        {'A', {{'B', 2}, {'C', 3}}},
        {'B', {{'A', 2}, {'C', 5}}},
        {'C', {{'A', 3}, {'B', 5}}},

        // Компонент 2
        {'D', {{'E', 1}}},
        {'E', {{'D', 1}, {'F', 4}}},
        {'F', {{'E', 4}}},

        // Одинокая вершина (тоже считается компонентом)
        {'G', {}}
    };

    prim(nodes, adj);
}