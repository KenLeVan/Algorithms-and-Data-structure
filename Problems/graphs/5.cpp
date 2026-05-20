#include <iostream>
#include <vector>
#include <queue>
#include <map>

void BFS(
    const std::string& start_green,
    const std::string& start_red
) {
    using namespace std;

    if (start_green == start_red) {
        cout << 0 << '\n';
        return;
    }

    vector<int> mv_x = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> mv_y = {2, 1, -1, -2, -2, -1, 1, 2};

    map<pair<string, string>, bool> is_visited;
    is_visited[{start_green, start_red}] = true;

    queue<pair<pair<string, string>, int>> q;
    q.push({{start_green, start_red}, 0});

    while (!q.empty()) {
        string cur_green = q.front().first.first;
        string cur_red = q.front().first.second;
        int count = q.front().second;

        q.pop();

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char green_mv_x = cur_green[0] + mv_x[i];
                char green_mv_y = cur_green[1] + mv_y[i];
                char red_mv_x = cur_red[0] + mv_x[j];
                char red_mv_y = cur_red[1] + mv_y[j];

                if (green_mv_x < 'a' || green_mv_y < '1' || green_mv_x > 'h' || green_mv_y > '8') {
                    break;
                }
                if (red_mv_x < 'a' || red_mv_y < '1' || red_mv_x > 'h' || red_mv_y > '8') {
                    continue;
                }

                string green_cords = {green_mv_x, green_mv_y};
                string red_cords = {red_mv_x, red_mv_y};

                auto it = is_visited.find({green_cords, red_cords});

                if (it != is_visited.end() && it->second == true) {
                    continue;
                }

                if (green_cords == red_cords) {
                    std::cout << count + 1 << '\n';
                    return;
                }

                is_visited[{green_cords, red_cords}] = true;
                q.push({{green_cords, red_cords}, count + 1});
            }
        }
    }
    
    std::cout << -1 << '\n';
}

int main() {
    std::string start_green, start_red;
    std::cin >> start_green >> start_red;

    BFS(start_green, start_red);
}