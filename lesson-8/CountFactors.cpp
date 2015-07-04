// Codility Lesson 8
// CountFactors

#include <cmath>

int solution(int N) {
    if (N == 1) return 1;
    int factor_count = 0;
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            factor_count += (N / i == i ? 1 : 2);
        }
    }
    return factor_count;
}
