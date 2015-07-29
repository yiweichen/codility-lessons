// Codility Lesson 3
// MinAvgTwoSlice

int solution(vector<int> &A) {
    double minAvg = (A[0] + A[1]) / 2.0;
    int minIndex = 0;
    double avg;
    for (int i = 0; i <= A.size() - 2; i++) {
        avg = (A[i] + A[i + 1]) / 2.0;
        if (i < A.size() - 2 && A[i + 2] < avg) avg = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
        if (avg < minAvg) {
            minAvg = avg;
            minIndex = i;
        }
    }
    return minIndex;
}
