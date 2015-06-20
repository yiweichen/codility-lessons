// Codility Lesson 2
// P2: PermCheck

int solution(vector<int> &A) {
    vector<bool> V = vector<bool>(A.size(), false);
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > A.size()) return 0;
        if (V[A[i]]) return 0;
        V[A[i]] = true;
    }
    return 1;
}
