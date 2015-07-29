// Codility Lesson 4
// MaxProductOfThree

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int N = A.size();
    return max(A[N - 1] * A[N - 2] * A[N - 3], A[N - 1] * A[0] * A[1]);
}
