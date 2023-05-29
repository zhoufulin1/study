#include <iostream>
#include <stack>

using namespace std;

void move(char x, char y) {
    cout << "Move disk from " << x << " to " << y << endl;
}

void hanoi(int n, char A, char B, char C) {
    stack<pair<int, pair<char, char>>> stk;  // 栈中保存状态，每个状态包括三个变量：盘子数、起始柱子、目标柱子
    stk.push(make_pair(n, make_pair(A, C)));

    while (!stk.empty()) {  // 循环直到栈为空
        pair<int, pair<char, char>> top = stk.top();
        stk.pop();

        n = top.first;
        char x = top.second.first;
        char y = top.second.second;

        if (n == 1) {  // 只有一个盘子时直接移动
            move(x, y);
        } else if (n > 1) {  // 盘子数大于1时需要进行分解子问题
            stk.push(make_pair(n - 1, make_pair(x, B)));  // 将 n-1 个盘子从起始柱子 x 移动到过渡柱子 B 上
            stk.push(make_pair(1, make_pair(x, y)));  // 将最大的盘子从起始柱子 x 直接移动到目标柱子 y 上
            stk.push(make_pair(n - 1, make_pair(B, y)));  // 将 n-1 个盘子从过渡柱子 B 移动到目标柱子 y 上
        }
    }
}

int main() {
    int n = 3;  // 汉诺塔的层数
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
