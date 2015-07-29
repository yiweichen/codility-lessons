// Codility Lesson 5
// Fish

#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    stack<int> fish_stack = stack<int>();
    int living_fish = 0;
    for (int i = 0; i < A.size(); i++) {
        if (B[i] == 1) fish_stack.push(A[i]);
        else {
            while (!fish_stack.empty() && fish_stack.top() < A[i]) fish_stack.pop();
            if (fish_stack.empty()) living_fish++;
        }
    }
    living_fish += fish_stack.size();
    return living_fish;
}
