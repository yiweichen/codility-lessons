// Codility Lesson 1
// P2: PermMissingElem

int solution(vector<int> &A) {
    long expectedSum = 0;
    for (int i = 1; i <= A.size() + 1; i++) {
        expectedSum += i;
    }
    
    long actualSum = 0;
    for (int i = 0; i < A.size(); i++) {
        actualSum += A[i];
    }
    
    return expectedSum - actualSum;
}
