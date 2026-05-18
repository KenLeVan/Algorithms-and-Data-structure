#include <iostream>
#include <vector>
#include <queue>

struct Point {
    int x, y, z;
    Point(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
    
    bool operator!=(const Point& other) const {
        return x != other.x || y != other.y || z != other.z;
    }
};

void BFS(
    const std::vector<std::vector<std::vector<char>>>& cave,
    int x,
    int y,
    int z
) {
    using namespace std;

    if (x == 0) {
        cout << 0 << '\n';
        return;
    }

    vector<int> mx = {1, -1, 0, 0, 0, 0};
    vector<int> my = {0, 0, 1, -1, 0, 0};
    vector<int> mz = {0, 0, 0, 0, 1, -1};

    vector<vector<vector<Point>>> parent_table(cave.size(), vector<vector<Point>>(cave.size(), vector<Point>(cave.size())));
    vector<vector<vector<bool>>> visited(cave.size(), vector<vector<bool>>(cave.size(), vector<bool>(cave.size(), false)));

    Point start(x, y, z);

    visited[x][y][z] = true;
    queue<Point> q;
    q.push(start);

    Point p;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            bool possible = true;

            if (current.x + mx[i] >= cave.size() || cave[current.x + mx[i]][current.y][current.z] == '#' || current.x + mx[i] < 0) possible = false;
            if (current.y + my[i] >= cave.size() || cave[current.x][current.y + my[i]][current.z] == '#' || current.y + my[i] < 0) possible = false;
            if (current.z + mz[i] >= cave.size() || cave[current.x][current.y][current.z + mz[i]] == '#' || current.z + mz[i] < 0) possible = false;

            if (possible) {
                Point move(current.x + mx[i], current.y + my[i], current.z + mz[i]);
                if (visited[move.x][move.y][move.z]) continue;

                visited[move.x][move.y][move.z] = true;
                parent_table[move.x][move.y][move.z] = Point(current.x, current.y, current.z);
                q.push(move);

                if (move.x == 0) {
                    p = move;

                    int count = 0;
                    while (p != start) {
                        count++;
                        p = parent_table[p.x][p.y][p.z];
                    }

                    std::cout << count << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    int num;
    std::cin >> num;

    std::vector<std::vector<std::vector<char>>> cave(num, std::vector<std::vector<char>>(num, std::vector<char>(num)));
    Point p;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                char point;
                std::cin >> point;

                if (point == 'S') {
                    p.x = i;
                    p.y = j;
                    p.z = k;
                }

                cave[i][j][k] = point;
            }
        }
    }

    BFS(cave, p.x, p.y, p.z);
}