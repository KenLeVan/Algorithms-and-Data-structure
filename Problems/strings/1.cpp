#include <iostream>
#include <string>
#include <string_view>

std::string standardize_number(const std::string& number) {
    std::string answer = "";

    int i = 0;

    while (i < number.length()) {
        if (number[i] == '(' || number[i] == ')' || number[i] == '-') {
            i++;
            continue;
        }

        answer += number[i];
        i++;
    }

    if (answer[0] == '+') {
        answer = answer.substr(2);
    } else {
        if (answer.length() == 7) {
            answer = "495" + answer;
        } else if (answer[0] == '8') {
            answer = answer.substr(1);
        }
    }

    return answer;
}

int main() {
    std::string current_number;
    std::cin >> current_number;

    current_number = standardize_number(current_number);

    for (int i = 0; i < 3; i++) {
        std::string number;
        std::cin >> number;

        if (current_number == standardize_number(number)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}