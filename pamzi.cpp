#include <iostream>
#include <stack>

using namespace std;

void move(char x, char y) {
    cout << "Move disk from " << x << " to " << y << endl;
}

void hanoi(int n, char A, char B, char C) {
    stack<pair<int, pair<char, char>>> stk;  // ջ�б���״̬��ÿ��״̬������������������������ʼ���ӡ�Ŀ������
    stk.push(make_pair(n, make_pair(A, C)));

    while (!stk.empty()) {  // ѭ��ֱ��ջΪ��
        pair<int, pair<char, char>> top = stk.top();
        stk.pop();

        n = top.first;
        char x = top.second.first;
        char y = top.second.second;

        if (n == 1) {  // ֻ��һ������ʱֱ���ƶ�
            move(x, y);
        } else if (n > 1) {  // ����������1ʱ��Ҫ���зֽ�������
            stk.push(make_pair(n - 1, make_pair(x, B)));  // �� n-1 �����Ӵ���ʼ���� x �ƶ����������� B ��
            stk.push(make_pair(1, make_pair(x, y)));  // ���������Ӵ���ʼ���� x ֱ���ƶ���Ŀ������ y ��
            stk.push(make_pair(n - 1, make_pair(B, y)));  // �� n-1 �����Ӵӹ������� B �ƶ���Ŀ������ y ��
        }
    }
}

int main() {
    int n = 3;  // ��ŵ���Ĳ���
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
