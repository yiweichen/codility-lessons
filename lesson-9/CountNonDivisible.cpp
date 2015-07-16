// Codility Lesson 9
// CountNonDivisible

#include <cmath>

vector<int> solution(vector<int> &A) {
    vector<int> dCount = vector<int>(A.size() * 2 + 2, -1);
    vector<int> nCount = vector<int>(A.size() * 2 + 2, 0);
    for (int i = 0; i < A.size(); i++) nCount[A[i]]++;
    vector<int> ans = vector<int>(A.size());
    for (int i = 0; i < A.size(); i++) {
        if (dCount[A[i]] >= 0) {
            ans[i] = A.size() - dCount[A[i]];
            continue;
        }
        dCount[A[i]] = 0;
        for (int j = 1; j <= sqrt(A[i]); j++) {
            if (A[i] % j == 0) {
                dCount[A[i]] += nCount[j];
                if (j != A[i] / j) dCount[A[i]] += nCount[A[i] / j];
            }
        }
        ans[i] = A.size() - dCount[A[i]];
    }
    return ans;
}
