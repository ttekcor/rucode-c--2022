#include <iostream>
#include <vector>

std::vector<int> calculateMinPrimeDivisors(int limit) {
    std::vector<int> minPrimeDivisors(limit + 1, 0);

    for (int i = 2; i <= limit; i++) {
        if (minPrimeDivisors[i] == 0) {
            for (int j = i; j <= limit; j += i) {
                if (minPrimeDivisors[j] == 0) {
                    minPrimeDivisors[j] = i;
                }
            }
        }
    }

    return minPrimeDivisors;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> minPrimeDivisors = calculateMinPrimeDivisors(n);

    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        sum += minPrimeDivisors[i];
    }

    std::cout << sum;

    return 0;
}