// Codility Lesson 5
// Nesting

int solution(string &S) {
    int depth = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') depth++;
        else if (depth == 0) return 0;
        else depth--;
    }
    return depth == 0 ? 1 : 0;
}
