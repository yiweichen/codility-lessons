// Codility Lesson 11
// FibFrog

int solution(vector<int> &A) {
    int n = A.size();
    if (n == 0 || n == 1) return 1;
    
    vector<int> fib(n + 2);
    fib[0] = 0;
    fib[1] = 1;
    int fib_count = 2;
    for (int i = 2; ; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
        if (fib[i] == n + 1) return 1;
        fib_count++;
        if (fib[i] >= n + 1) break;
    }
    
    vector<int> min_step(n + 1);
    min_step[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!A[i]) {
            min_step[i] = -1;
            continue;
        }
        int curr_min_step = -1;
        for (int j = 2; j < fib_count; j++) {
            if (i + fib[j] > n) break;
            if (i + fib[j] == n) {
                curr_min_step = 0;
                break;
            }
            if ((A[i + fib[j]]) && (min_step[i + fib[j]] >= 0)
                    && (curr_min_step < 0 || min_step[i + fib[j]] < curr_min_step)) {
                curr_min_step = min_step[i + fib[j]];
            }
        }
        min_step[i] = curr_min_step >= 0 ? 1 + curr_min_step : -1;
    }
    
    int min_step_start = -1;
    for (int j = 2; j < fib_count; j++) {
        if (-1 + fib[j] > n) break;
        if (-1 + fib[j] == n) {
            min_step_start = 0;
            break;
        }
        if ((A[-1 + fib[j]]) && (min_step[-1 + fib[j]] >= 0)
                && (min_step_start < 0 || min_step[-1 + fib[j]] < min_step_start)) {
            min_step_start = min_step[-1 + fib[j]];
        }
    }
    
    return min_step_start >= 0 ? 1 + min_step_start : -1;
}
