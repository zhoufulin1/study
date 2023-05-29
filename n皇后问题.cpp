#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int n;
const int N = 12;
int a[N];
int result[N][N];

bool check(int x, int y) {
    for (int i = 1; i <= x; i++) {
        if (a[i] == y)
            return false;
        if (i + a[i] == x + y)
            return false;
        if (i - a[i] == x - y)
            return false;
    }
    return true;
}

void dfs(int row) {
    if (row == n+1) {
        cnt++;
        for (int i = 1; i <= n; i++) {
            result[cnt][i] = a[i];
        } 
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (check(row, i)) {
        	cout<<"Âú×ãÌõ¼ş"<<i<<endl;
            a[row] = i;
            dfs(row+1);
            a[row] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << "Total solutions: " << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << "Solution #" << i << ":" << endl;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (k == result[i][j]) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
