// Codility Lesson 2
// P4: MaxCounters

vector<int> solution(int N, vector<int> &A) {
    vector<int> C = vector<int>(N, 0);
    int base = 0;
    int max = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] <= N) {
            if (C[A[i] - 1] < base) C[A[i] - 1] = base;
            C[A[i] - 1]++;
            if (C[A[i] - 1] > max) max = C[A[i] - 1];
        } else {
            base = max;
        }
    }
    for (int i = 0; i < N; i++) {
        if (C[i] < base) C[i] = base;
    }
    return C;
}
