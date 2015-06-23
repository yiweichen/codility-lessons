// Codility Lesson 5
// Brackets

#include <stack>

int solution(string &S) {
    stack<char> char_stack = stack<char>();
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(' || S[i] == '[' || S[i] == '{') char_stack.push(S[i]);
        else if (!char_stack.empty()
            && (S[i] == ')' && char_stack.top() == '('
                || S[i] == ']' && char_stack.top() == '['
                || S[i] == '}' && char_stack.top() =='{')) char_stack.pop();
        else return 0;
    }
    return char_stack.empty() ? 1 : 0;
}
