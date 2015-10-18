// Codility Lesson 11
// Ladder

#include <algorithm>

vector<int> solution(vector<int> &A, vector<int> &B) {
    int max_A = *max_element(A.begin(), A.end());
    vector<int> ways_to = vector<int>(max_A + 1);
    ways_to[0] = ways_to[1] = 1;
    for (int i = 2; i <= max_A; i++) {
        ways_to[i] = ways_to[i - 1] + ways_to[i - 2];
        ways_to[i] %= (1 << 30);
    }
    vector<int> results = vector<int>(A.size());
    for (int i = 0; i < A.size(); i++) {
        results[i] = ways_to[A[i]] % (1 << B[i]);
    }
    return results;
}
