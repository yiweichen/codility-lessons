// Codility Lesson 2
// P3: MissingInteger

int solution(vector<int> &A) {
    vector<bool> V = vector<bool>(A.size() + 1, false);
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0 && A[i] <= A.size()) {
            V[A[i]] = true;
        }
    }
    for (int i = 1; i <= A.size(); i++) {
        if (!V[i]) return i;
    }
    return A.size() + 1;
}
