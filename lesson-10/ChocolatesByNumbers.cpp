// Codility Lesson 10
// ChocolatesByNumbers

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int solution(int N, int M) {
    return N / gcd(N, M);
}
