#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

template <typename T, typename Q>
bool kunh_recursive (
    const T& element,
    std::unordered_set<Q>& is_visited,
    std::map<Q, T>& existing_pairs,
    const std::map<T, std::vector<Q>>& adj
) {
    for (const Q& match : adj.at(element)) {
        if (is_visited.count(match)) continue;

        is_visited.insert(match);

        if (existing_pairs.find(match) == existing_pairs.end() ||
        kunh_recursive(existing_pairs[match], is_visited, existing_pairs, adj)) {
            existing_pairs[match] = element;
            return true;
        }
    }
    return false;
};

template <typename T, typename Q>
void kunh(
    const std::map<T, std::vector<Q>>& adj,
    const std::vector<T>& left_side
) {
    std::map<Q, T> existing_pairs;

    for (const T& element : left_side) {
        std::unordered_set<Q> is_visited;
        kunh_recursive(element, is_visited, existing_pairs, adj);
    }

    for (const auto& pair : existing_pairs) {
        std::cout << pair.second << " - " << pair.first << std::endl;
    }
}

int main() {
    std::map<int, std::vector<char>> adj = {
        {1, {'A', 'B'}},
        {2, {'A', 'B'}},
        {3, {'B', 'C'}},
        {4, {'C', 'D'}},
        {5, {'D'}}
    };

    std::vector<int> left_side = {1, 2, 3, 4, 5};

    kunh(adj, left_side);
}