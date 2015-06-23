// Codility Lesson 3
// GenomicRangeQuery

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> lastA = vector<int>(S.size(), -1);
    vector<int> lastC = vector<int>(S.size(), -1);
    vector<int> lastG = vector<int>(S.size(), -1);
    for (int i = 0; i < S.size(); i++) {
        if (i > 0) {
            lastA[i] = lastA[i - 1];
            lastC[i] = lastC[i - 1];
            lastG[i] = lastG[i - 1];
        }
        if (S[i] == 'A') lastA[i] = i;
        if (S[i] == 'C') lastC[i] = i;
        if (S[i] == 'G') lastG[i] = i;
    }
    vector<int> result = vector<int>(P.size(), 4);
    for (int i = 0; i < P.size(); i++) {
        if (lastG[Q[i]] >= P[i]) result[i] = 3;
        if (lastC[Q[i]] >= P[i]) result[i] = 2;
        if (lastA[Q[i]] >= P[i]) result[i] = 1;
    }
    return result;
}
