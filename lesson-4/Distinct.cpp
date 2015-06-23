// Codility Lesson 4
// Distinct

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int distinct = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i == 0 || A[i] != A[i - 1]) distinct++;
    }
    return distinct;
}
