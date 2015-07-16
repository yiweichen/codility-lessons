// Codility Lesson 9
// CountSemiprimes

#include <cmath>

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<bool> isPrime = vector<bool>(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> prime = vector<int>();
    for (int i = 2; i <= N; i++) {
        if (!isPrime[i]) continue;
        prime.push_back(i);
        for (int j = i * 2; j <= N; j += i) isPrime[j] = false;
    }
    
    vector<int> semiprimeCount = vector<int>(N + 1);
    semiprimeCount[0] = 0;
    for (int i = 1; i <= N; i++) {
        semiprimeCount[i] = semiprimeCount[i - 1];
        for (int j = 0; j < prime.size() && prime[j] <= sqrt(i); j++) {
            if (i % prime[j] == 0 && isPrime[i / prime[j]] ) {
                semiprimeCount[i]++;
                break;
            }
        }
    }
    
    vector<int> ans = vector<int>(P.size());
    for (int i = 0; i < P.size(); i++) {
        ans[i] = semiprimeCount[Q[i]] - semiprimeCount[P[i] - 1];
    }
    return ans;
}
