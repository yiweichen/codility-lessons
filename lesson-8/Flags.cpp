// Codility Lesson 8
// Flags

#include <cmath>

int solution(vector<int> &A) {
    int N = A.size();
    if (N < 3) return 0;
    vector<int> peak_index = vector<int>();
    for (int i = 1; i < N - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) peak_index.push_back(i);
    }
    if (peak_index.size() == 0) return 0;
    for (int flags = (int)sqrt(N) + 1; flags >= 1; flags--) {
        int last_flag = peak_index[0];
        bool found = true;
        for (int i = 2; i <= flags; i++) {
            vector<int>::const_iterator it = lower_bound(peak_index.begin(),
                                                         peak_index.end(),
                                                         last_flag + flags);
            if (it == peak_index.end()) {
                found = false;
                break;
            }
            last_flag = *it;
        }
        if (found) return flags;
    }
    return 0;
}
