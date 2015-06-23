// Codility Lesson 3
// PassingCars

int solution(vector<int> &A) {
    int count_zeros = 0;
    int count_pairs = 0;
    bool exceeded = false;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 0) {
            count_zeros++;
            if (count_zeros > 1000000000) exceeded = true;
        } else {
            if (exceeded) return -1;
            count_pairs += count_zeros;
            if (count_pairs > 1000000000) return -1;
        }
    }
    return count_pairs;
}
