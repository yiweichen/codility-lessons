// Codility Lesson 4
// NumberOfDiscIntersections

#include <algorithm>

int solution(vector<int> &A) {
    int N = A.size();
    vector<long> left = vector<long>(N);
    vector<long> right = vector<long>(N);
    for (int i = 0; i < N; i++) {
        left[i] = right[i] = i;
        left[i] -= A[i];
        right[i] += A[i];
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int count = 0;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && right[i] >= left[j]) j++;
        count += j - i - 1;
        if (count > 10000000) return -1;
    }
    return count;
}
