// Codility Lesson 8
// Peaks

int solution(vector<int> &A) {
    vector<int> peak_index = vector<int>();
    int N = A.size();
    for (int i = 1; i < N - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peak_index.push_back(i);
        }
    }
    if (peak_index.size() == 0) return 0;
    for (int K = N / peak_index.size(); K <= N; K++){
        if (N % K > 0) continue;
        bool found = true;
        for (int i = 0; i < N / K; i++) {
            vector<int>::const_iterator it = lower_bound(peak_index.begin(), peak_index.end(), i * K);
            if (it == peak_index.end() || (*it) > i * K + K - 1) {
                found = false;
                break;
            }
        }
        if (found) return N / K;
    }
}
