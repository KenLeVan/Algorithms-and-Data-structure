#include <iostream>
#include <vector>

void vector_print(const std::vector<std::vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == -1) {
                std::cout << "* ";
            } else {
                std::cout << vec[i][j] << ' ';
            }
        }
        std::cout << '\n';
    }
}

void place_numbers(std::vector<std::vector<int>>& vec) {
    std::vector<int> mv_x = {0, 1, 1, 1, 0, -1, -1, -1};
    std::vector<int> mv_y = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == -1) continue;

            int count = 0;

            for (int k = 0; k < 8; k++) {
                int move_x = i + mv_x[k];
                int move_y = j + mv_y[k];

                if (move_x < 0 || move_x >= vec.size() || move_y < 0 || move_y >= vec[i].size()) continue;

                if (vec[move_x][move_y] == -1) count++;
            }

            vec[i][j] = count;
        }
    }
}

int main() {
    int width, height, num;
    std::cin >> width >> height >> num;

    std::vector<std::vector<int>> field(width, std::vector<int>(height));

    for (int i = 0; i < num; i++) {
        int x, y;
        std::cin >> x >> y;

        field[x - 1][y - 1] = -1;
    }

    place_numbers(field);
    vector_print(field);
}
