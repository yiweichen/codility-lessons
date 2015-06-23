// Codility Lesson 5
// StoneWall

#include <stack>

int solution(vector<int> &H) {
    stack<int> block_stack = stack<int>();
    int height = 0;
    int count = 0;
    for (int i = 0; i < H.size(); i++) {
        if (block_stack.empty() || height < H[i]) {
            block_stack.push(H[i] - height);
            height = H[i];
            count++;
        } else {
            while (height > H[i]) {
                height -= block_stack.top();
                block_stack.pop();
            }
            if (height < H[i]) {
                block_stack.push(H[i] - height);
                height = H[i];
                count++;
            }
        }
    }
    return count;
}
