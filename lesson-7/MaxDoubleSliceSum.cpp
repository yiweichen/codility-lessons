// Codility Lesson 7
// MaxDoubleSliceSum

int solution(vector<int> &A) {
    vector<int> F = vector<int>(A.size(), 0);
    vector<int> G = vector<int>(A.size(), 0);
    F[0] = 0;
    for (int i = 1; i < A.size(); i++) {
        if (F[i - 1] > 0) F[i] = F[i - 1] + A[i];
        else F[i] = A[i];
    }
    G[A.size() - 1] = 0;
    for (int i = A.size() - 2; i >= 0; i--) {
        if (G[i + 1] > 0) G[i] = G[i + 1] + A[i];
        else G[i] = A[i];
    }
    int max_sum = 0;
    for (int i = 1; i <= A.size() - 2; i++) {
        int sum = 0;
        if (F[i - 1] > 0) sum += F[i - 1];
        if (G[i + 1] > 0) sum += G[i + 1];
        if (sum > max_sum) max_sum = sum;
    }
    return max_sum;
}
