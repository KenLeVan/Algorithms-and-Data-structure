#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>

template <typename T>
struct Edge {
    T from;
    T to;
    int weight;
};

template <typename T>
void dijkstra(
    const std::vector<T>& nodes,
    const std::map<char, std::vector<std::pair<char, int>>>& adj,
    const T& starting_node,
    const T& target_node
) {
    std::set<std::pair<int, T>> active_nodes;
    std::map<T, int> min_distances;
    std::map<T, T> parent_table;
    std::stack<T> path;

    for (const T& node : nodes) {
        active_nodes.insert({INT_MAX, node});
        min_distances[node] = INT_MAX;
    }

    active_nodes.erase({INT_MAX, starting_node});
    active_nodes.insert({0, starting_node});
    min_distances[starting_node] = 0;

    while (!active_nodes.empty()) {
        auto it = active_nodes.begin();

        int current_dist = it->first;
        T current_node = it->second;
        if (current_dist == INT_MAX) {
            break;
        }
        active_nodes.erase(active_nodes.begin());

        for (const auto& e : adj.at(current_node)) {
            if (min_distances[e.first] > min_distances[current_node] + e.second) {
                parent_table[e.first] = current_node;

                active_nodes.erase({min_distances[e.first], e.first});
                min_distances[e.first] = min_distances[current_node] + e.second;
                active_nodes.insert({min_distances[e.first], e.first});
            }
        }
    }

    if (min_distances[target_node] == INT_MAX) {
        std::cout << "path to the node does not exist" << std::endl;
    }
    else {
        T current_node = target_node;
        while (current_node != starting_node) {
            path.push(current_node);
            current_node = parent_table[current_node];
        }
        path.push(current_node);

        std::cout << "the shortest path is: " << min_distances[target_node] << std::endl;

        std::cout << "the path is: ";
        while (!path.empty()) {
            std::cout << path.top() << " ";
            path.pop();
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F'};

    std::map<char, std::vector<std::pair<char, int>>> adj = {
        {'A', {{'B', 4}, {'C', 2}}},
        {'B', {{'D', 1}, {'E', 3}}},
        {'C', {{'F', 10}}},
        {'D', {}},
        {'E', {{'F', 2}}},
        {'F', {}}
    };

    dijkstra(nodes, adj, nodes[0], nodes[5]);
}