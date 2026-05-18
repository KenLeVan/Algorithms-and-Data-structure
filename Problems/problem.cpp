#include <iostream>
#include <vector>
#include <map>

enum class Direction {
    N = 0,
    S = 1,
    W = 2,
    E = 3,
    U = 4,
    D = 5
};

int char_to_direction(char c) {
    switch(c) {
        case 'N': return 0;
        case 'S': return 1;
        case 'W': return 2;
        case 'E': return 3;
        case 'U': return 4;
        case 'D': return 5;
    }
    return -1;
}

int count_moves(
    const std::vector<std::string>& moves,
    char c,
    int n,
    std::map<std::pair<char, int>, int>& patterns
 ) {
    if (n == 1) return 1;

    if (patterns.find({c, n}) == patterns.end()) {
        int count = 1;
        for (char ch : moves[char_to_direction(c)]) {
            count += count_moves(moves, ch, n - 1, patterns);
        }
        patterns[{c, n}] = count;
        return count;
    } else {
        return patterns[{c, n}];
    }
}

int main() {
    std::vector<std::string> mv(6);
    for (int i = 0; i < 6; i++) std::getline(std::cin, mv[i]);

    char collector_move;
    int n;

    std::cin >> collector_move >> n;

    std::map<std::pair<char, int>, int> patterns;
    std::cout << count_moves(mv, collector_move, n, patterns) << '\n';
}