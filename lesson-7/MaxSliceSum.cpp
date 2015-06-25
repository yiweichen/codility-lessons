// Codility Lesson 7
// MaxSliceSum

int solution(vector<int> &A) {
    vector<int> F = vector<int>(A.size(), 0);
    F[0] = A[0];
    int max_sum = F[0];
    for (int i = 1; i < A.size(); i++) {
        if (F[i - 1] > 0) F[i] = F[i - 1] + A[i];
        else F[i] = A[i];
        if (F[i] > max_sum) max_sum = F[i];
    }
    return max_sum;
}
