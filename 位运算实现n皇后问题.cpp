#include <iostream>
#include <vector>

using namespace std;

int n = 8; // �ʺ�����
vector<bool> row(n, false); // �м�֦
vector<bool> col(n, false); // �м�֦
vector<bool> diag(2*n-1, false); // �Խ��߼�֦
vector<string> ans; // ���н⣨���ַ�����ʾ��

bool is_valid(int r, int c) {
    // �ж�һ��λ���Ƿ�Ϸ�
    return !row[r] && !col[c] && !diag[r+c] && !diag[n-1+r-c];
}

void dfs(string& state, int r) {
    if (r == n) { // �ҵ�һ����
        ans.push_back(state);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (is_valid(r, c)) {
            row[r] = true;
            col[c] = true;
            diag[r+c] = true;
            diag[n-1+r-c] = true;
            state[c] = 'Q';
            dfs(state, r+1);
            row[r] = false;
            col[c] = false;
            diag[r+c] = false;
            diag[n-1+r-c] = false;
            state[c] = '.';
        }
    }
}

void solve() {
    string state(n, '.');
    dfs(state, 0);

    // �Գ������°벿��
    for (int i = 0; i < ans.size(); i++) {
        string sym(n, '.');
        for (int j = 0; j < n; j++) {
            sym[n-1-j] = ans[i][j];
        }
        if (sym != ans[i]) { // �����ظ����ӽ�
            ans.push_back(sym);
        }
    }
}

int main() {
    solve();

    if (ans.empty()) {
        cout << "No solution found" << endl;
    } else {
        cout << "Total solutions found: " << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << "Solution " << i+1 << ":" << endl;
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
