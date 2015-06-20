// Codility Lesson 2
// P1: FrogRiverOne

int solution(int X, vector<int> &A) {
    vector<bool> V = vector<bool>(A.size(), false);
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (!V[A[i]]) {
            V[A[i]] = true;
            sum++;
            if (sum == X) {
                return i;
            }
        }
    }
    return -1;
}
