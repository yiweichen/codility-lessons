// Codility Lesson 6
// Dominator

#include <unordered_map>

int solution(vector<int> &A) {
    unordered_map<int, int> map_count = unordered_map<int, int>();
    for (int i = 0; i < A.size(); i++) {
        if (!map_count.count(A[i])) map_count[A[i]] = 0;
        map_count[A[i]]++;
        if (map_count[A[i]] > A.size() / 2) return i;
    }
    return -1;
}
