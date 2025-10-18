#include <iostream>
#include <vector>

int main() {

    const int coins[5] = {1, 5, 10, 25, 50};
    const int MAX_AMOUNT = 30000;

    std::vector<unsigned long long> ways(MAX_AMOUNT + 1, 0);
    ways[0] = 1;

    for (int c : coins) {
        for (int amt = c; amt <= MAX_AMOUNT; ++amt) {
            ways[amt] += ways[amt - c];
        }
    }

    int n;
    while (std::cin >> n) {
        unsigned long long m = ways[n];
        if (m == 1ULL) {
            std::cout << "There is only 1 way to produce " << n << " cents change.\n";
        } else {
            std::cout << "There are " << m << " ways to produce " << n << " cents change.\n";
        }
    }
    return 0;
}
