// Codility Lesson 8
// MinPerimeterRectangle

#include <cmath>

int solution(int N) {
    for (int i = (int)sqrt(N); i >= 1; i--) {
        if (N % i == 0) {
            return 2 * (i + N / i);
        }
    }
}
