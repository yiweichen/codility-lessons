// Codility Lesson 1
// TapeEquilibrium

#include <cmath>

int solution(vector<int> &A) {
    long left = A[0];
    long right = 0;
    for (int i = 1; i < A.size(); i++) {
        right += A[i];
    }
    long minDiff = abs(left - right);
    long diff;
    
    for (int p = 1; p < A.size() - 1; p++) {
        left += A[p];
        right -= A[p];
        diff = abs(left - right);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}
