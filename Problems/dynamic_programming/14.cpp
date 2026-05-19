#include <iostream>
#include <vector>

int main() {
    int num;
    std::cin >> num;

    std::vector<int> A(num);
    std::vector<int> B(num);
    std::vector<int> C(num);

    for (int i = 0; i < num; i++) std::cin >> A[i] >> B[i] >> C[i];

    std::vector<int> dp(num + 1);
    dp[0] = 0;
    dp[1] = A[0];
    dp[2] = std::min(dp[1] + A[1], B[0]);

    for (int i = 3; i <= num; i++) {
        dp[i] = std::min(dp[i - 1] + A[i - 1], std::min(dp[i - 2] + B[i - 2], dp[i - 3] + C[i - 3]));
    }

    std::cout << dp[num] << '\n';
}