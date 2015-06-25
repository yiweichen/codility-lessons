// Codility Lesson 7
// MaxProfit

int solution(vector<int> &A) {
    if (A.size() == 0) return 0;
    vector<int> F = vector<int>(A.size());
    F[0] = A[0];
    int max_profit = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < F[i - 1]) F[i] = A[i];
        else F[i] = F[i - 1];
        if (A[i] - F[i] > max_profit) max_profit = A[i] - F[i];
    }
    return max_profit;
}
