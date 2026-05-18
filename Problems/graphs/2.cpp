#include <iostream>
#include <vector>
#include <queue>

struct Cell {
    int r, c;
};

int main() {
    int N, M, S, T, Q;
    if (!(std::cin >> N >> M >> S >> T >> Q)) return 0;

    std::vector<std::vector<int>> dist(N + 1, std::vector<int>(M + 1, -1));

    std::queue<Cell> q;
    dist[S][T] = 0;
    q.push({S, T});

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[cur.r][cur.c] + 1;
                q.push({nr, nc});
            }
        }
    }

    long long total_sum = 0;
    bool possible = true;

    for (int i = 0; i < Q; ++i) {
        int br, bc;
        std::cin >> br >> bc;
        if (dist[br][bc] == -1) {
            possible = false;
        }
        if (possible) {
            total_sum += dist[br][bc];
        }
    }

    if (!possible) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << total_sum << std::endl;
    }

    return 0;
}