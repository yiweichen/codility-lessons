// Codility Lesson 6
// EquiLeader

#include <unordered_map>

int solution(vector<int> &A) {
    unordered_map<int, int> map_count = unordered_map<int, int>();
    int max_count = 0;
    int max_element;
    for (int i = 0; i < A.size(); i++) {
        if (!map_count.count(A[i])) map_count[A[i]] = 0;
        map_count[A[i]]++;
        if (map_count[A[i]] > max_count) {
            max_count = map_count[A[i]];
            max_element = A[i];
        };
    }
    int equi_leaders = 0;
    int left = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] == max_element) left++;
        if (left > (i + 1) / 2 && max_count - left > (A.size() - i - 1) / 2) equi_leaders++;
    }
    return equi_leaders;
}
