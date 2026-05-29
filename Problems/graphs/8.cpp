#include <iostream>
#include <vector>

bool DFS(
    const std::vector<std::vector<int>>& adj_list,
    int current,
    int prev,
    std::vector<int>& global_visited,
    std::vector<int>& parent_table,
    int& start,
    int& end
) {
    global_visited[current] = 0;

    for (int edge : adj_list[current]) {
        if (edge == prev) continue;

        if (global_visited[edge] == 0) {
            start = edge;
            end = current;
            return true;
        }

        if (global_visited[edge] == -1) {
            parent_table[edge] = current;
            if (DFS(adj_list, edge, current, global_visited, parent_table, start, end)) return true;
        }
    }

    global_visited[current] = 1;
    return false;
}

void find_cycle(const std::vector<std::vector<int>>& adj_list) {
    std::vector<int> global_visited(adj_list.size(), -1);
    std::vector<int> parent_table(adj_list.size(), -1);
    int start = -1, end = -1;

    for (int i = 0; i < adj_list.size(); i++) {
        if (global_visited[i] == 1) continue;

        std::vector<int> current_path;
        
        if (DFS(adj_list, i, -1, global_visited, parent_table, start, end)) break;
    }

    if (start == -1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";

        std::vector<int> cycle;
        for (int i = end; i != start; i = parent_table[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(start);
        std::cout << cycle.size() << '\n';

        for (int node : cycle) {
            std::cout << node + 1 << ' ';
        }

        std::cout << '\n';
    }
}

int main() {
    int size;
    std::cin >> size;

    std::vector<std::vector<int>> adj_list(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int x;
            std::cin >> x;

            if (x == 1) adj_list[i].push_back(j);
        }
    }

    find_cycle(adj_list);
}