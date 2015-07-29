// Codility Lesson 10
// CommonPrimeDivisors

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solution(vector<int> &A, vector<int> &B) {
    int res = 0;
    for (int i = 0; i < A.size(); i++) {
        int gcdAB = gcd(A[i], B[i]);
        int gcdABA = gcd(gcdAB, A[i]);
        while (gcdABA != 1) {
            A[i] /= gcdABA;
            gcdABA = gcd(gcdAB, A[i]);
        }
        if (gcdAB % A[i] > 0) continue;
        int gcdABB = gcd(gcdAB, B[i]);
        while (gcdABB != 1) {
            B[i] /= gcdABB;
            gcdABB = gcd(gcdAB, B[i]);
        }
        if (gcdAB % B[i] > 0) continue;
        res++;
    }
    return res;
}
